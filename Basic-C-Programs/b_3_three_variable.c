#include <stdio.h>
#include <math.h>

void three_variable_basic_c_problems()
{
    char b_3;
    int a, b, c;
    do
    {
        system("cls");
        printf("\nEnter First Variable: ");
        scanf("%d", &a);
        printf("Enter Second Variable: ");
        scanf("%d", &b);
        printf("Enter Third Variable: ");
        scanf("%d", &c);
        printf("\n1. Find Greatest Among Three Numbers\n");
        printf("2. Find Smallest Among Three Numbers\n");
        printf("3. Find Middle Among Three Numbers\n");
        printf("4. Sum of Three Numbers\n");
        printf("5. Product of Three Numbers\n");
        printf("6. Swap Three Numbers (Clockwise)\n");
        printf("7. Swap Three Numbers (Anti-Clockwise)\n");
        printf("U. Update new variables\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        do
        {
            fflush(stdin);
            printf("\n>>  ");
            scanf("%c", &b_3);
            switch (b_3)
            {
            case '1':
                printf("\nThe Greatest Number among %d, %d and %d is %d\n", a, b, c, gr_three_no(a, b, c));
                break;
            case '2':
                printf("\nThe Smallest Number among %d, %d and %d is %d\n", a, b, c, sm_three_no(a, b, c));
                break;
            case '3':
                printf("\nThe Middle Number among %d, %d and %d is %d\n", a, b, c, mid_three_no(a, b, c));
                break;
            case '4':
                printf("\nThe Sum of %d, %d and %d is %d\n", a, b, c, sum_three_no(a, b, c));
                break;
            case '5':
                printf("\nThe Product of %d, %d and %d is %d\n", a, b, c, product_three_no(a, b, c));
                break;
            case '6':
                printf("\nBefore Swapping:\nHere a = %d, b = %d and c = %d\n", a, b, c);
                swap_3_cw(&a, &b, &c);
                printf("\nClockwise Swap Completed:\nNow a = %d, b = %d and c = %d\n", a, b, c);
                break;
            case '7':
                printf("\nBefore Swapping:\nHere a = %d, b = %d and c = %d\n", a, b, c);
                swap_3_acw(&a, &b, &c);
                printf("\nAnti-Clockwise Swap Completed:\nNow a = %d, b = %d and c = %d\n", a, b, c);
                break;
            case '0':
                printf("Returning to sub menu... Press any key to continue\n");
                continue;
                break;
            case 'u':
            case 'U':
                printf("Press any key to continue and update the variable...\n");
                getch();
                continue;
                break;
            case 'x':
            case 'X':
                printf("\nShutting down...\n");
                exit(1);
                break;
            default:
                printf("Input Error!!\n");
                break;
            }
        } while (b_3 != '0' && b_3 != 'u' && b_3 != 'U');
        printf("\nPress Any Key to Continue...\n");
        getch();
    } while (b_3 != '0');
}