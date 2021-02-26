#include <stdio.h>
#include <stdlib.h>


typedef struct letter{
    char sym;
    struct letter* next;
}letter;


letter *Enter_string(){
// Ввод строки по символьно и запись ее в список
    printf("Enter string\n");
    letter head = {'*', NULL};
    letter *tail = &head;
    char a = (char)getchar();
    while (a != '\n'){
        tail->next = calloc(1, sizeof(letter));
        tail = tail->next;
        tail->sym = a;
        tail->next = NULL;
        a = (char)getchar();
    }
return head.next;
}

void Print_string(letter* s){
// Вывод списка(строки) с учетом кавычек
    printf("\"");
    for (letter* i = s; i != NULL; i = i->next){
        printf("%c",i->sym);
    }
    printf("\"");
}


void List_free(letter *s){
//    Очистка памяти
    letter *past = NULL;
    while (s != NULL){
        past = s;
        s = s->next;
        free(past);
    }
}


letter* String_processing(letter* head) {
//    Проблемы: Пробел в конце - смерть(решено),
//      две и одна буква - смерть(решено)
    letter *stop = head;
    letter *start = NULL;
    int k = 0;
    int flag = 0;
    while (stop != NULL) {
//        Пропускаем пробелы
        while (stop != NULL && (stop->sym == ' ' || stop->sym == '\t')) {
            start = stop;
            stop = stop->next;
        }
        if (stop == NULL) {
            break;
        }
//    удаляем первую букву
//      Если начало - передвигаем голову
        if (stop == head) {
            head = head->next;
            free(stop);
            stop = head;
            start = stop;
        }
//        Иначе просто удаляем элемент
        else {
            start->next = stop->next;
            free(stop);
            stop = start->next;
        }
        if (head == NULL) {
            break;
        }
//        Ищем конец слова, считаем кол-во символов
        while (stop != NULL && stop->sym != ' ' && stop->sym != '\t') {
            k++;
            stop = stop->next;
        }
//        Делаем поправку
        if (k == 1 && stop == NULL) {
            if (start == head) {
                stop = start->next;
                head = NULL;
                free(stop);
                break;
            }
            else {
                  start->next = NULL;
                  break;
            }
        }
        if ((start->sym == ' ' || start->sym == '\t') && (k != 1)) {
            k--;
        }
        else if (k != 1) k-=2;
        else if (start == head){
            head = head->next;
            free(start);
            start = head;
            k = -1;
        }
//        Передвигаем указатель на нужное место
        for (int i = k; i > 0; i--) {
            start = start->next;
        }
//        Удаляем последнюю букву
        stop = start->next;
        if (stop != NULL) {
            start->next = stop->next;
            free(stop);
            stop = start->next;
        }
        k = 0;
    }
    return head;
}


int main(){
// Ввод строки и добавление ее в список
    letter* s = NULL;
    s = Enter_string();
// Обработка строки
    s = String_processing(s);
// Вывод
    Print_string(s);
// Очистка памяти
    List_free(s);

    return 0;
}