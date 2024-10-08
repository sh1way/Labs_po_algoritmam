#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct node {
    char inf[256]; // �������� ���������� 
    int priority;
    struct node* next; // ������ �� ��������� ������� 
};

struct node* head = NULL, * last = NULL, * f = NULL; // ��������� �� ������ � ��������� 
int dlinna = 0;

void spstore(void), review(void), del(char* name);
char find_el[256];
struct node* find(char* name); // ������� ���������� �������� 
struct node* get_struct(void); // ������� �������� �������� 

struct node* get_struct(void)
{
    struct node* p = NULL;
    char s[256];
    int pr;
    if ((p = (struct node*)malloc(sizeof(struct node))) == NULL) // �������� ������ ��� ����� ������� ������ 
    {
        printf("������ ��� ������������� ������\n ");
        exit(1);
    }
    printf("������� �������� ������� : \n"); // ������ ������ 
    scanf("%s", s);
    printf("������� ���������: \n");
    scanf("%d", &pr);


    if (*s == 0) {
        printf("������ �� ���� �����������\n");
        return NULL;
    }
    strcpy(p->inf, s);
    p->priority = pr;
    p->next = NULL;
    return p; // ���������� ��������� �� ��������� ������� 
}
/* ���������������� ���������� � ������ �������� (� �����)*/
void spstore(void)
{
    struct node* p = NULL;
    p = get_struct();
    if (head == NULL || head->priority < p->priority) // ���� ������ ���, �� ������������� ������  
    {
        p->next = head;
        head = p;
    }
    else
    {
        struct node* current = head;
        while (current->next != NULL && current->next->priority >= p->priority) {
            current = current->next;
        }
        p->next = current->next;
        current->next = p;
    }
    return;
}
/* �������� ����������� ������. */
void review(void)
{
    struct node* struc = head;
    if (head == NULL)
    {
        printf("������ ����\n ");
        return;
    }
    while (struc)
    {
        printf("���: %s, ���������: %d\n", struc->inf, struc->priority);
        struc = struc->next;
    }
}

/* ����� �������� �� �����������. */
struct node* find(char* name)
{
    struct node* struc = head;
    while (struc)
    {
        if (strcmp(name, struc->inf) == 0)
        {
            return struc;
        }
        struc = struc->next;
    }
    printf("������� �� ������\n");
    return NULL;
}
/* �������� �������� �� �����������. 
void del(char* name)
{
    struct node* struc = head; // ���������, ���������� �� ������ ���������� �� ������������ 
    struct node* prev = NULL;// ��������� �� �������������� ���������� ������� 
    int flag = 0; // ��������� ���������� ���������� �������� � ������ 
    if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ���� 
    {
        printf("������ ����\n");
        return;
    }
    if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������ 
    {
        flag = 1;
        head = struc->next; // ������������� ������ �� ��������� ������� 
        free(struc); // ������� ������ ������� 
        struc = head; // ������������� ��������� ��� ����������� ������ 
    }
    else
    {
        prev = struc;
        struc = struc->next;
    }
    while (struc) // ������ �� ������ � ����� ���������� �������� 
    {
        if (strcmp(name, struc->inf) == 0) // ���� �����, �� 
        {
            flag = 1; // ���������� ��������� 
            if (struc->next) // ���� ��������� ������� �� ��������� � ������ 
            {
                prev->next = struc->next; // ������ ��������� 
                free(struc); // ������� ������� 
                struc = prev->next; // ������������� ��������� ��� ����������� ������ 
            }
            else // ���� ��������� ������� ��������� � ������ 
            {
                prev->next = NULL; // �������� ��������� ��������������� �������� 

                free(struc); // ������� ������� 
                return;

            }
        }
        else // ���� �� �����, �� 
        {
            prev = struc; // ������������� ��������� ��� ����������� ������ 
            struc = struc->next;
        }
    }
    if (flag == 0) // ���� ���� = 0, ������ ������ ������� �� ������ 
    {
        printf("������� �� ������\n ");
        return;
    }
}*/

int main() {
    setlocale(LC_ALL, "Russian");

    char s[10];

    spstore();
    spstore();
    spstore();
    review();

    printf("������� ������� ��� ������: \n");
    scanf("%s", s);
    struct node* f = find(s);
    if (f != NULL) {
        printf("��������� �������: %s, ���������: %d\n", f->inf, f->priority);
    }

    return 0;
}
