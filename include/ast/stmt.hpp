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
  Stmt(StmtKind, Expr *, Expr *, Expr *, Decl *, Stmt *, Stmt *, Stmt *,
       yy::location);

  static Stmt *newExpr(Expr *, yy::location);
  static Stmt *newDecl(Decl *, yy::location);
  static Stmt *newBlock(Stmt *, yy::location);
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
  Expr *nextExpr;
  Decl *decl;

  Stmt *consequence;
  Stmt *alternative;

  Stmt *next;

  yy::location loc;
};

std::ostream &operator<<(std::ostream &, Stmt *);