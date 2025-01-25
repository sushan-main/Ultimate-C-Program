int assign_name_units_sp(char op, char m_op[], char op_unit[])
{
    switch (op)
    {
    case '1':
        strcpy(m_op, "Meters per second");
        strcpy(op_unit, "m/s");
        break;
    case '2':
        strcpy(m_op, "Meters per hour");
        strcpy(op_unit, "m/hr");
        break;
    case '3':
        strcpy(m_op, "Kilometers per second");
        strcpy(op_unit, "km/s");
        break;
    case '4':
        strcpy(m_op, "Kilometers per hour");
        strcpy(op_unit, "km/hr");
        break;
    case '5':
        strcpy(m_op, "Miles per second");
        strcpy(op_unit, "mi/s");
        break;
    case '6':
        strcpy(m_op, "Miles per hour");
        strcpy(op_unit, "mi/hr");
        break;
    case '7':
        strcpy(m_op, "Knots");
        strcpy(op_unit, "kn");
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
float unit_conver_sp(char op1, float op1_value, char op2)
{
    double value_in_mps, converted_value;
    switch (op1)
    {
    case '1':
        value_in_mps = op1_value * 1;
        break;
    case '2':
        value_in_mps = op1_value / 3600;
        break;
    case '3':
        value_in_mps = op1_value * 1000;
        break;
    case '4':
        value_in_mps = op1_value * (1 / 3.6);
        break;
    case '5':
        value_in_mps = op1_value * 1609.344;
        break;
    case '6':
        value_in_mps = op1_value * 0.44704;
        break;
    case '7':
        value_in_mps = op1_value * 0.514444444;
        break;
    default:
        break;
    }
    switch (op2)
    {
    case '1':
        converted_value = value_in_mps / 1;
        break;
    case '2':
        converted_value = value_in_mps * 3600;
        break;
    case '3':
        converted_value = value_in_mps / 1000;
        break;
    case '4':
        converted_value = value_in_mps * 3.6;
        break;
    case '5':
        converted_value = value_in_mps / 1609.344;
        break;
    case '6':
        converted_value = value_in_mps / 0.44704;
        break;
    case '7':
        converted_value = value_in_mps / 0.514444444;
        break;
    default:
        break;
    }
    return (float)converted_value;
}

int sp_conver()
{
    char op1, op2;
    char m_op1[25], m_op2[25];
    char op1_unit[7], op2_unit[7];
    float op1_value, op2_value;
    do
    {

        printf("\nChoose \"From\" and \"To\"\n");
        printf("1. Meters per second(m/s)\n");
        printf("2. Meters per hour(m/h)\n");
        printf("3. Kilometers per second(km/s)\n");
        printf("4. Kilometers per hour(km/hr)\n");
        printf("5. Miles per second(mi/s)\n");
        printf("6. Miles per hour(mi/hr)\n");
        printf("7. Knots(kn)\n");
        printf("0. Return Back\n");
        printf("x. Terminate Process\n");
        printf("From--> ");
        fflush(stdin);
        scanf("%c", &op1);
        int a = assign_name_units_sp(op1, m_op1, op1_unit);
        if (a == 99)
            continue;
        printf("To--> ");
        fflush(stdin);
        scanf("%c", &op2);
        int b = assign_name_units_sp(op2, m_op2, op2_unit);
        if (b == 99)
            continue;

        printf("\n%s(%s) --> %s(%s)", m_op1, op1_unit, m_op2, op2_unit);
        printf("\nEnter speed in %s(%s): ", m_op1, op1_unit);
        scanf("%f", &op1_value);
        op2_value = unit_conver_sp(op1, op1_value, op2);
        printf("\n%.2f %s = %.2f %s\n", op1_value, op1_unit, op2_value, op2_unit);
        getch();
    } while (op1 != '0' && op2 != '0');
}