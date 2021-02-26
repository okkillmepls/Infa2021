#include <stdio.h>
#include <string.h>
#include <time.h>
#include "inputs.h"
#include "functions.h"
#include "dialogue.h"
#include "car.h"

const char *MSGS[] = {"0. Quit", "1. From keyboard", "2. From file", "3. Random generation"};
const int MSGS_SIZE = sizeof(MSGS) / sizeof(MSGS[0]); 

int main() {
    car *cars = NULL;
    int countOfCars;
    char *specificMark = NULL;

    printf("Chose data input:");
    int c = dialog(MSGS, MSGS_SIZE);
    if (c == 0) {
        printf("Exiting\n");
        return 0;
    }

    switch(c) {
    case 1:
        cars = inputFromKeyboard(&countOfCars, &(specificMark));
        break;
    case 2:
        cars = inputFromFile(&countOfCars, &(specificMark));
        break;
    case 3:
        cars = inputFromRandom(&countOfCars, &(specificMark));
        break;
    }

    FILE *output = fopen("output.txt", "w");
    printf("Specific Mark = %s\nCount Of Cars = %d\n", specificMark, countOfCars);
    fprintf(output, "Specific Mark = %s\nCount Of Cars = %d\n", specificMark, countOfCars);

    printf("Cars:\n");
    fprintf(output, "Cars:\n");
    for (int i = 0; i < countOfCars; i++) {
        printf("[%d]: %s, %s, %s\n", i, cars[i].mark, cars[i].number, cars[i].owner);
        fprintf(output, "[%d]: %s, %s, %s\n", i, cars[i].mark, cars[i].number, cars[i].owner);
    }
    
    printf("Sorting...\n");
    printf("Which sort to do?:\n1 - Bubble Sort\n2 - Quick Sort\nYour choice: ");
    scanf("%d", &c);
    int startTime = clock();
    if (c == 1) {
        fprintf(output, "Bubble Sort...\n");
        bubbleSort(cars, countOfCars);
    } else if (c == 2) {
        fprintf(output, "Quick Sort...\n");
        quickSort(cars, 0, countOfCars - 1);
    } else {
        printf("There must be 1 or 2. Exiting\n");
        fprintf(output, "Error\n");
        fclose(output);
        return 0;
    }
    int timing = clock() - startTime;
    
    printf("Result of sort (%d ms)\n", timing);
    fprintf(output, "Result of sort (%d ms)\n", timing);
    for (int i = 0; i < countOfCars; i++) {
        printf("[%d]: %s, %s, %s\n", i, cars[i].mark, cars[i].number, cars[i].owner);
        fprintf(output, "[%d]: %s, %s, %s\n", i, cars[i].mark, cars[i].number, cars[i].owner);
    }    

    startTime = clock();
    int result = process(cars, countOfCars, specificMark);
    timing = clock() - startTime;

    printf("Result = %d (%d ms)\n", result, timing);
    fprintf(output, "Result = %d (%d ms)\n", result, timing);
    
    printf("See result in 'output.txt' file\n");
    fclose(output);

    for (int i = 0; i < countOfCars; i++) {
        free(cars[i].number);
        free(cars[i].owner);
        free(cars[i].mark);
    }

    free(cars);
    free(specificMark);
    return 0;
}