#ifndef VALUES_H
#define VALUES_H

typedef enum ValueType {
    VT_UNPROCESSED = 0,
    VT_ERROR = 1,
    VT_INT = 2,
    VT_DOUBLE = 4,
} ValueType;

typedef union Value {
    int i_value;
    double d_value;
} Value;

const char* getColorForValueType(ValueType value_type);
const char* getStringForValueType(ValueType value_type);

#endif // VALUES_H