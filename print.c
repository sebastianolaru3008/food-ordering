#include <stdio.h>
#include <string.h>
#include "print.h"

void printOrderHeader(char username[])
{
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
}

void printOrderFood(char foodChoice, char recipeChoice, char drinkChoice, char foodRecipes[][4][30],
                    int foodPrices[][4], char drinks[][20], int drinkPrices[],int userWantsDrink)
{
    printf("Food items:\n");
    printf("---%s: %d\n", foodRecipes[foodChoice][recipeChoice], foodPrices[foodChoice][recipeChoice]);
    if (userWantsDrink)
        printf("---%s: %d\n", drinks[drinkChoice], drinkPrices[drinkChoice]);
}

void printOrderInfo(char cutleryChoice, int userHasAdditionalInfo, char additionalInfo[], int foodPrices[][4], char foodChoice, char recipeChoice, int drinkPrices[], char drinkChoice)
{
    printf("Cutlery: %s\n", (cutleryChoice == 0) ? "yes" : "no");
    if (userHasAdditionalInfo)
        printf("Aditional info: %s\n", additionalInfo);
    int
            paymentAmount = foodPrices[foodChoice][recipeChoice] + drinkPrices[drinkChoice];
    printf("Payment amount: %d\n", paymentAmount);
}
void printOrderFooter()
{
    printf("--------------------\n");
    printf("a) Confirm order\n");
    printf("b) Go back\n");
}

void printFoodOptions(int foodRows, char foodTypes[][10], int *lastIndex)
{
    printf("Please choose the food you feel like eating today:\n");
    for (int i = 0; i < foodRows; i++) {
        putchar('a' + i);
        printf(") %s\n", foodTypes[i]);
        (*lastIndex)++;
    }
    putchar('a' + (*lastIndex));
    printf(") Go back\n");
}

void printRecipeOptions(char foodTypes[][10], char foodRows, int foodCols, char foodChoice, char foodRecipes[][4][30], int *lastIndex)
{
    printf("Please choose the type of %s:\n", foodTypes[foodChoice]);
    for (int j = 0; j < foodRows; ++j) {
        if (j == foodChoice) {
            for (int i = 0; i < foodCols; i++) {
                if (strcmp(foodRecipes[j][i], "") != 0) {
                    putchar('a' + i);
                    printf(") %s\n", foodRecipes[j][i]);
                    (*lastIndex)++;
                } else break;
            }

            putchar('a' + (*lastIndex));
            printf(") Go back\n");
        }
    }
}

void printDrinkOptions(char foodTypes[][10], char foodChoice, char drinksCount, char drinks[][20], int *lastIndex)
{
    printf("Please choose a drink to go with your %s:\n", foodTypes[foodChoice]);
    for (int i = 0; i < drinksCount; i++)
    {
        putchar('a' + i);
        printf(") %s\n", drinks[i]);
        (*lastIndex)++;
    }

    putchar('a' + (*lastIndex)++);
    printf(") No, thanks!\n");

    putchar('a' + (*lastIndex));
    printf(") Go back!\n");
}

void printCutleryOptions()
{
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No,thanks!\n");
    printf("c) Go back!\n");
}