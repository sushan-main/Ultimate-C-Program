#include <stdio.h>
#include "b_functions_list.c"
#include "b_series_functions.c"
#include "b_1_one_variable.c"
#include "b_2_two_variable.c"
#include "b_3_three_variable.c"
#include "b_4_series_upto_n_term.c"
#include "b_5_series_upto_nth_term.c"
#include "b_6_series_from_n1_to_n2_term.c"
#include "b_7_array.c"
#include "b_8_miscellaneous_programs.c"

void basic_c_programs()
{
    char b_main;
    do
    {
        system("cls");
        fflush(stdin);
        printf("\nB] Try out some of the basic c programs below\n");
        printf("------------------------------------\n");
        printf("1. Programs involving one variable\n");
        printf("2. Programs involving two variables\n");
        printf("3. Programs involving three variables\n");
        printf("4. Series upto n term\n");
        printf("5. Series upto nth term\n");
        printf("6. Series from n1 to n2 term\n");
        printf("7. Integer and String Arrays\n");
        printf("8. Miscellaneous Programs\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("------------------------------------\n");
        printf("\nEnter your option: ");
        scanf("%s", &b_main);
        switch (b_main)
        {
        case '1':
            one_variable_basic_c_problems();
            break;
        case '2':
            two_variable_basic_c_problems();
            break;
        case '3':
            three_variable_basic_c_problems();
            break;
        case '4':
            series_upto_n_term();
            break;
        case '5':
            series_upto_nth_term();
            break;
        case '6':
            series_from_n1_to_n2_term();
            break;
        case '7':
            array_main();
            break;
        case '8':
            miscellaneous_programs();
            break;
        case '0':
            printf("Returning to main menu... Press any key to continue\n");
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
        printf("\nPress Any Key to Continue...\n");
        getch();
    } while (b_main != '0');
}