#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "car.h"
#include<string.h>

car *inputFromFile(int *countOfCars, char **specificMark) {
    char filename[80];
    printf("Input filename: ");
    scanf("%s", filename);
    
    FILE *input = fopen(filename, "r");
    if (input == NULL) {
        printf("Cannot open the file!\n");
        exit(-1);
    }
    
    fscanf(input, "%d", countOfCars);

    car *cars = (car*)calloc(*countOfCars, sizeof(car));
    for (int i = 0; i < *countOfCars; i++) {
        char mark[50];
        char owner[50];
        char number[50];

        fscanf(input, "%s", mark);
        cars[i].mark = (char*) calloc(strlen(mark) + 1, sizeof(char));
        memcpy(cars[i].mark, mark, strlen(mark));
        cars[i].mark[strlen(mark)] = '\0';

        fscanf(input, "%s", number);
        cars[i].number = (char*) calloc(strlen(number) + 1, sizeof(char));
        memcpy(cars[i].number, number, strlen(number));
        cars[i].number[strlen(number)] = '\0';

        fscanf(input, "%s", owner);
        cars[i].owner = (char*) calloc(strlen(owner) + 1, sizeof(char));
        memcpy(cars[i].owner, owner, strlen(owner));
        cars[i].owner[strlen(owner)] = '\0';
    }

    char answer[50];
    fscanf(input, "%s", answer);
    (*specificMark) = (char*)calloc(strlen(answer) + 1, sizeof(char));
    memcpy((*specificMark), answer, strlen(answer));

    fclose(input);
    
    return cars;
}


car* inputFromKeyboard(int *countOfCars, char **specificMark) {
    printf("Input count of cars to input: ");
    scanf("%d", countOfCars);

    car *cars = (car*)calloc(*countOfCars, sizeof(car));
    for (int i = 0; i < *countOfCars; i++) {
        char number[50];
        char mark[50];
        char owner[50];

        printf("Input mark of car[%d]: ", i);
        scanf("%s", mark);
        cars[i].mark = (char*) calloc(strlen(mark) + 1, sizeof(char));
        memcpy(cars[i].mark, mark, strlen(mark));
        cars[i].mark[strlen(mark)] = '\0';

        printf("Input number of car[%d]: ", i);
        scanf("%s", number);
        cars[i].number = (char*) calloc(strlen(number) + 1, sizeof(char));
        memcpy(cars[i].number, number, strlen(number));
        cars[i].number[strlen(number)] = '\0';

        printf("Input surname car[%d]'s owner: ", i);
        scanf("%s", owner);
        cars[i].owner = (char*) calloc(strlen(owner) + 1, sizeof(char));
        memcpy(cars[i].owner, owner, strlen(owner));
        cars[i].owner[strlen(owner)] = '\0';
    }

    printf("Which mark's owner must be counted?: ");
    char answer[50];
    scanf("%s", answer);
    (*specificMark) = (char*)calloc(strlen(answer) + 1, sizeof(char));
    memcpy((*specificMark), answer, strlen(answer));
    
    return cars;
}


char *generateRandomString() {
    int len = rand() % 10 + 1;
    char letters[] = "qQwWeE rRtTyY uUiIoO pPaAsS dDfFgG hHjJkK lLzZxX cCvVbB nNmM";
    char *result = (char*)calloc(len, sizeof(char));

    for (int j = 0; j < len; j ++) {
        char symbol = letters[rand() % strlen(letters)];
        if (j == 0 || result[j - 1] == ' ') {
            while (symbol == ' ') {
                symbol = letters[rand() % strlen(letters)];
            }
        }
        result[j] = symbol;
    }

    return result;

}

car* inputFromRandom(int *countOfCars, char **specificMark) {
    srand(time(NULL));    
    *countOfCars = rand() % 9 + 1;

    car *cars = (car*)calloc(*countOfCars, sizeof(car));
    char letters[] = "qQwWeE rRtTyY uUiIoO pPaAsS dDfFgG hHjJkK lLzZxX cCvVbB nNmM";
    for (int i = 0; i < *countOfCars; i++) {
        cars[i].mark = generateRandomString();

        cars[i].number = generateRandomString();

        cars[i].owner = generateRandomString();
    }

    (*specificMark) = generateRandomString();
    
    return cars;
}