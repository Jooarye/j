#pragma once

#include "ast.hpp"
#include "parser.hpp"
#include <string>
#include <vector>

#define YY_DECL yy::parser::symbol_type yylex(Driver &drv)
YY_DECL;

class Driver {
public:
  Driver();

  std::vector<Decl *> ast;
  std::string file;

  int parse(const std::string &f);

  void scan_begin();
  void scan_end();

  yy::location location;
};