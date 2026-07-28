#include <stdio.h>
#include <unistd.h>
#include "atm.h"

int main(void)
{
    Bank bank;
    initialize(&bank);

    int choice,choice1;

    do
    {   printf("1. Login\n");
        printf("2. Admin Login\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: login(&bank); break;
        case 2: admin(&bank); break;
        case 3: for(int i=0;i<=100;i++){
                printf("\rTerminating Session.....");
                printf("%d%%",i);
                fflush(stdout);
                usleep(10000);
                }
                printf("\nSession Terminated!!\n");
                return 1; 
        default:printf("Invalid choice!\n");
        }
    }while(choice!=3);
    return 0;

}