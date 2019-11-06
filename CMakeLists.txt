cmake_minimum_required(VERSION 3.0)

project(c-nodes)

find_program(LEX_EXE
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/win_flex_bison/win_flex
)
if(LEX_EXE STREQUAL "LEX_EXE-NOTFOUND")
    message(FATAL_ERROR "dear user, please install flex!")
endif(LEX_EXE STREQUAL "LEX_EXE-NOTFOUND")

find_program(YACC_EXE
    ${CMAKE_CURRENT_SOURCE_DIR}/tools/win_flex_bison/win_bison
)
if(YACC_EXE STREQUAL "YACC_EXE-NOTFOUND")
    message(FATAL_ERROR "dear user, please install bison!")
endif(YACC_EXE STREQUAL "YACC_EXE-NOTFOUND")

# reuseable cmake macro for yacc
MACRO(YACC_FILE _filename)
    GET_FILENAME_COMPONENT(_basename ${_filename} NAME_WE)
    ADD_CUSTOM_COMMAND(
        OUTPUT  ${CMAKE_CURRENT_SOURCE_DIR}/src/__generated__/${_basename}.c
        ${CMAKE_CURRENT_SOURCE_DIR}/src/__generated__/${_basename}.h
        COMMAND ${YACC_EXE} -d
                -o ${CMAKE_CURRENT_SOURCE_DIR}/src/__generated__/${_basename}.c
                ${CMAKE_CURRENT_SOURCE_DIR}/${_filename}
        DEPENDS ${_filename}
    )
ENDMACRO(YACC_FILE)

# reuseable cmake macro for lex
MACRO(LEX_FILE _filename)
    GET_FILENAME_COMPONENT(_basename ${_filename} NAME_WE)
    ADD_CUSTOM_COMMAND(
        OUTPUT  ${CMAKE_CURRENT_SOURCE_DIR}/src/__generated__/${_basename}.c
        COMMAND ${LEX_EXE}
                -o ${CMAKE_CURRENT_SOURCE_DIR}/src/__generated__/${_basename}.c
                ${CMAKE_CURRENT_SOURCE_DIR}/${_filename}
        DEPENDS ${_filename} )
ENDMACRO(LEX_FILE)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/)

SET(BASEPATH "${CMAKE_SOURCE_DIR}")

LEX_FILE(src/scanner.l)
YACC_FILE(src/parser.y)

INCLUDE_DIRECTORIES("${BASEPATH}")

add_executable(${PROJECT_NAME}
    #src/main.c
    src/ast.c
    src/symtab.c
    src/nodes/node.c
    src/nodes/node_value.c
    src/nodes/node_variable.c
    src/__generated__/scanner.c
    src/__generated__/parser.c
)