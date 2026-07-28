#include <stdio.h>
#include "file.h"
#include"transaction.h"

void loadAccounts(Bank *bank)
{
    FILE *fp=fopen("accounts.csv","r");
    if(fp==NULL)
    {
        bank->accountCount=0;
        return;
    }
    bank->accountCount=0;
    while (fscanf(fp,
                  "%d,%49[^,],%14[^,],%49[^,],%9[^,],%lf",
                  &bank->accounts[bank->accountCount].accountNo,
                  bank->accounts[bank->accountCount].name,
                  bank->accounts[bank->accountCount].phone,
                  bank->accounts[bank->accountCount].email,
                  bank->accounts[bank->accountCount].pin,
                  &bank->accounts[bank->accountCount].balance) == 6)
    {
        bank->accountCount++;
    }

    fclose(fp);
}

void saveAccounts(Bank *bank)
{
    FILE *fp=fopen("accounts.csv","w");
    if(fp==NULL) return;

    for (int i = 0; i < bank->accountCount; i++)
    {
        fprintf(fp, "%d,%s,%s,%s,%s,%.2lf\n",
                bank->accounts[i].accountNo,
                bank->accounts[i].name,
                bank->accounts[i].phone,
                bank->accounts[i].email,
                bank->accounts[i].pin,
                bank->accounts[i].balance);
    }

    fclose(fp);
}
#include <time.h>

void logTransaction(int accountNo, char *type, double amount, double balance)
{
    FILE *fp = fopen("history.csv", "a");
    if(fp == NULL)
    {
        printf("Unable to open file\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char id[20];
    generateTransactionID(id);
    fprintf(fp, "%s,%d,%s,%.2lf,%.2lf,%02d-%02d-%04d,%02d:%02d:%02d\n",id,
            accountNo,
            type,
            amount,
            balance,
            t->tm_mday,
            t->tm_mon + 1,
            t->tm_year + 1900,
            t->tm_hour,
            t->tm_min,
            t->tm_sec);

    fclose(fp);
}