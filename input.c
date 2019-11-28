#include <stdio.h>

void signInForm(char *username, char *password) {
    printf("\nWelcome to Food Thingies!\n");
    printf("Please sign in to continue!\n");
    printf("--Username\n");
    gets(username);
    printf("--Password\n");
    gets(password);
}

int choiceAnalyser(int noOfChoices, int *state) {
    int choiceIndex;
    char choice = getchar();
    getchar();
    if (choice == 'a' + noOfChoices) {
        (*state)--;
    } else {
        choiceIndex = choice - 'a';
        (*state)++;
    }
    return choiceIndex;
}

int getFinalOrderChoice(int *state, char username[]) {
    int orderFinished = 0;
    printf("a) Confirm order \n");
    printf("b) Go back \n");
    char choice = getchar();
    if (choice == 'a') {
        orderFinished = 1;
        printf("Order confirmed! Thank you for buying from us, %s! \n", username);
    } else {
        (*state) -= 2;
    }
    getchar();
    return orderFinished;
}