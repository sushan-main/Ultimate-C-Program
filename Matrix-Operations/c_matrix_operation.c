#include <stdio.h>

void mat_inp(char mat_name[], int x, int y, int z[][50])
{
    printf("\nEnter Matrix %s: \n", mat_name);
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("Element [%d],[%d]: ", i, j);
            scanf("%d", &z[i][j]);
        }
    }
}
void mat_out(char mat_name[], int x, int y, int z[][50])
{
    printf("\nThe Matrix %s is: \n", mat_name);
    int i, j;
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < y; j++)
        {
            printf("%d\t", z[i][j]);
        }
        printf("\n");
    }
}
void mat_transpose(char mat_name[], int x, int y, int z[][50])
{
    int i, j;
    int temp[50][50];
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            temp[i][j] = z[j][i];
        }
        printf("\n");
    }
    mat_out(mat_name, y, x, temp);
}

void mat_add(char mat_name[], int p, int q, int m, int n, int a[][50], int b[][50])
{
    int i, j, c[p][50];
    if (p == m && q == n)
    {
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < n; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }
        mat_out(mat_name, p, n, c);
    }
    else
        printf("Matrix Addition not possible!!");
}

void mat_subt(char mat_name[], int p, int q, int m, int n, int a[][50], int b[][50])
{
    int i, j, c[p][50];
    if (p == m && q == n)
    {
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < n; j++)
            {
                c[i][j] = a[i][j] - b[i][j];
            }
        }
        mat_out(mat_name, p, n, c);
    }
    else
        printf("Matrix Subraction not possible!!");
}

void mat_mul(char mat_name[], int p, int q, int m, int n, int a[][50], int b[][50])
{
    int temp = 0, i, j, k, c[p][50];
    if (q == m)
    {
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < n; j++)
            {
                temp = 0;
                for (k = 0; k < q; k++)
                {
                    temp = temp + a[i][k] * b[k][j];
                }
                c[i][j] = temp;
            }
        }
        mat_out(mat_name, p, n, c);
    }
    else
        printf("Matrix Multiplication %s not possible", mat_name);
}

void matrix_operation()
{
    int mat_no;
    char mat_option;
    do
    {
        system("cls");
        printf("\nEnter no of Matrices you want: (Either 1 or 2 only)\n");
        scanf("%d", &mat_no);
        if (mat_no == 1)
        {
            int p, q;
            printf("Enter the no of rows of Matrix A: ");
            scanf("%d", &p);
            printf("Enter the no of cols of Matrix A: ");
            scanf("%d", &q);
            int mat_a[p][q];
            mat_inp("A", p, q, mat_a);
            printf("\nChoose an Operation:\n");
            printf("1. Output Matrix\n");
            printf("2. Transpose Matrix\n");
            printf("U. Re-enter Matrixes\n");
            printf("0. Return Back\n");
            printf("x. Terminate Process\n");
            do
            {
                printf("\n>> ");
                fflush(stdin);
                scanf("%c", &mat_option);
                switch (mat_option)
                {
                case '1':
                    mat_out("A", p, q, mat_a);
                    break;
                case '2':
                    mat_transpose("A transpose", p, q, mat_a);
                    break;
                case 'u':
                case 'U':
                    printf("Returning... Press any key to continue\n");
                    break;
                case '0':
                    printf("Returning to main menu... Press any key to continue\n");
                    break;
                case 'x':
                case 'X':
                    exit(1);
                    break;
                default:
                    printf("Input Error!!\n");
                    break;
                }
            } while (mat_option != 'u' && mat_option != 'U' && mat_option != '0');
        }
        else if (mat_no == 2)
        {
            int p, q, m, n;
            printf("\nFor Matrix A\n");
            printf("Enter the no of rows: ");
            scanf("%d", &p);
            printf("Enter the no of cols: ");
            scanf("%d", &q);
            int mat_a[p][q];
            mat_inp("A", p, q, mat_a);
            printf("\nFor Matrix B\n");
            printf("Enter the no of rows: ");
            scanf("%d", &m);
            printf("Enter the no of cols: ");
            scanf("%d", &n);
            int mat_b[m][n];
            mat_inp("A", m, n, mat_b);
            printf("\nChoose an Operation:\n");
            printf("1. Output Matrix A\n");
            printf("2. Output Matrix B\n");
            printf("3. Add Matrix A and B\n");
            printf("4. Matrix A - Matrix B\n");
            printf("5. Matrix B - Matrix A\n");
            printf("6. Matrix A * Matrix B\n");
            printf("7. Matrix B * Matrix A\n");
            printf("U. Re-enter Matrixes\n");
            printf("0. Return Back\n");
            printf("x. Terminate Process\n");
            do
            {
                printf("\n>> ");
                fflush(stdin);
                scanf("%c", &mat_option);
                switch (mat_option)
                {
                case '1':
                    mat_out("A", p, q, mat_a);
                    break;
                case '2':
                    mat_out("B", m, n, mat_b);
                    break;
                case '3':
                    mat_add("A + B", p, q, m, n, mat_a, mat_b);
                    break;
                case '4':
                    mat_subt("A - B", p, q, m, n, mat_a, mat_b);
                    break;
                case '5':
                    mat_subt("B - A", m, n, p, q, mat_b, mat_a);
                    break;
                case '6':
                    mat_mul("A * B", p, q, m, n, mat_a, mat_b);
                    break;
                case '7':
                    mat_mul("B * A", m, n, p, q, mat_b, mat_a);
                    break;
                case 'u':
                case 'U':
                    printf("Returning... Press any key to continue\n");
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
            } while (mat_option != 'u' && mat_option != 'U' && mat_option != '0');
        }
        printf("\nPress Any Key to Continue...\n");
        getch();
    } while (mat_no != '0' && mat_option != '0');
}
