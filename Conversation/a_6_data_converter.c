#include <stdio.h>

int assign_name_units_da(char op, char m_op[], char op_unit[])
{
    switch (op)
    {
    case '1':
        strcpy(m_op, "Bits");
        strcpy(op_unit, "bit");
        break;
    case '2':
        strcpy(m_op, "Nibble");
        strcpy(op_unit, "nybl");
        break;
    case '3':
        strcpy(m_op, "Bytes");
        strcpy(op_unit, "B");
        break;
    case '4':
        strcpy(m_op, "KiloBytes");
        strcpy(op_unit, "KB");
        break;
    case '5':
        strcpy(m_op, "MegaBytes");
        strcpy(op_unit, "MB");
        break;
    case '6':
        strcpy(m_op, "GigaBytes");
        strcpy(op_unit, "GB");
        break;
    case '7':
        strcpy(m_op, "TeraBytes");
        strcpy(op_unit, "TB");
        break;
    case '8':
        strcpy(m_op, "PetaBytes");
        strcpy(op_unit, "PB");
        break;
    case '9':
        strcpy(m_op, "ExaBytes");
        strcpy(op_unit, "EB");
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
float unit_conver_da(char op1, float op1_value, char op2)
{
    double value_in_bit, converted_value;
    switch (op1)
    {
    case '1':
        value_in_bit = op1_value * 1;
        break;
    case '2':
        value_in_bit = op1_value * 4;
        break;
    case '3':
        value_in_bit = op1_value * 8;
        break;
    case '4':
        value_in_bit = op1_value * 8 * pow(1024, 1);
        break;
    case '5':
        value_in_bit = op1_value * 8 * pow(1024, 2);
        break;
    case '6':
        value_in_bit = op1_value * 8 * pow(1024, 3);
        break;
    case '7':
        value_in_bit = op1_value * 8 * pow(1024, 4);
        break;
    case '8':
        value_in_bit = op1_value * 8 * pow(1024, 5);
        break;
    case '9':
        value_in_bit = op1_value * 8 * pow(1024, 6);
        break;
    default:
        break;
    }
    switch (op2)
    {
    case '1':
        converted_value = value_in_bit / 1;
        break;
    case '2':
        converted_value = value_in_bit / 4;
        break;
    case '3':
        converted_value = value_in_bit / 8;
        break;
    case '4':
        converted_value = value_in_bit / (8 * pow(1024, 1));
        break;
    case '5':
        converted_value = value_in_bit / (8 * pow(1024, 2));
        break;
    case '6':
        converted_value = value_in_bit / (8 * pow(1024, 3));
        break;
    case '7':
        converted_value = value_in_bit / (8 * pow(1024, 4));
        break;
    case '8':
        converted_value = value_in_bit / (8 * pow(1024, 5));
        break;
    case '9':
        converted_value = value_in_bit / (8 * pow(1024, 6));
        break;
    default:
        break;
    }
    return (float)converted_value;
}

int da_conver()
{
    char op1, op2;
    char m_op1[25], m_op2[25];
    char op1_unit[7], op2_unit[7];
    float op1_value, op2_value;
    do
    {

        printf("\nChoose \"From\" and \"To\"\n");
        printf("1. Bits(bit)\n");
        printf("2. Nibble(nybl)\n");
        printf("3. Bytes(B)\n");
        printf("4. KiloBytes(KB)\n");
        printf("5. MegaBytes(MB)\n");
        printf("6. GigaBytes(GB)\n");
        printf("7. TeraBytes(TB)\n");
        printf("8. PetaBytes(PB)\n");
        printf("9. ExaBytes(EB)\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("From--> ");
        fflush(stdin);
        scanf("%c", &op1);
        int a = assign_name_units_da(op1, m_op1, op1_unit);
        if (a == 99)
            continue;
        printf("To--> ");
        fflush(stdin);
        scanf("%c", &op2);
        int b = assign_name_units_da(op2, m_op2, op2_unit);
        if (b == 99)
            continue;
        printf("\n%s(%s) --> %s(%s)", m_op1, op1_unit, m_op2, op2_unit);
        printf("\nEnter data in %s(%s): ", m_op1, op1_unit);
        scanf("%f", &op1_value);
        op2_value = unit_conver_da(op1, op1_value, op2);
        printf("\n%.2f %s = %.2f %s\n", op1_value, op1_unit, op2_value, op2_unit);
        getch();
    } while (op1 != '0' && op2 != '0');
}