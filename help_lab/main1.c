#include <stdio.h>
#include "Solution.h"

int main() {
    Queue *s = NULL;
    do {
        printf("Input string: ");
        s = queue_read();
        if (s) {
            printf("Result: ");
            char *answer = algorithm(s);
            printf("%s\n", answer);
            queue_delete(s);
            free(answer);
        }
    } while(s); // Условие не выполнится, если s будет NULL (то есть произойдёт конец ввода)

    return 0;
}