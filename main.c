#include <stdio.h>
#include <string.h>


typedef struct{

  char username[20];
  char password[50];
  int attempts;
  char role[10];
  int success;
}login_info;
int start_menu(){
  int choice;
  printf("\n=======================================================\n");
  printf("OFFICE MANAGEMENT SYSTEM");
  printf("========================================================\n");
  printf("%s","1. Login\n");
  printf("%s","2. Create Account\n");
  printf("%s","3. Admin Login and controls\n");
  printf("%s","4. Exit\n");

  printf("%s","Enter your menu choice\n");
  scanf("%d",&choice);
  return choice;
}

//===================LOGIN FUNCTION============
int login_user(login_info *info)
{
    printf("\n============ LOGIN================\n");
    printf("Enter usenmae:");
    scanf("%19s", info->username);
    printf("Enter password:");
    scanf("%49s",info->password);
    printf("\nLogin information received .\n");
    return 1;
}

//========================== CREATE ACCOUNT =============
int create_acc(login_info *info)
{
 printf("\n============ CREATE ACCOUNT ================\n");
    printf("Enter usenmae:");
    scanf("%19s", info->username);
    printf("Enter password:");
    scanf("%49s",info->password);
    printf("Enter role(Admin/USER):");
    scanf("%9s", info->role);
    printf("\nAccount information received.\n");
    return 1;
}

