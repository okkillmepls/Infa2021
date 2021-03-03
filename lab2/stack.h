#ifndef CAR_3_H_STACK_H
#define CAR_3_H_STACK_H
#ifdef vector
typedef struct stack{
    char *sym;
    int top;
    int n;
}stack;

stack* stack_init(int n);
int stack_write(stack* a, char b);
int stack_read(stack* a, char *b);
#endif
#ifndef vector
typedef struct stack_{
    char sym;
    struct stack_* next;
}stack_;
stack_* stack_write_list(stack_* top, char b);
stack_* stack_read_list(stack_* top, char *b);
#endif
#endif //CAR_3_H_STACK_H
