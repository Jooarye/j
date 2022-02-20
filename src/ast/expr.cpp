#include "ast/expr.hpp"
#include "ast/type.hpp"
#include "message.hpp"
#include <algorithm>
#include <cassert>
#include <cerrno>
#include <cstdint>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <vector>

Expr::Expr(ExprKind kind, Expr *left, Expr *right, std::string string,
           uint64_t integer, yy::location loc) {
  this->kind = kind;
  this->left = left;
  this->right = right;
  this->string = string;
  this->integer = integer;
  this->loc = loc;
  this->loc.begin.filename = new std::string(*this->loc.begin.filename);
  this->loc.end.filename = new std::string(*this->loc.end.filename);
}

Expr *Expr::newBinary(ExprKind kind, Expr *left, Expr *right,
                      yy::location loc) {
  return new Expr(kind, left, right, "", 0, loc);
}

Expr *Expr::newUnary(ExprKind kind, Expr *left, yy::location loc) {
  return new Expr(kind, left, 0, "", 0, loc);
}

Expr *Expr::newConst(std::string string, yy::location loc) {
  return new Expr(ExprKind::STR, 0, 0, string, 0, loc);
}

Expr *Expr::newConst(uint64_t integer, yy::location loc) {
  return new Expr(ExprKind::INT, 0, 0, "", integer, loc);
}

Expr *Expr::newIdent(std::string string, yy::location loc) {
  return new Expr(ExprKind::ID, 0, 0, string, 0, loc);
}

Expr *Expr::newArg(Expr *e, yy::location loc) {
  return new Expr(ExprKind::ARG, e, 0, "", 0, loc);
}

void Expr::add(Expr *e) {
  if (!this->right)
    this->right = e;
  else
    this->right->add(e);
}

void Expr::resolve() {
  if (this->kind == ExprKind::ID) {
    this->sym = scopeLookup(this->string);

    if (!this->sym)
      Message::error("unknown reference: " + this->string, this->loc);
  }

  if (this->left)
    this->left->resolve();

  if (this->right)
    this->right->resolve();
}

Type *Expr::typeCheck() {
  switch (this->kind) {
  case ExprKind::INT:
    return Type::newAtomic(TypeKind::INT);
  case ExprKind::STR:
    return Type::newAtomic(TypeKind::STR);
  case ExprKind::ADD:
  case ExprKind::SUB:
  case ExprKind::DIV:
  case ExprKind::MUL:
  case ExprKind::MOD:
  case ExprKind::AND:
  case ExprKind::XOR:
  case ExprKind::OR: {
    Type *lt = this->left->typeCheck();
    Type *rt = this->right->typeCheck();

    Type *intt = Type::newAtomic(TypeKind::INT);

    if (!lt->isEqual(intt) || !rt->isEqual(intt))
      Message::error("type missmatch in arithmetic operation", this->loc);

    return Type::newAtomic(TypeKind::INT);
  }
  case ExprKind::EQ:
  case ExprKind::NE:
  case ExprKind::LT:
  case ExprKind::LTEQ:
  case ExprKind::GT:
  case ExprKind::GTEQ: {
    Type *lt = this->left->typeCheck();
    Type *rt = this->right->typeCheck();

    if (!lt->isEqual(rt))
      Message::error("type missmatch in comparision operation", this->loc);

    return lt;
  }
  case ExprKind::ID:
    if (!this->sym) {
      Message::error("unknown variable", this->loc);
      return Type::newAtomic(TypeKind::NIL);
    }

    return this->sym->type;
  case ExprKind::CALL: {
    if (!this->left->sym) {
      Message::error("unknown function", this->loc);
      return Type::newAtomic(TypeKind::NIL);
    }

    Param *p = this->left->sym->type->params;
    Expr *a = this->right;

    while (p && a) {
      yy::location pos = a->loc;
      Type *at = a->left->typeCheck();
      Type *pt = p->type;

      if (!at->isEqual(pt))
        Message::error("invalid type for argument", pos);

      p = p->next;
      a = a->right;
    }

    if (a || p)
      Message::error("invalid amount of arguments for function call",
                     this->loc);

    return this->left->sym->type->subType;
  }
  case ExprKind::ASSIGN: {
    if (!this->left->sym) {
      Message::error("can't assign to unknown variable", this->loc);
      return Type::newAtomic(TypeKind::NIL);
    }

    Type *rt = this->right->typeCheck();

    if (!rt->isEqual(this->left->sym->type)) {

      Message::error("type missmatch in variable assignment", this->loc);
      return Type::newAtomic(TypeKind::NIL);
    }

    return rt;
  }
  case ExprKind::INC:
  case ExprKind::DEC: {
    if (!this->left->sym) {
      Message::error("can't inc or dec unknown variable", this->loc);
    }

    if (this->left->sym->type->kind != TypeKind::INT) {
      Message::error("can't inc or dec non int variable", this->loc);
    }

    return Type::newAtomic(TypeKind::INT);
  }
  case ExprKind::INDEX: {
    Type *lt = this->left->typeCheck();
    Type *rt = this->right->typeCheck();

    if (lt->kind != TypeKind::STR && lt->kind != TypeKind::ARRAY) {
      Message::error("type not indexable", this->loc);
    }

    if (rt->kind != TypeKind::INT)
      Message::error("index type can only be int", this->right->loc);

    if (lt->kind == TypeKind::STR)
      return Type::newAtomic(TypeKind::INT);

    return lt->subType;
  }
  default:
    Message::note("typechecking not implemented for this yet", this->loc);
  }

  return Type::newAtomic(TypeKind::NIL);
}

std::ostream &operator<<(std::ostream &os, Expr *e) {
  if (e->kind == ExprKind::INT) {
    os << std::to_string(e->integer);
    return os;
  } else if (e->kind == ExprKind::ID) {
    os << e->string;
    return os;
  } else if (e->kind == ExprKind::STR) {
    os << "\"" << e->string << "\"";
    return os;
  } else if (e->kind == ExprKind::NOT) {
    os << "~" << e->left;
    return os;
  } else if (e->kind == ExprKind::INC) {
    os << e->left << "++";
    return os;
  } else if (e->kind == ExprKind::DEC) {
    os << e->left << "--";
    return os;
  } else if (e->kind == ExprKind::LNOT) {
    os << "(not " << e->left << ")";
    return os;
  } else if (e->kind == ExprKind::INDEX) {
    os << e->left << "[" << e->right << "]";
    return os;
  } else if (e->kind == ExprKind::CALL) {
    os << e->left << "(" << e->right << ")";
    return os;
  } else if (e->kind == ExprKind::ARG) {
    os << e->left;

    if (e->right)
      os << ", " << e->right;

    return os;
  }

  os << "(" << e->left;

  switch (e->kind) {
  case ExprKind::ASSIGN:
    os << " = ";
    break;
  case ExprKind::ADD:
    os << " + ";
    break;
  case ExprKind::SUB:
    os << "-";
    break;
  case ExprKind::MUL:
    os << "*";
    break;
  case ExprKind::DIV:
    os << "/";
    break;
  case ExprKind::MOD:
    os << "%";
    break;
  case ExprKind::EQ:
    os << "==";
    break;
  case ExprKind::NE:
    os << "!=";
    break;
  case ExprKind::LT:
    os << "<";
    break;
  case ExprKind::GT:
    os << ">";
    break;
  case ExprKind::LTEQ:
    os << "<=";
    break;
  case ExprKind::GTEQ:
    os << ">=";
    break;
  case ExprKind::AND:
    os << "&";
    break;
  case ExprKind::OR:
    os << "|";
    break;
  case ExprKind::XOR:
    os << "^";
    break;
  case ExprKind::LAND:
    os << " and ";
    break;
  case ExprKind::LOR:
    os << " or ";
    break;
  default:
    break;
  }

  os << e->right << ")";

  return os;
}