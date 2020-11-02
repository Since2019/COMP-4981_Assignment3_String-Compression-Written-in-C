#include <inttypes.h>
#include <stdio.h>
#include <stdbool.h>
#include "input_handler.h"

#define NUM_CHARS 256
#define LINESIZE 1024

uint8_t find_sentinel_wbuf(char **buffer)
{

    int buffersize = LINESIZE;
    *buffer = malloc(sizeof(char) * buffersize);
    int pos = 0;

    int char_list[NUM_CHARS];

    // initialize char_list
    size_t i;
    for (i = 0; i < NUM_CHARS; i++)
    {
        char_list[i] = 0;
    }

    // read number of character occurences
    int c;
    while (1)
    {
        c = getchar();

        if (c == EOF) // EOF
            break;

        fprintf(stderr, "before insert\n");
        (*buffer)[pos] = c;
        fprintf(stderr, "%c\n", c);
        pos++;

        if (pos >= LINESIZE)
        {
            buffersize += LINESIZE;
            *buffer = realloc(*buffer, buffersize * sizeof(char));
            fprintf(stderr, "reallocing");
            if (!*buffer)
            {
                fprintf(stderr, "shell: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        char_list[c]++;
    }

    // find least character
    int index = 0;
    int smallest = char_list[index];
    uint8_t sentinel = 0;

    while (index < NUM_CHARS)
    {
        if (char_list[index] < smallest)
        {
            smallest = char_list[index];
            sentinel = index;
        }
        index++;
    }

    return sentinel;
}

uint8_t find_sentinel()
{

    int char_list[NUM_CHARS];

    // initialize char_list
    size_t i;
    for (i = 0; i < NUM_CHARS; i++)
    {
        char_list[i] = 0;
    }

    // read number of character occurences
    int c;
    while (1)
    {
        c = getchar();

        if (c == EOF) // EOF
            break;

        char_list[c]++;
    }

    // find least character
    int index = 0;
    int smallest = char_list[index];
    uint8_t sentinel = 0;

    while (index < NUM_CHARS)
    {
        if (char_list[index] < smallest)
        {
            smallest = char_list[index];
            sentinel = index;
        }

        index++;
    }

    return sentinel;
}

void compress_wbuf(char *buf, uint8_t sentinel)
{
    fprintf(stdout, "%c", sentinel);

    int c = 0;
    uint8_t next = 0;
    uint8_t prev = buf[0];

    int letter_count = 0;

    int index = 1;

    while (1)
    {
        c = buf[index++];

        next = c;
        letter_count++;
        if (prev != next || letter_count >= 255)
        {

            if (letter_count <= 3)
            {
                int i = 0;
                for (i = 0; i < letter_count; i++)
                    printf("%c", prev);
            }
            else
            {
                printf("%c%c%c", sentinel, letter_count, prev);
            }

            prev = c;
            letter_count = 0;
        }

        if (c == EOF || !c)
            break;
    }
}

void compress(uint8_t sentinel)
{
    fprintf(stdout, "%c", sentinel);

    int c = 0;
    uint8_t next = 0;
    uint8_t prev = getchar();

    int letter_count = 0;

    while (1)
    {
        c = getchar();
        next = c;
        letter_count++;

        if (prev != next || letter_count >= 255)
        {

            if (letter_count <= 3)
            {
                int i = 0;
                for (i = 0; i < letter_count; i++)
                    fprintf(stdout, "%c", prev);
            }
            else
            {
                fprintf(stdout, "%c%c%c", sentinel, letter_count, prev);
            }

            prev = c;
            letter_count = 0;
        }

        if (c == EOF)
            break;
    }
}

int main(int argc, char const *argv[])
{
    bool from_stdin = false;

    // handle file IO
    ih_parse_args(argc, argv);

    uint8_t sentinel;
    char *buffer;

    // read whole file to find the supposed sentinel
    if (isatty(STDIN_FILENO))
    {
        from_stdin = true;
        sentinel = find_sentinel_wbuf(&buffer);
        fprintf(stderr, "before print\n");
        for (int i = 0; i < 10; i++)
        {
            fprintf(stderr, "%c", buffer[i]);
        }
        fprintf(stderr, "after print\n");
        compress_wbuf(buffer, sentinel);
    }
    else
    {
        sentinel = find_sentinel();
        fseek(stdin, 0, SEEK_SET);
        clearerr(stdin);
        compress(sentinel);
    }

    // compress the data while writing to file

    return 0;
}
