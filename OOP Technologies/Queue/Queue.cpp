#include "Queue_.h"

int main() {
	setlocale(LC_ALL, "");
	srand(time(0));
	int tmp_in;
	

	std::cout << "Введите максимальный размер первой очереди: ";
	std::cin >> tmp_in;
	Queue* g1 = new Queue(tmp_in);
	std::cout << "Заполните её: \n";
	tmp_in < 0 ? tmp_in *= -1 : tmp_in = tmp_in;
	for (int i = 0, tmp; i < tmp_in; ++i) {
		std::cout << "  ";
		std::cin >> tmp;
		g1->Push(tmp);
	}
	std::cout << "Первая очередь заполнена!\n\n\n";


	std::cout << "\nВведите максимальный размер второй очереди: ";
	std::cin >> tmp_in;
	Queue g2(tmp_in);
	std::cout << "Введите размер массива элементов, который будет помещен в очередь: ";
	std::cin >> tmp_in;
	tmp_in < 0 ? tmp_in *= -1 : tmp_in = tmp_in;
	int* arr = new int[tmp_in];
	for (int i = 0; i < tmp_in; ++i) {
		arr[i] = rand() % (2 * 30 + 1) - 30;
	}
	std::cout << "Массив был заполнен случайными числами в диапазоне [-30;30].\n";
	g2.Push(arr, tmp_in);
	std::cout << "Массив был помещен во вторую очередь.\n\n\n\n";


	Queue* g3 = new Queue(/**g1*/);
	std::cout << "Третья очередь была созданна пустой.\n\n\n";


	std::cout << "\nПроверим пусты ли очереди:\n1я - " << g1->Empty() << "\n2я - " << g2.Empty() << "\n3я - " << g3->Empty() << "\n\n\n\n";
	std::cout << "Выведем очереди на экран:\n\nПервая:\n";
	g1->Show();
	std::cout << "\nВторая:\n";
	g2.Show();
	std::cout << "\nТретья:\n";
	g3->Show();


	std::cout << "\n\n\nСоединим первую и вторую очереди, заполнив их объединением третью.\n";
	*g3 = g1->Unite(g2);
	//*g3 = g3->Unite(g2);
	std::cout << "Третья очередь выглядит вот так:\n";
	g3->Show();


	std::cout << "\n\n\nСколько элементов желаете удалить из третьей очереди, перед сравнением её со второй? ";
	std::cin >> tmp_in;
	tmp_in < 0 ? tmp_in *= -1 : tmp_in = tmp_in;
	g3->Pop(tmp_in);
	std::cout << "Теперь третья очередь выглядит вот так:\n";
	g3->Show();


	std::cout << "\n\n\nДля наглядности выведем на экран вторую очередь.\n";
	g2.Show();
	std::cout << "Равны ли вторая и третья очереди? ";
	std::cout << g2.Compare(*g3);


	std::cout << "\n\n\n\nВыведем на экран содержимое всех очередей в последний раз, затем очистим их.\n";
	
	std::cout << "\nПервая:\n";
	g1->Show(); // 1
	g1->Show_i();
	g1->Show_size();

	std::cout << "\nВторая:\n";
	g2.Show(); // 2
	g2.Show_i();
	g2.Show_size();

	std::cout << "\nТретья:\n";
	g3->Show(); // 3
	g3->Show_i();
	g3->Show_size();

	std::cout << "\n";
	g1->Clear(); // очистка
	g2.Clear();
	g3->Clear();

	std::cout << "\nПервая:\n";
	g1->Show(); // 1
	g1->Show_i();
	g1->Show_size();

	std::cout << "\nВторая:\n";
	g2.Show(); // 2
	g2.Show_i();
	g2.Show_size();

	std::cout << "\nТретья:\n";
	g3->Show(); // 3
	g3->Show_i();
	g3->Show_size();



	return 0;
}