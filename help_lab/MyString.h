#include <stdlib.h>
#include <string.h>

typedef struct Item {
    char data;
    struct Item *next;
} Item;

typedef struct Queue {
    Item *head;
    Item *tail;
} Queue;

Queue* queue_new() {
    return (Queue*)calloc(1, sizeof(Queue));
}

void queue_delete(Queue *queue) {
    Item *elem = queue->head, *elem_prev;
    while (elem) {
        elem_prev = elem;
        elem = elem->next;
        free(elem_prev);
    }
    free(queue);
}

int queue_push(Queue *queue, char data) {
    Item *new_item = (Item *) malloc(sizeof(Item));
    if (!new_item) {
        return -1;
    }

    new_item->data = data;
    new_item->next = NULL;
    if (!queue->head) {
        queue->head = new_item;
        queue->tail = new_item;
    } else {
        queue->tail->next = new_item;
        queue->tail = new_item;
    }
    return 0;
}

Queue *queue_from_string(char *str) {
    Queue *answer = queue_new(); //Инициализация пустой строки
    answer->head = NULL;

    for (int i = 0; i <= strlen(str); i++)
        queue_push(answer, str[i]);

    return answer;
}

Queue* queue_read() {
    // p - переменная, в которую записывается по одному символу из ввода
    char p;
    p = getchar();
    char *input = (char*)calloc(1, sizeof(char));
    int input_len = 0;
    while(!feof(stdin) && p != '\n') {
        input_len++;
        input = (char*)realloc(input, (input_len)*sizeof(char));
        input[input_len-1] = p;

        p = getchar();
    }
    input = (char*)realloc(input, (input_len + 1)*sizeof(char));
    input[input_len] = '\0';
//    free

    if (feof(stdin)) { // То есть конец ввода (ctrl+D в PuTTY)
        return NULL;
    }

    Queue *answer = queue_from_string(input);

    free(input);

    return answer;
}
