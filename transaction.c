#include "transaction.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include "atm.h"
#include "file.h"
#include "validation.h"
void login_menu(Bank* bank){
    int Choice=0;
    do
    {printf("\t1.Deposit\n");
    printf("\t2.Withdraw\n");
    printf("\t3.Transfer\n");
    printf("\t4.Balance Enquiry\n");
    printf("\t5.Mini Statement\n");
    printf("\t6.Exit\n");
    printf("\tEnter your choice: ");
    scanf("%d",&Choice);
    switch(Choice){
    case 1:deposit(bank); 
                   break;
    case 2:withdraw(bank); 
                   break;
    case 3:transfer(bank); 
                   break;
    case 4:balanceEnquiry(bank); 
                   break;
    case 5: miniStatement(bank); 
                   break;
    case 6: saveAccounts(bank);
            for(int i=0;i<=100;i++){
                printf("\rTerminating Session.....");
                printf("%d%%",i);
                fflush(stdout);
                usleep(10000);
                }
                printf("\nSession Terminated!!\n");
                return ; 
    default:printf("Invalid Choice");

    }
    } while(Choice!=6);
}
void deposit(Bank *bank){
    double amt;
    printf("\tEnter the amount you would deposite in INR:");
    scanf("%lf",&amt);
    if(amt<=0)
    {
    printf("Invalid Amount!!\n");
    return;
    }
    bank->accounts[Index[0]].balance+=amt;
    logTransaction(bank->accounts[Index[0]].accountNo,"Deposit",amt,bank->accounts[Index[0]].balance);
    printf("Deposited Succesfully!\n");
}
void withdraw(Bank *bank){
    double amt,temp;
    printf("\tEnter the amount you would Withdraw in INR:");
    scanf("%lf",&amt);
    if(amt<=0)
        {
        printf("Invalid Amount!!\n");
        return;
        }
    temp=bank->accounts[Index[0]].balance-amt;
    if(temp<500){
        printf("Insufficient Balance!!");
        return;
    }
    bank->accounts[Index[0]].balance=temp;
    logTransaction(bank->accounts[Index[0]].accountNo,"Withdrawn",amt,bank->accounts[Index[0]].balance);
    printf("Withdrawn Succesfully!\n");
}
void transfer(Bank* bank){
    printf("\tTRANSFER Options\n");
    printf("\t1.transfer by Account No\n");
    printf("\t2.transfer by phone\n");
    printf("\t3.transfer by email\n");
    printf("\t4.Exit\n");
    printf("\tEnter your choice: ");
    int Choice;
    char str[50];
    z=-1;
    scanf("%d", &Choice);
    switch (Choice)
    {
    case 1:
         int temp1;
         printf("\tEnter Account No:");
         scanf("%d",&temp1);
         for(int i=0;i<bank->accountCount;i++){
            if(bank->accounts[i].accountNo==temp1){
               z=i; 
            }
        }
        if(z==Index[0]){
        printf("Cannot transfer to same account!!\n");
        return;
        }
        if(z<0){
        printf("\tNo Account found!!\n");
        return;}
        double amt;
        char check;
        printf("Enter the amount you would transfer:");
        scanf(" %lf",&amt);
        printf("Are you sure you want to transfer Rs%0.2lf to %s (y/n)",amt,bank->accounts[z].name);
        scanf(" %c",&check);
        double temp2=bank->accounts[Index[0]].balance-amt;
        if(temp2<500){
            printf("\tError:Exceeds Minimum balance\n");
            printf("Transfer canceled");
            return;
        }
        else if(check=='y'){
            bank->accounts[Index[0]].balance=temp2;
            bank->accounts[z].balance+=amt;
            saveAccounts(bank);
            for(int i=0;i<=100;i++){
                printf("\rTransfering amount to %s.....",bank->accounts[z].name);
                printf("%d%%",i);
                fflush(stdout);
                usleep(10000);
                }
                char type[100];
                sprintf(type, "Transfer to %s", bank->accounts[z].name);
                logTransaction(bank->accounts[Index[0]].accountNo,type,amt,bank->accounts[Index[0]].balance);
                printf("\nTransfer Succesfull!!\n");
                return ; 
        }

        break;
    case 2:
         printf("\tEnter Phone Number:");
         scanf(" %[^\n]",str);
         if(!is_phone(str)){
            return ;
         }
         for(int i=0;i<bank->accountCount;i++){
            if(strcmp(bank->accounts[i].phone,str)==0){
               z=i; 
            }
        }
        if(z==Index[0]){
        printf("Cannot transfer to same account!!\n");
        return;
        }
        if(z<0){
        printf("\tNo Account found!!\n");
        return;}
        printf("Enter the amount you would transfer:");
        scanf(" %lf",&amt);
        printf("Are you sure you want to transfer Rs%0.2lf to %s (y/n)",amt,bank->accounts[z].name);
        scanf(" %c",&check);
        temp2=bank->accounts[Index[0]].balance-amt;
        if(temp2<500){
            printf("\tError:Exceeds Minimum balance\n");
            printf("Transfer canceled");
            return;
        }
        else if(check=='y'){
            bank->accounts[Index[0]].balance=temp2;
            bank->accounts[z].balance+=amt;
            saveAccounts(bank);
            for(int i=0;i<=100;i++){
                printf("\rTransfering amount to %s.....",bank->accounts[z].name);
                printf("%d%%",i);
                fflush(stdout);
                usleep(10000);
                }
                char type[100];
                sprintf(type, "Transfer to %s", bank->accounts[z].name);
                logTransaction(bank->accounts[Index[0]].accountNo,type,amt,bank->accounts[Index[0]].balance);
                printf("\nTransfer Succesfull!!\n");
                return ; 
        }
        break;
    case 3:
        printf("\tEnter Email:");
         scanf(" %[^\n]",str);
         if(!is_email(str)){
            return ;
         }
         for(int i=0;i<bank->accountCount;i++){
            if(strcmp(bank->accounts[i].email,str)==0){
               z=i; 
            }
        }
        if(z==Index[0]){
        printf("Cannot transfer to same account!!\n");
        return;
        }
        if(z<0){
        printf("\tNo Account found!!\n");
        return;}
        printf("Enter the amount you would transfer:");
        scanf(" %lf",&amt);
        printf("Are you sure you want to transfer Rs%0.2lf to %s (y/n)",amt,bank->accounts[z].name);
        scanf(" %c",&check);
        temp2=bank->accounts[Index[0]].balance-amt;
        if(temp2<500){
            printf("\tError:Exceeds Minimum balance\n");
            printf("Transfer canceled");
            return;
        }
        else if(check=='y'){
            bank->accounts[Index[0]].balance=temp2;
            bank->accounts[z].balance+=amt;
            saveAccounts(bank);
            for(int i=0;i<=100;i++){
                printf("\rTransfering amount to %s.....",bank->accounts[z].name);
                printf("%d%%",i);
                fflush(stdout);
                usleep(10000);
                }
                char type[100];
                sprintf(type, "Transfer to %s", bank->accounts[z].name);
                logTransaction(bank->accounts[Index[0]].accountNo,type,amt,bank->accounts[Index[0]].balance);
                printf("\nTransfer Succesfull!!\n");
                return ; 
        }
        break;
    case 4:
      return;
    default:
       printf("Error: Invalid choice!,Try again");
    } 
    return ;
}
void balanceEnquiry(Bank* bank){
    char str[10];
    printf("Enter the pin:");
    scanf(" %[^\n]",str);
    if(strcmp(bank->accounts[Index[0]].pin,str)==0){
    printf("Balance: %g Rs",bank->accounts[Index[0]].balance);
    }
    return;
}
void miniStatement(Bank *bank)
{
    int choice;

    printf("\n====== MINI STATEMENT ======\n");
    printf("1. View Statement\n");
    printf("2. Export Statement (.txt)\n");
    printf("3. Back\n");
    printf("Choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1:
            viewMiniStatement(bank);
            break;

        case 2:
            exportMiniStatement(bank);
            break;

        case 3:
            return;

        default:
            printf("Invalid Choice\n");
    }
}
int loadHistory(history h[])
{
    int count = 0;

    FILE *fp = fopen("history.csv","r");

    if(fp == NULL)
    {
        printf("History file not found\n");
        return 0;
    }
while ((fscanf(fp,
    " %15[^,],%d,%99[^,],%lf,%lf,%10[^,],%8s",
    h[count].transactionID,
    &h[count].accountNo,
    h[count].type,
    &h[count].amount,
    &h[count].balance,
    h[count].date,
    h[count].time)) == 7)
{
    count++;
}
    fclose(fp);
    return count;
}
void viewMiniStatement(Bank *bank)
{
    char pin[10];

    printf("Enter PIN : ");
    scanf(" %[^\n]",pin);

    if(strcmp(bank->accounts[Index[0]].pin,pin)!=0)
    {
        printf("Wrong PIN\n");
        return;
    }

    history h[1000];
    int count = loadHistory(h);

    printf(Y "%-16s %-12s %-10s %-12s %-12s %-20s\n" RS,
           "Transaction ID","Date","Time","Amount","Balance","Transaction Type");
    printf(B"------------------------------------------------------------------------------------------------------------\n"RS);
    
      int printed = 0;

    for(int i=count-1;i>=0 && printed<10;i--)
    {
        if(h[i].accountNo != bank->accounts[Index[0]].accountNo)
            continue;

        printed++;

        if(strcmp(h[i].type,"Deposit")==0)
        {
            printf("%-16s %-12s %-10s %s %+12.2lf %s %12.2lf\t%-20s\n",
                   h[i].transactionID,h[i].date,h[i].time,G,
                   h[i].amount,RS,h[i].balance,h[i].type);
        }
        else if(strcmp(h[i].type,"Withdrawn")==0)
        {
            printf("%-16s %-12s %-10s %s %12.2lf %s %12.2lf\t%-20s\n",
                   h[i].transactionID,h[i].date,h[i].time,R,
                   h[i].amount,RS,h[i].balance,h[i].type);
        }
        else if(strncmp(h[i].type,"Transfer",8)==0)
        {
            printf("%-16s %-12s %-10s %s %12.2lf %s %12.2lf\t%-20s\n",
                   h[i].transactionID,h[i].date,h[i].time,R,
                   -h[i].amount,RS,h[i].balance,h[i].type);
        }
    }
}
void exportMiniStatement(Bank *bank)
{
    char pin[10];

    printf("Enter PIN : ");
    scanf(" %[^\n]",pin);

    if(strcmp(bank->accounts[Index[0]].pin,pin)!=0)
    {
        printf("Wrong PIN\n");
        return;
    }

    history h[1000];
    int count = loadHistory(h);

    time_t now=time(NULL);
    struct tm *t=localtime(&now);

    char fileName[100];
    sprintf(fileName,"statement_%d_%02d-%02d-%04d.txt",
            bank->accounts[Index[0]].accountNo,
            t->tm_mday,t->tm_mon+1,t->tm_year+1900);

    char path[150]="statements/";
    strcat(path,fileName);

    FILE *out=fopen(path,"w");

    if(out==NULL)
    {
        printf("Unable to create file\n");
        return;
    }

    fprintf(out,"==========================================================================================================\n");
    fprintf(out,"\t\t\t\t\t\t\t\t\t\tATM MINI STATEMENT\n");
    fprintf(out,"==========================================================================================================\n\n");
    fprintf(out,"Name        : %s\n",bank->accounts[Index[0]].name);
    fprintf(out,"Account No. : %d\n",bank->accounts[Index[0]].accountNo);
    fprintf(out,"Current Bal : %.2lf INR\n\n",bank->accounts[Index[0]].balance);

    fprintf(out,"%-16s %-12s %-10s %-12s %-12s %-20s\n",
            "Transaction ID","Date","Time","Amount","Balance","Transaction Type");

    int printed=0;

    for(int i=count-1;i>=0 && printed<10;i--)
    {
        if(h[i].accountNo != bank->accounts[Index[0]].accountNo)
            continue;

        printed++;

        double amt=h[i].amount;

        if(strcmp(h[i].type,"Withdrawn")==0 || strncmp(h[i].type,"Transfer",8)==0)
            amt=-amt;

        fprintf(out,"%-16s %-12s %-10s %+10.2lf %12.2lf  %-20s\n",
                h[i].transactionID,h[i].date,h[i].time,amt,h[i].balance,
                h[i].type);
    }
    fprintf(out,"==========================================================================================================\n");
    fprintf(out,"\t\t\t\t\t\t\t\t\t\tTHANK YOU FOR BANKING\n");
    fprintf(out,"==========================================================================================================\n\n");
    fclose(out);                                                                               

    printf("\nStatement exported successfully.\n");
    printf("Saved as : %s\n",path);
}
void generateTransactionID(char id[])
{
    static const char ch[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    static int seeded=0;

    if(!seeded)
    {
        srand(time(NULL));
        seeded=1;
    }

    strcpy(id,"ZORO");

    for(int i=4;i<15;i++)
        id[i]=ch[rand()%36];

    id[15]='\0';
}
