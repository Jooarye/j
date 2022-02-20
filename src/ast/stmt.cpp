#include "ast/stmt.hpp"
#include <assert.h>

Stmt::Stmt(StmtKind kind, Expr *expr, Expr *init, Expr *next, Decl *decl,
           Stmt *cons, Stmt *alter, yy::location loc) {
  this->kind = kind;
  this->expr = expr;
  this->init = init;
  this->next = next;
  this->decl = decl;
  this->consequence = cons;
  this->alternative = alter;
  this->loc = loc;
  this->loc.begin.filename = new std::string(*this->loc.begin.filename);
  this->loc.end.filename = new std::string(*this->loc.end.filename);
}

Stmt *Stmt::newExpr(Expr *expr, yy::location loc) {
  return new Stmt(StmtKind::EXPR, expr, 0, 0, 0, 0, 0, loc);
}

Stmt *Stmt::newDecl(Decl *decl, yy::location loc) {
  return new Stmt(StmtKind::DECL, 0, 0, 0, decl, 0, 0, loc);
}

Stmt *Stmt::newBlock(yy::location loc) {
  return new Stmt(StmtKind::BLOCK, 0, 0, 0, 0, 0, 0, loc);
}

Stmt *Stmt::newIf(Expr *expr, Stmt *cons, Stmt *alter, yy::location loc) {
  return new Stmt(StmtKind::IF, expr, 0, 0, 0, cons, alter, loc);
}

Stmt *Stmt::newWhile(Expr *expr, Stmt *cons, yy::location loc) {
  return new Stmt(StmtKind::WHILE, expr, 0, 0, 0, cons, 0, loc);
}

Stmt *Stmt::newFor(Expr *init, Expr *expr, Expr *next, Stmt *body,
                   yy::location loc) {
  return new Stmt(StmtKind::FOR, expr, init, next, 0, body, 0, loc);
}

Stmt *Stmt::newReturn(Expr *expr, yy::location loc) {
  return new Stmt(StmtKind::RETURN, expr, 0, 0, 0, 0, 0, loc);
}

Stmt *Stmt::newContinue(yy::location loc) {
  return new Stmt(StmtKind::CONTINUE, 0, 0, 0, 0, 0, 0, loc);
}

Stmt *Stmt::newBreak(yy::location loc) {
  return new Stmt(StmtKind::BREAK, 0, 0, 0, 0, 0, 0, loc);
}

void Stmt::addChild(Stmt *s) { this->body.push_back(s); }

void Stmt::resolve() {
  switch (this->kind) {
  case StmtKind::DECL:
    this->decl->resolve();
    break;
  case StmtKind::EXPR:
    this->expr->resolve();
    break;
  case StmtKind::BLOCK:
    for (Stmt *s : this->body)
      s->resolve();
    break;
  case StmtKind::IF:
    this->expr->resolve();
    this->consequence->resolve();
    if (this->alternative)
      this->alternative->resolve();
    break;
  case StmtKind::FOR:
    this->init->resolve();
    this->expr->resolve();
    this->next->resolve();
    this->consequence->resolve();
    break;
  case StmtKind::WHILE:
    this->expr->resolve();
    this->consequence->resolve();
    break;
  case StmtKind::RETURN:
    if (this->expr)
      this->expr->resolve();
    break;
  case StmtKind::BREAK:
  case StmtKind::CONTINUE:
    break;
  default:
    assert(0 && "resolve not implemented");
  }
}

void Stmt::typeCheck() {
  switch (this->kind) {
  case StmtKind::EXPR:
    this->expr->typeCheck();
    break;
  case StmtKind::DECL:
    this->decl->typeCheck();
    break;
  case StmtKind::BLOCK:
    for (Stmt *s : this->body) {
      s->typeCheck();
    }
    break;
  case StmtKind::IF:
    this->expr->typeCheck();
    this->consequence->typeCheck();

    if (this->alternative)
      this->alternative->typeCheck();
    break;
  case StmtKind::WHILE:
    this->expr->typeCheck();
    this->consequence->typeCheck();
    break;
  case StmtKind::FOR:
    this->expr->typeCheck();
    this->init->typeCheck();
    this->next->typeCheck();
    this->consequence->typeCheck();
    break;
  case StmtKind::BREAK:
    break;
  case StmtKind::RETURN:
    if (this->expr)
      this->expr->typeCheck();
    break;
  case StmtKind::CONTINUE:
    break;
  }
}

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