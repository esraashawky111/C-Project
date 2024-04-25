/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       Author:  ESRAA ALI
 *       Module:
 *       Date  :
        Version:
 *  Description:
 *
 *********************************************************************************************************************/
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#define MAX_NUMBER_USERS 34


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef struct account
{
    char Account_ID ;
    char* Account_Password;
    float Balance;
}Account_t;
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void MENU(void);
_Bool validity( char Account_ID, const char *Account_Password);
char login_To_system(void);
void print_Balance(char Account_ID);
void Desposit(char Account_ID,float cash_amount);
void Transfer(char Account_ID);
float Withdraw(char Account_ID,float Withdraw_amount);
#endif // HEADER_H_INCLUDED

/**********************************************************************************************************************
 *  END OF FILE:
  *********************************************************************************************************************/
