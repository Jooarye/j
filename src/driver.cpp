#include "driver.hpp"
#include "parser.hpp"

Driver::Driver() {}

int Driver::parse(const std::string &f) {
  file = f;
  location.initialize(&file);
  scan_begin();
  yy::parser parse(*this);
  int res = parse();
  scan_end();
  return res;
}