/**
 * @author Andrej Bartulin
 * PROJECT: 3x
 * LICENSE: Public Domain
 * DESCRIPTION: Main file for C version
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <inttypes.h>

int main(int argc, char **argv)
{
    int mode = 1;

    int64_t previous = 0;
    static int64_t max = 0;
    static int64_t starter = 0;
    int64_t n = 0;

    #define print printf("%"PRId64"\n", n);

    if (argc != 3)
    {
        printf("Argument error!\nEnter mode (1 - without max number, 2 - which max number): ");
        scanf("%d", &mode);

        printf("Enter number: ");
        scanf("%"PRId64"", &n);
        printf("Starter number: \t%"PRId64"\t\n", n);
    }

    else
    {
        mode = atoi(argv[1]);
        n = atoi(argv[2]);
        printf("Starter number: \t%"PRId64"\t\n", n);
    }

    max = n;
    starter = n;

    printf("I need to use variable. %"PRId64".\n", previous);

    if (mode == 1)
    {
        while (1)
        {
            if (n == 1)
            {
                break;
            }

            if (n % 2 == 0)
            {
                n /= 2;
                print
            }

            else
            {
                n *= 3;
                n++;
                print
            }
        }

        printf("We came to the loop. Number n at start was: %"PRId64", now is: %"PRId64".\n", starter, n);
    }

    else if (mode == 2)
    {
        while (1)
        {
            if (n == 1)
            {
                break;
            }

            if (n % 2 == 0)
            {
                n /= 2;
                print
            }

            else
            {
                n *= 3;
                n++;
                print
            }

            if (n > max)
            {
                max = n;
            }

            previous = n;
        }

        printf("We came to the loop. Number n at start was: %"PRId64", now is: %"PRId64". Max is: %"PRId64".\n", starter, n, max);
    }

    else
    {
        printf("Wrong mode %d! Exiting with value 1...", mode);
        return 1;
    }
    
    return 0;
}
