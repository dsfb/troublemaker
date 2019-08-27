add_executable(troublemaker main.cpp)
target_compile_features(troublemaker PRIVATE cxx_std_20)

target_link_libraries(troublemaker PRIVATE troublemaker_lib glfw)
