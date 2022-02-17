#include "ast/stmt.hpp"
#include <assert.h>

Stmt::Stmt(StmtKind kind, Expr *expr, Expr *init, Expr *next, Decl *decl,
           Stmt *cons, Stmt *alter) {
  this->kind = kind;
  this->expr = expr;
  this->init = init;
  this->next = next;
  this->decl = decl;
  this->consequence = cons;
  this->alternative = alter;
}

Stmt *Stmt::newExpr(Expr *expr) {
  return new Stmt(StmtKind::EXPR, expr, 0, 0, 0, 0, 0);
}

Stmt *Stmt::newDecl(Decl *decl) {
  return new Stmt(StmtKind::DECL, 0, 0, 0, decl, 0, 0);
}

Stmt *Stmt::newBlock() { return new Stmt(StmtKind::BLOCK, 0, 0, 0, 0, 0, 0); }

Stmt *Stmt::newIf(Expr *expr, Stmt *cons, Stmt *alter) {
  return new Stmt(StmtKind::IF, expr, 0, 0, 0, cons, alter);
}

Stmt *Stmt::newWhile(Expr *expr, Stmt *cons) {
  return new Stmt(StmtKind::WHILE, expr, 0, 0, 0, cons, 0);
}

Stmt *Stmt::newFor(Expr *init, Expr *expr, Expr *next, Stmt *body) {
  return new Stmt(StmtKind::FOR, expr, init, next, 0, body, 0);
}

Stmt *Stmt::newReturn(Expr *expr) {
  return new Stmt(StmtKind::RETURN, expr, 0, 0, 0, 0, 0);
}

Stmt *Stmt::newContinue() {
  return new Stmt(StmtKind::CONTINUE, 0, 0, 0, 0, 0, 0);
}

Stmt *Stmt::newBreak() { return new Stmt(StmtKind::BREAK, 0, 0, 0, 0, 0, 0); }

void Stmt::addChild(Stmt *s) { this->body.push_back(s); }

std::ostream &operator<<(std::ostream &os, Stmt *s) {
  switch (s->kind) {
  case StmtKind::DECL:
    os << s->decl << "\n";
    break;
  case StmtKind::EXPR:
    os << s->expr << ";\n";
    break;
  case StmtKind::IF:
    os << "if " << s->expr << " " << s->consequence;

    if (s->alternative)
      os << " else " << s->alternative;

    os << "\n";
    break;
  case StmtKind::WHILE:
    os << "while " << s->expr << " " << s->consequence << "\n";
    break;
  case StmtKind::FOR:
    os << "for " << s->init << "; " << s->expr << "; " << s->next << " "
       << s->consequence << "\n";
    break;
  case StmtKind::RETURN:
    os << "return " << s->expr << ";\n";
    break;
  case StmtKind::CONTINUE:
    os << "continue;\n";
    break;
  case StmtKind::BREAK:
    os << "break;\n";
    break;
  case StmtKind::BLOCK:
    os << "{\n";

    for (Stmt *s : s->body) {
      os << s;
    }

    os << "}";
    break;
  }

  return os;
}