#include <stdio.h>
#include <string.h>

int main() {
    //user input
    char username[40];
    char password[20];
    char additionalInfo[50] = "";
    char choice, foodChoice, recipeChoice, drinkChoice, cutleryChoice, goBackChoice;
    int userWantsDrink = 1;
    int userHasAdditionalInfo = 1;
    int menuesGoneThrough = 0;
    int paymentAmount = 0;

    //food data
    int lastIndex;
    char foodTypes[][10] = {"Pizza", "Pasta", "Salad"};
    char foodRecipes[3][4][30] = {{"Pizza Carbonara", "Pizza Diavola", "Pizza Margherita", ""},
                                  {"Chicken Alfredo", "Mac&cheese",    "",                 ""},
                                  {"Tuna Salad",      "Chicken Salad", "Greek Salad",      "Cobb"}};
    char drinks[4][20] = {"Coca-cola", "Fanta", "Lipton", "Water"};
    int foodPrices[3][4] = {{21, 23, 19, 0},
                            {23, 21, 0, 0},
                            {23, 22, 19, 21}};
    int drinkPrices[5] = {5, 5, 5, 4, 0};

    //constants
    const char nullRecipe[30] = "";
    const char nullAdditionalInfo[50] = "";
    const int foodCols = sizeof(foodRecipes[0]) / sizeof(foodRecipes[0][0]);
    const int foodRows = sizeof(foodTypes) / sizeof(foodTypes[0]);
    const int drinksCount = sizeof(drinks) / sizeof(drinks[0]);

    //Signing in
    signIn:
    printf("Welcome to Food Thingies!\n");
    printf("Please sign in to continue!\n");
    printf("--Username\n");
    gets(username);
    printf("--Password\n");
    gets(password);
    menuesGoneThrough = 1;


    //Selecting food type
    food:
    printf("Please choose the food you feel like eating today:\n");
    lastIndex = 0;

    for (int i = 0; i < foodRows; i++) {
        putchar('a' + i);
        printf(") %s\n", foodTypes[i]);
        lastIndex++;
    }

    putchar('a' + lastIndex);
    printf(") Go back\n");

    choice = getchar();
    fflush(stdin);
    foodChoice = choice - 'a';

    menuesGoneThrough = 2;
    if (foodChoice == lastIndex) goto goBack;



    //Selecting specific food
    recipe:
    printf("Please choose the type of %s:\n", foodTypes[foodChoice]);

    for (int j = 0; j < foodRows; ++j) {
        if (j == foodChoice) {
            lastIndex = 0;

            for (int i = 0; i < foodCols; i++) {
                if (strcmp(foodRecipes[j][i], nullRecipe) != 0) {
                    putchar('a' + i);
                    printf(") %s\n", foodRecipes[j][i]);
                    lastIndex++;
                } else break;
            }

            putchar('a' + lastIndex);
            printf(") Go back\n");
        }
    }

    choice = getchar();
    fflush(stdin);
    recipeChoice = choice - 'a';

    menuesGoneThrough = 3;
    if (recipeChoice == lastIndex) goto goBack;

    // Selecting drink
    drink:
    printf("Please choose a drink to go with your %s:\n", foodTypes[foodChoice]);
    lastIndex = 0;

    for (int i = 0; i < drinksCount; i++) {
        putchar('a' + i);
        printf(") %s\n", drinks[i]);
        lastIndex++;
    }

    putchar('a' + lastIndex++);
    printf(") No, thanks!\n");

    putchar('a' + lastIndex);
    printf(") Go back!\n");

    choice = getchar();
    fflush(stdin);
    drinkChoice = choice - 'a';

    menuesGoneThrough = 4;
    if (drinkChoice == (lastIndex - 1)) userWantsDrink = 0;
    else if (drinkChoice == lastIndex) goto goBack;


    //Choosing cutlery
    cutlery:
    printf("Do you want cutlery?\n");
    printf("a) Yes\n");
    printf("b) No,thanks!\n");
    printf("c) Go back!\n");

    choice = getchar();
    fflush(stdin);
    cutleryChoice = choice - 'a';

    menuesGoneThrough = 5;
    if (cutleryChoice == 2) goto goBack;


    //Adding additional info
    addInfo:
    printf("Any additional info?\n");
    gets(additionalInfo);

    if (strcmp(additionalInfo, nullAdditionalInfo) == 0) userHasAdditionalInfo = 0;
    menuesGoneThrough = 6;


    //Printing order
    printf("This is your order:\n");
    printf("-------------------\n");
    printf("Name: %s\n", username);
    printf("Food items:\n");
    printf("---%s: %d\n", foodRecipes[foodChoice][recipeChoice], foodPrices[foodChoice][recipeChoice]);
    if (userWantsDrink)
        printf("---%s: %d\n", drinks[drinkChoice], drinkPrices[drinkChoice]);
    printf("Cutlery: %s\n", (cutleryChoice == 0) ? "yes" : "no");
    if (userHasAdditionalInfo)
        printf("Aditional info: %s\n", additionalInfo);
    paymentAmount = foodPrices[foodChoice][recipeChoice] + drinkPrices[drinkChoice];
    printf("Payment amount: %d\n", paymentAmount);
    printf("--------------------\n");

    printf("a) Confirm order\n");
    printf("b) Go back\n");

    choice = getchar();
    fflush(stdin);
    if(choice = 'b') goto goBack;

    return 0;

    goBack:
    printf("Where do you wanna go back to?\n");
    if (menuesGoneThrough > 1) printf("a)Food types menu\n");
    if (menuesGoneThrough > 2) printf("b)Recipes menu\n");
    if (menuesGoneThrough > 3) printf("c)Drinks menu\n");
    if (menuesGoneThrough > 4) printf("d)Cutlary menu\n");
    if (menuesGoneThrough > 5) printf("e)Aditional info menu\n");
    choice = getchar();
    goBackChoice = choice - 'a';
    fflush(stdin);
    switch (goBackChoice) {
        case 0:
            goto food;
        case 1:
            goto recipe;
        case 2:
            goto drink;
        case 3:
            goto cutlery;
        case 4:
            goto addInfo;
    }

}