#ifndef FOOD_ORDERING_PRINT_H
#define FOOD_ORDERING_PRINT_H


void printOrder(char username[], char drinkChoice, char cutleryChoice, char foodRecipes[],
                double foodPrices, int noOfDrinks, char drinks[], double drinkPrices, char additionalInfo[],
                int *orderFinished, int *state);

void printFoodTypeOptions(int noOfFoodTypes, char *foodTypes[], int *foodChoice, int *state);

void printRecipeOptions(int noOfRecipes, char foodTypes[], char *foodRecipes[], double prices[], int *recipeChoice,
                        int *state);

void printDrinkOptions(int noOfDrinks, char foodTypes[], char *drinks[], double drinksPrices[], int *drinkChoice,
                       int *state);

void printCutleryOptions(int *cutleryChoice, int noOfCutleryOptions, int *state);

#endif //FOOD_ORDERING_PRINT_H
