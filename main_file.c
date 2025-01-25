#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>
#include "Conversation\a_conversation.c"
#include "Basic-C-Programs\b_basic_c_programs.c"
#include "Matrix-Operations\c_matrix_operation.c"
#include "Patterns\d_patterns.c"

int main()
{
    char main_op;
    while (1)
    {
        fflush(stdin);
        printf("\nWelcome to the ULTIMATE C PROGRAM to ever exist!!\n");
        printf("-------------------------------------------------\n");
        printf("A. Conversation\n");
        printf("B. Basic C Programs\n");
        printf("C. Matrix Operations\n");
        printf("D. Pattern Programs in C\n");
        printf("x. Terminate Process\n");
        printf("-------------------------------------------------\n");
        printf("\nEnter your option: ");
        fflush(stdin);
        scanf("%c", &main_op);
        switch (main_op)
        {
        case 'A':
        case 'a':
            conversion();
            break;
        case 'B':
        case 'b':
            basic_c_programs();
            break;
        case 'C':
        case 'c':
            matrix_operation();
            break;
        case 'D':
        case 'd':
            patterns_in_c();
            break;
        case 'x':
        case 'X':
            printf("\nShutting down...\n");
            exit(1);
            break;
        default:
            printf("\nInput Error!!!\n");
            getch();
            break;
        }
    }
}