#include "symtab.h"

#include <string.h>

AddSymbol_Result addSymbol(SymbolTable* sym_tab, const char* identifier, SymbolValue value) {
    if(sym_tab->symbol_count == MAX_SYMBOLS) {
        return ASR_TABLE_FULL;
    }
    for(uint8_t i = 0; i < sym_tab->symbol_count; i++) {
        if(!strcmp(sym_tab->identifiers[i], identifier)) {
            return ASR_ALREADY_DECLARED;
        }
    }
    uint8_t i = sym_tab->symbol_count++;
    strcpy_s(sym_tab->identifiers[i], 20, identifier);
    sym_tab->values[i] = value;
    return ASR_SUCCESS;
}

SymbolValue getSymbolValue(const SymbolTable* sym_tab, const char* identifier) {
    for(uint8_t i = 0; i < sym_tab->symbol_count; i++) {
        if(!strcmp(sym_tab->identifiers[i], identifier)) {
            return sym_tab->values[i];
        }
    }
    return (SymbolValue) {
        .type = VT_ERROR,
        .value.i_value = 0,
        .is_const = true,
    };
}

UpdateSymbolValue_Result updateSymbolValue_Int(SymbolTable* sym_tab, const char* identifier, const int value) {
    for(uint8_t i = 0; i < sym_tab->symbol_count; i++) {
        if(!strcmp(sym_tab->identifiers[i], identifier)) {
            if(sym_tab->values[i].type != VT_INT) {
                return USVR_TYPE_MISMATCH;
            }
            if(sym_tab->values[i].is_const) {
                return USVR_IS_CONST;
            }
            sym_tab->values[i].value.i_value = value;
            return USVR_SUCCESS;
        }
    }
    return USVR_ID_NOT_FOUND;
}

UpdateSymbolValue_Result updateSymbolValue_Double(SymbolTable* sym_tab, const char* identifier, const double value) {
    for(uint8_t i = 0; i < sym_tab->symbol_count; i++) {
        if(!strcmp(sym_tab->identifiers[i], identifier)) {
            if(sym_tab->values[i].type != VT_DOUBLE) {
                return USVR_TYPE_MISMATCH;
            }
            if(sym_tab->values[i].is_const) {
                return USVR_IS_CONST;
            }
            sym_tab->values[i].value.d_value = value;
            return USVR_SUCCESS;
        }
    }
    return USVR_ID_NOT_FOUND;
}