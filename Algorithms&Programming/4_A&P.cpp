#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void filePrint(const char* fName);
int searchLargestByMansValueCourse(const char* fName);

int main()
{
	const int countOfStudents = 10;
	const char* fName = "students.txt";
	int largestByMansValueCourse, birth[10], course[10];
	char thirdName[countOfStudents][13] = { "Андреевич","Андреевич","Михайлович","Игоревич","Алексеевич","Вячеслава","Сергеевна","Александра","Григорьевна","Юрьевна" },
		secondName[countOfStudents][13] = { "Норец","Норец","Куренков","Марченко","Тимошицкий","Старченко","Мищенко","Леонова","Медовая","Демьяненко" },
		firstName[countOfStudents][13] = { "Данил","Денис","Богдан","Вадим","Богдан","Дарья","Катерина","Татьяна","Катерина","Юлия" },
		gender[10] = { 'Ч','Ч','Ч','Ч','Ч','Ч','Ч','Ж','Ж','Ж' };

	srand(time(0));
	setlocale(0, "");
	
	ofstream fin(fName);
	if (!fin) cout << "Ошибка записи в файл "<< fName << " информации о студентах", system("pause"), exit(2);
	for (int i = 0; i < 10; i++) {
		birth[i] = 1996 + rand() % 8;
		course[i] = rand() % 5 + 1;
		fin << secondName[i] << ',' << firstName[i] << ',' << thirdName[i] << ',' << birth[i] << ',' << course[i] << ',' << gender[i] << ';';
	}
	fin.close();

	filePrint(fName);
	largestByMansValueCourse = searchLargestByMansValueCourse(fName);
	if (largestByMansValueCourse == 0) cout << "\nКурса с наибольшим кол-вом мужчин нет. Их либо несколько, либо в выборке нет мужчин.\n\n";
	else {
		cout << "\nНаибольшее кол-во мужчин учится на курсе с номером";
		if (largestByMansValueCourse == 1) cout << " 1";
		if (largestByMansValueCourse == 2) cout << " 2";
		if (largestByMansValueCourse == 3) cout << " 3";
		if (largestByMansValueCourse == 4) cout << " 4";
		if (largestByMansValueCourse == 5) cout << " 5";
		cout << "\n\n";
	}
	system("pause");
}

void filePrint(const char* fName)
{
	char buff[50];
	ifstream fout(fName);

	cout << "Данные о студентах:\n\n";
	for (int i = 0; i < 10; i++) {
		fout.getline(buff, sizeof(buff), ';');
		cout << buff << endl;
	}
	fout.close();
}

int searchLargestByMansValueCourse(const char* fName)
{
	int courses[5]{ 0 }, tmp;
	char buff[64], * lek, course[64];
	ifstream fout(fName);
	
	for (int j = 0; j < 10; j++) {
		fout.getline(buff, sizeof(buff), ';');
		lek = strtok(buff, ",");
		for (int i = 0, tmpp; i < 6; i++) {
				strcpy(course, lek);
				if (i == 4)
					tmpp = (int)course[0]-48;
				if (i == 5 && !strcmp(lek, "Ч"))
					courses[tmpp - 1]++;
			lek = strtok(NULL, ",");
		}
	}
	fout.close();

	if (courses[0] > courses[1] && courses[0] > courses[2] && courses[0] > courses[3] && courses[0] > courses[4]) return 1;
	if (courses[1] > courses[0] && courses[1] > courses[2] && courses[1] > courses[3] && courses[1] > courses[4]) return 2;
	if (courses[2] > courses[1] && courses[2] > courses[0] && courses[2] > courses[3] && courses[2] > courses[4]) return 3;
	if (courses[3] > courses[1] && courses[3] > courses[2] && courses[3] > courses[0] && courses[3] > courses[4]) return 4;
	if (courses[4] > courses[1] && courses[4] > courses[2] && courses[4] > courses[3] && courses[4] > courses[0]) return 5;
	return 0;
}
