#include <iostream>
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "codegen/CodeGenContext.h"

int main() {
    std::string source = "42";

    Lexer lexer(source);
    Parser parser(lexer);

    Expr* expr = parser.parseExpression();

    CodeGenContext ctx;
    ctx.module->print(llvm::outs(), nullptr);

    std::cout << "TinyC compiler initialized.\n";
    return 0;
}
