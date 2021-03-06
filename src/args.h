#ifndef ARGS_H
#define ARGS_H

#include "args_base.h"

#define ARG_COUNT 6
typedef union MyArgs {
    Arg args[ARG_COUNT];
    struct {
        Arg expr;
        Arg symbols;
        Arg json;
        Arg tex;
        Arg json_file;
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
        .symbols = {
            .name = "-symbols",
            .type = ArgType_String,
            .value.as_string = "",
        },
        .json = {
            .name = "-json",
            .type = ArgType_Flag
        },
        .tex = {
            .name = "-tex",
            .type = ArgType_Flag,
        },
        .json_file = {
            .name = "-json_file",
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