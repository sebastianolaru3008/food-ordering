#include <stdio.h>
#include <string.h>
#include "print.h"
#include "inputFunctions.h"

#define CUTLERRY_OPTIONS 2

int main() {
    int state = 0;
    int orderFinished = 0;
    //user input
    char username[40], password[20], additionalInfo[50];
    char foodChoice, recipeChoice, drinkChoice, cutleryChoice, confirmChoice;
    //food data
    int lastIndex, userWantsDrink = 1, userHasAdditionalInfo = 1;
    char foodTypes[][10] = {"Pizza", "Pasta", "Salad"};
    char foodRecipes[3][4][MAX_FOOD_RECIPE_NAME] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita"},
                                                    {"Chicken Alfredo", "Mac&cheese"},
                                                    {"Tuna Salad",      "Chicken Salad", "Greek Salad", "Cobb"}};
    int noOfRecipes[] = {3, 2, 4};
    char drinks[][MAX_DRINK_NAME] = {"Coca-cola", "Fanta", "Lipton", "Water"};
    int foodPrices[3][4] = {{21, 23, 19, 0},
                            {23, 21, 0,  0},
                            {23, 22, 19, 21}};
    int drinkPrices[5] = {5, 5, 5, 4};
    //constants
    int noOfFoodTypes = sizeof(foodTypes) / sizeof(foodTypes[0]);
    int noOfDrinks = sizeof(drinks) / sizeof(drinks[0]);

    while (!orderFinished) {
        switch (state) {
            case 0: {
                signInForm(username, password);
                state++;
                break;
            }
            case 1: {
                printFoodTypeOptions(noOfFoodTypes, foodTypes);
                foodChoice = choiceAnalyser(noOfFoodTypes, &state);
                break;
            }
            case 2: {
                printRecipeOptions(noOfRecipes[foodChoice], foodTypes[foodChoice], foodRecipes[foodChoice],
                                   foodPrices[foodChoice]);
                recipeChoice = choiceAnalyser(noOfRecipes[foodChoice], &state);
                break;
            }
            case 3: {
                printDrinkOptions(noOfDrinks, foodTypes[foodChoice], drinks, drinkPrices);
                drinkChoice = choiceAnalyser(noOfDrinks, &state);
                break;
            }
            case 4: {
                printCutleryOptions();
                cutleryChoice = choiceAnalyser(CUTLERRY_OPTIONS, &state);
                break;
            }
            case 5: {
                printf("Any additional info?\n");
                gets(additionalInfo);
                state++;
            }
            case 6: {
                printOrderHeader(username);
                printOrderBody(drinkChoice, cutleryChoice, foodRecipes[foodChoice][recipeChoice],
                               foodPrices[foodChoice][recipeChoice], noOfDrinks, drinks[drinkChoice],
                               drinkPrices[drinkChoice], additionalInfo);
                orderFinished = getFinalOrderChoice(&state, username);
                break;
            }
        }
    }

    return 0;

}

