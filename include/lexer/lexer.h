#pragma once
#include <string>

enum class TokenType {
    EOF_TOKEN,
    INT,
    IDENT,
    PLUS,
    MINUS,
    STAR,
    SLASH,
    ASSIGN,
    SEMICOLON
};

struct Token {
    TokenType type;
    std::string lexeme;
};

class Lexer {
public:
    explicit Lexer(const std::string& src);
    Token nextToken();

private:
    std::string source;
    size_t index = 0;

    char peek() const;
    char get();
    void skipWhitespace();
};
