#include <stdio.h>
#include <string.h>
#include "print.h"
#include "inputFunctions.h"



int main() {
    //user input
    char username[40], password[20], additionalInfo[50];
    char foodChoice, recipeChoice, drinkChoice, cutleryChoice, confirmChoice;
    //food data
    int lastIndex, userWantsDrink = 1, userHasAdditionalInfo = 1;
    char foodTypes[][10] = {"Pizza", "Pasta", "Salad"};
    char foodRecipes[3][4][30] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita", ""    },
                                  {"Chicken Alfredo", "Mac&cheese"   ,  ""               , ""    },
                                  {"Tuna Salad",      "Chicken Salad", "Greek Salad"     , "Cobb"}};
    char drinks[4][20] = {"Coca-cola", "Fanta", "Lipton", "Water"};
    int foodPrices[3][4] = {{21, 23, 19, 0},
                            {23, 21, 0,  0},
                            {23, 22, 19, 21}};
    int drinkPrices[5] = {5, 5, 5, 4, 0};
    //constants
    const int foodCols = sizeof(foodRecipes[0]) / sizeof(foodRecipes[0][0]);
    const int foodRows = sizeof(foodTypes) / sizeof(foodTypes[0]);
    const int drinksCount = sizeof(drinks) / sizeof(drinks[0]);

    signIn:
        signInForm(username, password);
    food:
        lastIndex = 0;
        printFoodOptions(foodRows, foodTypes, &lastIndex);
        choiceAnalyser(&foodChoice);
        if (foodChoice == lastIndex) goto signIn;
    recipe:
        lastIndex = 0;
        printRecipeOptions(foodTypes, foodRows, foodCols, foodChoice, foodRecipes, &lastIndex);
        choiceAnalyser(&recipeChoice);
        if (recipeChoice == lastIndex) goto food;
    drink:
        lastIndex = 0;
        printDrinkOptions(foodTypes, foodChoice, drinksCount, drinks, &lastIndex);
        choiceAnalyser(&drinkChoice);
        if (drinkChoice == (lastIndex - 1)) userWantsDrink = 0;
        else if (drinkChoice == lastIndex) goto recipe;
    cutlery:
        printCutleryOptions();
        choiceAnalyser(&cutleryChoice);
        if (cutleryChoice == 2) goto drink;
    //Adding additional info
        printf("Any additional info?\n");
        gets(additionalInfo);
        if (strcmp(additionalInfo, "") == 0) userHasAdditionalInfo = 0;
    //Printing order
        printOrderHeader(username);
        printOrderFood(foodChoice, recipeChoice, drinkChoice, foodRecipes, foodPrices, drinks, drinkPrices, userWantsDrink);
        printOrderInfo(cutleryChoice, userHasAdditionalInfo, additionalInfo, foodPrices, foodChoice, recipeChoice,
                       drinkPrices, drinkChoice);
        printOrderFooter();
        choiceAnalyser(&confirmChoice);
        if (confirmChoice == 1) goto cutlery;

    return 0;

}

