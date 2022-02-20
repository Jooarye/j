#pragma once

#include "codegen/backend.hpp"
#include <vector>

class Fasm_x86_64 : public Backend {
public:
  Fasm_x86_64(std::string);

  void generate(std::vector<Decl *> *);
  void compile();

private:
  std::string temp;
};