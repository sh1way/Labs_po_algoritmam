#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct node {
    char inf[256]; // полезная информация 
    struct node* next; // ссылка на следующий элемент 
};

struct node* head = NULL, * last = NULL, * f = NULL; // указатели на первый и последний 
int dlinna = 0; // длина списка

void spstore(void), review(void), del(char* name);
char find_el[256];
struct node* find(char* name); // функция нахождения элемента 
struct node* get_struct(void); // функция создания элемента 

struct node* get_struct(void) {
    struct node* p = NULL;
    char s[256];
    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) { // выделяем память под новый элемент списка 
        printf("Ошибка при распределении памяти\n");
        exit(1);
    }
    printf("Введите название объекта: \n"); // вводим данные 
    scanf("%s", s);

    if (*s == 0) {
        printf("Запись не была произведена\n");
        return NULL;
    }
    strcpy(p->inf, s);
    p->next = NULL;
    return p; // возвращаем указатель на созданный элемент 
}

/* Последовательное добавление в список элемента (в конец) */
void spstore(void) {
    struct node* p = get_struct();
    if (p == NULL) return;

    if (head == NULL) { // если списка нет, то устанавливаем голову  
        head = p;
        last = p;
    }
    else { // список уже есть, то вставляем в конец 
        last->next = p;
        last = p;
    }
    dlinna++; // увеличиваем длину списка
    printf("Элемент добавлен: %s\n", p->inf);
}

/* Просмотр содержимого списка. */
void review(void) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }
    printf("Содержимое списка:\n");
    while (struc) {
        printf("Имя: %s\n", struc->inf);
        struc = struc->next;
    }
}

/* Поиск элемента по содержимому. */
struct node* find(char* name) {
    struct node* struc = head;
    if (head == NULL) {
        printf("Список пуст\n");
        return NULL;
    }
    while (struc) {
        if (strcmp(name, struc->inf) == 0) {
            return struc;
        }
        struc = struc->next;
    }
    printf("Элемент не найден\n");
    return NULL;
}

/* Удаление элемента по содержимому. */
void del(char* name) {
    struct node* struc = head; // указатель, проходящий по списку установлен на начало списка 
    struct node* prev = NULL; // указатель на предшествующий удаляемому элемент 
    if (head == NULL) { // если голова списка равна NULL, то список пуст 
        printf("Список пуст\n");
        return;
    }
    // Удаление первого элемента
    if (strcmp(name, struc->inf) == 0) {
        head = struc->next;
        free(struc);
        dlinna--; // уменьшаем длину списка
        printf("Элемент удалён: %s\n", name);
        return;
    }
    // Поиск и удаление элемента
    while (struc != NULL) {
        if (strcmp(name, struc->inf) == 0) {
            prev->next = struc->next;
            if (struc == last) {
                last = prev; // обновляем указатель на последний элемент
            }
            free(struc);
            dlinna--;
            printf("Элемент удалён: %s\n", name);
            return;
        }
        prev = struc;
        struc = struc->next;
    }
    printf("Элемент не найден\n");
}

int main() {
    setlocale(LC_ALL, "Russian");

    char s[256];

    spstore();
    spstore();
    spstore();
    review();

    printf("Введите элемент для поиска: ");
    scanf("%s", s);
    f = find(s);

    if (f != NULL) {
        printf("Найденный элемент: %s\n", f->inf);
    }

    printf("Введите элемент для удаления: ");
    scanf("%s", s);
    
    del(s);
    review();

    return 0;
}
