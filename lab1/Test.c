#include <stdio.h>
#include <stdlib.h>

int getInt(int *a)
{
    int n;
    do{
        n = scanf("%d", a);
        if (n < 0)
            return 0;
        if (n == 0){
            printf("%s\n", "Error! Repeat input");
            scanf("%*c");
        }
    } while (n == 0);
    return 1;
}

int GetInt(int *a){
//    Функция чтения целочисленного типа, при ошибке чтения возвращает 1

    char start[256], *end;
    int flag = 1;
    do {
        if (flag == 0) {
            printf("Error, repeat your input\n");
            scanf("%*[^\n]");
        }
        scanf("%s", start);
        *a = strtol(start, &end, 10);
        flag = (*a != 0) + (a == 0) * (*end == '\0');
    } while(flag == 0);
    return flag;
}





int main(){
    int n, m;
    while (1) {

        printf("%d %d\n", m, n);
    }
    return 0;
}