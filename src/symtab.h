#ifndef SYMTAB_H
#define SYMTAB_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "src/values.h"

#define MAX_SYMBOL_LENGTH 20
#define MAX_SYMBOLS 64

typedef struct SymbolValue {
    ValueType type;
    Value value;
    bool is_const;
} SymbolValue;

typedef struct SymbolHandle {
    uint8_t value;
} SymbolHandle;

typedef struct SymbolTable {
    char identifiers[MAX_SYMBOL_LENGTH][MAX_SYMBOLS];
    SymbolValue values[MAX_SYMBOLS];
    uint8_t symbol_count;
} SymbolTable;

typedef enum AddSymbol_Result {
    ASR_SUCCESS,
    ASR_ALREADY_DECLARED,
    ASR_TABLE_FULL
} AddSymbol_Result;

AddSymbol_Result addSymbol(SymbolTable* sym_tab, const char* identifier, SymbolValue value);

SymbolHandle    getSymbolHandle(const SymbolTable* sym_tab, const char* identifier);
SymbolValue     getSymbolValue(const SymbolTable* sym_tab, const SymbolHandle handle);

typedef enum UpdateSymbolValue_Result {
    USVR_SUCCESS,
    USVR_ID_NOT_FOUND,
    USVR_TYPE_MISMATCH,
    USVR_IS_CONST
} UpdateSymbolValue_Result;

UpdateSymbolValue_Result updateSymbolValue_Int(SymbolTable* sym_tab, const SymbolHandle handle, const int value);
UpdateSymbolValue_Result updateSymbolValue_Double(SymbolTable* sym_tab, const SymbolHandle handle, const double value);

void printSymTab_Tikz(const SymbolTable* sym_tab, FILE* file);

#endif // SYMTAB_H