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

/* �������� ���������� ��������. */
void del(char* name) {
    if (head == NULL) {
        printf("������ ����, �������� ����������\n");
        return;
    }

    // ���� � ������ ������ ���� �������
    if (head == last) {
        printf("����� �������: %s\n", head->inf);
        free(head);
        head = NULL;
        last = NULL;
        dlinna--;
        return;
    }

    // ������ � �������������� ��������
    struct node* current = head;
    while (current->next != last) {
        current = current->next;
    }

    // ������� ��������� �������
    printf("����� �������: %s\n", last->inf);
    free(last);
    last = current;
    last->next = NULL;
    dlinna--;
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

    printf("������� _1_ ��� �������� ��������: ");
    scanf("%s", s);
    if (strcmp(s, "1") == 0) {
        del(s);
    }
    review();

    return 0;
}
