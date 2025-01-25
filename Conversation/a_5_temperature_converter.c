#include <stdio.h>

int assign_name_units_tr(char op, char m_op[], char op_unit[])
{
    switch (op)
    {
    case '1':
        strcpy(m_op, "Celsius");
        strcpy(op_unit, "`C");
        break;
    case '2':
        strcpy(m_op, "Farenheit");
        strcpy(op_unit, "`F");
        break;
    case '3':
        strcpy(m_op, "Kelvin");
        strcpy(op_unit, "K");
        break;
    case '4':
        strcpy(m_op, "Reaumur");
        strcpy(op_unit, "`Re");
        break;
    case '5':
        strcpy(m_op, "Rankine");
        strcpy(op_unit, "`R");
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
        printf("Input Error!!\n");
        break;
    }
}
float unit_conver_tr(char op1, float op1_value, char op2)
{
    double value_in_ratio, converted_value;
    switch (op1)
    {
    case '1':
        value_in_ratio = op1_value / 5;
        break;
    case '2':
        value_in_ratio = (op1_value - 32) / 9;
        break;
    case '3':
        value_in_ratio = (op1_value - 273.15) / 5;
        break;
    case '4':
        value_in_ratio = op1_value / 4;
        break;
    case '5':
        value_in_ratio = (op1_value - 491.67) / 9;
        break;
    default:
        break;
    }
    switch (op2)
    {
    case '1':
        converted_value = value_in_ratio * 5;
        break;
    case '2':
        converted_value = (value_in_ratio * 9) + 32;
        break;
    case '3':
        converted_value = (value_in_ratio * 5) + 273.15;
        break;
    case '4':
        converted_value = value_in_ratio * 4;
        break;
    case '5':
        converted_value = (value_in_ratio * 9) + 491.67;
        break;
    default:
        break;
    }
    return (float)converted_value;
}

int tr_conver()
{
    char op1, op2;
    char m_op1[25], m_op2[25];
    char op1_unit[5], op2_unit[5];
    float op1_value, op2_value;
    do
    {
        printf("\nChoose \"From\" and \"To\" (Using ` instead of Degree due to terminal limitations)\n");
        printf("1. Celsius(`C)\n");
        printf("2. Farenheit(`F)\n");
        printf("3. Kelvin(K)\n");
        printf("4. Reaumur(`Re)\n");
        printf("5. Rankine(`R)\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("From--> ");
        fflush(stdin);
        scanf("%c", &op1);
        int a = assign_name_units_tr(op1, m_op1, op1_unit);
        if (a == 99)
            continue;
        printf("To--> ");
        fflush(stdin);
        scanf("%c", &op2);
        int b = assign_name_units_tr(op2, m_op2, op2_unit);
        if (b == 99)
            continue;
        printf("\n%s(%s) --> %s(%s)", m_op1, op1_unit, m_op2, op2_unit);
        printf("\nEnter temperature in %s(%s): ", m_op1, op1_unit);
        scanf("%f", &op1_value);
        op2_value = unit_conver_tr(op1, op1_value, op2);
        printf("\n%.2f %s = %.2f %s\n", op1_value, op1_unit, op2_value, op2_unit);
        getch();
    } while (op1 != '0' && op2 != '0');
}