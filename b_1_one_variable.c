#include <stdio.h>
#include <math.h>

void one_variable_basic_c_problems()
{
    char b_1;
    int n;
    do
    {
        printf("\nEnter the value of n: ");
        scanf("%d", &n);
        printf("\n1. Check Whether a Number is Positive, Negative, or Zero\n");
        printf("2. Check Whether Number is Even or Odd\n");
        printf("3. Find Factorial of a Number\n");
        printf("4. Find length of a Number and Sum of all its digits\n");
        printf("5. Check Armstrong Number or not\n");
        printf("6. Reverse a Number\n");
        printf("7. Check Whether a Number is a Palindrome or Not\n");
        printf("8. Check Whether a Number is Prime or Not\n");
        printf("9. Find All Factors of a Natural Number\n");
        printf("U. Update new value of n\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        do
        {
            fflush(stdin);
            printf("\n>>  ");
            scanf("%c", &b_1);
            switch (b_1)
            {
            case '1':
                positive_negative_or_zero(n);
                break;
            case '2':
                odd_or_even(n);
                break;
            case '3':
                printf("\nFactorial of %d = %d\n", n, factorial_using_recursion(n));
                break;
            case '4':
                printf("\nLength of %d is %d and sum of its digits is %d\n", n, length_of_number(n), sum_of_digits_of_no(n));
                break;
            case '5':
                if (n == check_armstrong_no(n))
                    printf("\n%d is Armstring no.\n", n);
                else
                    printf("\n%d is not Armstring no.\n", n);
                break;
            case '6':
                printf("\nReverse of %d = %d\n", n, reverse_no(n));
                break;
            case '7':
                if (n == reverse_no(n))
                    printf("\n%d is a Palindrome no.\n", n);
                else
                    printf("\n%d is not a Palindrome no.\n", n);
                break;
            case '8':
                if (check_prime_no_or_not(n))
                    printf("\n%d is a Prime no.\n", n);
                else
                    printf("\n%d is not a Prime no.\n", n);
                break;
            case '9':
                printf("\nThe Factors of %d are: \n", n);
                print_factors(n);
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
            getch();
        } while (b_1 != '0' && b_1 != 'u' && b_1 != 'U');
    } while (b_1 != '0');
}