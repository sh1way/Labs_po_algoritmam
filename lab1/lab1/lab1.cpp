#include <iostream>
using namespace std;

int main() {
	int mass[10] = { 3, 2, 1, 4, 5, 10, 7, 8, 9, 6 };
	int max = INT_MIN, min = INT_MAX;

	for (int i = 0; i < 10; i++) {
		if (mass[i] < min) {
			min = mass[i];
		}
		if (mass[i] > max) {
			max = mass[i];
		}
	}
	
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;

	return 0;
}