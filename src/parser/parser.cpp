#include "parser/Parser.h"

Parser::Parser(Lexer& l) : lexer(l) {
    advance();
}

void Parser::advance() {
    current = lexer.nextToken();
}

Expr* Parser::parseExpression() {
    if (current.type == TokenType::INT) {
        int value = std::stoi(current.lexeme);
        advance();
        return new IntLiteral(value);
    }
    return nullptr;
}
