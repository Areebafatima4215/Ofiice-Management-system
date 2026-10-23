#include <stdio.h>
#include <string.h>


typedef struct{

  char username[20];
  char password[50];
  int attempts;
  char role[10];
  int success;
}login_info;
//menu when the app starts
int start_menu();

//functions when the application starts
int login_user(login_info *info);
int create_acc(login_info *info);
int admin_controls(login_info *info);

//admin menu functions
int admin_approval();
int show_pending();
int admin_unlock_user();
//system functions

//GRN
int GRN();
int GRN_to_QCP();

//QC

int QC_passed();
int QC_failed();

//STORE
int QCpend_to_STORE();

//PRODUCTION
int PROD(login_info *info);

//code generator
int last_number(const char *prefix,const char *file_name);
void generate_code(const char *prefix,char *code,const char *file_name);

//File viewer
void file_viewer(const char *file_name);
switch (main_choice) {
            case 1: // Login
                if (login_user(&user_info)) {
                    printf("\nLogin successful! Welcome, %s (%s)\n", user_info.username, user_info.role);
                    int role_choice;

                    // -------------------- ADMIN MENU --------------------
                    if (strcmp(user_info.role, "ADMIN") == 0) {
                        do {
                            printf("\n--- ADMIN MENU ---\n");
                            printf("1. Approve users\n");
                            printf("2. View pending users\n");
                            printf("3. Unlock user\n");
                            printf("4. Create GRN\n");
                            printf("5. View GRN Approved\n");
                            printf("6. View QC Pending\n");
                            printf("7. View QC Passed\n");
                            printf("8. View QC Failed\n");
                            printf("9. View Store\n");
                            printf("10. Logout\n");
                            printf("Enter your choice: ");
                            scanf("%d", &role_choice);
                            getchar();
                            switch (role_choice) {
                                case 1: admin_approval(); break;
                                case 2: show_pending(); break;
                                case 3: admin_unlock_user(); break;
                                case 4: GRN(); break; // Create GRN
                                case 5: file_viewer("GRN_approved.txt"); break;
                                case 6: file_viewer("QC_pending.txt"); break;
                                case 7: file_viewer("QC_passed.txt"); break;
                                case 8: file_viewer("QC_failed.txt"); break;
                                case 9: file_viewer("store.txt"); break;
                                case 10: printf("Logging out...\n"); break;
                                default: printf("Invalid choice.\n");
                            }
                             if (role_choice != 10) printf("\nPress Enter to continue...");
                            getchar();

                        } while (role_choice != 10);
                    }
                     if (role_choice != 10) printf("\nPress Enter to continue...");
                            getchar();

                        } while (role_choice != 10);
                    }
                     // -------------------- QC MENU --------------------
                    else if (strcmp(user_info.role, "QC") == 0) {
                        do {
                            printf("\n--- QC MENU ---\n");
                            printf("1. Move QC Pending to Passed\n");
                            printf("2. Move QC Pending to Failed\n");
                            printf("3. View QC Pending\n");
                            printf("4. View QC Passed\n");
                            printf("5. View QC Failed\n");
                            printf("6. Logout\n");
                            printf("Enter your choice: ");
                            scanf("%d", &role_choice);
                            getchar();
                            switch (role_choice) {
                                case 1: QC_passed(); break;
                                case 2: QC_failed(); break;
                                case 3: file_viewer("QC_pending.txt"); break;
                                case 4: file_viewer("QC_passed.txt"); break;
                                case 5: file_viewer("QC_failed.txt"); break;
                                case 6: printf("Logging out...\n"); break;
                                default: printf("Invalid choice.\n");
                            }
                            if (role_choice != 6) printf("\nPress Enter to continue...");
                            getchar();

                        } while (role_choice != 6);
                    }
                     // -------------------- PRODUCTION MENU --------------------
                    else if (strcmp(user_info.role, "PRODUCTION") == 0) {
                        do {
                            printf("\n--- PRODUCTION MENU ---\n");
                            printf("1. Issue Products\n");
                            printf("2. View Store\n");
                            printf("3. View Production Issues\n");
                            printf("4. Logout\n");
                            printf("Enter your choice: ");
                            scanf("%d", &role_choice);
                            getchar();
                             switch (role_choice) {
                                case 1: PROD(&user_info); break;
                                case 2: file_viewer("store.txt"); break;
                                case 3: file_viewer("production_issue.txt"); break;
                                case 4: printf("Logging out...\n"); break;
                                default: printf("Invalid choice.\n");
                            }
                            if (role_choice != 4) printf("\nPress Enter to continue...");
                            getchar();

                        } while (role_choice != 4);
                    }
                     // -------------------- STORE ROLE MENU --------------------
                    else if (strcmp(user_info.role, "STORE") == 0) {
                        do {
                            printf("\n--- STORE MENU ---\n");
                            printf("1. Move QC Passed to Store\n");
                            printf("2. View Store\n");
                            printf("3. View Production Issue\n");
                            printf("4. View QC passed\n");
                            printf("5. View QC passed approved/added by store\n");
                            printf("6. Logout\n");
                            printf("Enter your choice: ");
                            scanf("%d", &role_choice);
                            getchar();

                            switch (role_choice) {
                                case 1: QCpend_to_STORE(); break;
                                case 2: file_viewer("store.txt"); break;
                                case 3: file_viewer("production_issue.txt"); break;
                                case 4: file_viewer("QC_passed.txt"); break;
                                case 5: file_viewer("QC_passed_approved.txt"); break;
                                 case 6: printf("Logging out...\n"); break;
                                default: printf("Invalid choice.\n");
                            }
                            if (role_choice != 6) printf("\nPress Enter to continue...");
                            getchar();

                        } while (role_choice != 6);
                    }

                    else {
                        printf("Role not recognized. Contact admin.\n");
                        printf("\nPress Enter to continue...");
                        getchar();
                    }
                } else {
                     printf("Login failed. Try again.\n");
                    printf("\nPress Enter to continue...");
                    getchar();
                }
                break;

            case 2: // Create Account
                create_acc(&user_info);
                printf("\nPress Enter to continue...");
                getchar();
                break;
                
            case 3: // Admin controls
                admin_controls(&user_info);
                printf("\nPress Enter to continue...");
                getchar();
                break;

            case 4: // Exit
                printf("Exiting...\n");
                return 0;

            default:
             printf("Invalid choice.\n");
                printf("\nPress Enter to continue...");
                getchar();
        }
    }

    return 0;
}



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

int login_user(login_info *info){

  char username[20];
  char password[50];
  info->success=0;
  int count=0;
  int found=0;
  getchar();
  
  while(count<3 && info->success==0){

    printf("%s","Enter your username: \n");
    fgets(username,sizeof(username),stdin);
    username[strcspn(username, "\n")] = '\0';
  
    printf("%s","Enter your password: \n");
    fgets(password,sizeof(password),stdin);
    password[strcspn(password, "\n")] = '\0';
     FILE *fptr;
    FILE *tempo;
    

    fptr=fopen("users.txt","r");
    tempo=fopen("temporary.txt","w");
    if (!fptr || !tempo) {
      printf("File error!\n");
      return 0;
    }
    
    char user[250];
    char file_user[20];
    char file_pass[50];
    char file_role[10];
    int file_attempts=0; found=0;
    
    
    
    
    while (fgets(user,sizeof(user),fptr) ){
      sscanf(user,"%[^,],%[^,],%[^,],%d\n",file_user,file_pass,file_role,&file_attempts);

      

      if(strcmp(file_user,username)==0 ){
          found=1;

        if(file_attempts<3){ 

          if(strcmp(file_pass,password)==0){
            info->success=1;
            strcpy(info->role,file_role);
            strcpy(info->username,username);
            strcpy(info->password,password);
            printf("%s","login successful\n");
            fprintf(tempo,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
else{

            file_attempts++;
            fprintf(tempo,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
            printf("Wrong password. Attempts left: %d\n", 3 - file_attempts);
          }
        }else{
          printf("%s","Account Locked\n");
          fprintf(tempo,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
        }

      }else{
        fprintf(tempo,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
      }
    }
  
    fclose(fptr);
    fclose(tempo);
    remove("users.txt");
    rename("temporary.txt","users.txt");
    count++;
    
    if(info->success==1){
      return 1;
    printf("%s","Login failed. Account may now be locked.\n");
    return 0;
}


int create_acc(login_info *info){

  char new_username[20];
  char new_password[50];
  char confirm_password[50];
  getchar();

  printf("%s","Enter the username you want: \n");
  fgets(new_username,sizeof(new_username),stdin);
  new_username[strcspn(new_username, "\n")] = '\0';
  

  printf("%s","Enter your password: ");
  fgets(new_password,sizeof(new_password),stdin);
   new_password[strcspn(new_password, "\n")] = '\0';
  

  do{

      printf("%s","Please correctly confirm your password: \n");
      fgets(confirm_password,sizeof(confirm_password),stdin);
      confirm_password[strcspn(confirm_password, "\n")] = '\0';
      

  }while(strcmp(new_password,confirm_password)!=0);

  FILE *fptr;
   char user[250];
  int found=1;
  fptr=fopen("users.txt","r");
  char *column;
  
  
  while(found){
    found=0;
    rewind(fptr);
    while (fgets(user,sizeof(user),fptr)){
      column=strtok(user,",");

      if(strcmp(column,new_username)==0){
        printf("%s","Username already in use!\n");
        found=1;
        break;
      }
    }if(found==1){ printf("%s","Enter the username you want again: \n");
    fgets(new_username,sizeof(new_username),stdin);
    new_username[strcspn(new_username, "\n")] = '\0';
    getchar();
    }
    

  }
  fclose(fptr);
  fptr=fopen("users.txt","a");
 fprintf(fptr,"%s,%s,%s,%d\n",new_username,confirm_password,"pending",0);
  fclose(fptr);
  info->success=1;
  info->attempts=0;
  strcpy(info->role,"pending");
  strcpy(info->username,new_username);
  strcpy(info->password,confirm_password);

  printf("%s","Account created successfully\n");
  return 1;
}

          }