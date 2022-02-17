#pragma once

#include <ostream>
#include <string>
#include <vector>

class Type;

class Param {
public:
  Param(std::string, Type *);

  static Param *newParam(std::string, Type *);

  std::string name;
  Type *type;
};

enum class TypeKind {
  INT,
  STR,
  FUNC,
  ARRAY,
  NIL,
};

class Type {
public:
  Type(TypeKind, Type *, std::vector<Param *> *);

  static Type *newAtomic(TypeKind);
  static Type *newArray(Type *);
  static Type *newComplex(TypeKind, Type *, std::vector<Param *> *);

  TypeKind kind;
  Type *subType;
  std::vector<Param *> *params;
};

std::ostream &operator<<(std::ostream &, Type *);
std::ostream &operator<<(std::ostream &, Param *);
std::ostream &operator<<(std::ostream &, std::vector<Param *> *);