#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct node {
    char inf[256]; // �������� ���������� 
    struct node* next; // ������ �� ��������� ������� 
};

struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� 
int dlinna = 0; // ����� ������

void spstore(void), review(void), del(char* name);
char find_el[256];
struct node* find(char* name); // ������� ���������� �������� 
struct node* get_struct(void); // ������� �������� �������� 

struct node* get_struct(void) {
    struct node* p = NULL;
    char s[256];
    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) { // �������� ������ ��� ����� ������� ������ 
        printf("������ ��� ������������� ������\n");
        exit(1);
    }
    printf("������� �������� �������: \n"); // ������ ������ 
    scanf("%s", s);

    if (*s == 0) {
        printf("������ �� ���� �����������\n");
        return NULL;
    }
    strcpy(p->inf, s);
    p->next = NULL;
    return p; // ���������� ��������� �� ��������� ������� 
}

/* ���������������� ���������� � ������ �������� (� �����) */
void spstore(void) {
    struct node* p = get_struct();
    if (p == NULL) return;

    if (head == NULL) { // ���� ������ ���, �� ������������� ������  
        head = p;
        last = p;
    }
    else { // ������ ��� ����, �� ��������� � ����� 
        last->next = p;
        last = p;
    }
    dlinna++; // ����������� ����� ������
    printf("������� ��������: %s\n", p->inf);
}

/* �������� ����������� ������. */
void review(void) {
    struct node* struc = head;
    if (head == NULL) {
        printf("������ ����\n");
        return;
    }
    printf("���������� ������:\n");
    while (struc) {
        printf("���: %s\n", struc->inf);
        struc = struc->next;
    }
}

/* ����� �������� �� �����������. */
struct node* find(char* name) {
    struct node* struc = head;
    if (head == NULL) {
        printf("������ ����\n");
        return NULL;
    }
    while (struc) {
        if (strcmp(name, struc->inf) == 0) {
            return struc;
        }
        struc = struc->next;
    }
    printf("������� �� ������\n");
    return NULL;
}

/* �������� �������� �� �����������. */
void del(char* name) {
    struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������ 
    struct node* prev = NULL; // ��������� �� �������������� ���������� ������� 
    if (head == NULL) { // ���� ������ ������ ����� NULL, �� ������ ���� 
        printf("������ ����\n");
        return;
    }
    // �������� ������� ��������
    if (strcmp(name, struc->inf) == 0) {
        head = struc->next;
        free(struc);
        dlinna--; // ��������� ����� ������
        printf("������� �����: %s\n", name);
        return;
    }
    // ����� � �������� ��������
    while (struc != NULL) {
        if (strcmp(name, struc->inf) == 0) {
            prev->next = struc->next;
            if (struc == last) {
                last = prev; // ��������� ��������� �� ��������� �������
            }
            free(struc);
            dlinna--;
            printf("������� �����: %s\n", name);
            return;
        }
        prev = struc;
        struc = struc->next;
    }
    printf("������� �� ������\n");
}

int main() {
    setlocale(LC_ALL, "Russian");

    char s[256];

    spstore();
    spstore();
    spstore();
    review();

    printf("������� ������� ��� ������: ");
    scanf("%s", s);
    f = find(s);

    if (f != NULL) {
        printf("��������� �������: %s\n", f->inf);
    }

    printf("������� ������� ��� ��������: ");
    scanf("%s", s);
    
    del(s);
    review();

    return 0;
}
