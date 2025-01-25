#include <stdio.h>
#include <math.h>

int series_from_n1_to_n2_term()
{
    char b_6;
    int first_term, n, ret_b6;
    do
    {
        ret_b6 = 0;
        printf("\nEnter \"From\" and \"To\"\n");
        printf("Starting Number--> ");
        scanf("%d", &first_term);
        printf("Ending Number--> ");
        scanf("%d", &n);

        if (n >= 1)
        {
            printf("\nChoose Series upto n below:\n");
            ret_b6 = series_decider(first_term, n, 1);
            if (ret_b6 == 99)
                break;
        }
        else if (first_term > n)
        {
            printf("Invalid range. Starting Number should be less than or equal to Ending Number.\n");
        }
        else
        {
            printf("Please enter a positive integer.\n");
        }
    } while (ret_b6 == 455);
}