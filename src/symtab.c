#include "symtab.h"

#include <assert.h>
#include <string.h>

#include "debug.h"

void setCurrentConfig(SymbolTable* sym_tab, SymbolValue value) {
    sym_tab->currentConfig = value;
}

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


AddSymbol_Result addSymbolWithCurrentConfig(SymbolTable* sym_tab, const char* identifier) {
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
    sym_tab->values[i] = sym_tab->currentConfig;
    return ASR_SUCCESS;
}

bool initializeSymbol(SymbolTable* sym_tab, SymbolHandle handle, Value value, ValueType type) {
    if(handle.value == 0) {
        return false;
    }
    int i = handle.value - 1;
    SymbolValue sym_value = getSymbolValue(sym_tab, handle);
    switch (sym_value.type) {
        case VT_INT:
            switch (type) {
                case VT_INT:
                    sym_tab->values[i].value.i_value = value.i_value;
                    break;
                case VT_DOUBLE:
                    sym_tab->values[i].value.i_value = (int)value.d_value;
                    break;
                default:
                    sym_tab->values[i].value.i_value = 0;
                    break;
            }
            break;
        case VT_DOUBLE:
            switch (type) {
                case VT_INT:
                    sym_tab->values[i].value.d_value = (double)value.i_value;
                    break;
                case VT_DOUBLE:
                    sym_tab->values[i].value.d_value = value.d_value;
                    break;
                default:
                    sym_tab->values[i].value.d_value = 0.0;
                    break;
            }
            break;
        default:
            break;
    }
    return true;
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
    PRINT_DEBUG("[DEBUG] Requested symbol value for handle %d\n", handle.value);
    PRINT_DEBUG("[DEBUG] * is_const %s\n", sym_val.is_const ? "true" : "false");
    PRINT_DEBUG("[DEBUG] * type %d\n", sym_val.type);
    PRINT_DEBUG("[DEBUG] * value %f\n", sym_val.type == VT_INT ? sym_val.value.i_value : sym_val.value.d_value);
    return sym_val;
}

UpdateSymbolValue_Result updateSymbolValue_Int(SymbolTable* sym_tab, const SymbolHandle handle, const int value) {
    if(handle.value == 0 || handle.value > sym_tab->symbol_count) { printf("handle.value: %d\n", handle.value); }
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

void printSymTab_Tikz(const SymbolTable* sym_tab, FILE* file) {
    fprintf(file, "\\begin{tabular}{ |c|c|c|c| }\n\\hline\n");
    fprintf(file, "Name & Value & Type & const? \\\\\n\\hline\n"); 
    for(uint8_t i = 0; i < sym_tab->symbol_count; i++) {
        fprintf(file, "%s & ", sym_tab->identifiers[i]);
        switch(sym_tab->values[i].type) {
            case VT_INT: 
                fprintf(file, "%d & ", sym_tab->values[i].value.i_value);
                break;
            case VT_DOUBLE: 
                fprintf(file, "%f & ", sym_tab->values[i].value.d_value);
                break;
            default:
                fprintf(file, "ERROR & ");
                break;
        } 
        fprintf(file, "%s & %d \\\\\n \\hline \n", getStringForValueType(sym_tab->values[i].type), sym_tab->values[i].is_const);
    }
    fprintf(file, "\\end{tabular}\n");
}