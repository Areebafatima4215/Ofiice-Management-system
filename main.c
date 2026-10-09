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

