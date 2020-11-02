#ifndef __FILE_HANDLER_H__
#define __FILE_HANDLER_H__

#include <stdio.h>
#include <unistd.h> // file checking
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h> // O_RDONLY | O_WRONLY

/**
 * return 1 if the file exists
 * 
 * @param filename the name of the file to be checked
 */
int fh_file_exists(const char *filename);

/**
 * return 1 if pass, else 0
 * 
 * @param filename the name of the file to be set as the output file
 */
int fh_set_outfile(const char *filename);

/**
 * return 1 if pass, else 0
 * 
 * @param filename the name of the file to be set as the input file
 */
int fh_set_infile(const char *filename);

#endif