#ifndef FOOD_ORDERING_INPUT_H
#define FOOD_ORDERING_INPUT_H

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define CUTLERRY_OPTIONS 2

void signInForm(char *username, char *password);

int choiceAnalyser(int noOfChoices, int *state);

int getFinalOrderChoice(int *state, char username[]);

#endif //FOOD_ORDERING_INPUT_H
