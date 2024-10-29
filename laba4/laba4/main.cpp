#include <iostream>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root;

struct Node* CreateTree(struct Node* root, struct Node* r, int data) // создание дерева
{
    if (r == NULL)
    {
        r = (struct Node*)malloc(sizeof(struct Node));
        if (r == NULL)
        {
            printf("Ошибка выделения памяти");
            exit(0);
        }

        r->left = NULL;
        r->right = NULL;
        r->data = data;
        if (root == NULL) return r;

        if (data > root->data) root->left = r;
        else root->right = r;
        return r;
    }

    if (data == r->data) {
        printf("Элемент %d уже существует\n", data);
        return root;
    }

    if (data > r->data)
        CreateTree(r, r->left, data);
    else
        CreateTree(r, r->right, data);

    return root;
}

void print_tree(struct Node* r, int l) {
    if (r == NULL)
    {
        return;
    }

    print_tree(r->right, l + 1);
    for (int i = 0; i < l; i++)
    {
        printf(" ");
    }

    printf("%d\n", r->data);
    print_tree(r->left, l + 1);
}

struct Node* find(struct Node* r, int data) {
    if (r == NULL) {
        printf("Не найден\n");
        return NULL;
    }

    if (r->data == data) {
        return r;
    }
    else if (r->data < data) {
        return find(r->left, data);
    }
    else {
        return find(r->right, data);
    }
}

int fcount(struct Node* r, int l, int count) {
    if (r == NULL) return count;
    if (r->data == l) count++;
    count = fcount(r->right, l, count);
    count = fcount(r->left, l, count);
    return count;
}

int main()
{
    setlocale(LC_ALL, "");
    int D, co, start = 1;
    struct Node* r = NULL;

    root = NULL;
    printf("-1 - окончание построения дерева\n");
    while (start)
    {
        printf("Введите число: ");
        scanf_s("%d", &D);
        if (D == -1)
        {
            printf("Построение дерева окончено\n\n");
            start = 0;
        }
        else
            root = CreateTree(root, root, D);

    }

    print_tree(root, 0);

    printf("Введите элемент для поиска: ");
    scanf_s("%d", &D);

    r = find(root, D);
    if (r != NULL) printf("Найден = %d\n", r->data);

    /*  co = fcount(root, D, 0);
      printf("Количество = %d\n", co);*/

    return 0;
}
