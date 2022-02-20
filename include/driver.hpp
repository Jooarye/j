#pragma once

#include "ast/decl.hpp"
#include "location.hpp"
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
  Decl *ast;
  std::string file;

  int parse(const std::string &f);
  void resolve();
  void typeCheck();

  void error(std::string, yy::location);
  void note(std::string, yy::location);

  void addImportedFile(std::string f, yy::location loc);

  void scan_begin();
  void scan_end();

  yy::location location;
};