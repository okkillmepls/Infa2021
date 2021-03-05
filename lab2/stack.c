#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
//#define vector


#ifdef vector

char stack_check(stack* top){
    if (top->top == 0) return 0;
    return *(top->sym + top->top - 1);
}

void stack_free(stack** top){
    free((*top)->sym);
    free(*top);
    printf("Vector: ");
}


stack* stack_init(int n){
    stack* rez = (stack*)calloc(1, sizeof(stack));
    rez->sym = (char*)calloc(n, sizeof(char));
    rez->top = 0;
    rez->n = n;
    return rez;
}


int stack_write(stack** a, char b){
    if ((*a)->top == (*a)->n){
        return -1;
    }
    else{
        *((*a)->sym + (*a)->top) = b;
        (*a)->top++;
    }
    return 0;
}


int stack_read(stack** a, char *b){
//    Считывает элемент из стэка, при ошибке возвращает -1
    if ((*a)->top == 0){
        return -1;
    }
    else{
        *b = *((*a)->sym + (*a)->top - 1);
        (*a)->top--;
    }
    return 0;
}
#endif

// Список
#ifndef vector

stack* stack_init(int n){
    return NULL;
}

char stack_check(stack* top){
    if (top) return top->sym;
    return 0;
}


int stack_write(stack** top, char b){
    stack *p = (stack*)calloc(1, sizeof(stack));
    p->sym = b;
    p->next = *top;
    *top = p;
    return 0;
}

int stack_read(stack** top, char *b){
    if (*top == NULL){
        return -1;
    }
    else {
        stack *p = NULL;
        p = *top;
        *b = (*top)->sym;
        *top = (*top)->next;
        free(p);
    }
    return 0;
}


void stack_free(stack** top){
    free(*top);
    printf("List: ");
}

#endif

