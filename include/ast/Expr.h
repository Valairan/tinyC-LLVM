#pragma once
#include "AST.h"
#include <string>

struct Expr : ASTNode {};

struct IntLiteral : Expr {
    int value;
    explicit IntLiteral(int v) : value(v) {}
    llvm::Value* codegen(CodeGenContext&) override;
};

struct BinaryExpr : Expr {
    char op;
    Expr* lhs;
    Expr* rhs;

    BinaryExpr(char o, Expr* l, Expr* r)
        : op(o), lhs(l), rhs(r) {}

    llvm::Value* codegen(CodeGenContext&) override;
};
