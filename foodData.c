#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "foodData.h"

int findNoOfSpecificFood(char buffer[]) {
    int noOfSpecificFood=0;
    char subbuffer1[MAX_BUFFER_SIZE], subbuffer2[MAX_BUFFER_SIZE];
    char *token = strchr(buffer, ':');
    strncpy(subbuffer1, buffer, token - buffer);
    subbuffer1[token - buffer] = '\0';
    token = strrchr(subbuffer1, ' ');
    strncpy(subbuffer2, token, subbuffer1 - token + strlen(subbuffer1));
    subbuffer2[subbuffer1 - token + strlen(subbuffer1)] = '\0';
    sscanf(subbuffer2, "%d", &noOfSpecificFood);

    return noOfSpecificFood;
}

void readFoodDataFromBuffer(char *buffer, int noOfParentheses, char *foodType, char **specificFood,
                            double *foodPrices) {
    char subbuffer[MAX_BUFFER_SIZE];
    char *token = strchr(buffer, ':');
    strncpy(subbuffer, buffer, token - buffer);
    subbuffer[token-buffer] = '\0';
    token = strrchr(subbuffer, ' ');
    //get foodType
    strncpy(foodType, subbuffer, token - subbuffer);
    foodType[token - subbuffer] = '\0';

    token = strchr(buffer, '(');
    token++;

    for (int i = 0; i < noOfParentheses; ++i) {
        char *subtoken = strstr(token, " - ");
        strncpy(specificFood[i], token, subtoken - token);
        specificFood[i][subtoken - token] = '\0';
        subtoken += 3;
        sscanf(subtoken, "%lf)", &foodPrices[i]);
        token = strchr(token, '(');
        token++;
    }

}

void readDrinkDataFromBuffer(char *buffer, int noOfDrinks, char **drink, double *drinkPrice) {
    char *token = strchr(buffer, '(');
    token++;
    for (int i = 0; i < noOfDrinks; ++i) {
        char *subtoken = strstr(token, " - ");
        strncpy(drink[i], token, subtoken - token);
        drink[i][subtoken - token] = '\0';
        subtoken += 3;
        sscanf(subtoken, "%lf)", &drinkPrice[i]);
        token = strchr(token, '(');
        token++;
    }
}

void loadFoodDataFromFile(FILE *f, char ***foodTypes, char ****specificFood, char ***drinks, double ***foodPrices,
                      double **drinkPrices,
                      int **noOfSpecificFood, int *noOfFoodTypes, int *noOfDrinks) {

    //allocation of food memory
    fscanf(f, "%d:\n", noOfFoodTypes);
    *foodTypes = (char **) malloc(*noOfFoodTypes * sizeof(char *));
    *specificFood = (char ***) malloc(*noOfFoodTypes * sizeof(char **));
    *noOfSpecificFood = (int *) malloc(*noOfFoodTypes * sizeof(int));
    *foodPrices = (double **) malloc(*noOfFoodTypes * sizeof(double *));
    for (int i = 0; i < *noOfFoodTypes; ++i) {

        char buffer[MAX_BUFFER_SIZE];
        fgets(buffer, MAX_BUFFER_SIZE, f);
        buffer[strlen(buffer) - 1] = '\0';
        (*noOfSpecificFood)[i] = findNoOfSpecificFood(buffer);

        (*foodTypes)[i] = (char *) malloc(MAX_FOODTYPE_NAME * sizeof(char));
        (*specificFood)[i] = (char **) malloc((*noOfSpecificFood)[i] * sizeof(char *));
        (*foodPrices)[i] = (double *) malloc((*noOfSpecificFood)[i] * sizeof(double));
        for (int j = 0; j < (*noOfSpecificFood)[i]; ++j) {
            (*specificFood)[i][j] = (char *) malloc(MAX_SPECIFIC_FOOD_NAME * sizeof(char));
        }

        //read food data
        readFoodDataFromBuffer(buffer, (*noOfSpecificFood)[i], (*foodTypes)[i], (*specificFood)[i], (*foodPrices)[i]);
    }

    //allocate drink memory
    fscanf(f, "%d:\n", noOfDrinks);
    *drinks = (char **) malloc(*noOfDrinks * sizeof(char *));
    *drinkPrices = (double *) malloc(*noOfDrinks * sizeof(double));
    for (int i = 0; i < *noOfDrinks; ++i) {
        (*drinks)[i] = (char *) malloc(MAX_DRINK_NAME * sizeof(char));
    }
    char buffer[MAX_BUFFER_SIZE];
    fgets(buffer, MAX_BUFFER_SIZE, f);
    buffer[strlen(buffer) - 1] = '\0';

    //read drink data
    readDrinkDataFromBuffer(buffer, *noOfDrinks, *drinks, *drinkPrices);
}

void freeDataFromMemory(char ***foodTypes, char ****specificFood, char ***drinks, double ***foodPrices,
                        double **drinkPrices,
                        int **noOfSpecificFood, int noOfFoodTypes, int noOfDrinks) {
    for (int i = 0; i < noOfFoodTypes; i++) {
        for (int j = 0; j < (*noOfSpecificFood)[i]; j++) {
            free((*specificFood)[i][j]);
        }
        free((*foodTypes)[i]);
        free((*specificFood)[i]);
        free((*foodPrices)[i]);
    }
    free(*foodTypes);
    free(*specificFood);
    free(*foodPrices);
    free(*noOfSpecificFood);

    for (int i = 0; i < noOfDrinks; i++) {
        free((*drinks)[i]);
    }
    free(*drinks);
    free(*drinkPrices);
}
