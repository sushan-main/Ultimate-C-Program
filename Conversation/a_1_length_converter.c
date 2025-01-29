#include <stdio.h>

int assign_name_units_ln(char op, char m_op[], char op_unit[])
{
    switch (op)
    {
    case '1':
        strcpy(m_op, "Millimeter");
        strcpy(op_unit, "mm");
        break;
    case '2':
        strcpy(m_op, "Centimeter");
        strcpy(op_unit, "cm");
        break;
    case '3':
        strcpy(m_op, "Meter");
        strcpy(op_unit, "m");
        break;
    case '4':
        strcpy(m_op, "Kilometer");
        strcpy(op_unit, "km");
        break;
    case '5':
        strcpy(m_op, "Inches");
        strcpy(op_unit, "in");
        break;
    case '6':
        strcpy(m_op, "Feet");
        strcpy(op_unit, "ft");
        break;
    case '7':
        strcpy(m_op, "Yards");
        strcpy(op_unit, "yd");
        break;
    case '8':
        strcpy(m_op, "Miles");
        strcpy(op_unit, "mi");
        break;
    case '0':
        printf("Returning to sub menu... Press any key to continue\n");
        return 99;
        break;
    case 'x':
    case 'X':
        printf("\nShutting down...\n");
        exit(1);
        break;
    default:
        printf("Input Error!! Press any key to continue\n");
        getch();
        return 0;
        break;
    }
}
float unit_conver_ln(char op1, float op1_value, char op2)
{
    double value_in_m, converted_value;
    switch (op1)
    {
    case '1':
        value_in_m = op1_value * 0.001;
        break;
    case '2':
        value_in_m = op1_value * 0.01;
        break;
    case '3':
        value_in_m = op1_value * 1;
        break;
    case '4':
        value_in_m = op1_value * 1000;
        break;
    case '5':
        value_in_m = op1_value * 0.0254;
        break;
    case '6':
        value_in_m = op1_value * 0.3048;
        break;
    case '7':
        value_in_m = op1_value * 0.9144;
        break;
    case '8':
        value_in_m = op1_value * 1609.344;
        break;
    default:
        break;
    }
    switch (op2)
    {
    case '1':
        converted_value = value_in_m / 0.001;
        break;
    case '2':
        converted_value = value_in_m / 0.01;
        break;
    case '3':
        converted_value = value_in_m / 1;
        break;
    case '4':
        converted_value = value_in_m / 1000;
        break;
    case '5':
        converted_value = value_in_m / 0.0254;
        break;
    case '6':
        converted_value = value_in_m / 0.3048;
        break;
    case '7':
        converted_value = value_in_m / 0.9144;
        break;
    case '8':
        converted_value = value_in_m / 1609.344;
        break;
    default:
        break;
    }
    return (float)converted_value;
}

int ln_conver()
{
    char op1, op2;
    char m_op1[25], m_op2[25];
    char op1_unit[5], op2_unit[5];
    float op1_value, op2_value;
    do
    {
        system("cls");
        printf("\nChoose \"From\" and \"To\"\n");
        printf("1. Millimeter(mm)\n");
        printf("2. Centimeter(cm)\n");
        printf("3. Meter(m)\n");
        printf("4. Kilometer(km)\n");
        printf("5. Inches(in)\n");
        printf("6. Feet(ft)\n");
        printf("7. Yards(yd)\n");
        printf("8. Miles(ml)\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("(Example: When From--> 1 From--> 2, Millimeter to Centimeter)\n\n");
        printf("From--> ");
        fflush(stdin);
        scanf("%c", &op1);
        int a = assign_name_units_ln(op1, m_op1, op1_unit);
        if (a == 99 || a == 0)
            continue;
        printf("To--> ");
        fflush(stdin);
        scanf("%c", &op2);
        int b = assign_name_units_ln(op2, m_op2, op2_unit);
        if (b == 99)
            continue;
        printf("\n%s(%s) --> %s(%s)", m_op1, op1_unit, m_op2, op2_unit);
        printf("\nEnter length in %s(%s): ", m_op1, op1_unit);
        scanf("%f", &op1_value);
        op2_value = unit_conver_ln(op1, op1_value, op2);
        printf("\n%.2f %s = %.2f %s\n", op1_value, op1_unit, op2_value, op2_unit);
        printf("\nPress Any Key to Continue...\n");
        getch();
    } while (op1 != '0' && op2 != '0');
}