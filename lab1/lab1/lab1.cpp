#include <iostream>
using namespace std;

int main() {
	int rows, cols;

	cout << "enter rows for massiv: ";
	cin >> rows;

	cout << "enter cols for massiv: ";
	cin >> cols;

	int** mass = (int**)malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		mass[i] = (int*)malloc(cols * sizeof(int));
	}
	
	int max = INT_MIN, min = INT_MAX;

	srand(time(NULL));


	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			mass[i][j] = rand() % 100;
		}
	}

	cout << "\nRandom mass:";
	for (int i = 0; i < rows; i++) {
		cout << "\n";
		for (int j = 0; j < cols; j++) {
			cout << mass[i][j] << " ";
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (mass[i][j] < min) {
				min = mass[i][j];
			}
			if (mass[i][j] > max) {
				max = mass[i][j];
			}
		}
	}
	
	cout << "\nMax: " << max << endl;
	cout << "Min: " << min << endl;
	
	cout << endl;
	int rowSUM;

	for (int i = 0; i < rows; i++) {
		rowSUM = 0;
		for (int j = 0; j < cols; j++) {
			rowSUM += mass[i][j];
		}
		cout << "Summa " << i + 1 << " row: " << rowSUM << endl;
	}
	
	cout << endl;
	int colSUM;

	for (int j = 0; j < cols; j++) {
		colSUM = 0;
		for (int i = 0; i < rows; i++) {
			colSUM += mass[i][j];
		}
		cout << "summa " << j + 1 << "col: " << colSUM << endl;
	}

	for (int i = 0; i < rows; ++i) {
		free(mass[i]);
	}
	free(mass);

	return 0;
}