#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "input_handler.h"

int main(int argc, char const *argv[])
{
    bool from_stdin = false;

    ih_parse_args(argc, argv);

    uint8_t sentinel = getchar();
    int8_t next;
    uint8_t count;
    uint8_t character;
    while (1)
    {
        next = getchar();

        if ((char)next == EOF)
            break;

        if ((uint8_t)next == sentinel)
        {
            count = getchar();
            character = getchar();

            int i;
            for (i = 0; i < count; i++)
                printf("%c", character);
        }
        else
        {
            printf("%c", next);
        }
    }

    return 0;
}
