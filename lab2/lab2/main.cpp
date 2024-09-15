#include <iostream>
#include <ctime>
#include <cstdlib>

void shell(int* mass, int size) {
	int gap, x, j;
	for (int k = 0; k < size; k++) {
		gap = mass[k];
		for (int i = gap; i < size; ++i) {
			x = mass[i];
			j = i - gap;
			while (j >= 0 && x < mass[j]) {
				mass[j + gap] = mass[j];
				j -= gap;
			}
			mass[j + gap] = x;
		}
	}
}

void qs(int* mass, int left, int right) {//вызов функции: qs(items, 0, count-1); 
	int i, j;
	int x, y;

	i = left; j = right;

	/* выбор компаранда */
	x = mass[(left + right) / 2];

	do {
		while ((mass[i] < x) && (i < right)) i++;
		while ((x < mass[j]) && (j > left)) j--;

		if (i <= j) {
			y = mass[i];
			mass[i] = mass[j];
			mass[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(mass, left, j);
	if (i < right) qs(mass, i, right);
}

int compare(const void* val1, const void* val2) {
	return (*(int*)val1 - *(int*)val2);
};

int main(void) {
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start, end;

	int size = 25000;

	int* mass = (int*)malloc(size * sizeof(int));

	srand(time(NULL));
	//случайный выбор
	
	for (int i = 0; i < size; i++) {
		mass[i] = rand() % 100 - 1;
	}
	
	//возрастающая последовательность чисел
	/*
	for (int i = 0; i < size; i++) {
		mass[i] = i;
	}
	*/
	//убывающая последовательность чисел
	/*
	for (int i = 0; i < size; i++) {
		mass[i] = size - i;
	}
	*/
	//домик
	/*
	for (int i = 0; i < size; i++) {
		if (i < size / 2) {
			mass[i] = i;
		}
		else {
			mass[i] = size - i;
		}
	}
	*/

	start = clock();
	//shell(mass, size);
	//qs(mass, 0, size - 1);
	qsort(mass, size, sizeof(int), compare);
	end = clock();

	std::cout << float(end - start)/CLOCKS_PER_SEC<< std::endl;

	free(mass);
	return(0);
}
