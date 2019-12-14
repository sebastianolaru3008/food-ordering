#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "userData.h"

void loadUsernameDataFromFile(char ***usernames, char ***passwords, char **key, int *noOfUsers, FILE *f) {
    initializeUserData(usernames, passwords, key, MAX_USERNAME_LENGTH);
    fgets(*key, MAX_KEY_LENGTH, f);
    (*key)[strlen(*key) - 1] = '\0';
    fscanf(f, "%d", noOfUsers);
    char *dump = (char*)malloc(MAX_BUFFER_SIZE* sizeof(char));
    fgets(dump,MAX_NUMBER_OF_USERS_MAGNITUDE,f);

    for (int i = 0; i < *noOfUsers; ++i) {
        char buffer[MAX_BUFFER_SIZE];
        fgets(buffer, MAX_BUFFER_SIZE, f);
        readDataFromBuffer(buffer, (*usernames)[i], (*passwords)[i]);
        converterVigenereChipher((*usernames)[i], *key, 'd');
        converterVigenereChipher((*passwords)[i], *key, 'd');
    }

}

void converterVigenereChipher(char givenString[], char key[], char encDecr) {
    char *alfabet = (char *) malloc(66 * sizeof(char));
    char *copyKey = (char *) malloc(strlen(givenString) * sizeof(char));
    char *result = (char *) malloc(strlen(givenString) * sizeof(char));
    strcpy(alfabet, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!_. ");
    for (int i = 0, j = 0; i < strlen(givenString); i++, j++) {
        if (j == strlen(key))
            j = 0;
        copyKey[i] = key[j];
    }
    copyKey[strlen(givenString)] = '\0';
    for (int i = 0; i < strlen(givenString); i++) {
        if (encDecr == 'e')
            result[i] = alfabet[
                    ((strchr(alfabet, givenString[i]) - alfabet) + (strchr(alfabet, copyKey[i]) - alfabet)) %
                    (strlen(alfabet))];
        else if (encDecr == 'd')
            result[i] = alfabet[((strchr(alfabet, givenString[i]) - alfabet) - (strchr(alfabet, copyKey[i]) - alfabet) +
                                 (strlen(alfabet))) % (strlen(alfabet))];
    }

    result[strlen(givenString)] = '\0';
    strcpy(givenString, result);
}

void initializeUserData(char ***usernames, char ***passwords, char **key, int noOfUsers) {

    *key = (char *) malloc(MAX_KEY_LENGTH * sizeof(char));
    *usernames = (char **) malloc(noOfUsers * sizeof(char *));
    *passwords = (char **) malloc(noOfUsers * sizeof(char *));
    for (int i = 0; i < noOfUsers; ++i) {
        (*usernames)[i] = (char *) malloc(MAX_USERNAME_LENGTH * sizeof(char));
        (*passwords)[i] = (char *) malloc(MAX_PASSWORD_LENGTH * sizeof(char));
    }
}

void readDataFromBuffer(char *buffer, char *username, char *password) {

    char *token = strchr(buffer, ',');
    strncpy(username, buffer + 1, token - buffer - 1);
    username[token - buffer - 1] = '\0';
    token += 2;
    char *endToken = strchr(token, ')');
    strncpy(password, token, endToken - token);
    password[endToken - token] = '\0';

}

