#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define NOT_EXIST -1
#define START_WITH_HASH_TAG 1

#define TEST_EXISTANCE 1


typedef struct {
    //string array stores the strings
    //that is added to the dictionary
    uint8_t ** seq;
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
void insert_seq(Dictionary* dict, uint8_t * seq){
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


    #ifdef START_WITH_HASH_TAG
    //flag at position 0
    insert_seq(dict,"#");
    #endif

    char seq[2] = "A";
    for(int i=0; i < 26; i++) {
        insert_seq(dict,seq);
        seq[0]++;
    }
}

void print_dictionary(Dictionary* dict){
    printf("=========================\n");
    printf("Code           Sequence\n");
    printf("=========================\n");
    for(int i=0; i< dict->size; i++){
        printf("%5d%7c",dict->code[i], ' ');
        printf("%s\n",dict->seq[i]);
    }
    printf("=========================\n");
}

/**
 *  @param dict: dictionary
 *  @param seq : compares if the seq are the same or not.
 */
int get_seq_code(Dictionary *dict,char* seq){
    for(int i=0;i<dict->size; i++){
        if(strcmp(dict->seq[i],seq)==0){
            return dict->code[i];
        }
    }
//  Not exist
    return NOT_EXIST;

}


void lzw_encode(uint8_t* text, Dictionary* dict){
    // Wonder how to make this dynamic
    uint8_t current[1000];
    uint8_t next;
    int  code;
    int  i = 0;
    while(i < strlen(text)){
        sprintf(current,"%c",text[i]);
        next = text[i+1];

        // Has not reached the end of the sequence table
        while(get_seq_code(dict,current) != NOT_EXIST){
            sprintf(current,"%s%c",current,next);
            i++;
            next = text[i+1];
        }

        current[strlen(current) - 1] = '\0';
        next = text[i];
        code = get_seq_code(dict,current);
        sprintf(current,"%s%c",current,next);
        insert_seq(dict,current);
        printf("%d %s\n",code,current);
    }

}

int main(){

    
    Dictionary dict;
    init_dictionary(&dict,1000);
    print_dictionary(&dict);

    #ifdef TEST_EXISTANCE
    //Checks if "B" exists.
    printf("%d\n",get_seq_code(&dict,"B"));
    #endif

    lzw_encode("TOBEORNOTTOBEORTOBEORNOT",&dict);

    return 0;
}