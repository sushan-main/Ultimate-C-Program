#include <stdio.h>
#include <math.h>

void two_variable_basic_c_problems()
{
    char b_2;
    int a, b;
    do
    {
        system("cls");
        printf("\nEnter First Variable: ");
        scanf("%d", &a);
        printf("Enter Second Variable: ");
        scanf("%d", &b);
        printf("\n1. Find Greatest Among Two Numbers\n");
        printf("2. Find Smallest Among Two Numbers\n");
        printf("3. Sum of Two Numbers\n");
        printf("4. Absolute Difference of Two Numbers\n");
        printf("5. Product of Two Numbers\n");
        printf("6. First Number raised to power of Second Number\n");
        printf("7. Second Number raised to power of First Number\n");
        printf("8. LCM and HCF of Two Numbers\n");
        printf("9. Swap Two Numbers\n");
        printf("U. Update new variables\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        do
        {
            fflush(stdin);
            printf("\n>>  ");
            scanf("%c", &b_2);
            switch (b_2)
            {
            case '1':
                printf("\nThe Greatest Number among %d and %d is %d\n", a, b, gr_among_two_no(a, b));
                break;
            case '2':
                printf("\nThe Smallest Number among %d and %d is %d\n", a, b, sm_among_two_no(a, b));
                break;
            case '3':
                printf("\nThe Sum of %d and %d is %d\n", a, b, sum_two_no(a, b));
                break;
            case '4':
                printf("\nThe Absolute Difference of %d and %d is %d\n", a, b, abs_diff_two_no(a, b));
                break;
            case '5':
                printf("\nThe Product of %d and %d is %d\n", a, b, pr_two_no(a, b));
                break;
            case '6':
                printf("\n%d raised to power of %d is %d\n", a, b, y_raised_to_the_power_of_x(b, a));
                break;
            case '7':
                printf("\n%d raised to power of %d is %d\n", b, a, y_raised_to_the_power_of_x(a, b));
                break;
            case '8':
                printf("\nThe LCM of %d and %d is %d and HCF is %d\n", a, b, lcm_two_no(a, b), hcf_two_no(a, b));
                break;
            case '9':
                swap_two_no(&a, &b);
                printf("\nSwap Completed:\nNow a = %d and b = %d\n", a, b);
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
        } while (b_2 != '0' && b_2 != 'u' && b_2 != 'U');
        printf("\nPress Any Key to Continue...\n");
        getch();
    } while (b_2 != '0');
}