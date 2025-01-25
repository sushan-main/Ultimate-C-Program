#include <stdio.h>

int assign_name_units_ti(char op, char m_op[], char op_unit[])
{
    switch (op)
    {
    case '1':
        strcpy(m_op, "Milliseconds");
        strcpy(op_unit, "ms");
        break;
    case '2':
        strcpy(m_op, "Second");
        strcpy(op_unit, "s");
        break;
    case '3':
        strcpy(m_op, "Minutes");
        strcpy(op_unit, "min");
        break;
    case '4':
        strcpy(m_op, "Hours");
        strcpy(op_unit, "Hr");
        break;
    case '5':
        strcpy(m_op, "Days");
        strcpy(op_unit, "d");
        break;
    case '6':
        strcpy(m_op, "Weeks");
        strcpy(op_unit, "wk");
        break;
    case '7':
        strcpy(m_op, "Year{non-leap-year}");
        strcpy(op_unit, "Y");
        break;
    case '8':
        strcpy(m_op, "Hr : Min : Sec ");
        strcpy(op_unit, "X");
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
float unit_conver_ti(char op1, float op1_value, char op2)
{
    double value_in_s, converted_value;
    switch (op1)
    {
    case '1':
        value_in_s = op1_value * 0.001;
        break;

    case '2':
        value_in_s = op1_value * 1;
        break;

    case '3':
        value_in_s = op1_value * 60;
        break;

    case '4':
        value_in_s = op1_value * 3600;
        break;

    case '5':
        value_in_s = op1_value * 86400;
        break;

    case '6':
        value_in_s = op1_value * 604800;
        break;

    case '7':
        value_in_s = op1_value * 31536000;
        break;

    default:
        break;
    }
    switch (op2)
    {
    case '1':
        converted_value = value_in_s / 0.001;
        break;

    case '2':
        converted_value = value_in_s / 1;
        break;

    case '3':
        converted_value = value_in_s / 60;
        break;

    case '4':
        converted_value = value_in_s / 3600;
        break;

    case '5':
        converted_value = value_in_s / 86400;
        break;

    case '6':
        converted_value = value_in_s / 604800;
        break;

    case '7':
        converted_value = value_in_s / 31536000;
        break;

    default:
        break;
    }
    return (float)converted_value;
}

void convert_to_hh_mm_ss(char op1, float op1_value)
{
    int hh, mm, ss;
    int a = unit_conver_ti(op1, op1_value, '2');
    hh = a / 3600;
    mm = (a - hh * 3600) / 60;
    ss = a - hh * 3600 - mm * 60;
    printf("\n%d Hr : %d Min : %d Sec\n\n", hh, mm, ss);
}

int ti_conver()
{
    char op1, op2;
    char m_op1[25], m_op2[25];
    char op1_unit[5], op2_unit[5];
    float op1_value, op2_value;
do
{
    
    printf("\nChoose \"From\" and \"To\"\n");
    printf("1. Milliseconds(ms)\n");
    printf("2. Seconds(s)\n");
    printf("3. Minutes(min)\n");
    printf("4. Hours(Hr)\n");
    printf("5. Days(d)\n");
    printf("6. Weeks(wk)\n");
    printf("7. Year{non-leap-year}(Y)\n");
    printf("8. In Hr : Min : Sec Format\n");
    printf("0. Return Back\n");
    printf("x. Terminate Process\n");
    printf("From--> ");
    fflush(stdin);
    scanf("%c", &op1);
    int a = assign_name_units_ti(op1, m_op1, op1_unit);
    if (a == 99)
        continue;
    printf("To--> ");
    fflush(stdin);
    scanf("%c", &op2);
    int b = assign_name_units_ti(op2, m_op2, op2_unit);
    if (b == 99)
        continue;
    printf("\n%s(%s) --> %s(%s)", m_op1, op1_unit, m_op2, op2_unit);
    if (op1 == '8')
    {
        float hhr, mmi, ssc;
        printf("\nEnter Hour: ");
        scanf("%f", &hhr);
        printf("Enter Minuates: ");
        scanf("%f", &mmi);
        printf("Enter Seconds: ");
        scanf("%f", &ssc);
        op1_value = hhr * 3600 + mmi * 60 + ssc;
        if (op2 == '8')
        {
            printf("\n%.2f Hr : %.2f Min : %.2f Sec = ", hhr, mmi, ssc);
            convert_to_hh_mm_ss('2', op1_value);
        }
        else
        {
            op2_value = unit_conver_ti('2', op1_value, op2);
            printf("\n%.2f Hr : %.2f Min : %.2f Sec --> %.2f %s\n", hhr, mmi, ssc, op2_value, op2_unit);
        }
    }
    else
    {
        printf("\nEnter time in %s(%s): ", m_op1, op1_unit);
        scanf("%f", &op1_value);
        if (op2 == '8')
        {
            convert_to_hh_mm_ss(op1, op1_value);
        }
        else
        {
            op2_value = unit_conver_ti(op1, op1_value, op2);
            printf("\n%.2f %s = %.2f %s\n", op1_value, op1_unit, op2_value, op2_unit);
        }
    }
    getch();
} while (op1 != '0' && op2 != '0');
}