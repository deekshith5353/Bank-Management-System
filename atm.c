#include <stdio.h>
#include <string.h>
#include "atm.h"
#include "file.h"
#include "transaction.h"
#include "validation.h"
#include <unistd.h>
int Index[MAX_ACCOUNTS];
int z;
void admin(Bank *bank)
{
    int admin_pass=716947,choice,pass;
    printf("Enter the Admin Login Password:");
    scanf("%d",&pass);
    if(pass==admin_pass)
    {do
        {   printf("\n===== ADMIN MENU =====\n");
            printf("1. Create Account\n");
            printf("2. Search Account\n");
            printf("3. List Accounts\n");
            printf("4. Edit Account\n");
            printf("5. Delete Account\n");
            printf("6. Exit\n");
            printf("Choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: createAccount(bank); break;
                case 2: searchAccount(bank); break;
                case 3: listAccounts(bank); break;
                case 4: editAccount(bank); break;
                case 5: deleteAccount(bank); break;
                case 6: exit_admin(bank); break;
                default: printf("Invalid Choice\n");
            }
        } while (choice!=6);
    }
}
void initialize(Bank *bank)
{
    loadAccounts(bank);
}
int generateAccountNumber(Bank *bank)
{
    if (bank->accountCount == 0)
        return 100001;

    int max = bank->accounts[0].accountNo;

    for(int i = 1; i < bank->accountCount; i++)
    {
        if(bank->accounts[i].accountNo > max)
            max = bank->accounts[i].accountNo;
    }

    return max + 1;
}
void createAccount(Bank *bank){
 char name[100],phone[100],email[100],pin[7];
 double balance;
    printf("\tCREATE ACCOUNT MENU\n");
    printf("\tEnter the Name:");
    scanf(" %[^\n]",name);
    if(!is_name(name)){
        return;
    }
    printf("\tEnter the Phone Number:");
    scanf(" %[^\n]",phone);
    if(!is_phone(phone)){
        return;
    }
    else if(duplicate_phone(bank,phone)){
        return;
    }
    printf("\tEnter the email:");
    scanf(" %[^\n]",email);
    if(!is_email(email)){
        return;
    }
    else if(duplicate_email(bank,email)){
        return;
    }
    printf("\tEnter the pin:");
    scanf(" %[^\n]",pin);
    if(!is_pin(pin)){
        return;
    }
    printf("Enter the balance in INR:");
    scanf("%lf",&balance);
    if(balance<500){
        printf("Minimum balance is 500\n");
        printf("Enter again:");
        scanf("%lf",&balance);
    }
    printf("Created Successfully");
    strcpy(bank->accounts[bank->accountCount].name,name);
    strcpy(bank->accounts[bank->accountCount].phone,phone);
    strcpy(bank->accounts[bank->accountCount].email,email);
    strcpy(bank->accounts[bank->accountCount].pin,pin);
    bank->accounts[bank->accountCount].accountNo=generateAccountNumber(bank);
    bank->accounts[bank->accountCount].balance=balance;
    bank->accountCount++;
}

void login(Bank *bank)
{ 
    printf("\tLogin Options\n");
    printf("\t1.login by Account No\n");
    printf("\t2.login by phone\n");
    printf("\t3.login by email\n");
    printf("\t4.Exit\n");
    printf("\tEnter your choice: ");
    int Choice;
    char str[50];
    scanf("%d", &Choice);
    switch (Choice)
    {
    case 1:
         int temp1;
         printf("\tEnter Account No:");
         scanf(" %d",&temp1);
         z=0;
         for(int i=0;i<bank->accountCount;i++){
            if(bank->accounts[i].accountNo==temp1){
               Index[z++]=i; 
            }
        }
        char temp[10];
        printf("Enter Pin:");
        scanf(" %[^\n]",temp);
        if(strcmp(bank->accounts[Index[0]].pin,temp)==0){
        if(z<=0){
        printf("\tNo Account found!!\n");
        return;}
        login_menu(bank);}
        break;
    case 2:
         printf("\tEnter Phone Number:");
         scanf(" %[^\n]",str);
         if(!is_phone(str)){
            return ;
         }
         for(int i=0;i<bank->accountCount;i++){
            if(strcmp(bank->accounts[i].phone,str)==0){
               Index[z++]=i; 
            }
        }
        printf("Enter Pin:");
        scanf(" %[^\n]",temp);
        if(strcmp(bank->accounts[Index[0]].pin,temp)==0){
        if(z<=0){
        printf("\tNo Account found!!\n");
        return;}
        login_menu(bank);}
        break;
    case 3:
        printf("\tEnter Email:");
         scanf(" %[^\n]",str);
         if(!is_email(str)){
            return ;
         }

         for(int i=0;i<bank->accountCount;i++){
            if(strcmp(bank->accounts[i].email,str)==0){
               Index[z++]=i; 
            }
        }
        printf("Enter Pin:");
        scanf(" %[^\n]",temp);
        if(strcmp(bank->accounts[Index[0]].pin,temp)==0){
        if(z<=0){
        printf("\tNo Account found!!\n");
        return;}
        login_menu(bank);}
        break;
    case 4:
      return;
    default:
       printf("Error: Invalid choice!,Try again");
    } 
    return ;
}


int searchAccount(Bank *bank){
    printf("\tSelect search criteria:\n");
    printf("\t1.search by name\n");
    printf("\t2.search by phone\n");
    printf("\t3.search by email\n");
    printf("\t4.Exit\n");
    printf("\tEnter your choice: ");
    int searchChoice;
    scanf("%d", &searchChoice);
    char str[50];
    switch (searchChoice)
    {
    case 1:
         printf("\tEnter name:");
         scanf(" %[^\n]",str);
         if(!is_name(str)){
            return 1;
         }
         z=0;
         for(int i=0;i<bank->accountCount;i++){
            if(strcmp(bank->accounts[i].name,str)==0){
               Index[z++]=i; 
            }
        }
        if(z==0)
        printf("\tNot found!!\n"); 
        break;
    case 2:
         printf("\tEnter Phone Number:");
         scanf(" %[^\n]",str);
         if(!is_phone(str)){
            return 1;
         }
         z=0;
         for(int i=0;i<bank->accountCount;i++){
            if(strcmp(bank->accounts[i].phone,str)==0){
               Index[z++]=i; 
            }
        }if(z==0)
         printf("\tNot found!!\n"); 
        break;
    case 3:
        printf("\tEnter Email:");
         scanf(" %[^\n]",str);
         if(!is_email(str)){
            return 1;
         }
         z=0;
         for(int i=0;i<bank->accountCount;i++){
            if(strcmp(bank->accounts[i].email,str)==0){
               Index[z++]=i; 
            }
        }if(z==0)
         printf("\tNot found!!\n"); 
        break;
    case 4:
        int temp;
        printf("\tEnter Account No:");
        scanf(" %d",&temp);
        z=0;
         for(int i=0;i<bank->accountCount;i++){
            if(bank->accounts[i].accountNo==temp){
               Index[z++]=i; 
            }
        }if(z==0)
         printf("\tNot found!!\n");
        break;
    default:
      return 1;
    }
printf("Account found\n");
printf("%-3s %-15s %-15s %-12s %-25s %-10s\n",
       "No", "Name", "Account No", "Phone", "Email", "Balance");
for(int i=0;i<z;i++){
printf("%-3d %-15s %-15d %-12s %-25s %-10.2lf\n",
       i+1,
       bank->accounts[Index[i]].name,
       bank->accounts[Index[i]].accountNo,
       bank->accounts[Index[i]].phone,
       bank->accounts[Index[i]].email,
       bank->accounts[Index[i]].balance);}
    return 0;
}

void listAccounts(Bank *bank)
{
    printf("\tLIST ACCOUNTS MENU");
    printf("\tSelect sort criteria:\n");
    printf("\t1. Sort by name\n");
    printf("\t2. Sort by phone\n");
    printf("\t3. Sort by email\n");
    printf("\t4. Sort by Account Number\n");
    printf("\t5. Exit\n");
    printf("\tEnter your choice: ");
    int sortChoice;
    scanf("%d", &sortChoice);
   switch(sortChoice){
    case 1: printf("Sorting by name : \n");
    for(int i=0;i<bank->accountCount-1;i++){
        for(int j=0;j<bank->accountCount-i-1;j++){
            if(strcmp(bank->accounts[j].name,bank->accounts[j+1].name)>0){
                Account temp=bank->accounts[j];
                bank->accounts[j]=bank->accounts[j+1];
                bank->accounts[j+1]=temp;
            }
        }
    }
    printf("%-3s %-15s %-15s %-12s %-25s %-10s\n",
       "No", "Name", "Account No", "Phone", "Email", "Balance");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0;i<bank->accountCount;i++){
    printf("%-3d %-15s %-15d %-12s %-25s %-10.2lf\n",
       i + 1,
       bank->accounts[i].name,
       bank->accounts[i].accountNo,
       bank->accounts[i].phone,
       bank->accounts[i].email,
       bank->accounts[i].balance);
    }
    break;
    case 2: printf("Sorting by phone : \n");
    for(int i=0;i<bank->accountCount-1;i++){
        for(int j=0;j<bank->accountCount-i-1;j++){
            if(strcmp(bank->accounts[j].phone,bank->accounts[j+1].phone)>0){
                Account temp=bank->accounts[j];
                bank->accounts[j]=bank->accounts[j+1];
                bank->accounts[j+1]=temp;
            }
        }
    }
    printf("%-3s %-15s %-15s %-12s %-25s %-10s\n",
       "No", "Name", "Account No", "Phone", "Email", "Balance");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0;i<bank->accountCount;i++){
    printf("%-3d %-15s %-15d %-12s %-25s %-10.2lf\n",
       i + 1,
       bank->accounts[i].name,
       bank->accounts[i].accountNo,
       bank->accounts[i].phone,
       bank->accounts[i].email,
       bank->accounts[i].balance);
    }
    break;
    case 3: printf("Sorting by email : \n");
    for(int i=0;i<bank->accountCount-1;i++){
        for(int j=0;j<bank->accountCount-i-1;j++){
            if(strcmp(bank->accounts[j].email,bank->accounts[j+1].email)>0){
                Account temp=bank->accounts[j];
                bank->accounts[j]=bank->accounts[j+1];
                bank->accounts[j+1]=temp;
            }
        }
    }
    printf("%-3s %-15s %-15s %-12s %-25s %-10s\n",
       "No", "Name", "Account No", "Phone", "Email", "Balance");
    printf("--------------------------------------------------------------------------------\n");
    for(int i=0;i<bank->accountCount;i++){
    printf("%-3d %-15s %-15d %-12s %-25s %-10.2lf\n",
       i + 1,
       bank->accounts[i].name,
       bank->accounts[i].accountNo,
       bank->accounts[i].phone,
       bank->accounts[i].email,
       bank->accounts[i].balance);
    }
    break;

   }
}
void editAccount(Bank *bank){
    printf("\tEDIT ACCOUNT MENU\n");
    if(searchAccount(bank)){
      return;
    };
     int ind=0;
    printf("\tEnter the Index of the contact you want to edit:");
    scanf("%d",&ind);
    if(ind<1 || ind>z)
    {printf("\tInvalid index\n");
    return;
    }
    else{
        int choice;
        printf("\t1.Edit Name\n\t2.Edit Phone Number\n\t3.Edit Email\n\t4.Exit\n\tEnter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:char str[20];
                   printf("\t Enter New name:");
                   scanf(" %[^\n]",str);
                   if(!is_name(str)){
                    return;
                   }
                   else{
                    strcpy(bank->accounts[Index[ind-1]].name,str);
                    printf("\tEdit Successfull!!");
                   }
                   break;
            case 2:printf("\t Enter New Phone Number:");
                   scanf(" %[^\n]",str);
                   if(!is_phone(str)){
                    return;
                   }
                   if(duplicate_phone(bank,str)){
                    return;
                   }
                   else{
                    strcpy(bank->accounts[Index[ind-1]].phone,str);
                    printf("\tEdit Successfull!!");
                   }
                   break;
            case 3:printf("\t Enter New Email:");
                   scanf(" %[^\n]",str);
                   if(!is_email(str)){
                    return;
                   }
                   if(duplicate_email(bank,str)){
                    return;
                   }
                   else{
                    strcpy(bank->accounts[Index[ind-1]].email,str);
                    printf("\tEdit Successfull!!");
                   }
                   break;
            case 4: return;
            default: printf("Invalid choice,Try again!");
                     return;
        }
    }

}
void deleteAccount(Bank *bank){
    printf("\tDELETE ACCOUNT MENU\n");
    if(searchAccount(bank)){
      return;
    }; 
    int ind=0;
    printf("\tEnter the Index of the contact you want to delete:");
    scanf("%d",&ind);
    if(ind<1 || ind>z)
    {printf("\tInvalid index\n");
    return;
    }
    char ch;
    printf("Are you sure you want to delete this contact Yes or No (y/n): ");
    scanf(" %c",&ch);
    if(ch=='y'||ch=='Y'){
    for(int j=Index[ind-1];j<bank->accountCount;j++)
    bank->accounts[j]=bank->accounts[j+1];
    bank->accountCount--;
    printf("Delete Successfull!!\n");
    }
    else{
        return;
    }  
}
void exit_admin(Bank *bank){
    for(int i=0;i<=100;i++){
        printf("\rSaving updates.....");
        printf("%d%%",i);
        fflush(stdout);
        usleep(10000);
        }
        printf("\nSaved succesfully\n");
    saveAccounts(bank);
};
