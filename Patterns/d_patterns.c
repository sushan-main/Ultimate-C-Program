#include <stdio.h>

// Function to print a right-half pyramid pattern
void print_right_half_pyramid(int n, char type)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            switch (type)
            {
            case '*':
                printf("* ");
                break;
            case '1':
                printf("%d ", j + 1);
                break;
            case 'A':
            case 'a':
                printf("%c ", j + 'A');
                break;
            default:
                printf("Invalid type\n");
                return;
            }
        }
        printf("\n");
    }
}

// Function to print an inverted right-half pyramid pattern
void print_inverted_right_half_pyramid(int n, char type)
{
    int i, j;
    for (i = n; i >= 1; --i)
    {
        for (j = 1; j <= i; ++j)
        {
            switch (type)
            {
            case '*':
                printf("* ");
                break;
            case '1':
                printf("%d ", j);
                break;
            case 'A':
            case 'a':
                printf("%c ", 'A' + j - 1);
                break;
            default:
                printf("Invalid type\n");
                return;
            }
        }
        printf("\n");
    }
}

// Function to print a left-half pyramid pattern
void print_left_half_pyramid(int n, char type)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2 * (n - i - 1); j++)
            printf(" ");

        for (k = 0; k <= i; k++)
        {
            switch (type)
            {
            case '*':
                printf("* ");
                break;
            case '1':
                printf("%d ", k + 1);
                break;
            case 'A':
            case 'a':
                printf("%c ", k + 'A');
                break;
            default:
                printf("Invalid type\n");
                return;
            }
        }
        printf("\n");
    }
}

// Function to print an inverted left-half pyramid pattern
void print_inverted_left_half_pyramid(int n, char type)
{
    int i, j, k;
    for (i = n; i >= 1; --i)
    {
        for (k = 1; k <= (n - i); k++)
            printf("  ");

        for (j = 1; j <= i; ++j)
        {
            switch (type)
            {
            case '*':
                printf("* ");
                break;
            case '1':
                printf("%d ", j);
                break;
            case 'A':
            case 'a':
                printf("%c ", 'A' + j - 1);
                break;
            default:
                printf("Invalid type\n");
                return;
            }
        }
        printf("\n");
    }
}

// Function to print a full pyramid pattern
void print_full_pyramid(int n, char type)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2 * (n - i - 1); j++)
            printf(" ");

        for (k = 0; k < 2 * i + 1; k++)
        {
            switch (type)
            {
            case '*':
                printf("* ");
                break;
            case '1':
                printf("%d ", k + 1);
                break;
            case 'A':
            case 'a':
                printf("%c ", k + 'A');
                break;
            default:
                printf("Invalid type\n");
                return;
            }
        }
        printf("\n");
    }
}

// Function to print an inverted full pyramid pattern
void print_inverted_full_pyramid(int n, char type)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 2 * i; j++)
        {
            printf(" ");
        }
        for (k = 0; k < 2 * (n - i) - 1; k++)
        {
            switch (type)
            {
            case '*':
                printf("* ");
                break;
            case '1':
                printf("%d ", k + 1);
                break;
            case 'A':
            case 'a':
                printf("%c ", k + 'A');
                break;
            default:
                printf("Invalid type\n");
                return;
            }
        }
        printf("\n");
    }
}

int patterns_in_c()
{
    int n;
    char type, choice;
    do
    {
        printf("\nD] Choose a pattern:\n");
        printf("1. Right Half Pyramid\n");
        printf("2. Inverted Right Half Pyramid\n");
        printf("3. Left Half Pyramid\n");
        printf("4. Inverted Left Half Pyramid\n");
        printf("5. Full Pyramid\n");
        printf("6. Inverted Full Pyramid\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("\nEnter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);
        if (choice == '0')
        {
            printf("Returning to main menu... Press any key to continue\n");
            getch();
            continue;
        }
        if (choice == 'x')
        {
            printf("\nShutting down...\n");
            exit(1);
        }
        printf("Enter the type (*, 1 or A): ");
        fflush(stdin);
        scanf(" %c", &type);
        printf("\nEnter the number of rows: ");
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("\nPlease enter a positive integer.\n");
            continue;
        }
        switch (choice)
        {
        case '1':
            print_right_half_pyramid(n, type);
            break;
        case '2':
            print_inverted_right_half_pyramid(n, type);
            break;
        case '3':
            print_left_half_pyramid(n, type);
            break;
        case '4':
            print_inverted_left_half_pyramid(n, type);
            break;
        case '5':
            print_full_pyramid(n, type);
            break;
        case '6':
            print_inverted_full_pyramid(n, type);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
        getch();
    } while (choice != '0');
}