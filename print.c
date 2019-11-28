#include <stdio.h>
#include <string.h>
#include "input.h"

#define MAX_SPECIFIC_FOOD_NAME 30


void printOrder(char username[], char drinkChoice, char cutleryChoice, char foodRecipes[],
                double foodPrices, int noOfDrinks, char drinks[], double drinkPrices, char additionalInfo[],
                int *orderFinished, int *state) {

    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
    printf("Food items:\n");
    printf("---%s: %.2lf\n", foodRecipes, foodPrices);
    if (drinkChoice != noOfDrinks)
        printf("---%s: %.2lf\n", drinks, drinkPrices);
    printf("Cutlery: %s\n", (cutleryChoice == 0) ? "yes" : "no");
    if (strcmp(additionalInfo, "") != 0)
        printf("Aditional info: %s\n", additionalInfo);
    printf("Payment amount: %.2lf\n", foodPrices + drinkPrices);
    printf("--------------------\n");

    *orderFinished = getFinalOrderChoice(state, username);
}

void printFoodTypeOptions(int noOfFoodTypes, char *foodTypes[], int *foodChoice, int *state) {
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < noOfFoodTypes; i++) {
        putchar('a' + i);
        printf(") %s\n", foodTypes[i]);
    }
    putchar('a' + noOfFoodTypes);
    printf(") Go back\n");
    *foodChoice = choiceAnalyser(noOfFoodTypes, state);
}

void printRecipeOptions(int noOfRecipes, char foodTypes[], char *foodRecipes[], double prices[], int *recipeChoice,
                        int *state) {
    printf("Please choose the type of %s \n", foodTypes);
    for (int i = 0; i < noOfRecipes; i++) {
        putchar('a' + i);
        printf(") %s: %.2lf \n", foodRecipes[i], prices[i]);
    }
    printf("%c) Go Back \n", 'a' + noOfRecipes);

    *recipeChoice = choiceAnalyser(noOfRecipes, state);
}

void printDrinkOptions(int noOfDrinks, char foodTypes[], char *drinks[], double drinksPrices[], int *drinkChoice,
                       int *state) {
    printf("Please choose a drink to go with your %s \n", foodTypes);
    for (int i = 0; i < noOfDrinks; i++) {
        putchar('a' + i);
        printf(") %s: %.2lf \n", drinks[i], drinksPrices[i]);
    }
    printf("%c) No thanks! \n", 'a' + noOfDrinks - 1);
    printf("%c) Go Back \n", 'a' + noOfDrinks);

    *drinkChoice = choiceAnalyser(noOfDrinks, state);
}

void printCutleryOptions(int *cutleryChoice, int noOfCutleryOptions, int *state) {
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No,thanks!\n");
    printf("c) Go back!\n");

    *cutleryChoice = choiceAnalyser(noOfCutleryOptions, state);
}