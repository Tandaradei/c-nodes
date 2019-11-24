#include "symtab.h"

#include <assert.h>
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
    strcpy(sym_tab->identifiers[i], identifier);
    sym_tab->values[i] = value;
    return ASR_SUCCESS;
}

SymbolHandle getSymbolHandle(const SymbolTable* sym_tab, const char* identifier) {
    for(uint8_t i = 0; i < sym_tab->symbol_count; i++) {
        if(!strcmp(sym_tab->identifiers[i], identifier)) {
            return (SymbolHandle){i + 1};
        }
    }
    return (SymbolHandle){0};
}

SymbolValue getSymbolValue(const SymbolTable* sym_tab, const SymbolHandle handle) {
    assert(handle.value > 0 && handle.value <= sym_tab->symbol_count);
    const SymbolValue sym_val = sym_tab->values[handle.value - 1];
    printf("[DEBUG] Requested symbol value for handle %d\n", handle.value);
    printf("[DEBUG] * is_const %s\n", sym_val.is_const ? "true" : "false");
    printf("[DEBUG] * type %d\n", sym_val.type);
    printf("[DEBUG] * value %f\n", sym_val.type == VT_INT ? sym_val.value.i_value : sym_val.value.d_value);
    return sym_val;
}

UpdateSymbolValue_Result updateSymbolValue_Int(SymbolTable* sym_tab, const SymbolHandle handle, const int value) {
    assert(handle.value > 0 && handle.value <= sym_tab->symbol_count);
    const uint8_t i = handle.value - 1;
    if(sym_tab->values[i].type != VT_INT) {
        return USVR_TYPE_MISMATCH;
    }
    if(sym_tab->values[i].is_const) {
        return USVR_IS_CONST;
    }
    sym_tab->values[i].value.i_value = value;
    return USVR_SUCCESS;
}

UpdateSymbolValue_Result updateSymbolValue_Double(SymbolTable* sym_tab, const SymbolHandle handle, const double value) {
    assert(handle.value && handle.value <= sym_tab->symbol_count);
    const uint8_t i = handle.value - 1;
    if(sym_tab->values[i].type != VT_DOUBLE) {
        return USVR_TYPE_MISMATCH;
    }
    if(sym_tab->values[i].is_const) {
        return USVR_IS_CONST;
    }
    sym_tab->values[i].value.d_value = value;
    return USVR_SUCCESS;
}