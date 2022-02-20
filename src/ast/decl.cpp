#include "ast/decl.hpp"
#include "ast/type.hpp"
#include "message.hpp"
#include <algorithm>
#include <cstddef>

Decl::Decl(DeclKind kind, std::string name, Stmt *body, Expr *value, Type *type,
           yy::location loc) {
  this->kind = kind;
  this->name = name;
  this->body = body;
  this->value = value;
  this->type = type;
  this->loc = loc;
  this->loc.begin.filename = new std::string(*this->loc.begin.filename);
  this->loc.end.filename = new std::string(*this->loc.end.filename);
}

Decl *Decl::newFn(std::string name, Stmt *body, Type *type, yy::location loc) {
  return new Decl(DeclKind::FUNC, name, body, 0, type, loc);
}

Decl *Decl::newVar(std::string name, Expr *value, Type *type,
                   yy::location loc) {
  return new Decl(DeclKind::VAR, name, 0, value, type, loc);
}

void Decl::resolve() {
  this->sym = Symbol::newSymbol(scopeLevel() == 1 ? SymbolKind::GLOBAL
                                                  : SymbolKind::LOCAL,
                                this->type, this->name);

  if (this->kind == DeclKind::FUNC) {
    scopeBind(this->name, this->sym);
    scopeEnter();

    for (Param *p : *this->type->params) {
      p->resolve();
    }

    if (this->body)
      this->body->resolve();

    scopeExit();
  } else {
    if (this->value)
      this->value->resolve();

    scopeBind(this->name, this->sym);
  }
}

void Decl::typeCheck() {
  if (this->kind == DeclKind::FUNC) {
    // TODO: implement this
    // std::cout << this->loc << ": note: can't type check functions atm" <<
    // std::endl;

    if (this->body)
      this->body->typeCheck();
  } else {
    if (!this->value)
      return;

    Type *vt = this->value->typeCheck();

    if (!this->type->isEqual(vt))
      Message::error("type missmatch for variable declaration", this->loc);
  }
}

std::ostream &operator<<(std::ostream &os, Decl *d) {
  if (d->kind == DeclKind::FUNC) {
    os << "fn " << d->name << "(" << d->type->params << ") ";

    if (d->type->subType->kind != TypeKind::NIL)
      os << d->type->subType << " ";

    if (d->body)
      os << d->body;
    else
      os << ";";

    os << "\n";
  } else {
    os << d->type << " " << d->name;

    if (d->value)
      os << " = " << d->value;

    os << ";\n";
  }

  return os;
}