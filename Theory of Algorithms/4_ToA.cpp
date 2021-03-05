#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	int **arr, n, min_i, min_j, itr, L, P, dec;
	float sum, res, prm,** ary, *vec;
	cout << "Введите размер матрицы: "; cin >> n; cout << "\n\n";
	while (n < 1)
		cin >> n;

	arr = new int* [n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[i][j] = -5 + rand() % 11;

	for (int i = 0; i < n; i++, cout << "\n\n")
		for (int j = 0; j < n; j++)
			cout << setw(5) << arr[i][j];

	min_i = 0, min_j = 0;
	if (arr[min_i][min_j] <= 0) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n && min_i == 0 && min_j == 0; j++)
				if (arr[i][j] > 0)
					min_i = i, min_j = j;
		if (min_i == 0 && min_j == 0)
			cout << "Положительного элемента в массиве нет\n\n";
		else {
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					if (arr[i][j] > 0 && arr[i][j] < arr[min_i][min_j])
						min_i = i, min_j = j;
			cout << "Минимальный положительный элемент ->  [" << min_i << "][" << min_j << "]\n\n";
		}
	}
	else {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (arr[i][j] > 0 && arr[i][j] < arr[min_i][min_j])
					min_i = i, min_j = j;
		cout << "Минимальный положительный элемент - > [" << min_i << "][" << min_j << "]\n\n";
	}

	sum = 0, itr = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (abs(arr[i][j] % 2) == 1)
				sum += arr[i][j], itr++;
	if (itr == 0)
		cout << "Непарных элементов нет\n\n";
	else {
		res = sum / itr;
		cout << "Среднее арифметическое непарных элементов =  " << res << "\n\n";
	}

	itr = 0;
	for (int i = 1; i < n - 1; i++)
		if (arr[i][i] > 0)
			itr++;
	if (n % 2 == 1) {
		for (int i = 1; i < n - 1; i++)
			if (arr[n - 1 - i][i] > 0 && i != (n / 2))
				itr++;
	}
	else
		for (int i = 1; i < n - 1; i++)
			if (arr[n - 1 - i][i] > 0)
				itr++;
	for (int i = 0; i < n; i++) {
		if (arr[0][i] > 0)
			itr++;
		if (arr[n - 1][i] > 0)
			itr++;
	}
	for (int i = 1; i < n - 1; i++) {
		if (arr[i][0] > 0)
			itr++;
		if (arr[i][n - 1] > 0)
			itr++;
	}
	cout << "По периметру и по диагоналям матрицы " << itr << " положительных чисел\n\n";

	for (int i = 0; i < n; i++)
		delete[] arr[i];
	delete[] arr;

	cout << "\n\nВведите L кол-во строк и P кол-во столбцов:\n\nL = "; cin >> L; cout << "\nP = "; cin >> P; cout << "\n\n";
	ary = new float* [P];
	for (int i = 0; i < P; i++)
		ary[i] = new float[L];

	for (int i = 0; i < P; i++)
		for (int j = 0; j < L; j++)
			prm = -5 + rand() % 11,
			dec = rand() % 100 / 100,
			prm += dec,
			ary[i][j] = prm;

	for (int i = 0; i < P; i++, cout << "\n\n")
		for (int j = 0; j < L; j++)
			cout << setw(5) << ary[i][j];//    L = 5   xxx   P = 3

	vec = new float[L];
	for (int i = 0; i < L; i++) {
		vec[i] = ary[0][i];
		for (int j = 0; j < P - 1; j++)
			if (vec[i] < ary[j + 1][i])
				vec[i] = ary[j + 1][i];
	}
	cout << "Вектор длинной L, содержащий наибольшие элементы столбцов матрицы L * P:\n\n";
	for (int i = 0; i < L; i++)
		cout << setw(5) << vec[i];
	cout << "\n\n";

	system("pause");
	return 0;
}
