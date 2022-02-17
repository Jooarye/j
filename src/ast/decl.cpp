#include "ast/decl.hpp"
#include <cstddef>

Decl::Decl(DeclKind kind, std::string name, Stmt *body, Expr *value,
           Type *type) {
  this->kind = kind;
  this->name = name;
  this->body = body;
  this->value = value;
  this->type = type;
}

Decl *Decl::newFn(std::string name, Stmt *body, Type *type) {
  return new Decl(DeclKind::FUNC, name, body, 0, type);
}

Decl *Decl::newVar(std::string name, Expr *value, Type *type) {
  return new Decl(DeclKind::VAR, name, 0, value, type);
}

std::ostream &operator<<(std::ostream &os, Decl *d) {
  if (d->kind == DeclKind::FUNC) {
    os << "fn " << d->name << "(" << d->type->params << ") ";

    if (d->type->subType->kind != TypeKind::NIL)
      os << d->type->subType << " ";

    os << d->body << "\n";
  } else {
    os << d->type << " " << d->name;

    if (d->value)
      os << " = " << d->value;

    os << ";\n";
  }

  return os;
}