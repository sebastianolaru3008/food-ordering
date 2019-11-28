#include <stdio.h>
#include "print.h"
#include "input.h"
#include "data.h"

int main() {
    int state = 0;
    int orderFinished = 0;
    //user input
    char username[MAX_USERNAME_LENGTH], password[MAX_PASSWORD_LENGTH], additionalInfo[MAX_ADDITIONAL_INFO_SIZE];
    int foodChoice, recipeChoice, drinkChoice, cutleryChoice;
    //food memory
    char **foodTypes, ***specificFood, **drinks;
    double **foodPrices, *drinkPrices;
    int *noOfSpecificFood;
    int noOfFoodTypes;
    int noOfDrinks;

    //Loading Data
    FILE *dataInput;
    dataInput=fopen("data.txt","r");
    if(dataInput==NULL){
        printf("%s", LOAD_DATA);
        loadDataFromFile(stdin,&foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
                         &noOfFoodTypes, &noOfDrinks);
    }
    else
        loadDataFromFile(dataInput,&foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
                         &noOfFoodTypes, &noOfDrinks);

    //Switching States
    while (!orderFinished) {
        switch (state) {
            case 0: {
                signInForm(username, password);
                state++;
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
                printOrder(username, drinkChoice, cutleryChoice, specificFood[foodChoice][recipeChoice],
                           foodPrices[foodChoice][recipeChoice], noOfDrinks, drinks[drinkChoice],
                           drinkPrices[drinkChoice], additionalInfo, &orderFinished, &state);
                break;
            }
        }
    }
    //Freeing Memory
    freeDataFromMemory(&foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
                       noOfFoodTypes, noOfDrinks);
    return 0;
}