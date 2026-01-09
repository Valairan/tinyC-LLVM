#include "parser/Parser.h"
#include <cstdlib>

Parser::Parser(Lexer& l) : lexer(l) {
    advance();
}

void Parser::advance() {
    current = lexer.next();
}

int Parser::precedence(TokenType type) {
    if (type == TokenType::PLUS || type == TokenType::MINUS) return 10;
    if (type == TokenType::STAR || type == TokenType::SLASH) return 20;
    return -1;
}

Expr* Parser::parsePrimary() {
    if (current.type == TokenType::INT) {
        int val = std::stoi(current.lexeme);
        advance();
        return new IntLiteral(val);
    }
    return nullptr;
}

Expr* Parser::parseBinaryRHS(int exprPrec, Expr* lhs) {
    while (true) {
        int tokPrec = precedence(current.type);
        if (tokPrec < exprPrec)
            return lhs;

        char op = current.lexeme[0];
        advance();

        Expr* rhs = parsePrimary();
        int nextPrec = precedence(current.type);

        if (tokPrec < nextPrec)
            rhs = parseBinaryRHS(tokPrec + 1, rhs);

        lhs = new BinaryExpr(op, lhs, rhs);
    }
}

Expr* Parser::parse() {
    Expr* lhs = parsePrimary();
    return parseBinaryRHS(0, lhs);
}
