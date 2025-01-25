// From One Variable
void positive_negative_or_zero(int n)
{
    if (n > 0)
        printf("\n%d is Positive.\n", n);
    else if (n == 0)
        printf("\n%d is Zero.\n", n);
    else
        printf("\n%d is Negative.\n", n);
}
void odd_or_even(int n)
{
    if (n % 2 == 0)
        printf("\n%d is Even.\n", n);
    else
        printf("\n%d is Odd.\n", n);
}
int isOdd(int num) 
{
    return num % 2 != 0;
}
int isEven(int num) 
{
    return num % 2 == 0;
}
int factorial_using_recursion(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial_using_recursion(n - 1);
}
int length_of_number(int n)
{
    int length = 0;
    while (n != 0)
    {
        n /= 10;
        length++;
    }
    return length;
}
int sum_of_digits_of_no(int n)
{
    int rem, sum = 0, len = length_of_number(n);
    while (n != 0)
    {
        rem = n % 10;
        sum += rem;
        n /= 10;
    }
    return sum;
}
int check_armstrong_no(int n)
{
    int n1 = n;
    int rem, length = length_of_number(n), arm = 0;
    while (n1 != 0)
    {
        rem = n1 % 10;
        arm += (float)pow(rem, length);
        n1 /= 10;
    }
    return arm;
}
int is_armstrong(int n){
    if (n==check_armstrong_no(n))
        return 1;
    else
        return 0;
    
}
int reverse_no(int n)
{
    int rev_num = 0;
    while (n != 0)
    {
        rev_num = rev_num * 10 + n % 10;
        n /= 10;
    }
    return rev_num;
}
int is_palindrome(int n){
    if (n==reverse_no(n))
        return 1;
    else
        return 0;
}
int check_prime_no_or_not(int n)
{
    int i, count = 0;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
            count++;
    }
    if (count == 2)
        return 1;
    else
        return 0;
}
void print_factors(int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
            printf("%d ", i);
    }
    printf("\n");
}

// From Two Variables
int gr_among_two_no(int x, int y)
{
    return (x > y) ? x : y;
}
int sm_among_two_no(int x, int y)
{
    return (x > y) ? y : x;
}
int sum_two_no(int x, int y)
{
    return x + y;
}
int abs_diff_two_no(int x, int y)
{
    if (x > y)
        return x - y;
    else
        return y - x;
}
int pr_two_no(int x, int y)
{
    return x * y;
}
int y_raised_to_the_power_of_x(int x, int y)
{
    int i, ans = 1;
    for (i = 0; i < y; i++)
    {
        ans *= x;
    }
    return ans;
}
int lcm_two_no(int n1, int n2)
{
    int max, lcm;
    max = (n1 > n2) ? n1 : n2;
    lcm = max;
    while ((lcm % n1 != 0) || (lcm % n2 != 0))
    {
        lcm += max;
    }
    return lcm;
    // lcm * hcf = n1 * n2
}
int hcf_two_no(int n1, int n2)
{
    int i, min, hcf;
    min = (n1 < n2) ? n1 : n2;
    for (i = 1; i <= min; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            hcf = i;
        }
    }
    return hcf;
    // lcm * hcf = n1 * n2
}
void swap_two_no(int *pa, int *pb)
{
    *pa = *pa + *pb;
    *pb = *pa - *pb;
    *pa = *pa - *pb;
}

// From Three Variables
int gr_three_no(int x, int y, int z)
{
    return ((x > y && x > z) ? x : (y > z) ? y : z);
}
int sm_three_no(int x, int y, int z)
{
    return ((x < y && x < z) ? x : (y < z) ? y : z);
}
int mid_three_no(int x, int y, int z)
{
    if ((x > y && x < z) || (x < y && x > z))
        return x;
    else if ((y > x && y < z) || (y < x && y > z))
        return y;
    else
        return z;    
}
int sum_three_no(int x, int y, int z)
{
    return x + y + z;
}
int product_three_no(int x, int y, int z)
{
    return x * y * z;
}
void swap_3_cw(int *x, int *y, int *z)
{
    int temp = *z;
    *z = *y;
    *y = *x;
    *x = temp;
}
void swap_3_acw(int *x, int *y, int *z)
{
    int temp = *x;
    *x = *y;
    *y = *z;
    *z = temp;
}