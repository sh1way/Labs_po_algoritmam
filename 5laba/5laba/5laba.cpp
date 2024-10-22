#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	int m, Gsize = 0;
	int** G, * deg;

	printf("������� �������� �����: ");
	scanf_s("%d", &m);

	printf("1.1 �������\n");

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

	printf("\n1.2 �������\n");

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				Gsize++;
			}
		}
	}
	Gsize = Gsize / 2;
	printf("������ ������: %d\n", Gsize);

	printf("\n1.3 �������\n");

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (G[i][j] == 1) {
				deg[i]++;
			}
		}
		printf("������� ������� %d = %d\n", i, deg[i]);
		if (deg[i] == 0) printf("������� %d �������������\n", i + 1);
		if (deg[i] == 1) printf("������� %d ��������\n", i + 1);
		if (deg[i] == m) printf("������� %d ������������\n", i + 1);
	}

	printf("\n2.1 �������");

	int** Ginciden, index = 0;

	Ginciden = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		Ginciden[i] = (int*)malloc(Gsize * sizeof(int));
		for (int j = 0; j < Gsize; j++) {
			Ginciden[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = i+1; j < m; j++) {
			if (G[i][j] == 1) {
				Ginciden[i][index] = 1;
				Ginciden[j][index] = 1;
				index++;
			}
		}
	}

	printf("\n������� �������������:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < Gsize; j++) {
			printf("%d ", Ginciden[i][j]);
		}
		printf("\n");
	}

	printf("\n2.2 �������");
	
	int Gedge = 0;

	for (int j = 0; j < Gsize; j++) {
		int column = 0;
		for (int i = 0; i < m; i++) {
			if (Ginciden[i][j] == 1) {
				column++;
			}
		}
		if (column == 2) {
			Gedge++;
		}
	}

	printf("\n������ ������(�� ������� �������������): %d\n", Gedge);

	printf("\n2.3 �������\n");

	for (int i = 0; i < m; i++) {
		int edge = 0;
		for (int j = 0; j < Gsize; j++) {
			if (Ginciden[i][j] == 1) {
				edge++;
			}
		}
		printf("������� ������� %d = %d\n", i + 1, edge);
		if (edge == 0) printf("������� %d �������������\n", i + 1);
		if (edge == 1) printf("������� %d ��������\n", i + 1);
		if (edge == Gedge) printf("������� %d ������������\n", i + 1);
	}

	for (int i = 0; i < m; i++) {
		free(G[i]);
	}
	free(G);
	free(deg);
	for (int i = 0; i < m; i++) {
		free(Ginciden[i]);
	}
	free(Ginciden);

	return 0;
}