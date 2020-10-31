#include <unistd.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define CODE_BITS 12

#define NOT_EXIST -1
#define START_WITH_HASH_TAG 1

// #define PRINT_OUT_DICTIONARY 1




// ============================HELPER FUNCTIONS=============================

/**
 * @param decimal_num : the number you want to convert into binary
 * @param bin_12_bits : uint8_t pointer, stores 12bits of binary number.
 */
void decimalToBinary(int decimal_num, uint8_t *bin_n_bits,size_t number_of_bits)
{
    int c, tmp;

    // bit shifting and do the conversion.
    for (c = number_of_bits - 1  ; c >= 0; c--)
    {
        tmp = decimal_num >> c;

        if (tmp & 1)
            bin_n_bits[number_of_bits - c - 1 ] = '1';
        else
            bin_n_bits[number_of_bits - c - 1 ] = '0';
    }
    bin_n_bits[number_of_bits] = '\0';
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
        // printf("%d %s\n",code,current);
        
        //// original code(in decimal)
        //printf("%d",code);

        //code in binary
        uint8_t* code_buffer; 
        decimalToBinary(code,code_buffer,CODE_BITS);
        printf("%s",code_buffer);

    }

}

/** 
  * @param argc : argument count
  * @param argv : argument vector
  */
void parse_args(int argc,char* argv[]){
    // If no arg is passed to the program
    int arg_count = 1;

    while(arg_count < argc && strcmp(argv[arg_count],">") != 0){
        
        fprintf(stderr, "checking args at %d with %s\n", arg_count, argv[arg_count]);
        if(strstr(argv[arg_count], ".txt") != NULL)
        {
            
            int fd = open(argv[arg_count], O_RDONLY);
            dup2(fd, STDIN_FILENO);
            // close(fd);
        }

        if(strcmp(argv[arg_count], ">") == 0)
        {
            fprintf(stderr, "if file was defined, please use a txt file\n");
        }
        arg_count++;
    }
}









int main(int argc, char* argv[]){

    parse_args(argc,argv);
    
    // int fdw = dup2(fdw,STDOUT_FIFENO);



    Dictionary dict;
    init_dictionary(&dict,1000);
    

    #ifdef PRINT_OUT_DICTIONARY
        print_dictionary(&dict);
    #endif

    
    uint8_t* buffer;
    uint8_t* file_content = malloc(sizeof(uint8_t)*10000);
    size_t index = 0;
    size_t ret;
    while(1){
        ret = read(STDIN_FILENO,buffer,1);
        if(ret == 0)
            break;
        // printf("%c",buffer[0]);
        file_content[index] = (uint8_t)buffer[0];
        ++index;
    }
    file_content[index]='\0';
    
    // printf("%s",file_content);
    lzw_encode(file_content,&dict);
    



    // lzw_encode("TOBEORNOTTOBEORTOBEORNOT",&dict);

    return 0;
}