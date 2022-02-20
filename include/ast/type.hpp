#pragma once

#include <map>
#include <ostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

class Type;
class Symbol;

class Param {
public:
  Param(std::string, Type *);

  static Param *newParam(std::string, Type *);

  void resolve();
  void add(Param *);

  bool isEqual(Param *);

  std::string name;
  Type *type;
  Symbol *sym;

  Param *next;
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
  Type(TypeKind, Type *, Param *);

  static Type *newAtomic(TypeKind);
  static Type *newArray(Type *);
  static Type *newComplex(TypeKind, Type *, Param *);

  bool isEqual(Type *);
  bool isAtomic();

  TypeKind kind;
  Type *subType;
  Param *params;
};

std::ostream &operator<<(std::ostream &, Type *);
std::ostream &operator<<(std::ostream &, Param *);

enum class SymbolKind {
  LOCAL,
  PARAM,
  GLOBAL,
};

class Symbol {
public:
  Symbol(SymbolKind, Type *, std::string, int);

  static Symbol *newSymbol(SymbolKind, Type *, std::string);

  SymbolKind kind;
  Type *type;
  std::string name;
  int which;
};

extern std::vector<std::unordered_map<std::string, Symbol *> *> *scopeStack;

void scopeEnter();
void scopeExit();
int scopeLevel();

void scopeBind(std::string, Symbol *);
Symbol *scopeLookup(std::string);
Symbol *scopeLookupCurrent(std::string);
