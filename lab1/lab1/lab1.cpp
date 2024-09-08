#include <iostream>
using namespace std;

int main() {
	int mass[10] = {0};
	int max = INT_MIN, min = INT_MAX;

	srand(time(NULL));

	for (int i = 0; i < 10; i++) {
		mass[i] = rand() % 100;
	}

	cout << "Random mass:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << mass[i] << " ";
	}

	for (int i = 0; i < 10; i++) {
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