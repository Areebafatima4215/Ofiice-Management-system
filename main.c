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
   while (fgets(product,sizeof(product),f)){
    sscanf(product,"%d,%[^,],%[^,],%[^,],%d,%d",&sno,part_no,part_name,supplier_name,&price_per_unit,&quantity);

    if(sno==sno1){
      fprintf(f1,"%s,%s,%s,%s,%d,%d\n",code,part_no,part_name,supplier_name,price_per_unit,quantity1);
      found=1;
      break;

    }

  }
  fclose(f);
  fclose(f1);
  if(!found){
      printf("%s","Invalid Choice.\n");
    }
    return found;
}

int GRN_to_QCP(){

  char GRN_num[10];
  char QC_code[10];

  printf("%s","Enter the GRN number for the received good to be moved to QC pending:\n");
  scanf("%s",GRN_num);
  getchar();

  FILE *f=fopen("QC_pending.txt","a");
  if(f == NULL){
    printf("Cannot open QC_pending.txt\n");
    return 0;
  }

  FILE *f1=fopen("GRN_approved.txt","r");
  if(f1 == NULL){
    printf("GRN_approved.txt not found\n");
    fclose(f);
    return 0;
    }

  char line[250];
  char GRN[10];
  char part_no[10];
  char part_name[50];
  char supplier_name[20];
  int price_per_unit;
  int quantity;
  



  int found=0;

  

  while (fgets(line,sizeof(line),f1)){
    sscanf(line,"%[^,],%[^,],%[^,],%[^,],%d,%d",GRN,part_no,part_name,supplier_name,&price_per_unit,&quantity);

    if(strcmp(GRN,GRN_num)==0){
      generate_code("QCPend",QC_code,"QC_pending.txt");
      fprintf(f,"%s,%s,%s,%s,%s,%d,%d\n",QC_code,GRN,part_no,part_name,supplier_name,price_per_unit,quantity);
      
      found=1;
      break;
    }
    
  }
  fclose(f);
  fclose(f1);
  if(!found){
    printf("%s","Invalid Choice.\n");
  }
  return found;

}

void file_viewer(const char *file_name){

  FILE *f=fopen(file_name,"r");
  if(f==NULL){
    printf("%s","Cant open file\n");
    return;
  }
  char line[500];
  printf("-------------------------------------\n");
  while(fgets(line,sizeof(line),f)){
    printf("%s\n",line);

  }
  printf("-------------------------------------\n");
  fclose(f);

}

int QC_passed(){
  char QC_pend_code[10];
  char line[300];
  printf("Enter the QC pending code of the good that you need to move to QC passed: \n");
  scanf("%s",QC_pend_code);
  getchar();

  FILE *QC_pend=fopen("QC_pending.txt","r");
  FILE *temp=fopen("temp.txt","w");
  FILE *QC_pass=fopen("QC_passed.txt","a");

  if(QC_pend == NULL || temp == NULL || QC_pass == NULL){
    printf("Error opening file(s)\n");
    return 0;
  }
  
  char QC_pend_code1[10];
  char QC_pass_code[10];
  char GRN[10];
  char part_no[10];
  char part_name[50];
  char supplier_name[20];
  int price_per_unit;
  int quantity;
  int found=0;

  while(fgets(line,sizeof(line),QC_pend)){
    sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d",QC_pend_code1,GRN,part_no,part_name,supplier_name,&price_per_unit,&quantity);

    if(strcmp(QC_pend_code1,QC_pend_code)==0){
      generate_code("QCPass",QC_pass_code,"QC_passed.txt");

      fprintf(QC_pass,"%s,%s,%s,%s,%s,%s,%d,%d\n",QC_pass_code,QC_pend_code1,GRN,part_no,part_name,supplier_name,price_per_unit,quantity);
      found=1;
      
    }else{
        fprintf(temp,"%s,%s,%s,%s,%s,%d,%d\n",QC_pend_code1,GRN,part_no,part_name,supplier_name,price_per_unit,quantity);

    }
  }


  fclose(temp);
  fclose(QC_pass);
  fclose(QC_pend);

  remove("QC_pending.txt");
  rename("temp.txt","QC_pending.txt");
  if(!found){
    printf("%s","Invalid Choice.\n");
  }else{
    printf("Record moved to QC_passed successfully.\n");
  }
  return found;
      
}

int QC_failed(){
  char QC_pend_code[10];
  char line[300];
  printf("Enter the QC pending code of the good that you need to move to QC failed: \n");
  scanf("%s",QC_pend_code);
  getchar();

  FILE *QC_pend=fopen("QC_pending.txt","r");
  FILE *temp=fopen("temp.txt","w");
  FILE *QC_fail=fopen("QC_failed.txt","a");

  if(QC_pend == NULL || temp == NULL || QC_fail == NULL){
    printf("Error opening file(s)\n");
    return 0;
  }
  
  char QC_pend_code1[10];
  char QC_fail_code[10];
  char GRN[10];
  char part_no[10];
  char part_name[50];
  char supplier_name[20];
  int price_per_unit;
  int quantity;
  int found=0;

  while(fgets(line,sizeof(line),QC_pend)){
    sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d",QC_pend_code1,GRN,part_no,part_name,supplier_name,&price_per_unit,&quantity);

    if(strcmp(QC_pend_code1,QC_pend_code)==0){
      generate_code("QCFail",QC_fail_code,"QC_failed.txt");

      fprintf(QC_fail,"%s,%s,%s,%s,%s,%s,%d,%d\n",QC_fail_code,QC_pend_code1,GRN,part_no,part_name,supplier_name,price_per_unit,quantity);
      found=1;
      
    }else{
        fprintf(temp,"%s,%s,%s,%s,%s,%d,%d\n",QC_pend_code1,GRN,part_no,part_name,supplier_name,price_per_unit,quantity);

    }
  }


  fclose(temp);
  fclose(QC_fail);
  fclose(QC_pend);

  remove("QC_pending.txt");
  rename("temp.txt","QC_pending.txt");
  if(!found){
    printf("%s","Invalid Choice.\n");
  }else{
    printf("Record moved to QC_failed successfully.\n");
  }
  return found;
      
}

int QCpend_to_STORE(){
  char QC_pass_code_user[10];
  char QC_pass_code[10];
  char QC_pend_code[10];
  char GRN[10];
  char part_no[10];
  char part_name[50];
  char supplier_name[20];
  int price_per_unit;
  int quantity;
  char line[300];
  int found=0;
  int final_quantity;
  char final_part_no[10];

  printf("Enter the QC passed code you want to update: \n");
  scanf("%s",QC_pass_code_user);
  getchar();

  FILE *QC_pass=fopen("QC_passed.txt","r");
  
  FILE *temp_pass=fopen("temporary.txt","w");
  FILE *QC_approve_record=fopen("QC_passed_approved.txt","a");

  if (!QC_pass || !temp_pass || !QC_approve_record) {
        printf("Error opening QC files.\n");
        return 0;
    }


  char store_approve_code[10];
  while(fgets(line,sizeof(line),QC_pass)){
    sscanf(line,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d,%d",QC_pass_code,QC_pend_code,GRN,part_no,part_name,supplier_name,&price_per_unit,&quantity);

    if(strcmp(QC_pass_code_user,QC_pass_code)==0){
      generate_code("QC_store_approve",store_approve_code,"QC_passed_approved.txt");
      fprintf(QC_approve_record,"%s,%s,%s,%s,%s,%s,%s,%d,%d\n",store_approve_code,QC_pass_code,QC_pend_code,GRN,part_no,part_name,supplier_name,price_per_unit,quantity);
      final_quantity=quantity;
      strcpy(final_part_no,part_no);
      found=1;
    }else{

      
      fprintf(temp_pass,"%s,%s,%s,%s,%s,%s,%d,%d\n",QC_pass_code,QC_pend_code,GRN,part_no,part_name,supplier_name,price_per_unit,quantity);
      
    }
  }
  fclose(temp_pass);
  fclose(QC_pass);
  fclose(QC_approve_record);
  
  remove("QC_passed.txt");
  rename("temporary.txt","QC_passed.txt");
  
  if(found){
    char store_line[300];

    FILE *temp2=fopen("temporary1.txt","w");
    FILE *store=fopen("store.txt","r");
    
    if (!store || !temp2) {
        printf("Error opening store files.\n");
        return 0;
      }
    int store_sno;
    char store_part_no[10];
    char store_part_name[50];
    char store_part_supplier[20];
    int store_price_per_unit;
    int store_quantity;

    while(fgets(store_line,sizeof(store_line),store)){
      sscanf(store_line,"%d,%[^,],%[^,],%[^,],%d,%d",&store_sno,store_part_no,store_part_name,store_part_supplier,&store_price_per_unit,&store_quantity);
      
      if(strcmp(final_part_no,store_part_no)==0){
        store_quantity=store_quantity+final_quantity;
        fprintf(temp2,"%d,%s,%s,%s,%d,%d\n",store_sno,store_part_no,store_part_name,store_part_supplier,store_price_per_unit,store_quantity);
      }else{
        fprintf(temp2,"%d,%s,%s,%s,%d,%d\n",store_sno,store_part_no,store_part_name,store_part_supplier,store_price_per_unit,store_quantity);
      }
    }
    fclose(store);
    fclose(temp2);
    

    remove("store.txt");
    rename("temporary1.txt","store.txt");
  }

  if(!found){
    printf("%s","Invalid Choice.\n");
  }else{
    printf("updated store record successfully.\n");
  }
  return found;
}

int PROD(login_info *info){
  file_viewer("store.txt");
  int sno;
  int quantity;
  int issued=0;

  printf("Enter the Sno. of the good that you want issued: \n");
  scanf("%d",&sno);
  getchar();

  printf("Enter the Quantity: \n");
  scanf("%d",&quantity);
  getchar();

  FILE *store=fopen("store.txt","r");
  FILE *temp=fopen("temp.txt","w");
  
  int store_sno;
  char store_part_no[10];
  char store_part_name[50];
  char store_part_supplier[20];
  int store_price_per_unit;
  int store_quantity;
  char store_line[300];
  int new_quantity;
  char selected_part_no[10];
  char selected_part_name[50];
  int selected_issued_quantity = quantity;
  int found = 0;

  while(fgets(store_line,sizeof(store_line),store)){
    sscanf(store_line,"%d,%[^,],%[^,],%[^,],%d,%d",&store_sno,store_part_no,store_part_name,store_part_supplier,&store_price_per_unit,&store_quantity);

    if(sno==store_sno){
      new_quantity=store_quantity-quantity;
      if (new_quantity>=0){
        store_quantity=new_quantity;
        issued=1;
        strcpy(selected_part_no, store_part_no);
        strcpy(selected_part_name, store_part_name);
        found = 1;
        fprintf(temp,"%d,%s,%s,%s,%d,%d\n",store_sno,store_part_no,store_part_name,store_part_supplier,store_price_per_unit,store_quantity);

      }else{
        fclose(temp);
        fclose(store);
        remove("temp.txt");
        printf("Stock unavailable");
        return issued;
        
      }
    }else{
      fprintf(temp,"%d,%s,%s,%s,%d,%d\n",store_sno,store_part_no,store_part_name,store_part_supplier,store_price_per_unit,store_quantity);
    }

  }
  fclose(store);
  fclose(temp);
  remove("store.txt");
  rename("temp.txt","store.txt");
  if (found){
    char issue_code[20];
    FILE *f=fopen("production_issue.txt","a");
    generate_code("PDI",issue_code,"production_issue.txt");
    fprintf(f,"%s,%s,%s,%d,%s\n",issue_code,selected_part_no,selected_part_name,quantity,info->username);

  fclose(f);
  }
  return issued;
}



          }