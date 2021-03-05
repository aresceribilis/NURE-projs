#include <iostream>

class Chesspiece {
private:
	Chesspiece() = default;
protected:
	bool color;
	int x;
	int y;
public:
	Chesspiece(bool color, int x, int y) : color(color), x(x), y(y) {}

	virtual void get_info() = 0;
	virtual bool moveable(int x, int y) = 0;
	int get_x() { return x; }
	int get_y() { return y; }
	bool get_color() { return color; }
};


class Checker : public Chesspiece {
	Checker() = default;
public:
	Checker(bool color, int x, int y) : Chesspiece(color, x, y) {}
	void get_info() override {
		color ? std::cout << "Белая  " : std::cout << "Черная ";
		std::cout << "пешка на позиции (" << x << "," << y << ")\n";
	}
	bool moveable(int x, int y) override {
		return (this->x == x && abs(this->y - y));
	}
};

class King : public Chesspiece {
	King() = default;
public:
	King(bool color, int x, int y) : Chesspiece(color, x, y) {}
	void get_info() override {
		color ? std::cout << "Белая  " : std::cout << "Черная ";
		std::cout << "ферзь на позиции (" << x << "," << y << ")\n";
	}
	bool moveable(int x, int y) override {
		return (abs((this->x - x) == abs(this->y - y)) && (this->x != x) || ((this->x == x) && (this->y != y)) || ((this->x != x) && (this->y == y)));
	}
};

struct Elem {
	Chesspiece* item;
	Elem* next;
	Elem() { item = nullptr; next = nullptr; }
};

class Board {
	Elem* head;
public:
	Board() : head(nullptr) {}
	void Add_chess(Chesspiece* elem) {
		if (elem->get_x() > 0 && elem->get_x() < 9 && elem->get_y() > 0 && elem->get_y() < 9) {
			Elem* tmp = new Elem;
			if (!strcmp(typeid(*elem).name(), "class Checker"))
				tmp->item = new Checker(elem->get_color(), elem->get_x(), elem->get_y());
			else
				tmp->item = new King(elem->get_color(), elem->get_x(), elem->get_y());
			tmp->item = elem;
			tmp->next = head;
			head = tmp;
		}
	}
	void Add_chess(Chesspiece* elem, int x, int y) {
		Elem* tmp = new Elem;
		if (!strcmp(typeid(*elem).name(), "class Checker"))
			tmp->item = new Checker(elem->get_color(), x, y);
		else
			tmp->item = new King(elem->get_color(), x, y);
		tmp->item = elem;
		tmp->next = head;
		head = tmp;
	}
	void Delete_chess() {
		Elem* tmp = head;
		head = head->next;
		tmp->next = nullptr;
		delete tmp;
	}
	void get_info() {
		std::cout << "Доска содержит:\n";
		Elem* tmp = head;
		while (tmp) {
			tmp->item->get_info();
			tmp = tmp->next;
		}
		std::cout << '\n';
	}
	void moveable(int x, int y) {
		std::cout << "Могут ли фигуры передвинуться на позицию (" << x << "," << y << "):\n";
		Elem* tmp = head;
		while (tmp) {
			if (tmp->item->moveable(x, y))
				std::cout << "Можно!  ";
			else
				std::cout << "Нельзя! ";
			tmp->item->get_info();
			tmp = tmp->next;
		}
	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	Checker* c1 = new Checker(false, 1, 6), *c2 = new Checker(true, 2, 4), *c3 = new Checker(false, 5, 2);
	King *k1 = new King(false, 1, 1), *k2 = new King(true, 2, 7), *k3 = new King(true, 9, 2);

	Board* board = new Board;
	board->get_info();
	board->Add_chess(c1);
	board->Add_chess(c3);
	board->Add_chess(k1, 6, 6);
	board->Add_chess(c2);
	board->Add_chess(k2);
	board->Add_chess(k3);
	board->get_info();
	board->Delete_chess();
	board->moveable(2, 3);
}