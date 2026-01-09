#pragma once
#include <llvm/IR/Value.h>

struct CodeGenContext;

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual llvm::Value* codegen(CodeGenContext&) = 0;
};
