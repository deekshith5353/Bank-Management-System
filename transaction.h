#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "atm.h"

void deposit(Bank*);
void withdraw(Bank*);
void transfer(Bank*);
void balanceEnquiry(Bank*);
void miniStatement(Bank*);
void viewMiniStatement(Bank*);
void exportMiniStatement(Bank*);
void login_menu(Bank*);
void generateTransactionID(char []);
#endif
