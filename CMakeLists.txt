cmake_minimum_required(VERSION 3.18.2)
project(error_detection C)

set(CMAKE_C_STANDARD 11)

# include_directories(/usr/local/include)
# link_directories(/usr/local/lib)

add_library(lib STATIC input_handler.c file_handler.c bit_array.c)

target_compile_options(lib PRIVATE -Wpedantic -Wall -Wextra)

add_executable(compress-rle compress-rle.c)
# target_link_libraries(compress-lzw lib)
target_compile_options(compress-rle PRIVATE -Wpedantic -Wall -Wextra)

add_executable(decompress-rle decompress-rle.c)
# target_link_libraries(decompress-lzw lib)
target_compile_options(decompress-rle PRIVATE -Wpedantic -Wall -Wextra)

add_executable(compress-lzw compress-lzw.c)
target_link_libraries(compress-lzw lib)
target_compile_options(compress-lzw PRIVATE -Wpedantic -Wall -Wextra)

add_executable(decompress-lzw decompress-lzw.c)
target_link_libraries(decompress-lzw lib)
target_compile_options(decompress-lzw PRIVATE -Wpedantic -Wall -Wextra)

add_executable(compress-huffman compress-huffman.c)
# target_link_libraries(compress-huffman lib)
target_compile_options(compress-huffman PRIVATE -Wpedantic -Wall -Wextra)

add_executable(decompress-huffman decompress-huffman.c)
# target_link_libraries(decompress-huffman lib)
target_compile_options(decompress-huffman PRIVATE -Wpedantic -Wall -Wextra)


