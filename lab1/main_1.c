#include <stdlib.h>
#include <stdio.h>
#define LINE 60

typedef struct array_{
    int *k;
    int num;
}array_;

typedef struct array_float{
    float *k;
    int num;
}array_float;



typedef struct matrix{
    array_ *k;
    int num;
}matrix;


int GetInt(int *a){
//    Функция чтения целочисленного типа
//    P.S. Не доработано
//    Вопросы:
//    1) Проблемы со вводом данных в строку, их не будет, если организовать ввод каждого числа
//    на отдельной строке ( когда числа идут вряд, то множество проблем возникает). Можно ли так сделать?
//    Также проблема с переполнением start (исправлю)
//  Doxygen посмотреть

    char start[50], *end;
    int flag = 1;
    do {
        if (flag == 0) {
            printf("Invalid input, repeat\n");
            scanf("%*[^\n]");
        }
        scanf("%s", start);
        *a = strtol(start, &end, 10);
        flag = (*a != 0) + (*a == 0) * (*end == 0);
    } while(flag == 0);
    return flag;
}



void GetMatrix(matrix *s){
//    Процедура создает матрицу и записывает в нее числа из входного потока

    int m, ni, x;
    array_* ar2 = NULL;
    printf("Enter line number\n");
    GetInt(&m);
    while (m < 0){
        printf("Negative number, repeat input\n");
        GetInt(&m);
    }
    s->num = m;
    s->k = (array_*)calloc(m, sizeof(array_));
    ar2 = s->k;
    for (int i = 0; i < m; i++){
        printf("Enter column number in line %d:", i);
        GetInt(&ni);
        while (ni < 0){
            printf("Negative number, repeat input\n");
            GetInt(&ni);
        }
        ar2[i].k = (int*)calloc(ni, sizeof(int));
        ar2[i].num = ni;
        printf("Enter numbers\n");
        for (int j = 0; j < ni; j++){
            GetInt(&x);
            ar2[i].k[j] = x;
        }
    }
}


void FreeMatrix(matrix *s){
//  Очистка памяти из-под матрицы
    for (int i = 0; i < s->num; i++){
        free(s->k[i].k);
        }
    free(s->k);
}


int sum_if(array_ *s, float* srd){
//    Получение значений вектора ( поиск в строке среднего арифм и
//    вычисление суммы элементов, которые больше данного значения)
    int sum;
    sum = 0;
    for (int i = 0; i < s->num; i++){
        sum += s->k[i];
    }
    *srd = (float)sum/(float)(s->num);
    sum = 0;
    for (int i = 0; i < s->num; i++){
        if ((float)(*(s->k + i)) > *srd) sum += *(s->k + i);
    }
    return sum;
}


void Matrix_process(matrix s, array_* b, array_float* r){
//    Запись значений вектора + вектор среднего арифм
int x;
float srd_arif = 0;
    for (int i = 0; i < s.num; i++){
        x = sum_if(s.k + i, &srd_arif);
        *(b->k + i) = x;
        *(r->k + i) = srd_arif;
    }
}


void array_output_int(const char* s, array_ a){
//    Вывод одномерного массива
    if (s != NULL){
        printf("%s", s);
    }
    for (int i = 0; i < a.num; i++){
        printf("%d ", *a.k);
        a.k = a.k + 1;
    }
    printf("\n");
}


void array_output_float(const char* s, array_float a){
//    Вывод одномерного массива
    if (s != NULL){
        printf("%s", s);
    }
    for (int i = 0; i < a.num; i++){
        printf("%0.3f ", *(a.k));
        a.k = a.k + 1;
    }
    printf("\n");
}


void matrix_output(matrix a){
//    Вывод матрицы
    printf("It is matrix\n");
    for (int i = 0; i < a.num; i++){
        array_output_int(NULL, *(a.k));
        a.k = a.k + 1;
    }
}


int main(){
    matrix s;
//  Ввод матрицы
    GetMatrix(&s);
    array_ b;
    array_float r;
    b.k = (int*)calloc(s.num, sizeof(int));
    b.num = s.num;
    r.k = (float*)calloc(s.num, sizeof(float));
    r.num = s.num;
//  Обработка матрицы
    Matrix_process(s, &b, &r);
//  Вывод вектора результата
    array_output_int("It is vector b:\n", b);
//  Вывод доп вектора
    array_output_float("It is vector r:\n", r);
//  Вывод матрицы
    matrix_output(s);
//  Чистка памяти
    FreeMatrix(&s);
    free (b.k);
    free (r.k);
    return 0;
}