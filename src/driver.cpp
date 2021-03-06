#include "driver.hpp"
#include "ast/decl.hpp"
#include "ast/type.hpp"
#include "location.hpp"
#include "message.hpp"
#include "parser.hpp"
#include <filesystem>

Driver::Driver() {}

int Driver::parse(const std::string &f) {
  file = f;

  std::filesystem::path cur = std::filesystem::absolute(this->file);
  this->handledFiles.push_back(cur);

  location.initialize(&file);
  scan_begin();

  yy::parser inst(*this);
  int res = inst();

  scan_end();

  if (res != 0)
    return res;

  for (std::string ifile : this->importedFiles) {
    if (std::find(this->handledFiles.begin(), this->handledFiles.end(),
                  ifile) != this->handledFiles.end())
      continue;

    Decl *cur = this->ast;

    res |= this->parse(ifile);

    this->ast->add(cur);
  }

  return res;
}

void Driver::resolve() {
  scopeEnter();

  this->ast->resolve();

  scopeExit();
}

void Driver::typeCheck() { this->ast->typeCheck(); }

void Driver::addImportedFile(std::string f, yy::location loc) {
  if (f.starts_with('/')) {
    if (!std::filesystem::exists(f)) {
      Message::error("file path couldn't be resolved");
      exit(1);
    }

    if (std::find(this->handledFiles.begin(), this->handledFiles.end(), f) !=
        this->handledFiles.end()) {
      return;
    }

    this->importedFiles.push_back(f);
  } else {
    // Relative
    if (!std::filesystem::exists(f)) {
      Message::error("file path couldn't be resolved");
      exit(1);
    }

    std::filesystem::path p = std::filesystem::absolute(f);

    if (std::find(this->handledFiles.begin(), this->handledFiles.end(), p) !=
        this->handledFiles.end()) {
      return;
    }

    this->importedFiles.push_back(p);
  }
}