#ifndef FOOD_ORDERING_PRINT_H
#define FOOD_ORDERING_PRINT_H

#define MAX_FOOD_RECIPE_NAME 30
#define MAX_DRINK_NAME 30

void printOrderHeader(char username[]);

void printOrderBody(char drinkChoice, char cutleryChoice, char foodRecipes[],
                    int foodPrices, int noOfDrinks, char drinks[], int drinkPrices, char additionalInfo[]);


void printFoodTypeOptions(int foodRows, char foodTypes[][10]);

void printRecipeOptions(int noOfRecipes, char foodTypes[], char foodRecipes[][MAX_FOOD_RECIPE_NAME], int prices[]);

void printDrinkOptions(int noOfDrinks, char foodTypes[], char drinks[][MAX_DRINK_NAME], int drinksPrices[]);

void printCutleryOptions();

#endif //FOOD_ORDERING_PRINT_H
