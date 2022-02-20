#include "codegen/fasm_x86_64.hpp"
#include "codegen/backend.hpp"
#include <fstream>

Fasm_x86_64::Fasm_x86_64(std::string file) : Backend(file) {
  this->temp = "/tmp/temp.asm";
}

void Fasm_x86_64::generate(std::vector<Decl *> *ast) {
  std::ofstream out(this->temp);

  // Code gen

  out.close();
}

void Fasm_x86_64::compile() {
  // Running commands
}