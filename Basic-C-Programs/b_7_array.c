#include <stdio.h>
#include <math.h>
void find_largest_element(int arr[], int n)
{
    int max = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("Largest element: %d\n", max);
}

void find_smallest_element(int arr[], int n)
{
    int min = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Smallest element: %d\n", min);
}

void find_max_and_min(int arr[], int n)
{
    int max = arr[0], min = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    printf("Maximum: %d, Minimum: %d\n", max, min);
}

void search_element(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            printf("Element %d found at position %d\n", key, i + 1);
            return;
        }
    }
    printf("Element %d not found.\n", key);
}

void calculate_average(int arr[], int n)
{
    int sum = 0, i;
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    printf("Average: %.2f\n", (float)sum / n);
}

void sort_array_ascending(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort_array_descending(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Array in descending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort_strings_ascending(char arr[][50], int n)
{
    char temp[50];
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    printf("Strings in ascending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
}

void sort_strings_descending(char arr[][50], int n)
{
    char temp[50];
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i], arr[j]) < 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    printf("Strings in descending order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", arr[i]);
    }
}

void capitalize_first_letter(char str[])
{
    if (str[0] >= 'a' && str[0] <= 'z')
    {
        str[0] = str[0] - ('a' - 'A');
    }
}

void capitalize_all_letters(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A');
        }
    }
}

void reverse_string(char str[])
{
    int len = strlen(str), i;
    for (i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int is_palindrome_string(char str[])
{
    int len = strlen(str), i;
    for (i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

void convert_to_lowercase(char str[])
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
        }
    }
}

void count_characters(char str[], int *vowels, int *consonants, int *digits, int *spaces, int *specials)
{
    int i;
    *vowels = *consonants = *digits = *spaces = *specials = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            char lowerChar = (str[i] >= 'A' && str[i] <= 'Z') ? (str[i] + ('a' - 'A')) : str[i];
            if (lowerChar == 'a' || lowerChar == 'e' || lowerChar == 'i' || lowerChar == 'o' || lowerChar == 'u')
            {
                (*vowels)++;
            }
            else
            {
                (*consonants)++;
            }
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            (*digits)++;
        }
        else if (str[i] == ' ')
        {
            (*spaces)++;
        }
        else
        {
            (*specials)++;
        }
    }
}
int array_main()
{
    int n, arr[50], i, key;
    char str[50], strArr[50][50];
    char choice, sub_choice;
checkpoint_b7:
    printf("\nHere are some of the sorting C programs.\n");
    printf("1. Integer Array\n");
    printf("\ta. Find the Largest Element in an Array\n");
    printf("\tb. Find the Smallest Element in an Array\n");
    printf("\tc. Find the Maximum and Minimum in an Array\n");
    printf("\td. Search an Element in an Array\n");
    printf("\te. Calculate the Average of All the Elements Present in an Array\n");
    printf("\tf. Sort the Elements of an Array in Ascending Order\n");
    printf("\tg. Sort the Elements of an Array in Descending Order\n");
    printf("2. String 1D Array\n");
    printf("\ta. Reverse a String\n");
    printf("\tb. Check if a String is a Palindrome\n");
    printf("\tc. Convert a String to Lowercase\n");
    printf("\td. Convert a String to Uppercase\n");
    printf("\te. Count Vowels, Consonants, Digits, Spaces, and Special Characters\n");
    printf("3. String 2D Array\n");
    printf("\ta. Sort the Strings in Ascending Order\n");
    printf("\tb. Sort the Strings in Descending Order\n");
    printf("\tc. Capitalize the First Letter of Each String\n");
    printf("\td. Concatenate All Strings with Spaces\n");
    printf("\nU. Update the Array\n");
    printf("0. Return Back\n");
    printf("x. Terminate Process\n");
    printf("\nEnter your choice: ");
    fflush(stdin);
    printf("\n>>  ");
    scanf("%c", &choice);

    if (choice == '1')
    {
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);
        printf("Enter the elements of the array:\n");
        for (i = 0; i < n; i++)
        {
            printf("Enter Element %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
    checkpoint_b7_1:
        fflush(stdin);
        printf("\nChoose an operation (a-g): ");
        scanf("%c", &sub_choice);
        switch (sub_choice)
        {
        case 'a':
            find_largest_element(arr, n);
            break;
        case 'b':
            find_smallest_element(arr, n);
            break;
        case 'c':
            find_max_and_min(arr, n);
            break;
        case 'd':
            printf("Enter the element to search: ");
            scanf("%d", &key);
            search_element(arr, n, key);
            break;
        case 'e':
            calculate_average(arr, n);
            break;
        case 'f':
            sort_array_ascending(arr, n);
            break;
        case 'g':
            sort_array_descending(arr, n);
            break;
        case '0':
            return 99;
            break;
        case 'u':
        case 'U':
            goto checkpoint_b7;
            break;
        case 'x':
        case 'X':
            printf("\nShutting down...\n");
            exit(1);
            break;
        default:
            printf("Invalid choice!\n");
        }
        getch();
        goto checkpoint_b7_1;
    }
    else if (choice == '2')
    {
        printf("\nEnter a string: ");
        scanf(" %[^\n]s", str);
    checkpoint_b7_2:
        printf("\nChoose an operation (a-e): ");
        fflush(stdin);
        scanf("%c", &sub_choice);
        switch (sub_choice)
        {
        case 'a':
            reverse_string(str);
            printf("Reversed string: %s\n", str);
            break;
        case 'b':
            if (is_palindrome_string(str))
                printf("The string is a palindrome.\n");
            else
                printf("The string is not a palindrome.\n");
            break;
        case 'c':
            convert_to_lowercase(str);
            printf("String in lowercase: %s\n", str);
            break;
        case 'd':
            capitalize_all_letters(str);
            printf("String in uppercase: %s\n", str);
            break;
        case 'e':
        {
            int vowels = 0, consonants = 0, digits = 0, spaces = 0, specials = 0;
            count_characters(str, &vowels, &consonants, &digits, &spaces, &specials);
            printf("Vowels: %d, Consonants: %d, Digits: %d, Spaces: %d, Special Characters: %d\n", vowels, consonants, digits, spaces, specials);
            break;
        }
        case '0':
            return 99;
            break;
        case 'u':
        case 'U':
            goto checkpoint_b7;
            break;
        case 'x':
        case 'X':
            printf("\nShutting down...\n");
            exit(1);
            break;
        default:
            printf("Invalid choice!\n");
        }
        getch();
        goto checkpoint_b7_2;
    }
    else if (choice == '3')
    {
        printf("\nEnter the number of strings: ");
        scanf("%d", &n);
        fflush(stdin);
        printf("Enter the strings:\n");
        for (i = 0; i < n; i++)
        {
            printf("Enter String %d: ", i + 1);
            gets(strArr[i]);
        }
    checkpoint_b7_3:
        fflush(stdin);
        printf("\nChoose an operation (a-d): ");
        scanf("%c", &sub_choice);
        switch (sub_choice)
        {
        case 'a':
            sort_strings_ascending(strArr, n);
            break;
        case 'b':
            sort_strings_descending(strArr, n);
            break;
        case 'c':
            for (i = 0; i < n; i++)
            {
                capitalize_first_letter(strArr[i]);
            }
            printf("Strings with first letters capitalized:\n");
            for (i = 0; i < n; i++)
            {
                printf("%s\n", strArr[i]);
            }
            break;
        case 'd': ;
            char concatenated[50 * 50] = "";
            for (i = 0; i < n; i++)
            {
                strcat(concatenated, strArr[i]);
                if (i < n - 1)
                {
                    strcat(concatenated, " ");
                }
            }
            printf("Concatenated string: %s\n", concatenated);
            break;
        case '0':
            return 99;
            break;
        case 'u':
        case 'U':
            goto checkpoint_b7;
            break;
        case 'x':
        case 'X':
            printf("\nShutting down...\n");
            exit(1);
            break;
        default:
            printf("Invalid choice!\n");
        }
        getch();
        goto checkpoint_b7_3;
    }
    else if (choice == 'x' || choice == 'X')
    {
        printf("\nShutting down...\n");
        exit(1);
    }
    else if (choice == '0')
        return 99;
    else
        printf("Invalid choice!\n");
    getch();
}