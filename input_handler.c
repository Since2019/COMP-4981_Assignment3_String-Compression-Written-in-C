#include "input_handler.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */

int ih_parse_args(int argc, const char* argv[])
{   

    // check if input file exists
    int arg_count = 1;
    while(arg_count < argc && strcmp(argv[arg_count], ">") != 0)
    {
        fprintf(stderr, "checking args at %d with %s\n", arg_count, argv[arg_count]);
        fh_set_infile(argv[arg_count]);       
        
        arg_count++;
    }

    return 0;
}

int ih_parse_args_wopt(int argc, const char* argv[], struct option long_option[], int opt_count)
{   

    char* const* args = (char* const*)argv;

    // if arguments is less than the number of required options
    // incremented by 1 since the program is counted as an argument
    if(argc < opt_count + 1) {
        return 0;
    }

    // option counter check
    int opt_counter;
    while (1)
    {

        int option_index = 0;
        opt_counter = getopt_long_only(argc, args, ":", long_option, &option_index);

        if (opt_counter == -1)
            break;
    }

    // check if input exits
    int arg_count = 1;
    while(arg_count < argc && strcmp(argv[arg_count], ">") != 0)
    {
        fprintf(stderr, "checking args at %d with %s\n", arg_count, argv[arg_count]);
        fh_set_infile(argv[arg_count]);
        arg_count++;
    }


    return 1;
}
