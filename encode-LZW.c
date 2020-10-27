#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


typedef struct {
    char ** seq;
    int *   code;
    int     size;
    int     max_size;
} Dictionary;

void insert_seq(Dictionary* dict, uint_8 * seq){
    int i = dict->size;
    dict -> seq[i] = malloc(sizeof(char) *strlen(seq) + 1);
}

// void init_dictionary(Dictionary * dict, int max_size) {
//     dict -> max_size = max_size;

// }