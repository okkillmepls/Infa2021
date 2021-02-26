#include <stdlib.h>
#include "car.h"

int compare(car a, car b) {
    return strcmp(a.owner, b.owner);
}

void quickSort(car *cars, int first, int last) {
    if (first < last) {
        int left = first, right = last;
        car middle = cars[(left + right) / 2];
        do {
            while (compare(cars[left], middle) < 0) left++;
            while (compare(cars[right], middle) > 0) right--;
            if (left <= right)
            {
                car tmp = cars[left];
                cars[left] = cars[right];
                cars[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quickSort(cars, first, right);
        quickSort(cars, left, last);
    }

}

void bubbleSort(car *cars, int count) {
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare(cars[j], cars[j + 1]) > 0) {
                car tmp = cars[j + 1];
                cars[j + 1] = cars[j];
                cars[j] = tmp;
            }
        }
    }
}

int process(car *cars, int count, char* specificMark) {
    int ownersCount = 0;
    char **owners = (char**)calloc(0, sizeof(char*)); // Список владельцев

    for (int i = 0; i < count; i++) {
        if (strcmp(cars[i].mark, specificMark) != 0) {
            continue;
        }
        
        int isInList = 0; // 1 - Этот владелец уже встречался в списке, 0 - не встречался
        for (int j = 0; j < ownersCount; j++) {
            if (strcmp(owners[j], cars[i].owner) == 0) {
                isInList = 1;
                break;
            }
        }

        if (isInList == 0) { // То есть не в листе, тогда добавляем
            ownersCount++;
            owners = (char**)realloc(owners, ownersCount * sizeof(char*));
            owners[ownersCount - 1] = cars[i].owner;
        }
    }

    // Раскомментировать, если надо вывести фамилии владельцев
/*  
    printf("Owners: ");
    for (int i = 0; i < ownersCount; i++) {
        printf("%s, ", owners[i]);
    }
    printf("\n");
*/

    free(owners);

    return ownersCount;
}