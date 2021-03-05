#include <iostream>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	const int size = 40;
	int arr[size], min=0, max=0, compare_counter = 0, swap_counter = 0, tmp_index;

	cout << "Unsorted massive:" << endl;
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 21 - 10;
		cout.width(4);
		cout << arr[i];
	}
	cout << endl;
	for (int j = 1; j < size-2; j+=2) {
		min = arr[j];
		for (int i = j+2; i < size; i+=2) {
			compare_counter++;
			if (arr[i] < min) {
				min = arr[i];
				tmp_index = i;
			}
		}
		swap_counter++;
		arr[tmp_index] = arr[j];
		arr[j] = min;
	}
	for (int j = 0; j < size-2; j += 2) {
		max = arr[j];
		for (int i = j+2; i < size; i += 2) {
			compare_counter++;
			if (arr[i] > max) {
				max = arr[i];
				tmp_index = i;
			}
		}
		swap_counter++;
		arr[tmp_index] = arr[j];
		arr[j] = max;
	}
	cout << "Sorted massive:" << endl;
	for (int i = 0; i < size; i++) {
		cout.width(4);
		cout << arr[i];
	}
	cout <<endl<< "Pairs:" << endl;
	for (int i = 0; i < size; i++) {
		if (i % 2 == 0) {
			cout.width(4);
			cout << arr[i];
		}
	}
	cout <<endl<< "Unpairs:"<< endl;
	for (int i = 0; i < size; i++) {
		if (i % 2 == 1) {
			cout.width(4);
			cout << arr[i];
		}
	}
	cout << "\n\nNumber of compares:" << compare_counter;
	cout << "\nNumber of swaps:" << swap_counter << "\n\n";
	system("pause");
	return 0;
}
