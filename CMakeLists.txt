cmake_minimum_required(VERSION 3.18.2)
project(error_detection C)

set(CMAKE_C_STANDARD 11)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

# add_library(lib STATIC input_handler.c bit_handler.c)

# target_compile_options(lib PRIVATE -Wpedantic -Wall -Wextra)

add_executable(compress-lzw compress-lzw.c)
# target_link_libraries(compress-lzw lib)
target_compile_options(compress-lzw PRIVATE -Wpedantic -Wall -Wextra)

add_executable(decompress-lzw decompress-lzw.c)
# target_link_libraries(decompress-lzw lib)
target_compile_options(decompress-lzw PRIVATE -Wpedantic -Wall -Wextra)

add_executable(huffman-compress huffman-compress.c)
# target_link_libraries(huffman-compress lib)
target_compile_options(huffman-compress PRIVATE -Wpedantic -Wall -Wextra)

add_executable(huffman-decompress huffman-decompress.c)
# target_link_libraries(huffman-decompress lib)
target_compile_options(huffman-decompress PRIVATE -Wpedantic -Wall -Wextra)


