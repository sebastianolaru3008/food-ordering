#include <stdio.h>
#include "inputFunctions.h"

void signInForm(char *username, char *password)
{
    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue!\n");
    printf("--Username\n");
    gets(username);
    printf("--Password\n");
    gets(password);
}

void choiceAnalyser(char *labelChoice)
{
    char choice = getchar();
    fflush(stdin);
    *labelChoice = choice - 'a';
}