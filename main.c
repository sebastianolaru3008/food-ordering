#include <stdio.h>
#include "print.h"
#include "input.h"
#include "foodData.h"
#include "signIn.h"
#include "userData.h"

int main() {
    int state = 0;
    int orderFinished = 0;
    //user input
    char **usernames, **passwords, *key;
    int noOfUsers = 1, userIndex = 0;
    int foodChoice, recipeChoice, drinkChoice, cutleryChoice;
    //food memory
    char **foodTypes, ***specificFood, **drinks;
    char additionalInfo[MAX_ADDITIONAL_INFO_SIZE];
    double **foodPrices, *drinkPrices;
    int *noOfSpecificFood;
    int noOfFoodTypes;
    int noOfDrinks;

    //Loading Data
    FILE *dataInput = fopen("data.txt", "r");
    if (dataInput == NULL) {
        printf("%s", LOAD_DATA);
        loadFoodDataFromFile(stdin, &foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
                             &noOfFoodTypes, &noOfDrinks);
    } else
        loadFoodDataFromFile(dataInput, &foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices,
                             &noOfSpecificFood,
                             &noOfFoodTypes, &noOfDrinks);
    fclose(dataInput);

    FILE *userData = fopen("users.txt", "r");
    loadUsernameDataFromFile(&usernames, &passwords, &key, &noOfUsers, userData);


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
                signUpProcess(&usernames, &passwords, key, &noOfUsers, &userIndex, &state);
                break;
            }
        }
    }
    //Freeing Memory
    freeDataFromMemory(&foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
                       noOfFoodTypes, noOfDrinks);
    return 0;
}

