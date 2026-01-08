#include "codegen/CodeGenContext.h"

CodeGenContext::CodeGenContext()
    : builder(context) {
    module = std::make_unique<llvm::Module>("tinyc", context);
}
