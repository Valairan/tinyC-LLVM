#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include "lexer/Lexer.h"
#include "parser/Parser.h"
#include "codegen/CodeGenContext.h"

int main() {
    std::string source = "42 + 3 * 5";

    Lexer lexer(source);
    Parser parser(lexer);
    Expr* ast = parser.parse();

    CodeGenContext ctx;

    llvm::FunctionType* ft =
        llvm::FunctionType::get(
            llvm::Type::getInt32Ty(ctx.context),
            false);

    llvm::Function* fn =
        llvm::Function::Create(
            ft,
            llvm::Function::ExternalLinkage,
            "main",
            ctx.module.get());

    llvm::BasicBlock* entry =
        llvm::BasicBlock::Create(ctx.context, "entry", fn);

    ctx.builder.SetInsertPoint(entry);

    llvm::Value* ret = ast->codegen(ctx);
    ctx.builder.CreateRet(ret);

    llvm::verifyFunction(*fn);
    ctx.module->print(llvm::outs(), nullptr);

    return 0;
}
