#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	
	// Параметризация
	int N, * arr, minElem, sum, counter;
	float* ary, prim, dec;
	
	cout << "Начало задания 1:\n\n";
	N = rand() % 5 + 6;
	cout << "Размер массива: " << N << "\n\n";

	arr = new int[N];
	for (int i = 0; i < N; i++) {
		// Заполнение массива
		arr[i] = rand() % (2 * N + 1) - N;
	}

	cout << "Начальный массив:\n\n";
	for (int i = 0; i < N; i++) {
		// Вывод массива
		cout << setw(5) << arr[i];
	}
	cout << "\n\n";

	minElem = arr[0]; // Нахождение минимального по модулю элемента массива
	for (int i = 1; i < N; i++)
		if (abs(arr[i]) < abs(minElem))
			minElem = arr[i];
	
	sum = 0; // Сумирование модулей элементов после первого встреченного элемента, равного 0
	for (int i = 0, flag = 0; i < N; i++) {
		if (arr[i] == 0 && flag == 0)
			flag = 1;
		if (flag)
			sum += abs(arr[i]);
	}
	
	delete[] arr; // Очистка памяти
	cout << "Минимальный по модулю элемент: " << minElem << "\nСумма модулей элементов после первого встреченного элемента, который равен нулю: " << sum << "\n\n"; // Вывод результатов

	cout << "Начало задания 2:\n\n";
	N = rand() % 5 + 6;
	cout << "Размер массива: " << N << "\n\n";
	
	ary = new float[N];
	for (int i = 0; i < N; i++) {
		// Заполнение массива
		prim = -9 + rand() % (2 * 9 + 1);
		dec = (float)(rand() % 10) / 10;
		if (prim < 0)
			ary[i] = prim - dec;
		else
			ary[i] = prim + dec;
	}

	cout << "Начальный массив:\n\n";
	for (int i = 0; i < N; i++) {
		// Вывод массива
		cout << setw(8) << ary[i];
	}
	cout << "\n\n";

	counter = 0;
	for (int i = 0; i < N - 1; i++)
		if (ary[i] == (-1 * ary[i + 1]))
			counter++;
	delete[] ary; // Очистка памяти
	cout << "Кол-во пар соседних элементов, с одинаковыми абсолютными значениями, при этом разнящихся знаком: " << counter << "\n\n";
	
	system("pause");
	return 0;
}
