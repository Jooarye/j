#pragma once

#include "ast/expr.hpp"
#include "ast/stmt.hpp"
#include "ast/type.hpp"
#include "location.hpp"
#include <ostream>
#include <vector>

class Stmt;

enum class DeclKind { FUNC, VAR };

class Decl {
public:
  Decl(DeclKind, std::string, Stmt *, Expr *, Type *, yy::location);

  static Decl *newFn(std::string, Stmt *, Type *, yy::location);
  static Decl *newVar(std::string, Expr *, Type *, yy::location);

  void resolve();
  void typeCheck();

  DeclKind kind;
  std::string name;
  Stmt *body;
  Expr *value;
  Type *type;
  Symbol *sym;

  yy::location loc;
};

std::ostream &operator<<(std::ostream &, Decl *);