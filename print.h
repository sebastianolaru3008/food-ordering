#ifndef FOOD_ORDERING_PRINT_H
#define FOOD_ORDERING_PRINT_H

void printOrderHeader(char username[]);
void printOrderFood(char foodChoice, char recipeChoice, char drinkChoice, char foodRecipes[][4][30],
                    int foodPrices[][4], char drinks[][20], int drinkPrices[],int userWantsDrink);
void printOrderInfo(char cutleryChoice, int userHasAdditionalInfo, char additionalInfo[], int foodPrices[][4],
                    char foodChoice, char recipeChoice, int drinkPrices[], char drinkChoice);
void printOrderFooter();


void printFoodOptions(int foodRows, char foodTypes[][10], int *lastIndex);
void printRecipeOptions(char foodTypes[][10], char foodRows, int foodCols, char foodChoice, char foodRecipes[][4][30], int *lastIndex);
void printDrinkOptions(char foodTypes[][10], char foodChoice, char drinksCount, char drinks[][20], int *lastIndex);
void printCutleryOptions();

#endif //FOOD_ORDERING_PRINT_H
