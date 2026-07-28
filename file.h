#ifndef FILE_H
#define FILE_H

#include "atm.h"

void loadAccounts(Bank *);
void saveAccounts(Bank *);
void logTransaction(int , char *, double , double );
#endif
