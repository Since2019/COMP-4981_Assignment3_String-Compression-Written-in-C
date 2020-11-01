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


    /**
     * 
     * ---------shifts one bit at a time----------
     * 
     * 12bits:     101001100101
     *   mask:     100000000000
     *  8bits:     00000000
     *  
     *  8bits  <- 12bits and mask
     * 
     *  shift 1:
     *  12bits:             101001100101
     *   mask:               100000000000 
     *  8bits:              10000000
     * 
     *  shift 4:
     *  12bits:          101001100101
     *   mask:               100000000000 
     *  8bits:           10100000
     * 
     *  shift 5:
     *  12bits:         101001100101
     *   mask:               100000000000 
     *  8bits:          10100100

     *  shift 8:
     *  12bits:         101001100101
     *   mask:                 100000000000 
     *  8bits:          10100110
     * 
     *  shift 9:
     *  12bits:         101001100101
     *   mask:                 100000000000 
     * 
     *  8bits#2:               00000000
     *  8bits#1:          10100110

     *  shift 12:
     *  12bits:     101001100101
     *   mask:                 100000000000 
     * 
     *  8bits#2:            01010000
     *  8bits#1:          10100110
     * 

     *  shift 13:
     *  12bits #1:     101001100101
     *  12bits #2:             100011100001   
     *   mask:                 100000000000 
     * 
     *  8bits#2:           01011000
     *  8bits#1:          10100110
     * 
     * 
     *  shift 16:
     *  12bits #1:     101001100101
     *  12bits #2:         100111100001   
     *   mask:                 100000000000 
     * 
     *  8bits#2:       01011001
     *  8bits#1:          10100110
     * 
     * if(8 bits is filled)
     *    move to the next 8 bits!
     * else if(12 bits becomes 0)
     *    move to the next 12 bits!
     * else 
     *    fill the last parts of 8bits with 0s !!!!!!
     * --------------------------------------------
     * 
     * 
     * 
     *=========right shift and then shift back=====
     *
     * --------right shift 4 bits and then shift back-----
     * 
     * 12bits:                  101001100101
     * 12bits_tmp shift 1       10100110
     *           (do the masking:)
     * 8bits:                   10100110
     * 
    
     * --------left shift 8 bits -----
     * 
     * 12bits:                  101001100101
     * 12bits_tmp shift 2       0101--------
     *           (do the masking:)
     * 8bits:                   0101----
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
     * 
    */



    // opens the file output descriptor
    int filedesc = open(STDOUT_FILENO, O_WRONLY | O_APPEND);
    
    // // This one will be the return value of the func
    // uint8_t* twelve_bits_array = malloc(sizeof(uint8_t)*2);
    
    uint16_t twelve_bit_from_read;

    uint16_t twelve_bit_tmp;

    uint8_t eight_bit_tmp;

    size_t index = 0;


    for(; twelve_bit_tmp != 0 ; twelve_bit_tmp >>= 1, eight_bit_tmp >>= 1) {

    }

    // now take a twelve bit variable, shift it to the right and copy each bit
    // into a uint_8, until the uint_8 is done OR the twelve bit is done!
    
    int step = 1;

    if(step == 1) {
        twelve_bit_tmp = twelve_bit_from_read >> 8;
        
    }
   

    while(1){
        // If it can't write anymore, it breaks.
        if (write(filedesc, eight_bit_tmp, 1) != sizeof(uint8_t)*1) {
            break;
        }
        
        ++index;
    }





}