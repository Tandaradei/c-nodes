#include "values.h"

#include <stdint.h>


const char* getColorForValueType(ValueType value_type) {
    static const char* VALUE_TYPE_COLORS[] = {
        "red",
        "green",
        "blue",
    };
    uint32_t converted_type = value_type;
    uint32_t index = 0;
    while(converted_type) {
        index++;
        converted_type >>= 1;
    }
    return VALUE_TYPE_COLORS[index];
}

const char* getStringForValueType(ValueType value_type) {
    static const char* VALUE_TYPE_NAMES[] = {
        "ERROR",
        "int",
        "double",
    };
    uint32_t converted_type = value_type;
    uint32_t index = 0;
    while(converted_type) {
        index++;
        converted_type >>= 1;
    }
    return VALUE_TYPE_NAMES[index];
}