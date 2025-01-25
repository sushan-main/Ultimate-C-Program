#include <stdio.h>
#include <math.h>

int series_upto_nth_term()
{
    char b_5;
    int n, ret_b5;
    do
    {
        ret_b5 = 0;
        printf("\nEnter the value of n: ");
        scanf("%d", &n);
        if (n >= 1)
        {
            printf("\nChoose Series upto n below:\n");
            ret_b5 = series_decider(1, n, 0);
            if (ret_b5 == 99)
                break;
        }
        else
        {
            printf("Please enter a positive integer.\n");
        }
    } while (ret_b5 == 455);
}