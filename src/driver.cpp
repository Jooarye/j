#include "driver.hpp"
#include "location.hpp"
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

  for (std::string ifile : this->importedFiles) {
    if (std::find(this->handledFiles.begin(), this->handledFiles.end(),
                  ifile) != this->handledFiles.end())
      continue;

    file = ifile;

    this->handledFiles.push_back(ifile);

    location.initialize(&file);
    scan_begin();

    res |= inst();

    scan_end();
  }

  return res;
}

void Driver::addImportedFile(std::string f, yy::location loc) {
  if (f.starts_with('/')) {
    if (!std::filesystem::exists(f)) {
      std::cerr << loc << ": error: file path couldn't be resolved"
                << std::endl;
      exit(1);
    }

    if (std::find(this->handledFiles.begin(), this->handledFiles.end(), f) !=
        this->handledFiles.end()) {
      std::cerr << loc << ": error: file cannot include be included twice"
                << std::endl;
      exit(1);
    }

    this->importedFiles.push_back(f);
  } else {
    // Relative
    if (!std::filesystem::exists(f)) {
      std::cerr << loc << ": error: file path couldn't be resolved"
                << std::endl;
      exit(1);
    }

    std::filesystem::path p = std::filesystem::absolute(f);

    if (std::find(this->handledFiles.begin(), this->handledFiles.end(), p) !=
        this->handledFiles.end()) {
      std::cerr << loc << ": error: file cannot include be included twice: "
                << std::endl;
      exit(1);
    }

    this->importedFiles.push_back(p);
  }
}