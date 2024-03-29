# additional target to perform clang-format run, requires clang-format
find_program(
            CLANG_FORMAT_EXE
            NAMES "clang-format"
            DOC "Path to clang-format executable"
)

if(CLANG_FORMAT_EXE)
    file(GLOB_RECURSE ALL_SOURCE_FILES *.cpp *.h)
    foreach (SOURCE_FILE ${ALL_SOURCE_FILES})
        string(FIND ${SOURCE_FILE} ${PROJECT_BINARY_DIR} PROJECT_BINARY_DIR_FOUND)
        if (NOT ${PROJECT_BINARY_DIR_FOUND} EQUAL -1)
            list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE})
        endif ()
    endforeach ()

    add_custom_target(
            clangformat
            COMMAND ${CLANG_FORMAT_EXE}
            -style=LLVM
            -i
            ${ALL_SOURCE_FILES}
    )
endif()
