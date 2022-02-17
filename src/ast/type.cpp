#include "ast/type.hpp"
#include <stdexcept>
#include <string>
#include <vector>

Type::Type(TypeKind kind, Type *subType, std::vector<Param *> *params) {
  this->kind = kind;
  this->subType = subType;
  this->params = params;
}

Type *Type::newAtomic(TypeKind kind) { return new Type(kind, 0, 0); }

Type *Type::newArray(Type *type) { return new Type(TypeKind::ARRAY, type, 0); }

Type *Type::newComplex(TypeKind kind, Type *subType,
                       std::vector<Param *> *params) {
  return new Type(kind, subType, params);
}

Param::Param(std::string name, Type *type) {
  this->name = name;
  this->type = type;
}

Param *Param::newParam(std::string name, Type *type) {
  return new Param(name, type);
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

std::ostream &operator<<(std::ostream &os, std::vector<Param *> *l) {
  bool first = true;

  for (Param *p : *l) {
    if (!first) {
      os << ", ";
    }

    os << p;
    first = false;
  }

  return os;
}