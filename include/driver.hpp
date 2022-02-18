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

  std::vector<std::string> importedFiles;
  std::vector<std::string> handledFiles;
  std::vector<Decl *> ast;
  std::string file;

  int parse(const std::string &f);
  void addImportedFile(std::string f, yy::location loc);

  void scan_begin();
  void scan_end();

  yy::location location;
};