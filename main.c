#include <stdio.h>
#include "print.h"
#include "input.h"
#include "data.h"

int main() {
    int state = 0;
    int orderFinished = 0;
    //user input
    char username[40], password[20], additionalInfo[50];
    int foodChoice, recipeChoice, drinkChoice, cutleryChoice;
    //region //food data (no more needed)
    //char foodTypes[][10] = {"Pizza", "Pasta", "Salad"};
    //char specificFood[3][4][MAX_SPECIFIC_FOOD_NAME] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
    //                                                {"Chicken Alfredo", "Mac&cheese"},
    //                                                {"Tuna Salad",      "Chicken Salad", "Greek Salad", "Cobb"}};
    //int noOfSpecificFood[] = {3, 2, 4};
    //char drinks[][MAX_DRINK_NAME] = {"Coca-cola", "Fanta", "Lipton", "Water"};
    //int foodPrices[3][4] = {{21, 23, 19, 0},
    //                        {23, 21, 0,  0},
    //                        {23, 22, 19, 21}};
    //int drinkPrices[5] = {5, 5, 5, 4};
    //endregion no
    //food memory
    char **foodTypes, ***specificFood, **drinks;
    double **foodPrices, *drinkPrices;
    int *noOfSpecificFood;
    int noOfFoodTypes;
    int noOfDrinks;

    //Loading Data
    loadDataFromConsole(&foodTypes, &specificFood, &drinks, &foodPrices, &drinkPrices, &noOfSpecificFood,
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

