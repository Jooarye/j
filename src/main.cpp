#include "ast.hpp"
#include "ast/decl.hpp"
#include "codegen/backend.hpp"
#include "codegen/fasm64.hpp"
#include "driver.hpp"
#include "message.hpp"
#include <iostream>
#include <string>

struct Conf {
  std::string input;
  std::string ouput = "a.out";

  bool silent = false;
};

bool cli(Conf &c, int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];

    if (arg.starts_with("-")) {
      if ((arg == "-o" || arg == "--out") && i + 1 < argc) {
        c.ouput = argv[i++];
      } else if (arg == "-s" || arg == "--silent") {
        c.silent = true;
      } else {
        std::cerr << "jc: error: unknown flag: " << arg << std::endl;
      }
    } else {
      c.input = arg;
      return true;
    }
  }

  // print help since parsing failed
  std::cout << "usage: jc [OPTIONS] file" << std::endl
            << std::endl
            << "OPTIONS:" << std::endl
            << "  -o, --output: specify the output file" << std::endl
            << "  -s, --silent: stop printing notes" << std::endl;

  return false;
}

int main(int argc, char *argv[]) {
  Conf c;

  if (!cli(c, argc, argv))
    exit(1);

  Driver drv;

  if (!drv.parse(c.input)) {
    drv.resolve();
    drv.typeCheck();

    bool fail = false;
    for (Message m : messages) {
      if (c.silent && m.kind == MessageKind::NOTE)
        continue;

      if (m.kind == MessageKind::ERROR)
        fail = true;

      std::cerr << m;
    }

    if (!fail) {
      Backend *be = new Fasm64(c.ouput);
      be->generate(drv.ast);
      be->compile();

      std::cout << "jc: note: compilation finished" << std::endl;
      exit(0);
    }
  }

  std::cout << "jc: error: compilation failed" << '\n';

  return 2;
}