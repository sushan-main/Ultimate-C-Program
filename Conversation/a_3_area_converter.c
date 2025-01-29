#include <stdio.h>

int assign_name_units_ar(char op, char m_op[], char op_unit[])
{
    switch (op)
    {
    case '1':
        strcpy(m_op, "Sq. Meters");
        strcpy(op_unit, "m^2");
        break;
    case '2':
        strcpy(m_op, "Sq. Centimeters");
        strcpy(op_unit, "cm^2");
        break;
    case '3':
        strcpy(m_op, "Sq. Feet");
        strcpy(op_unit, "ft^2");
        break;
    case '4':
        strcpy(m_op, "Sq. Inches");
        strcpy(op_unit, "in^2");
        break;
    case '5':
        strcpy(m_op, "Acres");
        strcpy(op_unit, "ac");
        break;
    case '6':
        strcpy(m_op, "Ares");
        strcpy(op_unit, "a");
        break;
    case '7':
        strcpy(m_op, "Hectares");
        strcpy(op_unit, "ha");
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
float unit_conver_ar(char op1, float op1_value, char op2)
{
    double value_in_m2, converted_value;
    switch (op1)
    {
    case '1':
        value_in_m2 = op1_value * 1;
        break;
    case '2':
        value_in_m2 = op1_value * 0.0001;
        break;
    case '3':
        value_in_m2 = op1_value * 0.09290304;
        break;
    case '4':
        value_in_m2 = op1_value * 0.00064516;
        break;
    case '5':
        value_in_m2 = op1_value * 4046.8564224;
        break;
    case '6':
        value_in_m2 = op1_value * 100;
        break;
    case '7':
        value_in_m2 = op1_value * 10000;
        break;
    default:
        break;
    }
    switch (op2)
    {
    case '1':
        converted_value = value_in_m2 / 1;
        break;
    case '2':
        converted_value = value_in_m2 / 0.0001;
        break;
    case '3':
        converted_value = value_in_m2 / 0.09290304;
        break;
    case '4':
        converted_value = value_in_m2 / 0.00064516;
        break;
    case '5':
        converted_value = value_in_m2 / 4046.8564224;
        break;
    case '6':
        converted_value = value_in_m2 / 100;
        break;
    case '7':
        converted_value = value_in_m2 / 10000;
        break;
    default:
        break;
    }
    return (float)converted_value;
}

int ar_conver()
{
    char op1, op2;
    char m_op1[25], m_op2[25];
    char op1_unit[7], op2_unit[7];
    float op1_value, op2_value;
    do
    {
        system("cls");
        printf("\nChoose \"From\" and \"To\"\n");
        printf("1. Sq. Meters(m^2)\n");
        printf("2. Sq. Centimeters(cm^2)\n");
        printf("3. Sq. Feet(ft^2)\n");
        printf("4. Sq. Inches(in^2)\n");
        printf("5. Acres(ac)\n");
        printf("6. Ares(a)\n");
        printf("7. Hectares(ha)\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("(Example: When From--> 1 From--> 2, Sq. Meters to Sq. Centimeters)\n\n");
        printf("From--> ");        
        fflush(stdin);
        scanf("%c", &op1);
        int a = assign_name_units_ar(op1, m_op1, op1_unit);
        if (a == 99 || a == 0)
            continue;
        printf("To--> ");
        fflush(stdin);
        scanf("%c", &op2);
        int b = assign_name_units_ar(op2, m_op2, op2_unit);
        if (b == 99 || b == 0)
            continue;
        printf("\n%s(%s) --> %s(%s)", m_op1, op1_unit, m_op2, op2_unit);
        printf("\nEnter length in %s(%s): ", m_op1, op1_unit);
        scanf("%f", &op1_value);
        op2_value = unit_conver_ar(op1, op1_value, op2);
        printf("\n%.2f %s = %.2f %s\n", op1_value, op1_unit, op2_value, op2_unit);
        printf("\nPress Any Key to Continue...\n");
        getch();
    } while (op1 != '0' && op2 != '0');
}