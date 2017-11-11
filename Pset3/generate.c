/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: ensure proper usage
    //n is pseudorandom numbers to generate,
    //s is seed for generator; s is optional.
    //print usage statement and exit
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    //TODO:convert string argv[1] to int
    int n = atoi(argv[1]);

    // TODO: if argc = 3(that is optional 's'is used),
     // then convert, into a long int.
    if (argc == 3)
    {
        srand48((long) atoi(argv[2])); //srand48 is a function used to "seed" drand48)
    }
    else
    {
        srand48((long) time(NULL));
    }

    // TODO: Print the random number n times
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
