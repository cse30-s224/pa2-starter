#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Assignment-2
 * Username: _______ (fill out your username here)
 * Class: UCSD CSE30-S224
 */


#define USAGE_STRING "usage: %s -c incols [-s] col1 [col2 ...]\n"
#define INCOLS_INVALID_RANGE "Err: incols must be >= 1 and <= %d\n"
#define INCOLS_MISSING "Err: input columns required\n"
#define OUTCOLS_MISSING "Err: at least one output column must be provided\n"
#define COL_OUT_OF_RANGE "Err: output column number must be >= 1 and <= %d\n"
#define TOO_MANY_COLS_ERR "Err: too many columns in row. Dropping row...\n"
#define TOO_FEW_COLS_ERR "Err: too few columns in row. Dropping row...\n"
#define STATS_STRING "%d valid lines\n" \
                    "%d dropped lines\n" \
                    "longest field = %d characters\n"
#define MAX_COLS 100

void usage(char *argv0) {
    fprintf(stderr, USAGE_STRING, argv0);
}

int main(int argc, char **argv) {
    int incols = 0; // number of columns in input file
    int outcols = 0; // number of columns in output

    char *linebuf = NULL; // buffer for reading in a single line
    char **colptrs = NULL; // array of pointers to start of each col
    int *outcols_buf = NULL; // buffer for list of output cols (1-indexed)

    unsigned int linecnt = 0; // number of valid lines
    unsigned int dropcnt = 0; // number of invalid (dropped) lines

    // longest field length (does not include whitespace)
    unsigned int longest_field = 0;

    int stats_flag = 0; // was -s provided
    int c_flag = 0; // was -c provided

    int c; // for reading options with getopt
    while ((c = getopt( /* TODO: fill in */ )) != -1) {
        switch (c) {
            /*
            TODO: uncomment this and fill in case to read incols
            case '':
                // parse incols and check for err
                // make sure that incols is in the valid range 
                // (see MAX_COLS)
                // if it is not, print INCOLS_INVALID_RANGE to stderr 
                // and return failure
                break;
            */
            case 's':
                // example for s flag
                stats_flag = 1;
                break;
            default:
                // if we got an invalid argument
                usage(*argv);
                return EXIT_FAILURE;
        }
    }
    // check if incols was provided
    // if it wasn't print INCOLS_MISSING to stderr,
    // call usage() with the first element of argv, and return failure


    // set outcols and check that it's at least 1
    // if no output columns are given, print MISSING_OUTCOL to stderr,
    // call usage() with the first element of argv, and return failure


    // allocate memory for outcols_buf
    // make sure to check that malloc didn't fail
    // (malloc returns null on failure)
    /*
    TODO uncomment this
    outcols_buf = malloc( TODO fill in );
    if ( TODO fill in ) {
        fprintf(stderr, "malloc failure\n");
        return EXIT_FAILURE;
    }
    */

    // parse the rest of argv and fill in outcols_buf
    // make sure to check that the argument is in the correct range
    // of columns
    // if it is not, print COL_OUT_OF_RANGE to stderr and return failure
    // you can use atoi for conversion, and you can assume that all
    // provided arguments will be proper integers

    // allocate space for colptrs using incols
    // if malloc fails, print and return failure
    /*
    TODO: uncomment this
    colptrs = malloc( TODO: fill in );
    if ( TODO: fill in ) {
        fprintf(stderr, "malloc failure\n");
        free(outcols_buf); // avoid memory leaks
        return EXIT_FAILURE;
    }
    */

    // read in the input lines using getline
    size_t buffer_len;
    char *p;
    while ((getline( /* TODO: fill in */ )) > 0) {
        // parse the line as described in the writeup, adding null
        // terminators to separate the whitespace delimiters and filling
        // in colptrs with pointers to the start of each column as you go


        // loop over line ( ... ) {
            // some tips/hints:
            // if you find a whitespace, find the start of the next column
            // by finding the next non-whitespace character
            //
            // it may help to keep track of how many columns you have found,
            // if there are too many, keep track of the failure and stop
            // processing this line
            //
            // keep track of the length of the longest field in the line,
            // it will be used for the statistics if this line is valid
        // }

        // make sure we have the right number of columns
        // if there were too many or too few columns, print the relevant
        // error message and go immediately to the next line

        // use TOO_FEW_COLS_ERR for too few cols
        // use TOO_MANY_COLS_ERR for too many cols

        // if the line was valid, update longest_field

        // print the output cols in specified order
        // make sure to have a single space after each column as a delimiter
        // except for the final column which has a newline immediately after
        // reminder: outcols_buf is 1-indexed
    }

    // print stats **to stderr** if -s provided

    // free any allocated memory (outcols_buf, colptrs, and linebuf)
    // before returning

    return EXIT_SUCCESS;
}
