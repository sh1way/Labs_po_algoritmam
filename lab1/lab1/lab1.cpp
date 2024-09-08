#include <iostream>
using namespace std;

int main() {
	int size;

	cout << "enter size for massiv: ";
	cin >> size;

	int* mass = (int*) malloc(size * sizeof(int));
	
	int max = INT_MIN, min = INT_MAX;

	srand(time(NULL));


	for (int i = 0; i < size; i++) {
		mass[i] = rand() % 100;
	}

	cout << "Random mass:" << endl;
	for (int i = 0; i < size; i++) {
		cout << mass[i] << " ";
	}

	for (int i = 0; i < size; i++) {
		if (mass[i] < min) {
			min = mass[i];
		}
		if (mass[i] > max) {
			max = mass[i];
		}
	}
	
	cout << "\nMax: " << max << endl;
	cout << "Min: " << min << endl;

	return 0;
}