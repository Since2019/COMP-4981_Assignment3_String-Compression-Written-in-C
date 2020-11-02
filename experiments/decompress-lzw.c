#include <unistd.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "bit_array.h"
#include "bit_array.c"

#define NOT_EXIST -1
// #define START_WITH_HASH_TAG 1

#define TEST_EXISTENCE 1


/**
 *  converts the binary uint8_t array into 
 *  an 8-bit unsigned integer
 */
int binToInt( uint8_t* binstr ) 
{          
    int result = 0 ;
    int bit = 0; 
    while( binstr[bit] != '\0' )
    {
        if( binstr[bit] == '1' )
        {
            result |= 1 ;
        }

        bit++ ;
        if( binstr[bit] != '\0' )
        {
            result <<= 1 ;
        }
    }

    return result ;
}          


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

    // char seq[2] = "A";
    // for(int i=0; i < 26; i++) {
    //     insert_seq(dict,seq);
    //     seq[0]++;
    // }

    // insert_seq(dict,"\0");
    char seq[2] = "\0";
    for(int i=0; i < 256; i++) {
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

/**
 *  @param dict: dictionary
 *  @param seq : compares if the seq are the same or not.
 */
uint8_t* get_code_seq(Dictionary *dict,uint16_t code){
    //err handling
    if(code < 0 || code >= dict->size) {
        return NULL;
    }
    else{
        int i = code;
        return dict->seq[i];
    }
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

/**
  * @param codes : codes
  * @param Dictionary* dict
  */
void lzw_decode(uint16_t codes[], int n,Dictionary* dict){
    uint16_t code;
    char prev[1000];
    char* output;

    code = codes[0];
    output = get_code_seq(dict,code);
    printf("%s", output);

    int i;
    for(i = 1; i < n; i ++){
        code = codes[i];
        strcpy(prev,output);
        output = get_code_seq(dict, code);
        sprintf(prev,"%s%c",prev,output[0]);

        insert_seq(dict,prev);

        printf("%s",output);
    }

}

/**
  * @param file_content : the content of the file is read into a very large buffer
  * returns the size of the the array
  */
  int read_codes(uint16_t* code_array){
     
      //===========READING INTO BIT ARRAY=============================
    //init bit_array
    bit_array *input = bit_array_create();
    bit_array_init(input, 4096 );
    // ----------Doing Reading --------------------------------------
    uint8_t* buffer = malloc(sizeof(uint16_t)*2);
    // uint8_t* file_content = malloc(sizeof(uint8_t)*100);
    size_t index = 0;
    size_t ret;
    //-----------Putting bits into a bit array.--------------
    while(1){
        
        // input = (bit_array*) realloc(input, sizeof(bit_array*)*index + 1);
        ret = read(STDIN_FILENO, buffer,1);
        if(ret == 0)
            break;
        // printf("%c",buffer[0]);
        // file_content[index] = (uint8_t)buffer[0];
        
        bit_array_add_byte(input,(uint8_t)buffer[0]);



        ++index;
        

    }



    // file_content[index]='\0';

    //-------------Write a function, extract 12 bits -------
    //-------------from the bit array and then put----------
    //-------------the bits into uint16_t variables---------
    //-------------(just modify the bit_array_check_byte function)
    //------------- into twelve bits, and it should work---------
    

    index = 0;
    
    for (size_t i = 0; i < input->bit_length / 12; i++) {
        // fprintf(stderr,"err happened after:%u",i);
        
        code_array[index] = bit_array_check_twelve_bits(input,i);  
        fprintf(stderr,"%u     ",code_array[index]);
        
        ++index;
        if(index == 90)
            break;
        
    }  
    
}
// int* read_codes(uint8_t* file_content){
//     uint8_t* buffer;
//     int code_buffer;
//     size_t index = 0;
//     size_t ret;

//     int* code_array;

//     // read 12 bits per time.
//     while(1){
//         file_content = realloc(file_content, sizeof(uint8_t)*(sizeof(file_content) + 12));
//         ret = read(STDIN_FILENO,buffer,12);
//         if(ret == 0)
//             break;
//         // printf("%c",buffer[0]);
//         file_content[index] = (uint8_t)buffer[0];
//         ++index;

//         code_array[index] = binToInt(buffer);
//     }
//     // The buffer ends.
//     file_content[index]='\0';


//     return code_array;
// }


int main(){

    //File content ( char array ) 
    uint8_t* file_content = malloc(sizeof(uint8_t)*13);


    uint16_t* code_array = malloc(sizeof(uint16_t)*4096);

    int num_of_codes = read_codes(code_array);

    Dictionary dict;

    // Not sure if 4096 is the correct num.
    init_dictionary(&dict,4096);

    



    
    
    lzw_decode(code_array,num_of_codes,&dict);


    return 0;
}