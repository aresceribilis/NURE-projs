#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int productsCountFind(const char* file_name);

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	struct DataInfo {
		int day, year;
		char month[15];
	};
	struct Product {
		char firm_name[32];
		char product_name[48];
		char supplier_country[15];
		int price, count;
		DataInfo data;
	};
	Product* products;
	int products_count;
	char buff[128];
	const char *file_name = "productss.txt";
	ifstream fout;
	int p_price, p_count, p_day, p_year;
	char f_name[15][48] = { "Братанчик.инк","Самсунг","Эндемик.инк","Нокия","Хуавей","Макдональдс","Стрендж.инк","Эпл","Марафонец","Викторианство","ХНУРЭ","Валерианство","Нокия","Гватемала","Папуг.инк" },
		p_name[15][64] = { "Мониторы от Норцов","Телефон А1","Мониторы гибкие","Телефон А2","Телефон А3","Мониторы из мака","Мониторы из мрамора","Телефон А4","Скакалка","Мониторы на отчисление","Мониторы из сената","Телефон А5","Телефон А6","Клаудфорест","Мониторы от папуга" },
		p_supplier_country[15][32] = { "Украина","Китай","Далекий остров","Китай","Китай","США","Космос","США","Россия","Edge of Empire","Страна забвения","Китай","Китай","Бразилия","Сердешко" },
		months[12][16] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" },
		p_month[15][16];

	ofstream fin(file_name);
	if (!fin) cout << "Ошибка записи в файл " << file_name << " информации о продуктах", system("pause"), exit(2);
	for (int i = 0, tmp_month; i < 15; i++) {
		tmp_month = rand() % 12;
		strcpy(p_month[i], months[tmp_month]);
		p_price = rand() % 2001;
		p_count = rand() % 1001;
		p_day = rand() % 30;
		p_year = 2012 + rand() % 2;
		fin << f_name[i] << ',' << p_name[i] << ',' << p_price << ',' << p_count << ',' << p_day << ',' << p_month[i] << ',' << p_year << ',' << p_supplier_country[i] << ';';
	}
	fin.close();

	products_count = productsCountFind(file_name);
	products = new Product[products_count];

	fout.open(file_name);
	if (!fout) cout << "Ошибка чтения из файла " << file_name << " информации о продуктах", exit(1);
	for (int i{ 0 }; i < products_count; i++) {
		fout.getline(buff, sizeof(buff), ';');
	
		strcpy(products[i].firm_name, strtok(buff, ","));
		strcpy(products[i].product_name, strtok(NULL, ","));
		products[i].price = atoi(strtok(NULL, ","));
		products[i].count = atoi(strtok(NULL, ","));
		products[i].data.day = atoi(strtok(NULL, ","));
		strcpy(products[i].data.month, strtok(NULL, ","));
		products[i].data.year = atoi(strtok(NULL, ","));
		strcpy(products[i].supplier_country, strtok(NULL, "\0"));
	}

	for (int i{ 0 }; i < products_count; i++) {
		cout << "Название фирмы: " << products[i].firm_name << "\nНазвание продукта: " << products[i].product_name << "\nСтоимость продукта: "
			 << products[i].price << "\nКол-во продуктов: " << products[i].count << "\nДата поставки: "
			 << products[i].data.day << '.' << products[i].data.month << '.'
			 << products[i].data.year << "\nСтрана-поставщик: " << products[i].supplier_country << "\n\n";
	}

	cout << "Названия фирм, которые соответствуют условию ревизора:\n";
	for (int i{ 0 }; i < products_count; i++) {
		if (strstr(products[i].product_name, "Мониторы") && products[i].price <= 1500 && strstr(products[i].data.month, "Март") && products[i].data.year == 2013)
			cout << products[i].firm_name << endl;
	}
	fout.close(); cout << endl;

	delete[] products;
	system("pause");
	return 0;
}
int productsCountFind(const char* file_name) {
	int counter = 0;
	char tmp[128];
	ifstream fout;

	fout.open(file_name);
	if (!fout) cout << "Ошибка чтения файла " << file_name << " во время определения кол-ва продуктов", exit(-1);
	while (fout.getline(tmp, sizeof(tmp), ';'))
		counter++;
	fout.close();
	return counter;
}
