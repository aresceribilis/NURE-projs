#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void fileFill(const char* fSName, ios_base::openmode mode, int size);
void fileOperations(const char* fSName1, const char* fSName2, const char* fSName3, const char* fSName4);
void fileToConsole(const char* fSName, ios_base::openmode mode);

int main() {
	srand(time(NULL));

	int size = 30;
	const char*  fSName1 = "file1.bin", *fSName2 = "file2.bin", *fSName3 = "file3.bin", *fSName4 = "file4.bin";

	fileFill(fSName1, ios::binary, size);
	fileFill(fSName2, ios::binary, size);

	fileOperations(fSName1, fSName2, fSName3, fSName4);

	fileToConsole(fSName3, ios::binary);
	fileToConsole(fSName4, ios::binary);
	system("pause");
	return 0;
}

void fileFill(const char* fSName, ios_base::openmode mode, int size) {
	ofstream fin;
	fin.open(fSName, mode);

	if (!fin) {
		cout << fSName << " didn't open in input mode!";
		exit(1);
	}
	cout << "Filling " << fSName << ": ";
	for (int i = 0, tmp; i < size; i++) {
		tmp = -size + rand() % (2 * size + 1);
		fin.write((char*)& tmp, sizeof(tmp));
	}

	fin.close();
	cout << "succesfully!\n";
}

void fileOperations(const char* fSName1, const char* fSName2, const char* fSName3, const char* fSName4) {
	int c1, c2, c3;
	ofstream fin1(fSName3, ios::binary), fin2(fSName4, ios::binary | ios::app);
	ifstream fout1(fSName1, ios::binary), fout2(fSName2, ios::binary);

	if (!fin1) {
		cout << fSName3 << " didn't open in input mode!";
		exit(1);
	}
	if (!fin2) {
		cout << fSName4 << " didn't open in input mode!";
		exit(1);
	}
	if (!fout1) {
		cout << fSName1 << " didn't open in output mode!";
		exit(1);
	}
	if (!fout2) {
		cout << fSName2 << " didn't open in output mode!";
		exit(1);
	}
	cout << "Read from " << fSName1 << " and " << fSName2 << ", operate with them and write in " << fSName3 << " and " << fSName4 << " files: ";
	fout1.read((char*)& c1, sizeof(c1));
	fout2.read((char*)& c2, sizeof(c2));
	while (fout1) {
		c3 = c1 - c2;
		if (c3 > 0)
			fin1.write((char*)& c3, sizeof(c3));
		else
			fin2.write((char*)& c3, sizeof(c3));
		fout1.read((char*)& c1, sizeof(c1));
		fout2.read((char*)& c2, sizeof(c2));
	}
	fin1.close();
	fin2.close();
	fout1.close();
	fout2.close();
	cout << "succesfully!\n";
}

void fileToConsole(const char* fSName, ios_base::openmode mode) {
	ifstream fout(fSName, ios::binary);
	int c;

	if (!fout) {
		cout << fSName << " didn't open in " << mode << " mode!";
		exit(1);
	}
	cout << "Read and cout from " << fSName << " file:\n";
	fout.read((char*)& c, sizeof(c));
	while (fout) {
		cout << setw(5) << c;
		fout.read((char*)& c, sizeof(c));
	}
	cout << endl;
	fout.close();
}
