#ifndef FOOD_ORDERING_USERDATA_H
#define FOOD_ORDERING_USERDATA_H

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_NUMBER_OF_USERS_MAGNITUDE 10
#define MAX_BUFFER_SIZE 400
#define MAX_KEY_LENGTH 20

void converterVigenereChipher(char givenString[], char key[], char encDecr);

void initializeUserData(char ***usernames, char ***passwords, char **key, int noOfUsers);

void readDataFromBuffer(char buffer[], char *username, char *password);

void loadUsernameDataFromFile(char ***usernames, char ***passwords, char **key, int *noOfUsers, FILE *f);

#endif //FOOD_ORDERING_USERDATA_H
