

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

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include"School_database.h
/**********************************************************************************************************************/
int counter=-1;
student_t student_data[max];
int index=-1;
void MENU(void){
 printf("==========================================================\n") ;
    printf("============SCHOOL DATABASE PROJECT====================\n") ;
    printf("=======================================================\n") ;
    printf("Enter 1 for ADDING STUDENT ............................\n") ;
    printf("Enter 2 for READ EXIST DATA ...........................\n") ;
    printf("Enter 3 for DeLETE STUDENT DATA.........................\n") ;
    printf("Enter 4 for IS FULL.....................................\n") ;
    printf("Enter 5 for GET USED SIZE...............................\n") ;
    printf("Enter 6 for GET LIST ...................................\n") ;
    printf("Enter 7 for IS ID EXIST.................................\n") ;
    printf("Enter 8 for EXIT.........................................\n") ;
    printf("==========================================================\n") ;
    printf("=========================================================\n") ;
    printf("=========================================================\n") ;

}

_Bool SDB_IsFULL(void){
if(counter==max-1){
printf("SDB FULL");
return 1;
}
else{
    return 0;
}}
Uint_8 SDB_GetUsedSize(void){
Uint_8 USEDSIZE=0;
if(counter!=-1){
    Uint_8 USEDSIZE = counter+1;
    return USEDSIZE ;}

  else{
    return 0;
  }
}
_Bool SDB_AddEntry(Uint_8 id, Uint_8 year, Uint_8* subjects, Uint_8* grades){
if(SDB_IsFULL()){
    printf("no space to add new student.\n");
    return 0;
}
else{
  counter++;
  student_data[counter].student_ID=id;
  student_data[counter].Year_Of_Brith=year;
  for(int i=0;i<3;i++){
  student_data[counter].subjests[i]=subjects[i];
  student_data[counter].grades[i]=grades[i];
  }
    return 1;
}}
_Bool SDB_ReadEntry(Uint_8 id, Uint_8 *year, Uint_8* subjects, Uint_8* grades){
    if(counter==-1){
        printf("Invaild ID.\n");
        return 0;
    }
    else{
      for(int i=0;i<=counter;i++) {
       if(student_data[i].student_ID==id){
        *year=student_data[i].Year_Of_Brith;
        for(int j=0; j<3;j++){
       subjects[j]=student_data[i].subjests[j];
         grades[j]=student_data[i].grades[j];}
         return 1;
       }
      }
      return 0;
    }}
void SDB_GetIdList(Uint_8* Count,Uint_8* List){
 if(SDB_GetUsedSize()==0||SDB_GetUsedSize()<*Count){
    printf("SDB IS EMPTY.\n");
 }
 else{
    for(int i=0;i<*Count;i++){

      List[i]= student_data[i].student_ID;
      printf("%d",student_data[i].student_ID);
    }
 }

}
 void SDB_DeleteEntry(Uint_8 id){

   if(SDB_IsIdExist(id)==1){
        for(int i=0;i<counter;i++)
        student_data[index]=student_data[index+1];
   }
   counter--;
   }

_Bool SDB_IsIdExist(Uint_8 ID){

 for(int i=0;i<=counter;i++) {
       if(student_data[i].student_ID==ID){
            index=i;
            return 1;}
        return 0;

      }}
