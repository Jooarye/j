#pragma once

#include "ast/expr.hpp"
#include "ast/stmt.hpp"
#include "ast/type.hpp"
#include <ostream>
#include <vector>

class Stmt;

enum class DeclKind { FUNC, VAR };

class Decl {
public:
  Decl(DeclKind, std::string, Stmt *, Expr *, Type *);

  static Decl *newFn(std::string, Stmt *, Type *);
  static Decl *newVar(std::string, Expr *, Type *);

  DeclKind kind;
  std::string name;
  Stmt *body;
  Expr *value;
  Type *type;
};

std::ostream &operator<<(std::ostream &, Decl *);