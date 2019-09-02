add_executable(troublemaker main.cpp)
target_compile_features(troublemaker PRIVATE cxx_std_17)

target_link_libraries(troublemaker PRIVATE troublemaker_lib glfw)

if(CLANG_TIDY_EXE)
  set_target_properties(
    troublemaker PROPERTIES
    CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
  )
endif()