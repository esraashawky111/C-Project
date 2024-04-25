
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------
 *       Author:  ESRAA ALI
 *       Module:
 *       Date  :15/8/2023
 *       Version:v0
 *  Description:  School Database Project
 *
 *********************************************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include "STD.H"
#include "School_database.h"
int main(){
    int choice;
 Uint_8 id ;
 Uint_32 year;
 Uint_8 subjects[3];
 Uint_8 grades[3] ;
 Uint_8 *Count, list[max] ;

    while(1){
     MENU();
     scanf("%d",&choice);
     printf("\n");
    switch(choice){
    case 1:
    printf("Enter the ID.\n");
    scanf("%d",&id);
    printf("Enter the Year of Brith.\n");
    scanf("%d",&year);
    printf(" Enter 1-for English\t,2-for MATH\t,3-for Arabic\t,4-for Programming\t ,5-for Sports \n");
    for(int i=0;i<3;i++){
    printf("Enter subject %d \n.",i);
    scanf("%d",&subjects[i]);
    printf("Enter grade %d\n.",i);
    scanf("%d",&grades[i]);
     }
    SDB_AddEntry(id,year,subjects,grades);
    break;

           case 2:
            printf("Enter the ID.\n");
            scanf("%d",&id);
            Uint_8 ret= SDB_ReadEntry(id,&year,subjects,grades);
            printf("%d",ret);
            break;

            case 3:;
            printf("Enter the ID.\n");
            scanf("%d",&id);
             SDB_DeleteEntry(id);
            break;

            case 4:;
             Uint_8 retu= SDB_IsFULL();
             printf("%d",retu);
            break;


            case 5:;
              Uint_8 size = SDB_GetUsedSize();
              printf("%d",size);
            break;
            case 6:;
                printf("Enter COUNT\n");
                scanf("%d",Count);
                SDB_GetIdList(Count,list);
                break;
            case 7:;
             printf("Enter the ID.\n");
             scanf("%d",&id);
            Uint_8 x =SDB_IsIdExist (id);
            printf("%d",x);
            break;
            case 8:
                exit(0);

            default:
                printf(".............wrong choice................\n");
        }
    }

    return 0;
}






