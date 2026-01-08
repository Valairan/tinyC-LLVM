#include "sema/SymbolTable.h"

void SymbolTable::declare(const std::string& name) {
    symbols[name] = true;
}

bool SymbolTable::exists(const std::string& name) const {
    return symbols.find(name) != symbols.end();
}
