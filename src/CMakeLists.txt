embedcpp_generate(GENERATED_FILES INC_PATH shaders/vertex.glsl)

# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
set(HEADER_LIST "${troublemaker_SOURCE_DIR}/include/glad/glad.h"
                "${troublemaker_SOURCE_DIR}/include/KHR/khrplatform.h"
                "${troublemaker_SOURCE_DIR}/include/troublemaker/window_context.hpp")

set(SOURCE_LIST "glad.c"
                "window_context.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(troublemaker_lib ${SOURCE_LIST} ${HEADER_LIST} ${GENERATED_FILES})

# We need this directory, and users of our library will need it too
target_include_directories(troublemaker_lib PUBLIC ../include ${INC_PATH})

target_link_libraries(troublemaker_lib PRIVATE glfw)

# All users of this library will need at least C++17
target_compile_features(troublemaker_lib PUBLIC cxx_std_17)

if(CLANG_TIDY_EXE)
  set_target_properties(
    troublemaker_lib PROPERTIES
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
  )
endif()

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
