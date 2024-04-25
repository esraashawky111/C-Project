/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *       Author:  ESRAA ALI
 *       Module:
 *       Date  :10/8/2023
 *       Version:v0
 *  Description:  ATM project
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 ********************************************************************************************************************/
#include "header.h"
#define MAX_NUMBER_USERS 34
/******************************************************************************************************************/
int USER_ID = -1;
int Password;
char ID;
float cash_amount=0.0;
enum x {False =0,True=1};
Account_t arr[MAX_NUMBER_USERS]={};


void init()
{
    arr[11].Account_ID = 11;
    arr[11].Account_Password = "111";
    arr[11].Balance = 1000.0;

    arr[22].Account_ID = 22;
    arr[22].Account_Password = "222";
    arr[22].Balance = 2000.0;

    arr[33].Account_ID = 33;
    arr[33].Account_Password = "333";
    arr[33].Balance = 3000.0;
}

void MENU(void){
    printf("=========================================\n") ;
    printf("============ATM PROJECT=================\n") ;
    printf("========================================\n") ;
    printf("Enter 1 for Login_To_System ............\n") ;
    printf("Enter 2 for check your Balance..........\n") ;
    printf("Enter 3 for Deposit.....................\n") ;
    printf("Enter 4 for Withdraw....................\n") ;
    printf("Enter 5 for Tranfer Money...............\n") ;
    printf("Enter 6 for EXIT........................\n") ;
    printf("========================================\n") ;
    printf("========================================\n") ;
    printf("========================================\n") ;

}
_Bool validity( char Account_ID, const char *Account_Password)
{
    _Bool ret = False;

    for (int i = 0; i < sizeof(arr)/ sizeof(arr[0]); i++)
    {

        if( (arr[i].Account_ID == Account_ID) && (strcmp(arr[i].Account_Password, Account_Password) == 0) )
        {
            USER_ID=Account_ID;
            ret = True;
        }
    }
    return ret;
}



char login_To_system(void)
{
int Account_ID;
char Account_Password[4];
printf("Enter the Account ID");
scanf("%d",&Account_ID);
printf("Enter the Account Password");
scanf("%s",Account_Password);
return validity(Account_ID,Account_Password);
}


void print_Balance(char Account_ID)
{
    if(USER_ID !=Account_ID)
    {
    printf("you must log in to system.\n");
    }
    else{
    printf("%f",arr[Account_ID].Balance);
        }
}


void Desposit(char Account_ID,float cash_amount)
{
     if(USER_ID !=Account_ID)
        {
      printf("you must log in to system.\n");

        }
    else{
      arr[Account_ID].Balance += cash_amount;
      printf("%f",arr[Account_ID].Balance);
        }
}


void Transfer(char Account_ID)
{

    if(USER_ID !=Account_ID){
      printf("you must log in to system.\n");
        }
    else{

    float Tranfer_amount=0;
    if(Tranfer_amount > arr[Account_ID].Balance|| Tranfer_amount < 0){
        printf("Your Balance is less than Transfer_amount");
    }
    else{
    float New_Balance_after_transfer =0;
    printf("Enter the amount of cash you want to transfer \n");
    scanf("%f",&cash_amount);
    New_Balance_after_transfer =arr[Account_ID].Balance-cash_amount;
    printf("%f\n",New_Balance_after_transfer);
     }
    }
}


float Withdraw(char Account_ID,float Withdraw_amount)
{
    if(USER_ID !=Account_ID)
      {
     printf("you must log in to system.\n");
       }
    else
    {
    if(Withdraw_amount >arr[Account_ID].Balance || Withdraw_amount < 0)
     {
        printf("Your Balance is less than Withdraw_amount");
        return -1;
      }
    else{
        float New_Balance_after_Withdraw = 0;
        New_Balance_after_Withdraw =arr[Account_ID].Balance-Withdraw_amount;
        return New_Balance_after_Withdraw;
      }
    }
}

