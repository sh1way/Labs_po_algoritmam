#include <iostream>
#include <time.h>

int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end;

	const int size = 2000;
	int i, j, r;

	int** a = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++) {
		a[i] = (int*)malloc(size * sizeof(int));
	}

	int** b = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++) {
		b[i] = (int*)malloc(size * sizeof(int));
	}

	int** c = (int**)malloc(size * sizeof(int*));
	for (i = 0; i < size; i++) {
		c[i] = (int*)malloc(size * sizeof(int));
	}
	
	int elem_c;
	i = 0;
	j = 0;

	srand(time(NULL));
	while (i < size) {
		while (j < size) {
			a[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}
	srand(time(NULL));
	i = 0; j = 0;
	while (i < size) {
		while (j < size) {
			b[i][j] = rand() % 100 + 1;
			j++;
		}
		i++;
	}

	start = clock();

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			elem_c = 0;
			for (r = 0; r < size; r++) {
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}

	end = clock();

	std::cout << float(start)/float(CLOCKS_PER_SEC)<< std::endl;
	std::cout << (float(end) - float(start))/float(CLOCKS_PER_SEC)<< std::endl;

	return(0);
}
