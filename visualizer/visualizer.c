/**
 * @author Andrej Bartulin
 * PROJECT: 3x
 * LICENSE: Public Domain
 * DESCRIPTION: Main for ascii visualizer
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "gmp.h"

#define STEP 3 /* how many lines to be between numbers */

typedef struct 
{
    int *array;
    size_t used;
    size_t size;
} c_vector;

void InitArray(c_vector *a, size_t initialSize) 
{
    a->array = malloc(initialSize * sizeof(int));
    a->used = 0;
    a->size = initialSize;
}

void InsertInArray(c_vector *a, int element) 
{
    // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
    // Therefore a->used can go up to a->size 
    if (a->used == a->size) 
    {
        a->size *= 2;
        a->array = realloc(a->array, a->size * sizeof(int));
    }
    a->array[a->used++] = element;
}

void FreeArray(c_vector *a) 
{
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void Draw(c_vector array, int number)
{
    if (number == 1)
    {
        /* draw rectangle */
        return;
    }

    if (number == array.array[number])
    {
        printf("%d", number);
    }
}

int main(int argc, const char *argv[])
{
    int mode;

    if (argc != 3)
    {
        printf("Usage: %s <mode> <number>\n", argv[0]);
        return 0;
    }

    mode = atoi(argv[1]);

    c_vector numbers;
    InitArray(&numbers, 1);
    InsertInArray(&numbers, atoi(argv[2]));


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
            }

            else
            {
                mpz_mul_ui(n, n, 3);
                mpz_add_ui(n, n, 1);
            }

            InsertInArray(&numbers, (int)mpz_get_ui(n));
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
            }

            else
            {
                mpz_mul_ui(n, n, 3);
                mpz_add_ui(n, n, 1);
            }

            if (mpz_cmp(n, max) > 0)
            {
                mpz_set(max, n);
            }

            mpz_set(previous, n);
            InsertInArray(&numbers, (int)mpz_get_ui(n));
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

    printf("Size of array is: %ld\n", numbers.used);  // print number of elements

    for (size_t i = 0; i < numbers.used; i++)
    {
        Draw(numbers, numbers.array[i]);
        printf("Element: %ld is: %d\n", i, numbers.array[i]);
    }

    FreeArray(&numbers);

    return 0;
}
