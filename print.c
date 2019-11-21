#include <stdio.h>
#include <string.h>
#include "print.h"

#define MAX_FOOD_RECIPE_NAME 30

void printOrderHeader(char username[]) {
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
}

void printOrderBody(char drinkChoice, char cutleryChoice, char foodRecipes[],
                    int foodPrices, int noOfDrinks, char drinks[], int drinkPrices, char additionalInfo[]) {

    printf("Food items:\n");
    printf("---%s: %d\n", foodRecipes, foodPrices);
    if (drinkChoice != noOfDrinks)
        printf("---%s: %d\n", drinks, drinkPrices);
    printf("Cutlery: %s\n", (cutleryChoice == 0) ? "yes" : "no");
    if (strcmp(additionalInfo, "") != 0)
        printf("Aditional info: %s\n", additionalInfo);
    printf("Payment amount: %d\n", foodPrices + drinkPrices);
    printf("--------------------\n");
}

void printFoodTypeOptions(int noOfFoodTypes, char foodTypes[][10]) {
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < noOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s\n", foodTypes[i]);
    }
    putchar('a' + noOfFoodTypes);
    printf(") Go back\n");
}

void printRecipeOptions(int noOfRecipes, char foodTypes[], char foodRecipes[][MAX_FOOD_RECIPE_NAME], int prices[]) {
    printf("Please choose the type of %s \n", foodTypes);
    for (int i = 0; i < noOfRecipes; i++) {
        putchar('a' + i);
        printf(") %s: %d \n", foodRecipes[i], prices[i]);
    }
    printf("%c) Go Back \n", 'a' + noOfRecipes);
}

void printDrinkOptions(int noOfDrinks, char foodTypes[], char drinks[][MAX_DRINK_NAME], int drinksPrices[]) {
    printf("Please choose a drink to go with your %s \n", foodTypes);
    for (int i = 0; i < noOfDrinks; i++) {
        putchar('a' + i);
        printf(") %s: %d \n", drinks[i], drinksPrices[i]);
    }
    printf("%c) No thanks! \n", 'a' + noOfDrinks - 1);
    printf("%c) Go Back \n", 'a' + noOfDrinks);
}

void printCutleryOptions() {
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No,thanks!\n");
    printf("c) Go back!\n");
}