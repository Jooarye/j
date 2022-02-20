#include "codegen/fasm64.hpp"
#include "codegen/backend.hpp"
#include <fstream>

Fasm64::Fasm64(std::string file) : Backend(file) {
  this->temp = "/tmp/temp.asm";
}

void Fasm64::generate(Decl *ast) {
  std::ofstream out(this->temp);

  // Code gen

  out.close();
}

void Fasm64::compile() {
  // Running commands
}