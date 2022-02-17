#include "ast/expr.hpp"
#include <cstdint>
#include <ostream>
#include <stdexcept>
#include <stdint.h>
#include <string>
#include <vector>

Expr::Expr(ExprKind kind, Expr *left, Expr *right, std::string string,
           uint64_t integer, std::vector<Expr *> *args) {
  this->kind = kind;
  this->left = left;
  this->right = right;
  this->string = string;
  this->integer = integer;
  this->args = args;
}

Expr *Expr::newBinary(ExprKind kind, Expr *left, Expr *right) {
  return new Expr(kind, left, right, "", 0, 0);
}

Expr *Expr::newUnary(ExprKind kind, Expr *left) {
  return new Expr(kind, left, 0, "", 0, 0);
}

Expr *Expr::newConst(std::string string) {
  return new Expr(ExprKind::STR, 0, 0, string, 0, 0);
}

Expr *Expr::newConst(uint64_t integer) {
  return new Expr(ExprKind::INT, 0, 0, "", integer, 0);
}

Expr *Expr::newIdent(std::string string) {
  return new Expr(ExprKind::ID, 0, 0, string, 0, 0);
}

Expr *Expr::newArgs(std::vector<Expr *> *args) {
  return new Expr(ExprKind::ARGS, 0, 0, "", 0, args);
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
    os << "not " << e->left;
    return os;
  } else if (e->kind == ExprKind::INDEX) {
    os << e->left << "[" << e->right << "]";
    return os;
  } else if (e->kind == ExprKind::CALL) {
    os << e->left << "(" << e->right << ")";
    return os;
  } else if (e->kind == ExprKind::ARGS) {
    os << e->args;
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

std::ostream &operator<<(std::ostream &os, std::vector<Expr *> *l) {
  bool first = true;

  for (Expr *e : *l) {
    if (!first)
      os << ", ";

    first = false;
    os << e;
  }

  return os;
}