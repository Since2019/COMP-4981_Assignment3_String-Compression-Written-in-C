cmake_minimum_required(VERSION 3.17)
project(dc_data_structures C)

set(CMAKE_C_STANDARD 11)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)
add_executable(test test.c)
target_link_libraries(test dc_utils)
