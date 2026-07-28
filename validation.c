#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "validation.h"
#include "atm.h"

int is_name(char str[])//FOR VALIDATION:to check if entered name meets all the validation
{   int count = 0;
    name:
        int valid = 1;
        if(strlen(str)<4){
            valid=0;
            printf("\tError : Name must contain atleast 4 characters\n");
        }
        for (int i = 0; str[i] != '\0'; i++)
        {
            if (!isalpha(str[i]) && str[i] != ' ')
            {   
                printf("\tError : Name can contain only Alphabets\n");
                valid = 0;
                break;
            }
        }
       if (count >= 3){
        printf("\tError :To many invalid attempts\n");
        return 0;}
        if(!valid){
            printf("\tEnter again: ");
            scanf(" %[^\n]",str);
            count++;
            goto name;
        }   
        return 1;   
}
int is_phone(char str[])//FOR VALIDATION:to check if entered phone meets all the validation
{
    int count = 0;
    phone:
    int valid = 1;
    if (strlen(str) != 10){
        valid = 0;
        printf("\tError :Number should have 10 digits\n");}
    if (str[0] < '6' || str[0] > '9'){
        valid = 0;
        printf("\tError :First digit must be between 6 and 9\n");
    }
   for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            valid = 0;
            printf("\tError :Only digits are allowed in phone number\n");
            break;
        }
    }
     if (count >= 3){
        printf("\tError :Too many invalid attempts\n");
        return 0;}
    if (!valid)
    {
        printf("\t Enter again: ");
        scanf(" %[^\n]", str);
        count++;
        goto phone;
    }
    return 1;
}
int is_email(char str[])//FOR VALIDATION:to check if entered email meets all the validation
{
    int count = 0;
    email:
    int valid = 1;
    int at = 0, dot = 0;
    int at_pos = -1, dot_pos = -1;

    if (isdigit(str[0])){
        printf("\tError :First charactor should be alphabet\n");
        valid = 0;}
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '@')
        {
            at++;
            at_pos = i;
        }
        else if (str[i] == '.')
        {
            dot++;
            dot_pos = i;
        }
        else if (!(islower(str[i]) || isdigit(str[i]) ))
        {   printf("\tError :email needs to be in lower case and cannot contain any special charactors other than""@""and"".""\n");
            valid = 0;
            break;
        }
    }
    if (at != 1){
        printf("\tError :only one ""@"" is allowed\n");
        valid = 0;}
    if (dot != 1 || dot_pos < at_pos){
        printf("\tError :only one ""."" is allowed and ""."" can appear only after ""@"" \n");
        valid = 0;}
    if (at_pos == 0){
        valid = 0;}
    if (dot_pos == at_pos+1){
        printf("\tError :Domain not found\n");
        valid = 0;}
    if (valid)
        for (int i = at_pos + 1; i < dot_pos; i++)
            if (!isalpha(str[i]))
            {   printf("\tError :Domain can only be of alphabets\n");
                valid = 0;
                break;
            }
    if (strlen(str) < 5 || strcmp(str + strlen(str) - 4, ".com") != 0){
        valid = 0;
        printf("\tError :email should end with .com\n");
    }
    if (count >= 3){
        printf("\tError :To0 many invalid attempts\n");
        return 0;}
    if (!valid)
    {
        printf("\tEnter again: ");
        scanf(" %[^\n]", str);
        count++;
        goto email;
    }
    return 1;
}
int is_pin(char str[])
{   int count = 0;
    pin:
    int valid = 1;
    if (strlen(str) != 6){
        valid = 0;
        printf("\tError :Number should have 6 digits\n");}
   for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            valid = 0;
            printf("\tError :Only digits are allowed in pin\n");
            break;
        }
    }
     if (count >= 3){
        printf("\tError :Too many invalid attempts\n");
        return 0;}
    if (!valid)
    {
        printf("\t Enter again: ");
        scanf(" %[^\n]", str);
        count++;
        goto pin;
    }
    return 1;
}
int duplicate_phone( Bank *bank, char phone[])//FOR VALIDATION:to check if entered number is unique 
{   int count=0;
    while (count<3)
    { int found=0;
    for (int i = 0; i < bank->accountCount; i++)
    {
        if (strcmp(bank->accounts[i].phone, phone) == 0){
            printf("\tphone number already exists! Enter again: ");
            scanf(" %[^\n]", phone);
            if(!is_phone(phone)){
             printf("Error:Too many Invalid attempts"); 
             return 1;  
            }
            found=1;
            count++;
            break;
        }    
    } 
    if(!found)
        return 0; 
    }
    printf("Error:Too many Invalid attempts");
    return 1;
}
int duplicate_email(Bank *bank, char email[])//FOR VALIDATION:to check if entered email is unique
{   int count=0;
    while(count<3){
        int found=0;
    for (int i = 0; i < bank->accountCount; i++)
    {
        if (strcmp(bank->accounts[i].email, email) == 0){
            printf("\tEmail already exists! Enter again: ");
            scanf(" %[^\n]", email);
            if(!is_email(email)){
            printf("Error:Too many Invalid attempts"); 
             return 1;  
            }
            found=1;
            count++;
            break;
        }
    }
    if(!found)
    return 0;
    }
    printf("Error:Too many Invalid attempts");
    return 1;   
}