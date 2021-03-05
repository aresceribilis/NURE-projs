#include <iostream>
#include <iomanip>

void Print(int** arr, int s1, int s2);

int main() {
	setlocale(LC_ALL, "Russian");
	int** ms, ** mi;
	enum { x1 = 0, x2, x3, x4 };
	enum { a = 0, b, c, d, e, f, g };
	int A[4] = { x1, x2, x3, x4 };
	int C[7] = { a, b, c, d, e, f, g };
	int B[13][3] = { {x1,a,x2},
		{x1,d,x4}, {x1,e,x4}, {x1,f,x3},
		{x2,a,x1}, {x2,c,x3}, {x2,b,x4},
		{x3,f,x1}, {x3,c,x2}, {x3,g,x3},
		{x4,b,x2}, {x4,d,x1}, {x4,e,x1} };
	int hills = sizeof(A) / sizeof(*A);
	int becon = sizeof(C) / sizeof(*C);
	int inc = sizeof(B) / sizeof(*B);

	std::cout << "A = { x1, x2, x3, x4 }\nC = { a, b, c, d, e, f, g }\nB = { {x1,a,x2}, \n    {x1,d,x4}, { x1,e,x4 }, { x1,f,x3 }, \n    { x2,a,x1 }, { x2,c,x3 }, { x2,b,x4 }, \n    { x3,f,x1 }, { x3,c,x2 }, { x3,g,x3 }, \n    { x4,b,x2 }, { x4,d,x1 }, { x4,e,x1 } }\n";
	std::cout << "А - множество вершин, С - множество рёбер, В - множество инцидентности\n\n";
	ms = new int* [hills];
	for (int i = 0; i < hills; ++i) {
		ms[i] = new int[hills];
		for (int j = 0; j < hills; ++j) {
			ms[i][j] = 0;
		}
	}
	for (int i = 0; i < inc; i++) {
		ms[B[i][0]][B[i][2]] = 2; 
		if (B[i][0] == B[i][2])
			ms[B[i][0]][B[i][2]] = 2;
	}
	std::cout << "\nМатрица смежности\n";
	Print(ms, hills, hills);

	mi = new int* [hills];
	for (int i = 0; i < hills; ++i) {
		mi[i] = new int[becon];
		for (int j = 0; j < becon; ++j) {
			mi[i][j] = 0;
		}
	}
	std::cout << "\n\n";
	for (int i = 0; i < inc; i++) {
		mi[B[i][0]][B[i][1]] = 2; 
		if (B[i][0] == B[i][2])
			mi[B[i][0]][B[i][1]] = 2;
	}
	std::cout << "Матрица инциденций (a, b, c, d, e, f, g)\n";
	Print(mi, hills, becon);

	for (int i = 0; i < hills; ++i)
		delete[] ms[i];
	for (int i = 0; i < hills; ++i)
		delete[] mi[i];
	delete[] ms;
	delete[] mi;

	return 0;
}

void Print(int** arr, int s1, int s2) {
	for (int i = 0; i < s1; ++i) {
		std::cout << "\n";
		for (int j = 0; j < s2; ++j) {
			std::cout << std::setw(4) << arr[i][j];
		}
		std::cout << "\n";
	}
}
