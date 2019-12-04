#ifndef ARGS_BASE_H
#define ARGS_BASE_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef enum ArgType {
    ArgType_Flag,
    ArgType_Int,
    ArgType_Double,
    ArgType_String,
} ArgType;

typedef union ArgValue {
    int as_int;
    double as_double;
    char as_string[500];
} ArgValue;

typedef struct Arg {
    const char* name;
    const ArgType type;
    ArgValue value;
    bool is_set;
} Arg;

void parseArg(unsigned int argc, char** argv, Arg* arg) {
    for(unsigned int value = 1; value < argc; value++) {
        if(!strcmp(arg->name, argv[value])) {
            if(arg->type != ArgType_Flag) {
                if(value < argc) {
                    char* endptr;
                    switch (arg->type){
                        case ArgType_Int:
                            arg->value.as_int = strtol(argv[value+1], &endptr, 10);
                            break;
                        case ArgType_Double:
                            arg->value.as_double = strtod(argv[value+1], &endptr);
                            break;
                        case ArgType_String:
                            strcpy(arg->value.as_string, argv[value+1]);
                            break;
                        
                        default:
                            break;
                    }
                }
            }
            arg->is_set = true;
        }
    }
}

#endif // ARGS_BASE_H