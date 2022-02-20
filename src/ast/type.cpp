#include "ast/type.hpp"
#include <cstdint>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

Type::Type(TypeKind kind, Type *subType, Param *params) {
  this->kind = kind;
  this->subType = subType;
  this->params = params;
}

Type *Type::newAtomic(TypeKind kind) { return new Type(kind, 0, 0); }

Type *Type::newArray(Type *type) { return new Type(TypeKind::ARRAY, type, 0); }

Type *Type::newComplex(TypeKind kind, Type *subType, Param *params) {
  return new Type(kind, subType, params);
}

bool Type::isEqual(Type *t) {
  if (this->kind == t->kind) {
    if (this->isAtomic() && t->isAtomic()) {
      return true;
    } else if (this->kind == TypeKind::ARRAY && t->kind == TypeKind::ARRAY) {
      return this->subType->isEqual(t->subType);
    } else if (this->kind == TypeKind::FUNC && t->kind == TypeKind::FUNC) {
      Param *a = this->params;
      Param *b = t->params;

      while (a && b) {
        if (!a->isEqual(b))
          return false;
      }

      if (a || b)
        return false;

      return this->subType->isEqual(t->subType);
    }
  }
  return false;
}

bool Type::isAtomic() {
  return this->kind == TypeKind::STR || this->kind == TypeKind::INT;
}

Param::Param(std::string name, Type *type) {
  this->name = name;
  this->type = type;
}

Param *Param::newParam(std::string name, Type *type) {
  return new Param(name, type);
}

void Param::add(Param *p) {
  if (!this->next)
    this->next = p;
  else
    this->next->add(p);
}

bool Param::isEqual(Param *p) {
  return p->name == this->name && p->type->isEqual(this->type);
}

void Param::resolve() {
  this->sym = Symbol::newSymbol(SymbolKind::PARAM, this->type, this->name);
  scopeBind(this->name, this->sym);

  if (this->next)
    this->next->resolve();
}

std::ostream &operator<<(std::ostream &os, Type *t) {
  switch (t->kind) {
  case TypeKind::INT:
    os << "int";
    break;
  case TypeKind::STR:
    os << "str";
    break;
  case TypeKind::NIL:
    os << "nil";
    break;
  case TypeKind::FUNC:
    os << "func";
    break;
  case TypeKind::ARRAY:
    os << t->subType << "[]";
    break;
  default:
    break;
  }

  return os;
}

std::ostream &operator<<(std::ostream &os, Param *p) {
  os << p->type << " " << p->name;
  return os;
}

Symbol::Symbol(SymbolKind kind, Type *type, std::string name, int which) {
  this->kind = kind;
  this->type = type;
  this->name = name;
  this->which = which;
}

Symbol *Symbol::newSymbol(SymbolKind kind, Type *type, std::string name) {
  return new Symbol(kind, type, name, 0);
}

std::vector<std::unordered_map<std::string, Symbol *> *> *scopeStack =
    new std::vector<std::unordered_map<std::string, Symbol *> *>();

void scopeEnter() {
  scopeStack->push_back(new std::unordered_map<std::string, Symbol *>());
}

void scopeExit() { scopeStack->pop_back(); }

int scopeLevel() { return scopeStack->size(); }

void scopeBind(std::string name, Symbol *sym) {
  scopeStack->back()->insert(std::pair<std::string, Symbol *>(name, sym));
}

Symbol *scopeLookup(std::string name) {
  for (int i = scopeStack->size() - 1; 0 <= i; i--) {
    for (std::pair<std::string, Symbol *> p : *scopeStack->at(i)) {
      if (p.first == name)
        return p.second;
    }
  }

  return nullptr;
}

Symbol *scopeLookupCurrent(std::string name) {
  for (std::pair<std::string, Symbol *> p : *scopeStack->back()) {
    if (p.first == name)
      return p.second;
  }

  return nullptr;
}