#pragma once

#include "location.hpp"
#include "type.hpp"
#include <cstdint>
#include <ostream>
#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <vector>

class Driver;

enum class ExprKind {
  ID,  // identifier
  INT, // 12, 23, -23
  STR, // "abcdef"

  ARG, // ("asd", 12)

  // Mathematical
  ADD, // +
  SUB, // -
  MUL, // *
  DIV, // /
  MOD, // %
  INC, // inc
  DEC, // dec

  // Comparasion
  EQ,   // ==
  NE,   // !=
  LT,   // <
  GT,   // >
  LTEQ, // <=
  GTEQ, // >=

  // Binary
  AND, // &
  OR,  // |
  XOR, // ^
  NOT, // ~

  // Logical
  LAND, // and
  LOR,  // or
  LNOT, // not

  CALL,   // call
  ASSIGN, // =
  INDEX,  // [1]
};

class Expr {
public:
  Expr(ExprKind, Expr *, Expr *, std::string, uint64_t, yy::location);

  static Expr *newBinary(ExprKind, Expr *, Expr *, yy::location);
  static Expr *newUnary(ExprKind, Expr *, yy::location);
  static Expr *newConst(std::string, yy::location);
  static Expr *newConst(uint64_t, yy::location);
  static Expr *newIdent(std::string, yy::location);
  static Expr *newArg(Expr *, yy::location);

  void resolve();
  void add(Expr *);
  Type *typeCheck();

  ExprKind kind;
  Expr *left;
  Expr *right;

  uint64_t integer;
  std::string string;

  yy::location loc;

  Symbol *sym;
};

std::ostream &operator<<(std::ostream &, Expr *);