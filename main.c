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
int admin_controls(login_info *info){

    if(login_user(info)==0){
      printf("Login Failed.\n");
        return 0; 
    
    }
    if(strcmp(info->role,"ADMIN")!=0){
      printf("%s","Access denied, Only Admins allowed\n");

    }




    int admin_choice=0;
    
      printf("%s","1.Approve pending accounts by specifying their roles\n");
      printf("%s","2.View Pending Accounts\n");
      printf("%s","3.Unlock Users with 3 attempts\n");
      printf("%s","Enter your menu choice\n");
      scanf("%d",&admin_choice);
      getchar();

    return admin_choice; // admin_choice==0 means a failed login attempt
}

int show_pending(){
  
  FILE *fptr;
  fptr=fopen("users.txt","r");
  char user[250];
  char file_user[20];
  char file_pass[50];
  char file_role[10];
  int file_attempts=0;

    
    while (fgets(user,sizeof(user),fptr) ){
      sscanf(user,"%[^,],%[^,],%[^,],%d\n",file_user,file_pass,file_role,&file_attempts);
      if (strcmp(file_role,"pending")==0){
        printf("%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
      }
    
    }
    fclose(fptr);
    return 0;
}

int admin_approval(){
  char approve_user[20];
  int role_no;
  char user_role[10];
  char role[15];
  FILE *fptr;
  fptr=fopen("emp_roles.txt","r");

  printf("%s","Enter the username you want to approve: \n");
  fgets(approve_user,sizeof(approve_user),stdin);
  approve_user[strcspn(approve_user, "\n")] = '\0';  
  getchar();

  while(fgets(role,sizeof(role),fptr)){
    sscanf(role,"%d.%[^\n]",&role_no,user_role);
    printf("%d.%s\n",role_no,user_role);

  }
  fclose(fptr);
  printf("%s","Enter the number of the role (displayed above) you want to approve for the user: ");
  scanf("%d",&role_no);
  getchar();

  FILE * fptr1;
  FILE *temp;
  temp=fopen("temporary.txt","w");
  fptr1=fopen("users.txt","r");
  char user[250];
  char file_user[20];
  char file_pass[50];
  char file_role[20];
  int file_attempts=0;
  int success=0;
    
  while (fgets(user,sizeof(user),fptr1) ){
    sscanf(user,"%[^,],%[^,],%[^,],%d\n",file_user,file_pass,file_role,&file_attempts);
    if(strcmp(file_user,approve_user)==0){
      switch(role_no){
        case 1:
          strcpy(file_role,"QC");
          fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
          success=1;
          break;
        case 2:
          strcpy(file_role,"ADMIN");
          fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
          success=1;
          break;
        case 3:
          strcpy(file_role,"PRODUCTION");
          fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
          success=1;
          break;
        case 4:
          strcpy(file_role,"GRN");
          fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
          success=1;
          break;
        case 5:
          strcpy(file_role,"STORE"); fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
          success=1;
          break;
      }
    }else{
      fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);

    }
  }
  fclose(fptr1);
  fclose(temp);
  remove("users.txt");
  rename("temporary.txt","users.txt");

  if(success){
    printf("%s","Role Approved!\n");
  }else{
    printf("%s","Approval Failed\n");
  }

  return success;
}

int admin_unlock_user(){

  char unlock_user[20];



  printf("%s","Enter the username you want to unlock: \n");
  fgets(unlock_user,sizeof(unlock_user),stdin);
  unlock_user[strcspn(unlock_user, "\n")] = '\0';  
  getchar();

  FILE *fptr1;
  FILE *temp;
  temp=fopen("temporary.txt","w");
  fptr1=fopen("users.txt","r");
  char user[250];
  char file_user[20];
  char file_pass[50];
  char file_role[10];
  int file_attempts=0;
  int success=0;
  int found=0;
    
  while (fgets(user,sizeof(user),fptr1) ){
    sscanf(user,"%[^,],%[^,],%[^,],%d\n",file_user,file_pass,file_role,&file_attempts);
    if(strcmp(file_user,unlock_user)==0){
      if(file_attempts==3){
        file_attempts=0;
        fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts); success=1;
        found=1;
      }else{
        fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
        
      }
    }else{
      fprintf(temp,"%s,%s,%s,%d\n",file_user,file_pass,file_role,file_attempts);
    }fclose(fptr1);
  fclose(temp);
  remove("users.txt");
  rename("temporary.txt","users.txt");

  if(success){
    printf("%s","User Unlocked\n");
  }else{
    if(found){
    printf("%s","User already unlocked\n");
    }else{
      printf("%s","User not found\n");
    }
  }

  return success;
}
int last_number(const char *prefix,const char *file_name ){
  FILE *f=fopen(file_name,"r");
  char line[256];char code[50];

  int number=0;
  if (f==NULL){
    return 0;
  }

  while(fgets(line, sizeof(line),f)){
    sscanf(line,"%[^,]",code);
    if (strncmp(code,prefix,strlen(prefix))==0){

      sscanf(code+strlen(prefix),"%d",&number);
      
    }

  }
  fclose(f);
  return number;
}
void generate_code(const char *prefix,char *code,const char *file_name){
int number=last_number(prefix,file_name);
  number++;
  
  sprintf(code, "%s%03d", prefix, number);

}


int GRN(){
  FILE *f=fopen("store.txt","r");
  if(f == NULL){
    printf("store.txt not found\n");
    return 0;
  }
  int sno;
  char part_no[10];
  char part_name[50];
  char supplier_name[20];
  int price_per_unit;
  int quantity;
  char product[250];
  int sno1;
  char code[20];
  int quantity1;
  int found=0;

  while (fgets(product,sizeof(product),f)){
    sscanf(product,"%d,%[^,],%[^,],%[^,],%d,%d",&sno,part_no,part_name,supplier_name,&price_per_unit,&quantity);

    printf("%d.%s\n",sno,part_name);

  }
  fclose(f);
  printf("%s","Enter the part number you want to enter in the GRN approved: \n");
  scanf("%d",&sno1);
  getchar();

  printf("%s","Enter the quantity: \n");scanf("%d",&quantity1);
  getchar();

  generate_code("GRN",code,"GRN_approved.txt");
  FILE *f1=fopen("GRN_approved.txt","a");
  if(f1 == NULL){
    printf("Cannot open GRN_approved.txt\n");
    
    return 0;
  }
  f=fopen("store.txt","r");
  if(f == NULL){
    printf("store.txt not found\n");
    fclose(f);
    return 0;
  }


          }