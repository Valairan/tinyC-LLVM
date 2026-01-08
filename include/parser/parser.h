#pragma once
#include "lexer/Lexer.h"
#include "ast/Expr.h"

class Parser {
public:
    explicit Parser(Lexer& lexer);

    Expr* parseExpression();

private:
    Lexer& lexer;
    Token current;

    void advance();
};
