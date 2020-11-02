#ifndef __INPUT_HANDLER_H__
#define __INPUT_HANDLER_H__

#include <getopt.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "file_handler.h"

/**
    parses the arguments if an input file is provided

    @param argc the number of arguments
    @param argv the arguments
*/
int ih_parse_args(int argc, const char* argv[]);

/**
    parses the arguments for options and if an input file is provided

    @param argc the number of arguments
    @param argv the arguments
    @param long_option the array of options
    @param opt_count the number of required options
*/
int ih_parse_args_wopt(int argc,  const char* argv[], struct option long_option[], int opt_count);

#endif