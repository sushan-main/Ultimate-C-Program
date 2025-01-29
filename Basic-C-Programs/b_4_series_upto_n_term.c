#include <stdio.h>
#include <math.h>

int series_upto_n_term()
{
    char b_4;
    int n, ret_b4;
    do
    {
        system("cls");
        printf("\nEnter the value of n: ");
        scanf("%d", &n);
        if (n >= 1)
        {
            printf("\nChoose Series upto n below:\n");
            ret_b4 = series_decider(1, n, 1);
            if (ret_b4 == 99)
                break;
        }
        else
        {
            printf("Please enter a positive integer.\n");
        }
        printf("\nPress Any Key to Continue...\n");
        getch();
    } while (ret_b4 == 455);
}