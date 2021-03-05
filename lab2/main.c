#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"




// Алгоритм Дейкстрой
typedef struct Mystr{
    char *c;
    int n;
}Mystr;


char *Postfix(char *s) {
    Mystr c;
    char l;
    c.c = (char *) calloc(strlen(s) + 1, sizeof(char));
    c.n = 0;
    stack *st;
    st = stack_init((int) strlen(s));
    char *p = s;
    while (*p != '\0') {
//         Если пробел, то пропускаем
        if (*p == ' '){
            p++;
        }
//        Если открывающая скобка, то в стек ее
        else if (*p == '(') {
            stack_write(&st, *p);
        }
//         Если закрывающая скобка - выталкиваем из стека все операции до открывающей скобки
        else if (*p == ')') {
            while ((stack_check(st) != '(') && (stack_check(st) != 0)) {
                stack_read(&st, c.c + c.n);
                c.n++;
            }
            stack_read(&st, &l);
        }
//         Если встретился * или /, то выгружаем все * или / из стека
        else if ((*p == '*') || (*p == '/')) {
            while (((stack_check(st) == '*') || (stack_check(st) == '/')) && (stack_check(st) != 0) && (stack_check(st) != '(')) {
                stack_read(&st, c.c + c.n);
                c.n++;
            }
            stack_write(&st, *p);
//            Если встретился + или минус, то выгружаем все + или - из стека
        } else if ((*p == '+') || (*p == '-')) {
            while ((stack_check(st) != '(') && (stack_check(st) > 0)) {
                stack_read(&st, c.c + c.n);
                c.n++;
            }
            stack_write(&st, *p);
//            Если встречается буква, то в строку ее
        } else {
            *(c.c + c.n) = *p;
            c.n++;
        }
        p++;
    }
//    Если в стеке остались данные, то
    while (stack_check(st) != 0){
        stack_read(&st, c.c + c.n);
        c.n++;
    }
    stack_free(&st);
    return c.c;

}

char *Reverse(char* s){
//    Возвращает инверсию строки с учетом скобок
    int len = (int)strlen(s);
    char *c = (char*)calloc(len + 1, sizeof(s));
    for (int i = 0; i < len; i++){
        if (*(s + len - i - 1)  == '('){
            *(c + i) = ')';

        }
        else if (*(s + len - i - 1)  == ')'){
            *(c + i) = '(';
    }
        else {
            *(c + i) = *(s + len - i - 1);
        }
    }
    return c;
}




char* Solution(char *s){
//    Переворачиваем с учетом скобо
    char *rev = Reverse(s);
//    Получаем постфиксную запись
    char *post =  Postfix(rev);
//    Переворачиваем строку
    char *post_rev = Reverse(post);
    free(rev);
    free(post);
    return post_rev;
    }

char* getString(){
    int n, len, len_res = 0;
    char buf[51];
    char *res = NULL;
    do{
        n = scanf("%50[^\n]", buf);
        if (n < 0){
            if (!res) return NULL;
        }
        else if (n > 0) {
            len = (int)strlen(buf);
            len_res += len;
            res = realloc(res, (len_res + 1) * sizeof(char));
            memcpy(res + len_res - len, buf, len);
        }
        else{
            scanf("%*c");
        }
    } while (n > 0);
    if (len_res > 0){
        res[len_res] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }
    return res;
}


int main(){
    char* s = NULL;
    char* c = NULL;
    s = getString();
    c = Solution(s);
    printf("%s", c);
    free(s);
    free(c);
    return 0;
}
