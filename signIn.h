#ifndef FOOD_ORDERING_SIGNIN_H
#define FOOD_ORDERING_SIGNIN_H

#define ERROR_PASSWORD_LONG         "The password must be at least 7 chars long"
#define ERROR_PASSWORD_NOT_USERNAME "The password must not contain the username"
#define ERROR_PASSWORD_SPECIAL_CHAR "The password must contain one of the following characters: {'.','_','!'}"
#define ERROR_PASSWORD_DIGITS       "The password must contain digits"

#define SIGN_IN_UP                  "Do you want to sign in or sign up?"
#define SIGN_IN                     "Sign in"
#define SIGN_UP                     "Sign up"
#define SIGNING_IN                  "Signing in!"
#define SIGNING_UP                  "Signing up!"

#define USER_NOT_FOUND              "Username doesn't exist"
#define DUPLICATE_USER              "Please choose another username!"
#define INCORRECT_PASSWORD          "Incorrect password"

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_NUMBER_OF_USERS 255

void chooseSignInOrUp(int *state);

void signInProcess(char **usernames, char **passwords, int noOfUsers, int *userIndex, int *state);

void signUpProcess(char ***usernames, char ***passwords, int *noOfUsers, int *userIndex, int *state);

int passwordValidation(char pass[], char username[]);

void initializeUserData(char ***usernames, char ***passwords, int noOfUsers);

#endif //FOOD_ORDERING_SIGNIN_H
