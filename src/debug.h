#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG 0
#define PRINT_DEBUG(...) if(DEBUG) { printf(__VA_ARGS__); }

#endif // DEBUG_H