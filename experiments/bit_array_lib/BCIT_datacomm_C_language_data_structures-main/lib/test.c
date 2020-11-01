#include <dc_utils/bit_array.h>
#include <stdio.h>

int main(void) {
    bit_array * my_bits = bit_array_create();
    bit_array_init(my_bits, 8);

    bit_array_add_byte(my_bits, 'a');
    bit_array_add_byte(my_bits, 'b');
    bit_array_add_bit(my_bits, 0);
    bit_array_add_bit(my_bits, 1);
    bit_array_add_bit(my_bits, 0);

    // Print out ascii bits
    // This does not print any padding
    for (size_t i = 0; i < my_bits->bit_length; i++) {
        int bit = bit_array_check_bit(my_bits, i);
        printf("%d", bit);
    }

    printf("\n");

    // Print out actual bits packed into uint8_t bytes
    // This includes padding on the last byte if necessary
    for (size_t i = 0; i < my_bits->bit_length; i+=8) {
        uint8_t byte = bit_array_check_byte(my_bits, i);
        printf("%c", byte);
    }

    printf("\n");

    int padding = 8 - (my_bits->bit_length % 8);
    printf("padding: %d", padding);

    printf("\n");

    return 0;
}