#include "ast.hpp"
#include "ast/decl.hpp"
#include "driver.hpp"
#include "message.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  Driver drv;

  if (!drv.parse("spec.j")) {
    drv.resolve();
    drv.typeCheck();

    for (Message m : messages) {
      std::cerr << m;
    }

    std::cout << "======== AST =========" << std::endl;
    for (Decl *d : drv.ast) {
      std::cout << d;
    }
  } else {
    std::cout << "parsing failed!" << '\n';
  }

  return 0;
}

/* int main(int argc, char *argv[]) {
  Expr *c1 = Expr::newConst(123);
  Expr *c2 = Expr::newConst(3);
  Expr *e = Expr::newBinary(ExprKind::ADD, c1, c2);

  Stmt *s = Stmt::newReturn(e);
  Stmt *b = Stmt::newBlock();
  b->addChild(s);

  Decl *d = Decl::newFn("test", b,
                        Type::newComplex(TypeKind::FUNC,
                                         Type::newAtomic(TypeKind::INT),
                                         new std::vector<Param *>()));

  std::cout << d->stringify() << std::endl;
} */