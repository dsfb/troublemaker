cmake_minimum_required(VERSION 3.14)

project(troublemaker VERSION 0.1
                     LANGUAGES C CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)

    # Let's nicely support folders in IDE's
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Setup for clang-tidy on build
    find_program(
                CLANG_TIDY_EXE
                NAMES "clang-tidy"
                DOC "Path to clang-tidy executable"
    )
    if(CLANG_TIDY_EXE)
        set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()

    include(cmake/clang-format.cmake)
endif()

# FetchContent downloads during the configure step
include(FetchContent)

# library for windows and user inputs
FetchContent_Declare(
                    glfw
                    GIT_REPOSITORY https://github.com/glfw/glfw.git
                    GIT_TAG 3.3
)
# adds glfw
FetchContent_MakeAvailable(glfw)

# The library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(app)
