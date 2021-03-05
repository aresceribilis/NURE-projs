#include <iostream>
using namespace std;

int main() {
	int size, t = 0, j = 0, p = 0, compare_counter = 0;
	int* arr_control = new int[10];
	cout << "Started massive: ";
	for (int i = 0; i < 10; i++)
		arr_control[i] = i, cout << arr_control[i] << " ";
	cout << "\nEnter the required spirits massive size: ";
	cin >> size;
	cout << "Fill it!: ";
	int* arr_dynamical = new int[size];
	for (int i = 0; i < size; i++)
		cin >> arr_dynamical[i];
	cout << "Spirits massive: ";
	for (int i = 0; i < size; i++)
		cout << arr_dynamical[i] << " ";
	cout << "\n\n";
	for (int i = 0; i < 10 - size + 1; i++) {
			compare_counter++;
			if (arr_control[i] == arr_dynamical[j]) {
				t = i;
				t++;
				j++;
				if (j == size) {
					p++;
					j = 0;
				}
			}
			while (arr_control[t] == arr_dynamical[j]) {
				compare_counter++;
				t++;
				j++;
				if (j == size) {
					p++;
					j = 0;
					break;
				}
			}
			j = 0;
		}
	cout << "Count of spirits:" << p << endl;
	cout << "Count of comparisons:" << compare_counter << "\n\n";
	system("pause");
	return 0;
}
