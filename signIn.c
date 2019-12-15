#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "signIn.h"
#include "userData.h"

void chooseSignInOrUp(int *state) {

    printf("%s\n", SIGN_IN_UP);
    printf("a) %s\n", SIGN_IN);
    printf("b) %s\n ", SIGN_UP);

    char choice = getchar();
    getchar();

    if (choice == 'a') *state = 7;
    else *state = 8;
}

void signInProcess(char **usernames, char **passwords, int noOfUsers, int *userIndex, int *state) {

    char providedUsername[MAX_USERNAME_LENGTH];
    char providedPassword[MAX_PASSWORD_LENGTH];

    printf("%s\n", SIGNING_IN);
    printf("---Username\n");
    gets(providedUsername);
    printf("---Password\n");
    gets(providedPassword);

    for (int i = 0; i < noOfUsers; ++i) {
        if (strcmp(providedUsername, usernames[i]) == 0) {
            if (strcmp(providedPassword, passwords[i]) == 0) {
                *state = 1;
                *userIndex = i;
                return;
            } else {
                printf("%s\n", INCORRECT_PASSWORD);
                return;
            }
        }
    }
    printf("%s\n", USER_NOT_FOUND);
    *state = 0;
}

void signUpProcess(char ***usernames, char ***passwords, char *key, int *noOfUsers, int *userIndex, int *state) {

    char providedUsername[MAX_USERNAME_LENGTH];
    char providedPassword[MAX_PASSWORD_LENGTH];
    FILE *f = fopen("users.txt", "a+");

    printf("%s\n", SIGNING_UP);
    printf("---Username\n");
    gets(providedUsername);
    printf("---Password\n");
    gets(providedPassword);

    for (int i = 0; i < *noOfUsers; ++i) {
        if (strcmp(providedUsername, (*usernames)[i]) == 0) {
            printf("%s\n", DUPLICATE_USER);
            return;
        } else {
            while (!passwordValidation(providedPassword, providedUsername)) {
                gets(providedPassword);
            }
            *state = 1;
            strcpy((*usernames)[*noOfUsers], providedUsername);
            converterVigenereChipher(providedUsername, key, 'e');
            fprintf(f, "(%s,", providedUsername);

            strcpy((*passwords)[*noOfUsers], providedPassword);
            converterVigenereChipher(providedPassword, key, 'e');
            fprintf(f, " %s)\n", providedPassword);

            fclose(f);
            FILE *f = fopen("users.txt", "r+");

            *userIndex = *noOfUsers;
            (*noOfUsers)++;

            fseek(f, 0, SEEK_SET);
            fprintf(f, "%s\n%d\n", key, *noOfUsers);
            fclose(f);
            break;
        }
    }
}

int passwordValidation(char password[], char username[]) {
    if (strlen(password) < 7) {
        printf("%s\n", ERROR_PASSWORD_LONG);
        return 0;
    }
    if (strstr(password, username) != NULL) {
        printf("%s\n", ERROR_PASSWORD_NOT_USERNAME);
        return 0;
    }
    if (!strchr(password, '.') && !strchr(password, '_') && !strchr(password, '!')) {
        printf("%s\n", ERROR_PASSWORD_SPECIAL_CHAR);
        return 0;
    }
    for (int i = 0; i < strlen(password); i++)
        if (password[i] >= '0' && password[i] <= '9')
            return 1;
    printf("%s\n", ERROR_PASSWORD_DIGITS);
    return 0;
}
