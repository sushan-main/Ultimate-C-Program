int assign_name_units_ma(char op, char m_op[], char op_unit[])
{
    switch (op)
    {
    case '1':
        strcpy(m_op, "Gram");
        strcpy(op_unit, "g");
        break;
    case '2':
        strcpy(m_op, "Kilogram");
        strcpy(op_unit, "kg");
        break;
    case '3':
        strcpy(m_op, "Tons");
        strcpy(op_unit, "t");
        break;
    case '4':
        strcpy(m_op, "Pounds");
        strcpy(op_unit, "lb");
        break;
    case '5':
        strcpy(m_op, "Ounces");
        strcpy(op_unit, "oz");
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
float unit_conver_ma(char op1, float op1_value, char op2)
{
    double value_in_kg, converted_value;
    switch (op1)
    {
    case '1':
        value_in_kg = op1_value * 0.001;
        break;
    case '2':
        value_in_kg = op1_value * 1;
        break;
    case '3':
        value_in_kg = op1_value * 1000;
        break;
    case '4':
        value_in_kg = op1_value * 0.45359237;
        break;
    case '5':
        value_in_kg = op1_value * 0.0283495231;
        break;
    default:
        break;
    }
    switch (op2)
    {
    case '1':
        converted_value = value_in_kg / 0.001;
        break;
    case '2':
        converted_value = value_in_kg / 1;
        break;
    case '3':
        converted_value = value_in_kg / 1000;
        break;
    case '4':
        converted_value = value_in_kg / 0.45359237;
        break;
    case '5':
        converted_value = value_in_kg / 0.0283495231;
        break;
    default:
        break;
    }
    return (float)converted_value;
}

int ma_conver()
{
    char op1, op2;
    char m_op1[25], m_op2[25];
    char op1_unit[7], op2_unit[7];
    float op1_value, op2_value;
    do
    {
        printf("\nChoose \"From\" and \"To\"\n");
        printf("1. Gram(g)\n");
        printf("2. Kilogram(kg)\n");
        printf("3. Tons(t)\n");
        printf("4. Pounds(lb)\n");
        printf("5. Ounces(oz)\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("From--> ");
        fflush(stdin);
        scanf("%c", &op1);
        int a = assign_name_units_ma(op1, m_op1, op1_unit);
        if (a == 99)
            continue;
        printf("To--> ");
        fflush(stdin);
        scanf("%c", &op2);
        int b = assign_name_units_ma(op2, m_op2, op2_unit);
        if (b == 99)
            continue;
        printf("\n%s(%s) --> %s(%s)", m_op1, op1_unit, m_op2, op2_unit);
        printf("\nEnter mass in %s(%s): ", m_op1, op1_unit);
        scanf("%f", &op1_value);
        op2_value = unit_conver_ma(op1, op1_value, op2);
        printf("\n%.2f %s = %.2f %s\n", op1_value, op1_unit, op2_value, op2_unit);
        getch();
    } while (op1 != '0' && op2 != '0');
}