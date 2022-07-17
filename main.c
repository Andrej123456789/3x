/**
 * @author Andrej Bartulin
 * PROJECT: 3x
 * LICENSE: Public Domain
 * DESCRIPTION: Main file for C version
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "gmp.h"

int main(int argc, const char *argv[])
{
    int mode;

    if (argc != 3)
    {
        printf("Usage: %s <mode> <number>\n", argv[0]);
        return 0;
    }

    else
    {
        mode = atoi(argv[1]);
    }

    /*
        mpz_t is the type defined for GMP integers.
        It is a pointer to the internals of the GMP integer data structure
    */
    mpz_t n, previous, max;
    int flag;

    /* Initialize the number */
    mpz_init(n);
    mpz_set_ui(n,0);

    /* Parse the input string as a base 10 number */
    flag = mpz_set_str(n, argv[2], 10);
    assert (flag == 0); /* If flag is not 0 then the operation failed */

    flag = mpz_set_str(previous, "0", 10);
    assert (flag == 0); /* If flag is not 0 then the operation failed */

    flag = mpz_set_str(max, argv[2], 10);
    assert (flag == 0); /* If flag is not 0 then the operation failed */

    if (mode == 1)
    {
        while (1)
        {
            if (mpz_cmp_d(n, (double)1) == 0)
            {
                break;
            }

            if (mpz_divisible_ui_p(n, (unsigned long)2) != 0)
            {
                mpz_div_ui(n, n, 2);
                mpz_out_str(stdout, 10, n); 
                printf("\n");
            }

            else
            {
                mpz_mul_ui(n, n, 3);
                mpz_add_ui(n, n, 1);
                mpz_out_str(stdout, 10, n);
                printf("\n");
            }
        }

        printf("We came to the loop! Number n at start was: %s, now is: ", argv[1]);
        mpz_out_str(stdout, 10, n); 
        printf(".\n");
    }

    else if (mode == 2)
    {
        while (1)
        {
            if (mpz_cmp_d(n, (double)1) == 0)
            {
                break;
            }

            if (mpz_divisible_ui_p(n, (unsigned long)2) != 0)
            {
                mpz_div_ui(n, n, 2);
                mpz_out_str(stdout, 10, n);
                printf("\n");
            }

            else
            {
                mpz_mul_ui(n, n, 3);
                mpz_add_ui(n, n, 1);
                mpz_out_str(stdout, 10, n);
                printf("\n");
            }

            if (mpz_cmp(n, max) > 0)
            {
                mpz_set(max, n);
            }

            mpz_set(previous, n);
        }
        
        printf("We came to the loop! Number n at start was: %s, now is: ", argv[1]);
        mpz_out_str(stdout, 10, n);
        printf(". Max is: ");
        mpz_out_str(stdout, 10, max);
        printf(".\n");
    }

    else
    {
        printf("Invalid mode\n");
        return 0;
    }

    /* Clean up the mpz_t handles or else we will leak memory */
    mpz_clear(n);

    return 0;
}
