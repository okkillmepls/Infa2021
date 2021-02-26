typedef struct stack_{
    char info;
    struct stack_* next;
}stack_;



stack_* stack_init(int n){
    stack_* p = (stack_*)calloc(1, sizeof(stack_*));
    p->next = NULL;
    return p;
}


stack_* stack_write(stack_* top, char b){
    stack_ *p = (stack_*)calloc(1, sizeof(stack_*));
    p->info = b;
    p->next = top;
    top = p;
    return top;
}


stack_* stack_read(stack_* top, char *b){
    stack_ *p = NULL;
    p = top;
    top = top->next;
    p->next = NULL;
    return top;
}