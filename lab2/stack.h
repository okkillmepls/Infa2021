#ifndef CAR_3_H_STACK_H
#define CAR_3_H_STACK_H
//#define vector

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
char stack_check(stack* top);
void stack_free(stack** top);
stack* stack_init(int n);
int stack_write(stack** a, char b);
int stack_read(stack** a, char *b);
#endif //CAR_3_H_STACK_H
