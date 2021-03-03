#ifndef CAR_3_H_STACK_H
#define CAR_3_H_STACK_H

#ifdef vector
typedef struct stack{
    char *sym;
    int top;
    int n;
}stack;
#endif

#ifndef vector
typedef struct stack{
    char sym;
    struct stack* next;
}stack;
#endif

stack* stack_write_list(stack* top, char b);
stack* stack_read_list(stack* top, char *b);
stack* stack_init(int n);
int stack_write(stack* a, char b);
int stack_read(stack* a, char *b);
#endif //CAR_3_H_STACK_H
