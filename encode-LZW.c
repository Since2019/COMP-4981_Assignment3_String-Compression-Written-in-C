#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


typedef struct {
    //string array stores the strings
    //that is added to the dictionary 
    char ** seq;
    //corresponding dictionary
    //code in the dictionary  
    int *   code;
    //the size of the dictonary 
    int     size;
    //how many code can the dictionary have 
    int     max_size;
} Dictionary;

/**
 * @param dict : the address of the Dictionary you want to init
 * @param seq : how many characters can it hold
 */
void insert_seq(Dictionary* dict, uint_8 * seq){
    int i = dict->size;
    // +1 means null byte
    dict -> seq[i] = malloc(sizeof(char) *strlen(seq) + 1);
    
    dict->code[i] = i;
    
    dict->size++;

    //fill the seq with the newly added item
    strcpy(dict->seq[i],seq);
}

/**
 * @param dict : the address of the Dictionary you want to init
 * @param max_size : how many characters can it hold
 */
void init_dictionary(Dictionary * dict, int max_size) {
    dict -> max_size = max_size;
    dict -> size     = 0;
    // 
    dict -> seq      = malloc(sizeof(char*) *max_size);
    dict -> code     = malloc(sizeof(int)   * max_size);

    //flag at position 0
    insert_seq(dict,"#");
    char seq[2] = 'A';
    for(int i=0; i < 26; i++) {
        insert_seq(dictionary,seq);
        seq[0]++;
    }
}

void print_dictionary(Dictionary* dict){
    printf("=========================\n");
    printf("Code           Sequence\n");
    printf("=========================\n");
    for(int i=0; i< dict->size; i++){
        printf("%5d%7c",dict->code[i]);
    }
    printf("=========================\n");
}

int main(){
    Dictionary dictt;
    init_dictionary(&dict,1000);
    print_dictionary(&dict);
}