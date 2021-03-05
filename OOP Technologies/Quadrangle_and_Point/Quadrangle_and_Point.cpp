#include "Quadrangle_and_Point.h"

int main() {
	setlocale(LC_ALL, "Russian");

	/*произвольный четырехугольник*/Point p4[4] = { {10, -15}, {31, 37}, {52, 27}, {35, -26} };
	/*прямоугольник*/Point p0[4] = { {1, -1}, {3, 3}, {5, 2}, {3, -2} };
	/*квадрат*/Point p1[4] = { {-4, 4}, {4, 4}, {4, -4}, {-4, -4} };
	/*паралелограм*/Point p2[4] = { {0, 0}, {2, 3}, {2, 0}, {0, -3} };
	/*ромб*/Point p3[4] = { {-2, 0}, {0, 3}, {2, 0}, {0, -3} };

	Quadrangle* quad4 = new Quadrangle(p4[0], p4[1], p4[2], p4[3]),
		* quad0 = new Quadrangle(p0[0], p0[1], p0[2], p0[3]),
		* quad1 = new Quadrangle(p1[0], p1[1], p1[2], p1[3]),
		* quad2 = new Quadrangle(p2[0], p2[1], p2[2], p2[3]),
		* quad3 = new Quadrangle(p3[0], p3[1], p3[2], p3[3]),
		* quad_empty = new Quadrangle;

	std::cout << "Было создано 5 четырехугольников, выведем информацию о первом из них.\n\n";
	quad4->show();
	std::cout <<"Как видим, на самом деле их 6. Все из-за созданного, но не упомянутого программистом ещё одного,\n   пустого четырехугольника.\n\n";
	quad_empty->show();
	std::cout << "Пытаясь вывести информацию о нём, получаем вот это. Действительно, он ведь пуст.\n\n";

	std::cout << "Переместим же содержимое первого четырехугольника в пустой шестой с помощью конструктора перемещения.\n";
	*quad_empty = std::move(*quad4);
	std::cout << "Перемещение выполнено. Отныне шестой владеет данными первого, а первый - пуст.\n\n";
	quad4->show();
	quad_empty->show();

	std::cout << "Вернув все на свои места, продолжим работу.\n\n";
	*quad4 = std::move(*quad_empty);

	float a, b;
	std::cout << "Проверим пренадлежит ли точка {a; b} шестому четырехугольнику. Введите а и b\n   a = ";
	std::cin >> a;
	std::cout << "   b = ";
	std::cin >> b;
	std::cout << "\n";
	true == isPointInQuadrangle({ a, b }, *quad4) ? std::cout << "Да, пренадлежит.\n\n" : std::cout << "Нет, не пренадлежит.\n\n";

	float c, d;
	std::cout << "Создадим точку {c; d} и узнаем расстояния:\n1) от неё до начала координат.\n2) от неё до точки {a; b}\n\nВведите c и d\n   c = ";
	std::cin >> c;
	std::cout << "   d = ";
	std::cin >> d;
	std::cout << "\n";
	Point ab{ a,b }, cd{ c, d };
	std::cout << "1) " << cd.distance_to_origin();
	std::cout << "\n2) " << cd.distance_btwn_points(ab);
	std::cout << "\n\n";

	std::cout << "Создадим массив со всеми четырехугольниками, затем отсортируем их по возрастанию периметра.\nВыводя на экран результат, будем удалять четырехугольники\n";
	Quadrangle* quads[6] = { quad4, quad0, quad1, quad2, quad3, quad_empty };

	std::cout << "\n\nДо сортировки:\n\n";
	for (int i = 0; i < 6; ++i)
		quads[i]->show();

	Quadrangle* tmp;
	for (int i = 0; i < 6; ++i) {
		for (int j = i + 1; j < 6; ++j)
			if (quads[i]->getPerimeter() < quads[j]->getPerimeter())
			{
				tmp = quads[j];
				quads[j] = quads[i];
				quads[i] = tmp;
			}
	}

	std::cout << "\n\nПосле сортировки:\n\n";
	for (int i = 0; i < 6; ++i) {
		quads[i]->show();
		delete quads[i];
	}

	return 0;
}