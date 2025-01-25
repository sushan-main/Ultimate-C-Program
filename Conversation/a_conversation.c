#include "a_1_length_converter.c"
#include "a_2_mass_converter.c"
#include "a_3_area_converter.c"
#include "a_4_volume_converter.c"
#include "a_5_temperature_converter.c"
#include "a_6_data_converter.c"
#include "a_7_speed_converter.c"
#include "a_8_time_converter.c"

void conversion()
{
    char a_main;
    do
    {
        fflush(stdin);
        printf("\nA]\tWelcome to the Conversation Section\n");
        printf("\t------------------------------------\n");
        printf("\t1. Length Conversation\n");
        printf("\t2. Mass Conversation\n");
        printf("\t3. Area Conversation\n");
        printf("\t4. Volume Conversation\n");
        printf("\t5. Temperature Conversation\n");
        printf("\t6. Data Conversation\n");
        printf("\t7. Speed Conversation\n");
        printf("\t8. Time Conversation\n");
        printf("\t0. Return Back\n");
        printf("\tx. Terminate Process\n");
        printf("\t------------------------------------\n");
        printf("\nEnter your option: ");
        scanf("%c", &a_main);
        switch (a_main)
        {
        case '1':
            ln_conver();
            break;
        case '2':
            ma_conver();
            break;
        case '3':
            ar_conver();
            break;
        case '4':
            vol_conver();
            break;
        case '5':
            tr_conver();
            break;
        case '6':
            da_conver();
            break;
        case '7':
            sp_conver();
            break;
        case '8':
            ti_conver();
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
            getch();
    } while (a_main != '0');
}