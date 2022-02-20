#pragma once

#include "ast/decl.hpp"
#include "ast/expr.hpp"
#include "location.hpp"
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
  Stmt(StmtKind, Expr *, Expr *, Expr *, Decl *, Stmt *, Stmt *, yy::location);

  static Stmt *newExpr(Expr *, yy::location);
  static Stmt *newDecl(Decl *, yy::location);
  static Stmt *newBlock(yy::location);
  static Stmt *newIf(Expr *, Stmt *, Stmt *, yy::location);
  static Stmt *newWhile(Expr *, Stmt *, yy::location);
  static Stmt *newFor(Expr *, Expr *, Expr *, Stmt *, yy::location);
  static Stmt *newReturn(Expr *, yy::location);
  static Stmt *newContinue(yy::location);
  static Stmt *newBreak(yy::location);

  void addChild(Stmt *);
  void resolve();
  void typeCheck();

  StmtKind kind;

  Expr *expr;
  Expr *init;
  Expr *next;
  Decl *decl;

  Stmt *consequence;
  Stmt *alternative;

  std::vector<Stmt *> body;

  yy::location loc;
};

std::ostream &operator<<(std::ostream &, Stmt *);