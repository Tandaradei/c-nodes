#include "values.h"

#include <stdint.h>


const char* getColorForValueType(ValueType value_type) {
    static const char* VALUE_TYPE_COLORS[] = {
        "red",
        "cyan",
        "orange"
    };
    uint32_t converted_type = value_type;
    uint32_t index = 0;
    while(converted_type) {
        index++;
        converted_type >>= 1;
    }
    return VALUE_TYPE_COLORS[index];
}