#include "lexer/Lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& src) : source(src) {}

char Lexer::peek() const {
    return index < source.size() ? source[index] : '\0';
}

char Lexer::get() {
    return index < source.size() ? source[index++] : '\0';
}

void Lexer::skipWhitespace() {
    while (std::isspace(peek())) get();
}

Token Lexer::nextToken() {
    skipWhitespace();

    char c = peek();
    if (c == '\0')
        return {TokenType::EOF_TOKEN, ""};

    if (std::isdigit(c)) {
        std::string num;
        while (std::isdigit(peek()))
            num += get();
        return {TokenType::INT, num};
    }

    if (std::isalpha(c)) {
        std::string id;
        while (std::isalnum(peek()))
            id += get();
        return {TokenType::IDENT, id};
    }

    get();
    switch (c) {
        case '+': return {TokenType::PLUS, "+"};
        case '-': return {TokenType::MINUS, "-"};
        case '*': return {TokenType::STAR, "*"};
        case '/': return {TokenType::SLASH, "/"};
        case '=': return {TokenType::ASSIGN, "="};
        case ';': return {TokenType::SEMICOLON, ";"};
        default:  return {TokenType::EOF_TOKEN, ""};
    }
}
