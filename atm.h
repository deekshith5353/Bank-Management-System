#ifndef ATM_H
#define ATM_H

#define MAX_ACCOUNTS 100
#define MAX_HISTORY 1000
extern int Index[MAX_ACCOUNTS];
extern int z;
#define R   "\033[31m"
#define G   "\033[32m"
#define Y   "\033[93m"
#define B   "\033[94m"
#define RS  "\033[0m"
typedef struct
{
    int accountNo;
    char name[50];
    char phone[15];
    char email[50];
    char pin[7];
    double balance;
}Account;

typedef struct
{
    Account accounts[MAX_ACCOUNTS];
    int accountCount;
}Bank;
  
typedef struct
{  char transactionID[16]; 
   int accountNo;
   char type[40];
   double amount;
   double balance;
   char date[11];
   char time[9];  
}history;

void initialize(Bank *);
void createAccount(Bank *);
void login(Bank *);
int searchAccount(Bank *);
void listAccounts(Bank *);
void editAccount(Bank *);
void deleteAccount(Bank *);
void admin(Bank *);
void exit_admin(Bank *);
#endif
