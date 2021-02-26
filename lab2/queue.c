#include <stdio.h>
#include <stdlib.h>


typedef struct Queue1{
    char sym;
    struct Queue1* next;
}Queue1;


typedef struct Queue{
    Queue1 *head;
    Queue1 *tail;
    int n;
}Queue;


Queue* Queue_init(){
    Queue *a;
    a = (Queue*)calloc(1, sizeof(Queue));
    a->head = NULL;
    a->tail = NULL;
    a->n = 0;
    return a;
}


void Queue_write(Queue* a, char b){
    Queue1 *c = (Queue1*)calloc(1, sizeof(Queue1));
    if (a->tail != NULL){
        a->tail->next = c;
    }
    a->tail = c;
    c->next = NULL;
    c->sym = b;
    if (a->head == NULL){
        a->head = a->tail;
    }
    a->n = a->n + 1;
}


int Queue_read(Queue* a, char *b){
    Queue1 *x = NULL;
    if (a->head != NULL){
        x = a->head;
        a->n = a->n - 1;
        a->head = a->head->next;
        *b = x->sym;
        return 0;
    }
    else{
        return -1;
    }
}

