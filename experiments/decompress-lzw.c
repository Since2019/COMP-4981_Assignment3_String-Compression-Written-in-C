#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include "bit_array.h"
#include "input_handler.h"

#define CODE_BITS 12
#define MAX_SIZE 4096

#define NOT_EXIST (-1)
// #define START_WITH_HASH_TAG 1
// #define START_WITH_NULL 1

// #define PRINT_OUT_DICTIONARY 1

typedef struct
{
    //string array stores the strings
    //that is added to the dictionary
    uint8_t **seq;
    //corresponding dictionary
    //code in the dictionary
    int *code;
    //the size of the dictonary
    int size;
} Dictionary;

/**
 * @param dict : the address of the Dictionary you want to init
 * @param seq : how many characters can it hold
 */
void insert_seq(Dictionary *dict, uint8_t *seq)
{
    int i = dict->size;
    // +1 means null byte
    dict->seq[i] = malloc(sizeof(char) * strlen(seq) + 1);

    dict->code[i] = i;

    dict->size++;

    // fprintf(stderr, "added %s\n", seq);

    // fill the seq with the newly added item
    strcpy(dict->seq[i], seq);
}

/**
 * @param dict : the address of the Dictionary you want to init
 * @param max_size : how many characters can it hold
 */
void init_dictionary(Dictionary *dict)
{
    (*dict).size = 0;
    (*dict).seq = malloc(sizeof(char *) * MAX_SIZE);
    (*dict).code = malloc(sizeof(int) * MAX_SIZE);

    char seq[2] = "\0";
    for (int i = 0; i < 256; i++)
    {
        insert_seq(dict, seq);
        seq[0]++;
    }
}

void print_dictionary(Dictionary *dict)
{
    printf("=========================\n");
    printf("Code           Sequence\n");
    printf("=========================\n");
    for (int i = 0; i < dict->size; i++)
    {
        printf("%5d%7c", dict->code[i], ' ');
        printf("%s\n", dict->seq[i]);
    }
    printf("=========================\n");
}

/**
 *  @param dict: dictionary
 *  @param seq : compares if the seq are the same or not.
 */
int get_seq_code(Dictionary *dict, char *seq)
{
    int i;
    for (i = 0; i < dict->size; i++)
    {
        if (strcmp(dict->seq[i], seq) == 0)
        {
            fprintf(stderr, "loop code %s vs %s returned %d\n", dict->seq[i], seq, dict->code[i]);
            return dict->code[i];
        }
    }
    //  Not exist
    fprintf(stderr, "loop code %s vs %s returned %d [FAIL]\n", dict->seq[i], seq, i);
    return i;
}

char *get_seq_char(Dictionary *dict, int code)
{
    int i;
    for (i = 0; i < dict->size; i++)
    {
        if (dict->code[i] == code)
        {
            fprintf(stderr, "returned sequence: %s\n", dict->seq[i]);
            return dict->seq[i];
        }
    }
    //  Not exist
    fprintf(stderr, "returned sequence: %s\n", "EOF");
    return "\0";
}

void debug_print(char *c)
{
    fprintf(stderr, "%s", c);
}

void print_bin(int val, int length)
{
    int what_bit_testing = 0;

    while (what_bit_testing < length)
    {
        if (val & 0x80)
        {
            // printf("bit %d is 1\n", what_bit_testing);
            fprintf(stderr, "1");
        }
        else
        {
            // printf("bit %d is 0\n", what_bit_testing);
            fprintf(stderr, "0");
        }

        what_bit_testing++;
        val = val << 1;
    }
    fprintf(stderr, "\n");
}

void append_to_int8(int8_t *b, int append_value)
{
    if (append_value == 1)
    {
        *b = ~*b;
        *b = *b << 1;
        *b = ~*b;
    }
    else if (append_value == 0)
    {
        *b = *b << 1;
    }
}

void append_to_int(int *b, int append_value)
{
    if (append_value == 1)
    {
        *b = ~*b;
        *b = *b << 1;
        *b = ~*b;
    }
    else if (append_value == 0)
    {
        *b = *b << 1;
    }
}

int read12bits(int *remainder, bool *eight_four, bool *is_eof) // read 8 + 4
{
    int code;
    if (*eight_four)
    {
        code = getchar();

        if (code != EOF)
            *remainder = getchar();
        else
            *is_eof = true;

        int what_bit_testing = 0;
        while (what_bit_testing < 4)
        {
            if (*remainder & 0x80)
            {
                append_to_int(&code, 1);
            }
            else
            {
                append_to_int(&code, 0);
            }

            what_bit_testing++;
            *remainder = *remainder << 1;
        }
    }
    else
    {
        code = 0;
        int what_bit_testing = 0;
        while (what_bit_testing < 4)
        {
            if (*remainder & 0x80)
            {
                append_to_int(&code, 1);
            }
            else
            {
                append_to_int(&code, 0);
            }

            what_bit_testing++;
            *remainder = *remainder << 1;
        }
        int new_byte = getchar();
        if (new_byte == EOF)
            *is_eof = true;
        what_bit_testing = 0;
        while (what_bit_testing < 8)
        {
            if (new_byte & 0x80)
            {
                append_to_int(&code, 1);
            }
            else
            {
                append_to_int(&code, 0);
            }

            what_bit_testing++;
            new_byte = new_byte << 1;
        }
    }

    (*eight_four) = !(*eight_four);
    return code;
}

int main(int argc, char const *argv[])
{
    Dictionary dict;

    ih_parse_args(argc, argv);

    // initialize dictionary
    init_dictionary(&dict);

    // intitialize sequence
    // print_dictionary(&dict);

    int prev = 0, curr = 0;
    int remainder = 0;
    bool readmode = true;
    bool iseof = false;
    prev = read12bits(&remainder, &readmode, &iseof);
    fprintf(stdout, "%s", get_seq_char(&dict, prev));
    char * prevseq = malloc(sizeof(char) * MAX_SIZE + 1);
    while (!iseof)
    {
        curr = read12bits(&remainder, &readmode, &iseof);
        char * entry = get_seq_char(&dict, curr);
        fprintf(stdout, "%s", entry);
        char ch[2] = "\0";
        ch[0] = entry[0];
        strcpy(prevseq, get_seq_char(&dict, prev));
        insert_seq(&dict, strcat(prevseq, ch));
        prev = curr;
    }

    // print_dictionary(&dict);

    return 0;
}