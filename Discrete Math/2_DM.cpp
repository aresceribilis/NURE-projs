#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	cout << " A B C D                 !D*C         !(!A + B + C)||D    !(A * B && !C * D)       !(z + y)          F = x + g\n";
	for (int A = 0; A < 2; ++A) {
		for (int B = 0; B < 2; ++B) {
			for (int C = 0; C < 2; ++C) {
				for (int D = 0; D < 2; ++D) {
					bool x = !D * C;
					bool y = !(!A + B + C) || D;
					bool z = !(A * B && !C * D);
					bool g = !(z + y);
					bool i = x + g;
					cout << setw(2) << A << setw(2) << B << setw(2) << C << setw(2) << D;
					cout << setw(20) << x << setw(20) << y << setw(20) << z << setw(20) << g << setw(20) << i << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}
