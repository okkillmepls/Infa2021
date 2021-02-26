#include<stdio.h>

int dialog(const char *msgs[], int n) {
    char *error = (char*)"";
    int choice;
    do {
        puts(error);
        error = (char*)"You're wrong. Try again!";
        for (int i = 0; i < n; ++i) {
            puts(msgs[i]);
        }
        puts("Make your choice: ");
        choice = getchar() - '0';  
        while (getchar() != '\n') {}
    } while (choice < 0 || choice >= n);
    return choice;
}
 