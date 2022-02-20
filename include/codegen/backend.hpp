#pragma once

#include "ast.hpp"
#include <string>

class Backend {
public:
  Backend(std::string);

  virtual void generate(Decl *) = 0;
  virtual void compile() = 0;

private:
  std::string file;
};