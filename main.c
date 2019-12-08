#include <stdio.h>
#include "print.h"
#include "input.h"
#include "data.h"
#include "signIn.h"

void chooseSignInOrUp(int *state);

int main() {
    int state = 0;
    int orderFinished = 0;
    //user input
    char **usernames, **passwords;
    char additionalInfo[MAX_ADDITIONAL_INFO_SIZE];
    int noOfUsers = 1, userIndex = 0;
    int foodChoice, recipeChoice, drinkChoice, cutleryChoice;
    //food memory
    char **foodTypes, ***specificFood, **drinks;
    double **foodPrices, *drinkPrices;
    int *noOfSpecificFood;
    int noOfFoodTypes;
    int noOfDrinks;

    //Loading Data
    FILE *dataInput;
    dataInput = fopen("data.txt", "r");
    if (dataInput == NULL) {
        printf("%s", LOAD_DATA);
        loadFoodDataFromFile(stdin, &foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
                         &noOfFoodTypes, &noOfDrinks);
    } else
        loadFoodDataFromFile(dataInput, &foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
                         &noOfFoodTypes, &noOfDrinks);

    initializeUserData(&usernames,&passwords,MAX_USERNAME_LENGTH);

    //Switching States
    while (!orderFinished) {
        switch (state) {
            case 0: {
                chooseSignInOrUp(&state);
                break;
            }
            case 1: {
                printFoodTypeOptions(noOfFoodTypes, foodTypes, &foodChoice, &state);
                break;
            }
            case 2: {
                printRecipeOptions(noOfSpecificFood[foodChoice], foodTypes[foodChoice], specificFood[foodChoice],
                                   foodPrices[foodChoice], &recipeChoice, &state);
                break;
            }
            case 3: {
                printDrinkOptions(noOfDrinks, foodTypes[foodChoice], drinks, drinkPrices, &drinkChoice, &state);
                break;
            }
            case 4: {
                printCutleryOptions(&cutleryChoice, CUTLERRY_OPTIONS, &state);
                break;
            }
            case 5: {
                printf("Any additional info?\n");
                gets(additionalInfo);
                state++;
                break;
            }
            case 6: {
                printf("%d\n",userIndex);
                printOrder(usernames[userIndex], drinkChoice, cutleryChoice, specificFood[foodChoice][recipeChoice],
                           foodPrices[foodChoice][recipeChoice], noOfDrinks, drinks[drinkChoice],
                           drinkPrices[drinkChoice], additionalInfo, &orderFinished, &state);
                break;
            }
            case 7: {
                signInProcess(usernames, passwords, noOfUsers, &userIndex, &state);
                break;
            }
            case 8: {
                signUpProcess(&usernames, &passwords, &noOfUsers, &userIndex, &state);
                printf("%d\n",userIndex);
                break;
            }
        }
    }
    //Freeing Memory
    freeDataFromMemory(&foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
                       noOfFoodTypes, noOfDrinks);
    return 0;
}

