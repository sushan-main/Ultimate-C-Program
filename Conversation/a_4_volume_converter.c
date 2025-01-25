#include <stdio.h>

int assign_name_units_vol(char op, char m_op[], char op_unit[])
{
    switch (op)
    {
    case '1':
        strcpy(m_op, "Milliliters");
        strcpy(op_unit, "ml");
        break;
    case '2':
        strcpy(m_op, "Liters");
        strcpy(op_unit, "l");
        break;
    case '3':
        strcpy(m_op, "Cubic Meters");
        strcpy(op_unit, "m^3");
        break;
    case '4':
        strcpy(m_op, "Cubic Centimeters");
        strcpy(op_unit, "cc");
        break;
    case '5':
        strcpy(m_op, "Cubic Inches");
        strcpy(op_unit, "in^3");
        break;
    case '6':
        strcpy(m_op, "Cubic Feets");
        strcpy(op_unit, "ft^3");
        break;
    case '7':
        strcpy(m_op, "UK Gallons");
        strcpy(op_unit, "gal");
        break;
    case '8':
        strcpy(m_op, "US Gallons");
        strcpy(op_unit, "gal");
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
float unit_conver_vol(char op1, float op1_value, char op2)
{
    double value_in_ltr, converted_value;
    switch (op1)
    {
    case '1':
        value_in_ltr = op1_value * 0.001;
        break;
    case '2':
        value_in_ltr = op1_value * 1;
        break;
    case '3':
        value_in_ltr = op1_value * 1000;
        break;
    case '4':
        value_in_ltr = op1_value * 0.001;
        break;
    case '5':
        value_in_ltr = op1_value * 0.016387064;
        break;
    case '6':
        value_in_ltr = op1_value * 28.316846592;
        break;
    case '7':
        value_in_ltr = op1_value * 4.54609;
        break;
    case '8':
        value_in_ltr = op1_value * 3.785411784;
        break;
    default:
        break;
    }
    switch (op2)
    {
    case '1':
        converted_value = value_in_ltr / 0.001;
        break;
    case '2':
        converted_value = value_in_ltr / 1;
        break;
    case '3':
        converted_value = value_in_ltr / 1000;
        break;
    case '4':
        converted_value = value_in_ltr / 0.001;
        break;
    case '5':
        converted_value = value_in_ltr / 0.016387064;
        break;
    case '6':
        converted_value = value_in_ltr / 28.316846592;
        break;
    case '7':
        converted_value = value_in_ltr / 4.54609;
        break;
    case '8':
        converted_value = value_in_ltr / 3.785411784;
        break;
    default:
        break;
    }
    return (float)converted_value;
}

int vol_conver()
{
    char op1, op2;
    char m_op1[25], m_op2[25];
    char op1_unit[7], op2_unit[7];
    float op1_value, op2_value;
    do
    {

        printf("\nChoose \"From\" and \"To\"\n");
        printf("1. Milliliters(ml)\n");
        printf("2. Liters(l)\n");
        printf("3. Cubic Meters(m^3)\n");
        printf("4. Cubic Centimeters(cc)\n");
        printf("5. Cubic Inches(in^3)\n");
        printf("6. Cubic Feets(ft^3)\n");
        printf("7. UK Gallons(gal)\n");
        printf("8. US Gallons(gal)\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("From--> ");
        fflush(stdin);
        scanf("%c", &op1);
        int a = assign_name_units_vol(op1, m_op1, op1_unit);
        if (a == 99)
            continue;
        printf("To--> ");
        fflush(stdin);
        scanf("%c", &op2);
        int b = assign_name_units_vol(op2, m_op2, op2_unit);
        if (b == 99)
            continue;
        printf("\n%s(%s) --> %s(%s)", m_op1, op1_unit, m_op2, op2_unit);
        printf("\nEnter volume in %s(%s): ", m_op1, op1_unit);
        scanf("%f", &op1_value);
        op2_value = unit_conver_vol(op1, op1_value, op2);
        printf("\n%.2f %s = %.2f %s\n", op1_value, op1_unit, op2_value, op2_unit);
        getch();
    } while (op1 != '0' && op2 != '0');
}