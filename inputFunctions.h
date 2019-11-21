#ifndef FOOD_ORDERING_INPUTFUNCTIONS_H
#define FOOD_ORDERING_INPUTFUNCTIONS_H

void signInForm(char *username, char *password);

int choiceAnalyser(int noOfChoices, int *state);

int getFinalOrderChoice(int *state, char username[]);

#endif //FOOD_ORDERING_INPUTFUNCTIONS_H
