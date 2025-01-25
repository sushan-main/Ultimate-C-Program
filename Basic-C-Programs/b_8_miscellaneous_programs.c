#include <stdio.h>
void print_table(int range, int num)
{
    for (int i = 1; i <= range; i++)
    {
        printf("%d * %d = %d\n", num, i, num * i);
    }
}
void simple_calculator()
{
    char operator;
    double num1, num2;
    printf("\nEnter operator (+, -, *, /): ");
    scanf(" %c", &operator);
    printf("Enter First Operands: ");
    scanf("%lf", &num1);
    printf("Enter Second Operands: ");
    scanf("%lf", &num2);
    switch (operator)
    {
    case '+':
        printf("\n%.2lf + %.2lf = %.2lf\n", num1, num2, num1 + num2);
        break;
    case '-':
        printf("\n%.2lf - %.2lf = %.2lf\n", num1, num2, num1 - num2);
        break;
    case '*':
        printf("\n%.2lf * %.2lf = %.2lf\n", num1, num2, num1 * num2);
        break;
    case '/':
        if (num2 == 0)
            printf("\nError: Division by zero!\n");
        else
            printf("\n%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
        break;
    default:
        printf("Error: Invalid operator!\n");
    }
}
void find_roots(int a, int b, int c)
{
    if (a == 0)
    {
        printf("Invalid\n");
        return;
    }
    int d = b * b - 4 * a * c;
    double sqrt_val = sqrt(abs(d));
    if (d > 0)
    {
        printf("Roots are real and unequal. They are:\n");
        printf("%.4f\n%.4f\n", (double)(-b + sqrt_val) / (2 * a), (double)(-b - sqrt_val) / (2 * a));
    }
    else if (d == 0)
    {
        printf("Roots are real and equal. They are:\n");
        printf("%.4f\n", -(double)b / (2 * a));
        printf("%.4f\n", -(double)b / (2 * a));
    }
    else
    {
        printf("Roots are complex. They are:\n");
        printf("%f + i%f\n%f - i%f\n", -(double)b / (2 * a), sqrt_val / (2 * a), -(double)b / (2 * a), sqrt_val / (2 * a));
    }
}

int check_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

void find_quotient_remainder()
{
    int A, B, quotient, remainder;
    printf("\nEnter two integers (A and B): ");
    scanf("%d %d", &A, &B);
    if (B == 0)
    {
        printf("\nDivision by zero not possible.\n");
        return;
    }
    quotient = A / B;
    remainder = A % B;
    printf("\nQuotient when A/B is: %d\n", quotient);
    printf("Remainder when A/B is: %d\n", remainder);
}

void get_initials(char *name)
{
    int i = 0;
    if (strlen(name) > 0 && isalpha(name[0]))
    {
        printf("%c ", toupper(name[0]));
    }

    while (name[i] != '\0')
    {
        if (name[i] == ' ')
        { // Use the custom function
            while (name[i] == ' ' && i <= strlen(name))
            {
                i++;
            }
            if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z'))
            {
                printf("%c ", toupper(name[i]));
            }
        }
        i++;
    }
    printf("\n");
}

void area_perimeter()
{
    int choice;
    double radius, length, width, base, height, side;
    printf("\nCalculate Area and Perimeter:\n");
    printf("1. Circle\n");
    printf("2. Rectangle\n");
    printf("3. Triangle\n");
    printf("4. Square\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter radius: ");
        scanf("%lf", &radius);
        printf("\nArea: %.2lf\nPerimeter: %.2lf\n", (22 / 7) * radius * radius, 2 * (22 / 7) * radius);
        break;
    case 2:
        printf("Enter length: ");
        scanf("%lf", &length);
        printf("Enter width: ");
        scanf("%lf", &width);
        printf("\nArea: %.2lf\nPerimeter: %.2lf\n", length * width, 2 * (length + width));
        break;
    case 3:
        printf("Enter base: ");
        scanf("%lf", &base);
        printf("Enter height: ");
        scanf("%lf", &height);
        printf("\nArea: %.2lf\n", 0.5 * base * height);
        break;
    case 4:
        printf("Enter side: ");
        scanf("%lf", &side);
        printf("\nArea: %.2lf\nPerimeter: %.2lf\n", side * side, 4 * side);
        break;
    default:
        printf("Invalid choice.\n");
    }
}
void volume()
{
    int choice;
    double radius, side, length, width, height, volume;
    printf("\nCalculate Volume:\n");
    printf("1. Sphere\n");
    printf("2. Cube\n");
    printf("3. Cylinder\n");
    printf("4. Cone\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("Enter radius: ");
        scanf("%lf", &radius);
        volume = (4.0 / 3.0) * (22 / 7) * radius * radius * radius;
        break;
    case 2:
        printf("Enter side: ");
        scanf("%lf", &side);
        volume = side * side * side;
        break;
    case 3:
        printf("Enter radius: ");
        scanf("%lf", &radius);
        printf("Enter height: ");
        scanf("%lf", &height);
        volume = (22 / 7) * radius * radius * height;
        break;
    case 4:
        printf("Enter radius: ");
        scanf("%lf", &radius);
        printf("Enter height: ");
        scanf("%lf", &height);
        volume = (1.0 / 3.0) * (22 / 7) * radius * radius * height;
        break;
    default:
        printf("Invalid choice.\n");
    }
    printf("\nVolume: %.2lf\n", volume);
}
void miscellaneous_programs()
{
    int range, num, a, b, c, year;
    char choice, name[100];
    do
    {
        fflush(stdin);
        printf("\nChoose a C program:\n");
        printf("1. Multiplication Table\n");
        printf("2. Simple Calculator\n");
        printf("3. Solution of Quadratic Equation\n");
        printf("4. Check Leap Year\n");
        printf("5. Find Quotient and Remainder\n");
        printf("6. Find Initials of a Name\n");
        printf("7. Area and Perimeter Calculator\n");
        printf("8. Volume Calculator\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("\nEnter your choice: ");
        scanf("%c", &choice);
        switch (choice)
        {
        case '1':
            printf("\nEnter the Number for the Multiplication Table: ");
            scanf("%d", &num);
            printf("Enter the Range for the Multiplication Table: \n");
            scanf("%d", &range);
            print_table(range, num);
            break;
        case '2':
            simple_calculator();
            break;
        case '3':
            printf("\nEnter coefficients a: ");
            scanf("%d", &a);
            printf("Enter coefficients b: ");
            scanf("%d", &b);
            printf("Enter coefficients c: ");
            scanf("%d", &c);
            find_roots(a, b, c);
            break;
        case '4':
            printf("\nEnter a year: ");
            scanf("%d", &year);
            if (check_leap_year(year))
                printf("%d is a leap year.\n", year);
            else
                printf("%d is not a leap year.\n", year);
            break;
        case '5':
            find_quotient_remainder();
            break;
        case '6':
            fflush(stdin);
            printf("\nEnter a Name: ");
            scanf(" %[^\n]s", name);
            printf("The Initials of the Name is: ");
            get_initials(name);
            break;
        case '7':
            area_perimeter();
            break;
        case '8':
            volume();
            break;
        case '0':
            printf("Returning to sub menu... Press any key to continue\n");
            break;
        case 'x':
        case 'X':
            printf("\nShutting down...\n");
            exit(1);
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
        getch();
    } while (choice != '0');
}
