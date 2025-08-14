/**
 * @author Andrej Bartulin
 * PROJECT: 3x
 * LICENSE: GPL-2.0 license
 * DESCRIPTION: Main file for C version
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <assert.h>
#include <inttypes.h>

#include "gmp.h"

int main(int argc, const char *argv[])
{
    uint8_t mode;

    /* ------------------------------------------ */
    /*              Check arguments               */
    /* ------------------------------------------ */
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
    mpz_t n, start, max;
    int flag;

    /* ------------------------------------------ */
    /*          Initialize the numbers            */
    /* ------------------------------------------ */

    mpz_init(n);
    mpz_init(start);
    mpz_init(max);

    /* ------------------------------------------ */
    /*         Assign values to the numbers       */
    /* ------------------------------------------ */

    flag = mpz_set_str(n, argv[2], 10);
    assert (flag == 0); // If flag is not 0 then the operation failed

    flag = mpz_set_str(start, argv[2], 10);
    assert (flag == 0); // If flag is not 0 then the operation failed

    flag = mpz_set_str(max, argv[2], 10);
    assert (flag == 0); // If flag is not 0 then the operation failed

    /* ------------------------------------------ */
    /*                Main loop                   */
    /* ------------------------------------------ */

    while (1)
    {
        if (mpz_cmp_si(n, 0) == 0 || mpz_cmp_si(n, 1) == 0)
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

        if (mode == 2)
        {
            if (mpz_cmp(n, max) > 0)
            {
                mpz_set(max, n);
            }
        }
    }

    /* ------------------------------------------ */
    /*              Print the results             */
    /* ------------------------------------------ */

    printf("We came to the loop!\n");
    gmp_printf("Start: '%Zd', end: '%Zd', max: '%Zd'.\n", start, n, max);

    /* ------------------------------------------ */
    /*              Free the numbers              */
    /* ------------------------------------------ */

    mpz_clear(n);
    mpz_clear(start);
    mpz_clear(max);

    return 0;
}
