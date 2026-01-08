#pragma once
#include <unordered_map>
#include <string>

class SymbolTable {
public:
    void declare(const std::string& name);
    bool exists(const std::string& name) const;

private:
    std::unordered_map<std::string, bool> symbols;
};
