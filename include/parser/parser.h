#pragma once
#include "lexer/Lexer.h"
#include "ast/Expr.h"

class Parser {
public:
    explicit Parser(Lexer& lexer);
    Expr* parse();

private:
    Lexer& lexer;
    Token current;

    void advance();
    Expr* parsePrimary();
    Expr* parseBinaryRHS(int prec, Expr* lhs);
    int precedence(TokenType type);
};
