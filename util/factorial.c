/**
 * @author Andrej Bartulin
 * PROJECT: 3x
 * LICENSE: Public Domain
 * DESCRIPTION: Main file for big number generator
*/

#include "factorial.h"

int main(int argc, const char **argv)
{
    int n;
    (argc == 2) ? (n = atoi(argv[1])) : (n = 0);

    char *p = factorial(n);
    printf("%d! = %s\n", n, strrev(p));
    free(p);
    return 0;
}