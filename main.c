
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *       Author:  ESRAA ALI
 *       Module:
 *       Date  : 10/8/2023
 *       Version:  v0
 *  Description:   ATM Project
 *
 *********************************************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "Source.c"
#include "Header.h"
#include <stdbool.h>
#include <string.h>

int main()
{  init();
    int ID_Account;
    float cash_amount;
    int choice ;
    while(1){
        MENU();
        scanf("%d",&choice);
        printf("\n");
        switch(choice){
            case 1:
                if(login_To_system())
                {
                    printf("LOG IN TO SYSTEM SUCCESS.\n");
                    //break;
                }
                else
                {
                    printf("login failed !!");
                }
                break;

            case 2:
                printf("Enter the Account_ID whose you want to check his Balance....\n");
                scanf("%d",&ID_Account);
                print_Balance(ID_Account);
            break;

            case 3:
                printf("Enter the Account_ID \n");
                scanf("%d",&ID_Account);
                printf("Enter the amount of cash\n");
                scanf("%f",&cash_amount);
                Desposit(ID_Account,cash_amount);
            break;

            case 4:;
                float new;
                printf("Enter the Account_ID \n Enter cash amount to Withdraw\n");
                scanf("%d %f",&ID_Account,&cash_amount);
                new=Withdraw(ID_Account,cash_amount);
                printf("%f", new);
            break;


            case 5:
                printf("Enter the Account_ID who you want to transfer money....\n");
                scanf("%d",&ID_Account);
                Transfer(ID_Account);
            break;

            case 6:
                exit(0);

            default:
                printf(".............wrong choice................\n");
        }
    }

    return 0;
}
