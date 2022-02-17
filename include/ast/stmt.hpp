#pragma once

#include "ast/decl.hpp"
#include "ast/expr.hpp"
#include <ostream>
#include <vector>

class Decl;

enum class StmtKind {
  EXPR,
  DECL,

  BLOCK,

  IF,
  WHILE,
  FOR,

  BREAK,
  RETURN,
  CONTINUE,
};

class Stmt {
public:
  Stmt(StmtKind, Expr *, Expr *, Expr *, Decl *, Stmt *, Stmt *);

  static Stmt *newExpr(Expr *);
  static Stmt *newDecl(Decl *);
  static Stmt *newBlock();
  static Stmt *newIf(Expr *, Stmt *, Stmt *);
  static Stmt *newWhile(Expr *, Stmt *);
  static Stmt *newFor(Expr *, Expr *, Expr *, Stmt *);
  static Stmt *newReturn(Expr *);
  static Stmt *newContinue();
  static Stmt *newBreak();

  void addChild(Stmt *);

  StmtKind kind;

  Expr *expr;
  Expr *init;
  Expr *next;
  Decl *decl;

  Stmt *consequence;
  Stmt *alternative;

  std::vector<Stmt *> body;
};

std::ostream &operator<<(std::ostream &, Stmt *);