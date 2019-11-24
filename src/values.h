#ifndef VALUES_H
#define VALUES_H

typedef enum ValueType {
    VT_ERROR = 0,
    VT_INT = 1,
    VT_DOUBLE = 2,
} ValueType;

typedef union Value {
    int i_value;
    double d_value;
} Value;

const char* getColorForValueType(ValueType value_type);

#endif // VALUES_H