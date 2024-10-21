#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Russian");

	int m = 5, Gsize = 0;
	int** G, * deg;

	printf("1 задание\n");

	G = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		G[i] = (int*)malloc(m * sizeof(int));
	}

	deg = (int*)malloc(m * sizeof(int));

	for (int i = 0; i < m; i++) {
		deg[i] = 0;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			G[i][i] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", G[i][j]);
		}
		printf("\n");
	}

	printf("\n2 задание\n");

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				Gsize++;
			}
		}
	}
	Gsize = Gsize / 2;
	printf("Размер граффа: %d\n", Gsize);

	printf("\n3 задание\n");

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				deg[i]++;
			}
		}
		printf("Степень вершины %d = %d\n", i, deg[i]);
		if (deg[i] == 0) printf("Вершина %d изалированна\n", i + 1);
		if (deg[i] == 1) printf("Вершина %d концевая\n", i + 1);
		if (deg[i] == m) printf("Вершина %d доминирующая\n", i + 1);
	}
}