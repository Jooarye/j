#pragma once

#include <cstdint>
#include <ostream>
#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <vector>

enum class ExprKind {
  ID,  // identifier
  INT, // 12, 23, -23
  STR, // "abcdef"

  ARGS, // ("asd", 12)

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
  Expr(ExprKind, Expr *, Expr *, std::string, uint64_t, std::vector<Expr *> *);

  static Expr *newBinary(ExprKind, Expr *, Expr *);
  static Expr *newUnary(ExprKind, Expr *);
  static Expr *newConst(std::string);
  static Expr *newConst(uint64_t);
  static Expr *newIdent(std::string);
  static Expr *newArgs(std::vector<Expr *> *);

  ExprKind kind;
  Expr *left;
  Expr *right;

  std::vector<Expr *> *args;

  uint64_t integer;
  std::string string;
};

std::ostream &operator<<(std::ostream &, Expr *);
std::ostream &operator<<(std::ostream &, std::vector<Expr *> *);