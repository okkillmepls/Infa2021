#ifndef CAR_3_H_STACK_H
#define CAR_3_H_STACK_H
typedef struct stack_{
    char sym;
    struct stack_* next;
}stack_;

typedef struct stack{
    char *sym;
    int top;
    int n;
}stack;

stack_* stack_write_list(stack_* top, char b);
stack_* stack_read_list(stack_* top, char *b);
stack* stack_init(int n);
int stack_write(stack* a, char b);
int stack_read(stack* a, char *b);
#endif //CAR_3_H_STACK_H
