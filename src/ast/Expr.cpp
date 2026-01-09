#include "ast/Expr.h"
#include "codegen/CodeGenContext.h"
#include <llvm/IR/Constants.h>

llvm::Value* IntLiteral::codegen(CodeGenContext& ctx) {
    return llvm::ConstantInt::get(
        llvm::Type::getInt32Ty(ctx.context), value);
}

llvm::Value* BinaryExpr::codegen(CodeGenContext& ctx) {
    llvm::Value* L = lhs->codegen(ctx);
    llvm::Value* R = rhs->codegen(ctx);

    switch (op) {
        case '+': return ctx.builder.CreateAdd(L, R, "addtmp");
        case '-': return ctx.builder.CreateSub(L, R, "subtmp");
        case '*': return ctx.builder.CreateMul(L, R, "multmp");
        case '/': return ctx.builder.CreateSDiv(L, R, "divtmp");
        default:  return nullptr;
    }
}
