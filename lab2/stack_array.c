typedef struct stack{
    char *sym;
    int top;
    int n;
}stack;



stack* stack_init(int n){
    stack* rez = (stack*)calloc(1, sizeof(stack));
    rez->sym = (char*)calloc(n, sizeof(char));
    rez->top = 0;
    rez->n = n;
    return rez;
}


int stack_write(stack* a, char b){
    if (a->top == a->n){
        return -1;
    }
    else{
        *(a->sym + a->top) = b;
        a->top++;
    }
    return 0;
}


int stack_read(stack* a, char *b){
//    Считывает элемент из стэка, при ошибке возвращает -1
    if (a->top == 0){
        return -1;
    }
    else{
        *b = *(a->sym + a->top - 1);
        a->top--;
    }
    return 0;
}