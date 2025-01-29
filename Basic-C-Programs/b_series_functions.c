#include <stdio.h>

int sum_print_prime_series(int first_term, int n, int upto_n)
{
    int sum = 0;
    if (upto_n)
    {
        int i;
        if (first_term == 1)
            printf("\nPrime numbers up to %d are:\n", n);
        else
            printf("\nPrime numbers from %d to %d are:\n", first_term, n);
        for (i = first_term; i <= n; i++)
        {
            if (check_prime_no_or_not(i))
            {
                printf("%d ", i);
                sum += i;
            }
        }
    }
    else
    {
        printf("\nFirst %d Prime numbers are:\n", n);
        int count = 0;
        int num = 2;
        while (count < n)
        {
            if (check_prime_no_or_not(num))
            {
                printf("%d ", num);
                count++;
                sum += num;
            }
            num++;
        }
    }
    printf("\n");
    return sum;
}
int sum_print_palindrome_series(int first_term, int n, int upto_n)
{
    int sum = 0;
    if (upto_n)
    {
        int i;
        if (first_term == 1)
            printf("\nPalindrome numbers up to %d are:\n", n);
        else
            printf("\nPalindrome numbers from %d to %d are:\n", first_term, n);
        for (i = first_term; i <= n; i++)
        {
            if (is_palindrome(i))
            {
                printf("%d ", i);
                sum += i;
            }
        }
    }
    else
    {
        printf("\nFirst %d Palindrome numbers are:\n", n);
        int count = 0;
        int num = 1;
        while (count < n)
        {
            if (is_palindrome(num))
            {
                printf("%d ", num);
                count++;
                sum += num;
            }
            num++;
        }
    }
    printf("\n");
    return sum;
}
int sum_print_armstrong_series(int first_term, int n, int upto_n)
{
    int sum = 0;
    if (upto_n)
    {
        int i;
        if (first_term == 1)
            printf("\nArmstrong numbers up to %d are:\n", n);
        else
            printf("\nArmstrong numbers from %d to %d are:\n", first_term, n);
        for (i = first_term; i <= n; i++)
        {
            if (is_armstrong(i))
            {
                printf("%d ", i);
                sum += i;
            }
        }
    }
    else
    {
        printf("\nFirst %d Armstrong numbers are:\n", n);
        int count = 0;
        int num = 1;
        while (count < n)
        {
            if (is_armstrong(num))
            {
                printf("%d ", num);
                count++;
                sum += num;
            }
            num++;
        }
    }
    printf("\n");
    return sum;
}
int sum_print_fibonacci_series(int first_term, int n, int upto_n)
{
    int sum = 0, sum1 = 0;
    int a = 0, b = 1, c;
    if (upto_n)
    {
        if (first_term == 1)
            printf("\nFibonacci series up to %d are:\n", n);
        else
            printf("\nFibonacci series from %d to %d are:\n", first_term, n);
        // Skip Fibonacci numbers below the range
        while (a < first_term)
        {
            c = a + b;
            a = b;
            b = c;
            sum1 += b;
        }
        // Print Fibonacci numbers within the range
        while (a <= n)
        {
            printf("%d ", a);
            sum += a;
            c = a + b;
            a = b;
            b = c;
        }
    }
    else
    {
        printf("\nFirst %d terms of the Fibonacci series are:\n", n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a);
            sum += a;
            int temp = a;
            a = b;
            b = temp + b;
        }
    }
    printf("\n");
    return sum;
}
int sum_print_square_series(int first_term, int n, int upto_n)
{
    int sum = 0;
    if (upto_n)
    {
        if (first_term == 1)
            printf("\nSquare numbers up to %d are:\n", n);
        else
            printf("\nSquare numbers from %d to %d are:\n", first_term, n);
        for (int i = 1; pow(i, 2) <= n; i++)
        {
            if (first_term <= pow(i, 2))
            {
                printf("%.0f ", (float)pow(i, 2));
                sum += (float)pow(i, 2);
            }
        }
    }
    else
    {
        printf("\nFirst %d Square numbers are:\n", n);
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", (int)pow(i, 2));
            sum += (float)pow(i, 2);
        }
    }
    printf("\n");
    return sum;
}
int sum_print_cube_series(int first_term, int n, int upto_n)
{
    int sum = 0;
    if (upto_n)
    {
        if (first_term == 1)
            printf("\nCube numbers up to %d are:\n", n);
        else
            printf("\nCube numbers from %d to %d are:\n", first_term, n);
        for (int i = 1; pow(i, 3) <= n; i++)
        {
            if (first_term <= pow(i, 3))
            {
                printf("%.0f ", (float)pow(i, 3));
                sum += (float)pow(i, 3);
            }
        }
    }
    else
    {
        printf("\nFirst %d Cube numbers are:\n", n);
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", (int)pow(i, 3));
            sum += (float)pow(i, 3);
        }
    }
    printf("\n");
    return sum;
}
int sum_print_odd_series(int first_term, int n, int upto_n)
{
    int sum = 0;
    if (upto_n)
    {
        int i;
        if (first_term == 1)
            printf("\nOdd numbers up to %d are:\n", n);
        else
            printf("\nOdd numbers from %d to %d are:\n", first_term, n);
        for (i = first_term; i <= n; i++)
        {
            if (isOdd(i))
            {
                printf("%d ", i);
                sum += i;
            }
        }
    }
    else
    {
        printf("\nFirst %d Odd numbers are:\n", n);
        int count = 0;
        int i = first_term;
        while (count < n)
        {
            if (isOdd(i))
            {
                printf("%d ", i);
                count++;
                sum += i;
            }
            i++;
        }
    }
    printf("\n");
    return sum;
}
int sum_print_even_series(int first_term, int n, int upto_n)
{
    int sum = 0;
    if (upto_n)
    {
        int i;
        if (first_term == 1)
            printf("\nEven numbers up to %d are:\n", n);
        else
            printf("\nEven numbers from %d to %d are:\n", first_term, n);
        for (i = first_term; i <= n; i++)
        {
            if (isEven(i))
            {
                printf("%d ", i);
                sum += i;
            }
        }
    }
    else
    {
        printf("\nFirst %d Even numbers are:\n", n);
        int count = 0;
        int i = first_term;
        while (count < n)
        {
            if (isEven(i))
            {
                printf("%d ", i);
                count++;
                sum += i;
            }
            i++;
        }
    }
    printf("\n");
    return sum;
}
int sum_print_natural_no(int first_term, int n)
{
    int sum = 0;
    int i;
    if (first_term == 1)
        printf("\nNatural numbers up to %d are:\n", n);
    else
        printf("\nNatural numbers from %d to %d are:\n", first_term, n);
    for (i = first_term; i <= n; i++)
    {
        printf("%d ", i);
        sum += i;
    }
    printf("\n");
    return sum;
}

int series_decider(int first_term, int n, int upto_n)
{
    char b_choice[3];
    int sum_of_series;
    printf("1. Natural Numbers\n");
    printf("2. Odd Numbers\n");
    printf("3. Even Numbers\n");
    printf("4. Square Numbers\n");
    printf("5. Cube Numbers\n");
    printf("6. Prime Numbers\n");
    printf("7. Armstrong Number\n");
    printf("8. Palindrome Number\n");
    printf("9. Fibonacci Series\n");
    printf("U. Update New Value of N or Range\n");
    printf("0. Return Back\n");
    printf("x. Terminate Process\n");
    printf("(To Find Sum of Series Also, Type s after options. Eg. 1s)\n");
    do
    {
        fflush(stdin);
        printf("\n>>  ");
        scanf("%s", &b_choice);
        switch (b_choice[0])
        {
        case '1':
            sum_of_series = sum_print_natural_no(first_term, n);
            break;
        case '2':
            sum_of_series = sum_print_odd_series(first_term, n, upto_n);
            break;
        case '3':
            sum_of_series = sum_print_even_series(first_term, n, upto_n);
            break;
        case '4':
            sum_of_series = sum_print_square_series(first_term, n, upto_n);
            break;
        case '5':
            sum_of_series = sum_print_cube_series(first_term, n, upto_n);
            break;
        case '6':
            sum_of_series = sum_print_prime_series(first_term, n, upto_n);
            break;
        case '7':
            sum_of_series = sum_print_armstrong_series(first_term, n, upto_n);
            break;
        case '8':
            sum_of_series = sum_print_palindrome_series(first_term, n, upto_n);
            break;
        case '9':
            sum_of_series = sum_print_fibonacci_series(first_term, n, upto_n);
            break;
        case '0':
            printf("Returning to sub menu... Press any key to continue\n");
            return 99;
            break;
        case 'u':
        case 'U':
            printf("Press any key to continue and update the variable...\n");
            getch();
            return 455;
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
        if (b_choice[1] == 's' || b_choice[1] == 'S')
        {
            printf("\nSum of Series = %d\n", sum_of_series);
        }
    } while (b_choice[1] != '0' && b_choice[1] != 'u' && b_choice[1] != 'U');
}