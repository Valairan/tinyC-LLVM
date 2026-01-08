#pragma once
#include "AST.h"
#include <string>

struct Expr : ASTNode {
    virtual ~Expr() = default;
};

struct IntLiteral : Expr {
    int value;
    explicit IntLiteral(int v) : value(v) {}
};

struct VarExpr : Expr {
    std::string name;
    explicit VarExpr(const std::string& n) : name(n) {}
};

struct BinaryExpr : Expr {
    char op;
    Expr* lhs;
    Expr* rhs;

    BinaryExpr(char o, Expr* l, Expr* r)
        : op(o), lhs(l), rhs(r) {}
};
