#ifndef FOOD_ORDERING_FOODDATA_H
#define FOOD_ORDERING_FOODDATA_H

#define LOAD_DATA "Please load the data \n"
#define MAX_FOODTYPE_NAME 30
#define MAX_SPECIFIC_FOOD_NAME 30
#define MAX_DRINK_NAME 30
#define MAX_BUFFER_SIZE 400
#define MAX_ADDITIONAL_INFO_SIZE 100

int findNoOfSpecificFood(char buffer[]);

void readFoodDataFromBuffer(char *buffer, int noOfParentheses, char *foodType, char **specificFood,
                            double *foodPrices);

void readDrinkDataFromBuffer(char *buffer, int noOfDrinks, char **drink, double *drinkPrice);

void loadFoodDataFromFile(FILE *f, char ***foodTypes, char ****specificFood, char ***drinks, double ***foodPrices,
                      double **drinkPrices, int **noOfSpecificFood, int *noOfFoodTypes, int *noOfDrinks);

void freeDataFromMemory(char ***foodTypes, char ****specificFood, char ***drinks, double ***foodPrices,
                        double **drinkPrices, int **noOfSpecificFood, int noOfFoodTypes, int noOfDrinks);

#endif //FOOD_ORDERING_FOODDATA_H
