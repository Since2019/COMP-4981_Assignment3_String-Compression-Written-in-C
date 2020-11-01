#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <stdint.h>
#include <inttypes.h>
struct head{
    unsigned int8_t byte;
    long count; /* 1 - Counts Occurance */
    char huffman_code[256] /* 2 - Array */
    long parent,left_child,right_child;

}
header[512],tmp;

void compress(){
    char* filename = malloc(sizeof(char)*256);
    char* outputfile = malloc(sizeof(char)*256);
    char* buffer = malloc(sizeof(char)*512);

    
}