#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int** createG(int size) {
    int** G = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        G[i] = (int*)malloc(size * sizeof(int));
    }

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (i == j) {
                G[i][j] = 0;
            }
            else {
                G[i][j] = rand() % 2;
                G[j][i] = G[i][j];
            }
        }
    }
    return G;
}

void printG(int** G, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

int** delV(int** G, int size, int v) {
    int** Gnew = createG(size - 1);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i < v && j < v) {
                Gnew[i][j] = G[i][j];
            }
            if (i > v && j > v) {
                Gnew[i - 1][j - 1] = G[i][j];
            }
            if (i > v && j < v) {
                Gnew[i - 1][j] = G[i][j];
            }
            if (i < v && j > v) {
                Gnew[i][j - 1] = G[i][j];
            }
        }
    }
    for (int i = 0; i < size; i++) {
        free(G[i]);
    }
    free(G);
    return Gnew;
}

//отожествление вершин
int** unionV(int** G, int size, int v1, int v2) {
    for (int i = 0; i < size; i++) {
        if (G[v2][i] == 1) {
            G[v1][i] = G[v2][i];
            G[i][v1] = G[i][v2];
        }
    }
    G = delV(G, size, v2);
    return G;
}

//стягивание ребра
int** contrE(int** G, int size, int v1, int v2) {
    G[v1][v2] = 0;
    G[v2][v1] = 0;
    for (int i = 0; i < size; i++) {
        if (G[v2][i] == 1) {
            G[v1][i] = G[v2][i];
            G[i][v1] = G[i][v2];
        }
    }
    G = delV(G, size, v2);
    return G;
}
//дубликат вершины
int** splitV(int** G, int size, int v) {
    int** Gnew = createG(size + 1);

    for (int i = 0; i < size; i++) {
        Gnew[i][size] = G[i][v];
        Gnew[size][i] = G[v][i];
    }
    printG(Gnew, size + 1);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            Gnew[i][j] = G[i][j];
        }
    }
    Gnew[v][v] = 0;
    Gnew[size][size] = 0;
    for (int i = 0; i < size; i++) {
        free(G[i]);
    }
    free(G);
    return Gnew;
}
//объединение
int** unionG(int** G1, int** G2, int size1, int size2) {
    int sizemax = (size1 > size2) ? size1 : size2;
    int sizemin = (size1 < size2) ? size1 : size2;

    int** Gnew = createG(sizemax);
    if (Gnew == NULL) {
        printf("Ошибка: не удалось выделить память для Gnew.\n");
        return NULL;
    }

    for (int i = 0; i < sizemax; i++) {
        for (int j = 0; j < sizemax; j++) {
            if (i < size1 && j < size1 && G1[i] != NULL && G1[i][j] != NULL) {
                Gnew[i][j] = G1[i][j];
            }
            else {
                Gnew[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < sizemin; i++) {
        for (int j = 0; j < sizemin; j++) {
            if (G2[i][j] == 1) {
                Gnew[i][j] = G2[i][j];
            }
        }
    }
    return Gnew;
}

//пересечение
int** intersectG(int** G1, int** G2, int size1, int size2) {
    int sizemin = (size1 < size2) ? size1 : size2;
    int** Gnew = createG(sizemin);
    for (int i = 0; i < sizemin; i++) {
        for (int j = 0; j < sizemin; j++) {
            Gnew[i][j] = G1[i][j] & G2[i][j];
        }
    }
    return Gnew;
}

//кольцевая сумма
int** xorG(int** G1, int** G2, int size1, int size2) {
    int sizemax = (size1 > size2) ? size1 : size2;
    int sizemin = (size1 < size2) ? size1 : size2;
    int step = 0;

    int** Gnew = createG(sizemax);
    for (int i = 0; i < sizemin; i++) {
        for (int j = 0; j < sizemin; j++) {
            Gnew[i][j] = G1[i][j] ^ G2[i][j];
        }
    }

    for (int i = 0; i < sizemax; i++) {
        for (int j = 0; j < sizemax; j++) {
            if (i < size1 && j < size1 && G1[i] != NULL && G1[i][j] != NULL) {
                Gnew[i][j] = G1[i][j];
            }
            else if (i < size2 && j < size2 && G2[i] != NULL && G2[i][j] != NULL) {
                Gnew[i][j] = G2[i][j];
            }
            else {
                Gnew[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < sizemax; i++) {
        step = 0;
        for (int j = 0; j < sizemax; j++) {
            if (Gnew[i][j] == 1) {
                step++;
            }
        }
        if (step == 0) {
            Gnew = delV(Gnew, sizemax, i);
            sizemax--;
            i--;
        }
    }

    return Gnew;
}

int main(void) {
    srand(time(0));
    setlocale(LC_ALL, "");
    int nG1, nG2;
    printf("Введите количество вершин первого графа:");
    scanf_s("%d", &nG1);
    printf("Введите количество вершин второго графа:");
    scanf_s("%d", &nG2);

    int** G1 = createG(nG1);
    printf("\nГраф 1:\n");
    printG(G1, nG1);

    int** G2 = createG(nG2);
    printf("\nГраф 2:\n");
    printG(G2, nG2);

    int** G3 = unionG(G1, G2, nG1, nG2);
    int nG3 = (nG1 > nG2) ? nG1 : nG2;
    printf("\nОбъединение графов\n");
    printG(G3, nG3);

    int** G4 = intersectG(G1, G2, nG1, nG2);
    int nG4 = (nG1 < nG2) ? nG1 : nG2;
    printf("\nПересечение графов\n");
    printG(G4, nG4);

    int** G5 = xorG(G1, G2, nG1, nG2);
    int nG5 = nG3;
    printf("\nКольцевая сумма графов\n");
    printG(G5, nG5);

    int action;
    while (1) {
        printf("\nВыберите действие:\n");
        printf("1. Отождествление вершин\n");
        printf("2. Стягивание ребра\n");
        printf("3. Расщепление вершины\n");
        printf("4. Выход\n");
        printf("Введите номер действия: ");
        scanf_s("%d", &action);

        if (action == 4) break;

        int v1, v2;
        switch (action) {
        case 1:
            printf("Введите вершины для отождествления (v1, v2): ");
            scanf_s("%d %d", &v1, &v2);
            G1 = unionV(G1, nG1, v1, v2);
            nG1--; // Уменьшаем количество вершин
            printf("После отождествления:\n");
            printG(G1, nG1);
            break;
        case 2:
            printf("Введите вершины для стягивания (v1, v2): ");
            scanf_s("%d %d", &v1, &v2);
            G1 = contrE(G1, nG1, v1, v2);
            printf("После стягивания:\n");
            printG(G1, nG1);
            break;
        case 3:
            printf("Введите вершину для расщепления (v): ");
            scanf_s("%d", &v1);
            G1 = splitV(G1, nG1, v1);
            nG1++; // Увеличиваем количество вершин
            printf("После расщепления:\n");
            printG(G1, nG1);
            break;
        default:
            printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
            break;
        }
    }

    for (int i = 0; i < nG1; i++) {
        free(G1[i]);
    }
    free(G1);
    for (int i = 0; i < nG2; i++) {
        free(G2[i]);
    }
    free(G2);

    return 0;
}