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

#define NOT_EXIST -1
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

uint8_t print_seq_wrem(int c)
{
    int what_bit_testing = 0;

    uint8_t bit8 = 0;

    while (what_bit_testing < 8)
    {
        if (c & 0x800)
        {
            append_to_int8(&bit8, 1);
        }
        else
        {
            append_to_int8(&bit8, 0);
        }

        what_bit_testing++;
        c = c << 1;
    }
    debug_print("wrem byte: ");
    printf("%c", bit8);
    print_bin(bit8, 8);
    what_bit_testing = 0;

    while (what_bit_testing < 8)
    {
        if (c & 0x800)
        {
            append_to_int8(&bit8, 1);
        }
        else
        {
            append_to_int8(&bit8, 0);
        }

        what_bit_testing++;
        c = c << 1;
    }
    return bit8;
}

void print_seq(int c, uint8_t remainder)
{
    debug_print("remainder: ");

    // array of bit masks
    const uint16_t mask[] = {0x0100, 0x0200, 0x0400, 0x0800};
    const uint8_t mask2[] = {0x01, 0x02, 0x04, 0x08};

    int pass = 0; // used to check how many bits has been passed through

    while (pass < 4)
    {
        if (c & mask[3 - pass])
        {
            remainder ^= mask2[3 - pass];
        }
        pass++;
    }
    printf("%c", remainder);
    print_bin(remainder, 8);

    debug_print("next byte: ");
    printf("%c", c);
    print_bin(c, 8);
}

int main(int argc, char const *argv[])
{
    Dictionary dict;

    ih_parse_args(argc, argv);

    // initialize dictionary
    init_dictionary(&dict);

    // intitialize sequence
    // print_dictionary(&dict);

    int printing8 = 1;
    char rc = 0;
    char *ch = malloc(sizeof(char) * 1 + 1);
    char *s = malloc(sizeof(char) * MAX_SIZE + 1);
    char * temp = malloc(sizeof(char) * MAX_SIZE + 1);
    uint8_t remainder = 0;
    while (rc != EOF)
    {
        rc = getchar();
        ch[0] = rc;
        ch[1] = '\0';

        // if (ch[0] == EOF)
        //     break;

        strcpy(temp, s);

        fprintf(stderr, "%c is read\n", rc);
        // fprintf(stderr, "current string: %s\n", strcat(temp, ch));
        fprintf(stderr, "current dict size: %d\n", dict.size);

        
        if (get_seq_code(&dict, strcat(temp, ch)) != dict.size)
        {
            // fprintf(stderr, "%s does not exist in dict\n", cur);

            s = strcat(s, ch);
        }
        else
        {
            // fprintf(stderr, "%s exists in dict\n", cur);
            if (printing8)
            {
                // debug_print("before bit printing8\n");
                remainder = print_seq_wrem(get_seq_code(&dict, s));
                // debug_print("after bit printing8\n");
            }
            else
            {
                // debug_print("before bit printing8 w R\n");
                print_seq(get_seq_code(&dict, s), remainder);
                // debug_print("after bit printing8 w R\n");
            }
            printing8 = !printing8;

            insert_seq(&dict, strcat(s, ch));
            s = malloc(sizeof(char) * 1 + 1);
            strcpy(s, ch);
        }
    }

    // debug_print("final print\n");
    if (printing8)
    {
        // debug_print("before bit printing8\n");
        remainder = print_seq_wrem(get_seq_code(&dict, s));
        // debug_print("after bit printing8\n");
    }
    else
    {
        // debug_print("before bit printing8 w R\n");
        print_seq(get_seq_code(&dict, s), remainder);
        // debug_print("after bit printing8 w R\n");
    }

    // print_dictionary(&dict);

    return 0;
}
