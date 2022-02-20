#pragma once

#include "codegen/backend.hpp"
#include <vector>

class Fasm64 : public Backend {
public:
  Fasm64(std::string);

  void generate(Decl *);
  void compile();

private:
  std::string temp;
};