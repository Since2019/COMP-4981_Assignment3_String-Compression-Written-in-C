#include <unistd.h>
#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>


/** Now we are going to create a bit array
 *  the bit array outputs 12 bit data by 
 *  seperating the data into two parts. 
 *  
 *  ---------------------repeatedly happens:------------------------------
 *  the first 8 bits in the (1st) 12 bits will be stored in [the first] uint8_t
 *  the remaining 4 bits will be stored in the next uint8_t
 *  
 *  the following 4 bits from the (2nd) 12 bits will be stored 
 *  in the the upcoming [the second] uint8_t, occupying the first 4 bits of [the second] uint8_t
 *  
 *  the remaining 8 bits in the (2rd) 12 bits can be stored in [the third] uint8_t 
 *  ----------------------next repetition----------------------------------
 */
void twelve_bits_output(uint16_t twelve_bits_array){

    // opens the file output descriptor
    int filedesc = open(STDOUT_FILENO, O_WRONLY | O_APPEND);
    
    // // This one will be the return value of the func
    // uint8_t* twelve_bits_array = malloc(sizeof(uint8_t)*2);
    
    uint16_t twelve_bit_tmp;

    uint8_t eight_bit_tmp;

    size_t index = 0;


    for(; twelve_bit_tmp != 0 ; twelve_bit_tmp >>= 1, eight_bit_tmp >>= 1) {

    }


    /**
     * 12bits: 101001100001
     *   mask:            1
     *  8bits:     00000000
     *  
     *  8bits  <- 12bits and mask
    */


    // now take a twelve bit variable, shift it to the right and copy each bit
    // into a uint_8, until the uint_8 is done OR the twelve bit is done!
    while(twelve_bit_tmp != 0){
        twelve_bit_tmp
    }

    while(1){
        // If it can't write anymore, it breaks.
        if (write(filedesc, eight_bit_tmp, 1) != sizeof(uint8_t)*1) {
            break;
        }
        
        ++index;
    }





}