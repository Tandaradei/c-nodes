#ifndef ARGS_H
#define ARGS_H

#include "args_base.h"

#define ARG_COUNT 5
typedef union MyArgs {
    Arg args[ARG_COUNT];
    struct {
        Arg expr;
        Arg d3;
        Arg tex;
        Arg d3_file;
        Arg tex_file;
    };
} MyArgs;

MyArgs parseArgs(unsigned int argc, char** argv) {
    MyArgs my_args = {
        .expr = {
            .name = "-expr",
            .type = ArgType_String,
            .value.as_string = "1 + 2 * 3 + 4",
        },
        .d3 = {
            .name = "-d3",
            .type = ArgType_Flag
        },
        .tex = {
            .name = "-tex",
            .type = ArgType_Flag,
        },
        .d3_file = {
            .name = "-d3_file",
            .type = ArgType_String,
            .value.as_string = "output.json",
        },
        .tex_file = {
            .name = "-tex_file",
            .type = ArgType_String,
            .value.as_string = "output.tex"
        },
        
    };
    for(unsigned int i = 0; i < ARG_COUNT; i++) {
        parseArg(argc, argv, &my_args.args[i]);
    }
    return my_args;
}

#endif // ARGS_H