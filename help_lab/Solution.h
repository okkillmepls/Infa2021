#include <stdio.h>
#include "MyString.h"
#include <string.h>

 char* algorithm(Queue *queue) {
    int result_len = 0;
    char *result = (char*)calloc(1, sizeof(char));
    char *currentWord = (char*)calloc(1, sizeof(char));


    for (Item *current = queue->head; current; current = current->next) {
        if ((current->data == '\0' || current->data == ' ') 
                    && strlen(currentWord) > 0) {

            if (strlen(currentWord) > 2) {
                int new_len = result_len + strlen(currentWord) - 2;
                result = (char*)realloc(result, (new_len) * sizeof(char));
                memcpy(result + result_len, currentWord + 1, (int)(strlen(currentWord)) - 2);
                result_len = new_len;

                if (current->next) {
                    result_len++;
                    result = (char*)realloc(result, (result_len + 1) * sizeof(char));
                    result[result_len - 1] = ' ';
                }
            }


            free(currentWord);
            currentWord = (char*)calloc(1, sizeof(char));
        } else {
            int new_len = strlen(currentWord) + 1;
            currentWord = (char*)realloc(currentWord, (new_len) * sizeof(char));
            currentWord[new_len - 1] = current->data;
        }
    }

    result[result_len] = '\0';
    free(currentWord);
    
    return result;
}