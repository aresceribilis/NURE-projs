#pragma once
#include <iostream> // раз уж все комментим)
#include <utility> // для std::move()

class Polynomial;

class Polynomial_info { // информация о полиноме
    int power; // его степень
    float coef; // его коефициент
    Polynomial_info* next; // указатель на следующих "х"
    Polynomial_info() = default; // конструктор по умолчанию
public:
    ~Polynomial_info(); // деструкторю
    Polynomial_info(int power, float coef); // конструктор с параметрами
    void show();
    friend std::ostream& operator<<(std::ostream& out, const Polynomial& pol); // для вывода информации о полиноме
    friend class Polynomial;
	friend Polynomial& operator*(float mult_coef, const Polynomial& pol); // для умножения полинома на число слева
	friend Polynomial& operator*(const Polynomial& pol, float mult_coef); // для умножения полинома на число справа
};

class Polynomial { // полином
    static int count_of_pols; // количество существующих полиномов
	static int current_count_of_pols;
    int p_num; // номер полинома
    Polynomial_info* data; // ссылка на информацию о полиноме
    int count_of_variables; // кол-во "х-ов"
public:
    ~Polynomial(); // деструктор

    Polynomial(); // конструктор по умолчанию
    Polynomial(const int size, Polynomial_info** datas); // конструктор с параметрами "

	template <char ch = '+'>
	int push(const int size, Polynomial_info* datas = NULL);
	template <char ch = '+'>
	int push(const int size, Polynomial_info** datas = NULL);

    Polynomial(Polynomial& pol); // конструктор копирования
    Polynomial& operator=(Polynomial& pol); // оператор копирования

    Polynomial(Polynomial&& pol); // конструктор перемещения
    Polynomial& operator=(Polynomial&& pol); // оператор перемещения

    bool operator==(const Polynomial& pol); // для сравнения полиномов на идентичность
    bool operator!=(const Polynomial& pol); // для сравнения полиномов на разность

    Polynomial& operator+(Polynomial& pol); // для сложения полиномов
    Polynomial& operator-(Polynomial& pol); // для вычитания полиномов

    float operator()(float x); // для возврата значения полинома при заданном "х"

    float operator[](int id); // для возврата коефициента "х" при указанном id

    friend Polynomial& operator+(Polynomial_info elem, const Polynomial& pol); // для сложения полинома с числом слева
    friend Polynomial& operator+(const Polynomial& pol, Polynomial_info elem); // для сложения полинома с числом справа

    friend Polynomial& operator*(float mult_coef, const Polynomial& pol); // для умножения полинома на число слева
    friend Polynomial& operator*(const Polynomial& pol, float mult_coef); // для умножения полинома на число справа

    friend std::ostream& operator<<(std::ostream& out, const Polynomial& pol); // для вывода информации о полиноме

    friend class Polynomial_info; //
};

int Polynomial::count_of_pols = 0;
int Polynomial::current_count_of_pols = 0;

Polynomial_info::~Polynomial_info() {
	next = NULL;
}

Polynomial_info::Polynomial_info(int power, float coef) {
	power >= 0 ? this->power = power : this->power = -1 * power;
	this->coef = coef;
	this->next = NULL;
}


void Polynomial_info::show() {
    std::cout << "Power = " << power << ", coef = " << coef << ", next = " << next << "\n\n";
}

//----------------------------------------------------------------------------------------------------------------------------

Polynomial::~Polynomial() { // деструктор
    --current_count_of_pols;
	data = NULL;
}

Polynomial::Polynomial() { // конструктор по умолчанию
    p_num = ++count_of_pols;
	++current_count_of_pols;
    data = NULL;
    count_of_variables = 0;
}

Polynomial::Polynomial(const int size, Polynomial_info** datas) {
	p_num = ++count_of_pols;
	++current_count_of_pols;
	if (datas)
		this->push(size, datas);
	else this->data = NULL;
}

template <char ch>
int Polynomial::push(const int size, Polynomial_info* datas) { // пуш элементов
	int i = 0;
	if (datas == NULL) return 0;

	if (ch != '-') {
		if (data == NULL) {
			data = new Polynomial_info(datas->power, datas->coef);
			++i;
			datas = datas->next;
		}
		Polynomial_info* tmp;
		for (; i < size && datas != NULL; ++i, datas = datas->next) {
			tmp = this->data;
			while (tmp->next != NULL && datas->power != tmp->power) {
				tmp = tmp->next;
			}
			if (datas->power == tmp->power) {
				tmp->coef += datas->coef;
			}
			else {
				tmp->next = new Polynomial_info;
				tmp->next->power = datas->power;
				tmp->next->coef = datas->coef;
			}
		}
	}
	else {
		if (data == NULL) {
			data = new Polynomial_info(datas->power, -1. * (datas->coef));
			++i;
			datas = datas->next;
		}
		Polynomial_info* tmp;
		for (; i < size && datas != NULL; ++i, datas = datas->next) {
			tmp = this->data;
			while (tmp->next != NULL && datas->power != tmp->power) {
				tmp = tmp->next;
			}
			if (datas->power == tmp->power) {
				tmp->coef -= datas->coef;
			}
			else {
				tmp->next = new Polynomial_info;
				tmp->next->power = datas->power;
				tmp->next->coef = -1. * (datas->coef);
			}
		}
	}

	Polynomial_info* tmp = this->data;
	int iter = 0;
	while (tmp && tmp->coef == 0) {
		this->data = this->data->next;
		tmp = this->data;
	}
	if (tmp) {
		++iter;
		while (tmp->next != NULL) {
			tmp = tmp->next;
			++iter;
		}
	}

	count_of_variables = iter;
	return i;
}

template <char ch>
int Polynomial::push(const int size, Polynomial_info** datas) { // пуш элементов
	int i = 0;
	if (datas == NULL) return 0;
	if ((*datas) == NULL) return 0;

	if (ch != '-') {
		if (data == NULL) {
			data = new Polynomial_info(datas[i]->power, datas[i]->coef);
			++i;
		}
		Polynomial_info* tmp;
		for (; i < size; ++i) {
			tmp = this->data;
			while (tmp->next != NULL && datas[i]->power != tmp->power) {
				tmp = tmp->next;
			}
			if (datas[i]->power == tmp->power) {
				tmp->coef += datas[i]->coef;
			}
			else {
				tmp->next = new Polynomial_info;
				tmp->next->power = datas[i]->power;
				tmp->next->coef = datas[i]->coef;
			}
		}
	}
	else {
		if (data == NULL) {
			data = new Polynomial_info(datas[i]->power, -1. * (datas[i]->coef));
			++i;
		}
		Polynomial_info* tmp;
		for (; i < size; ++i) {
			tmp = this->data;
			while (tmp->next != NULL && datas[i]->power != tmp->power) {
				tmp = tmp->next;
			}
			if (datas[i]->power == tmp->power) {
				tmp->coef -= datas[i]->coef;
			}
			else {
				tmp->next = new Polynomial_info;
				tmp->next->power = datas[i]->power;
				tmp->next->coef = -1. * (datas[i]->coef);
			}
		}
	}

	Polynomial_info* tmp = this->data;
	int iter = 0;
	while (tmp && tmp->coef == 0) {
		this->data = this->data->next;
		tmp = this->data;
	}
	if (tmp) {
		++iter;
		while (tmp->next != NULL) {
			tmp = tmp->next;
			++iter;
		}
	}

	count_of_variables = iter;
	return i;
}

Polynomial::Polynomial(Polynomial& pol) { // конструктор копирования
	this->count_of_variables = pol.count_of_variables;
	p_num = ++count_of_pols;
	++current_count_of_pols;
	if (pol.data) this->push(pol.count_of_variables, pol.data);
}

Polynomial& Polynomial::operator=(Polynomial& pol) { // оператор копирования
	if (this == &pol) return *this;
	this->p_num = count_of_pols;
	Polynomial tmp;
	if (pol.data) tmp.push(pol.count_of_variables, pol.data);
	this->count_of_variables = tmp.count_of_variables;
	this->data = tmp.data;

    return *this;
}

Polynomial::Polynomial(Polynomial&& pol) { // конструктор перемещения
	if (this != &pol) {
		this->data = pol.data;
		this->p_num = ++count_of_pols;
		count_of_variables = pol.count_of_variables;
		pol.count_of_variables = 0;
		pol.data = NULL;
	}
}

Polynomial& Polynomial::operator=(Polynomial&& pol) { // оператор перемещения
	if (this == &pol) return *this;
	this->data = pol.data;
	count_of_variables = pol.count_of_variables;
	pol.count_of_variables = 0;
	pol.data = NULL;

	return *this;
}

bool Polynomial::operator==(const Polynomial& pol) { // для сравнения полиномов на идентичность
	if (this == &pol) return 1;
	if (this->count_of_variables == pol.count_of_variables) return 1; // tmp->data == NULL || pol.data == NULL included

	Polynomial_info* tmp;
	for (int i = 0; i < count_of_variables; ++i) {
		tmp = this->data;
		while (tmp->next != NULL && tmp->power != pol.data->power)
			tmp = tmp->next;
		if (!(tmp->power == pol.data->power && tmp->coef == pol.data->coef)) return 0;
	}

	return 1;
}

bool Polynomial::operator!=(const Polynomial& pol) { // для сравнения полиномов на разность
	if (this == &pol) return 0;
	if (this->count_of_variables != pol.count_of_variables) return 1; // tmp->data == NULL || pol.data == NULL included

	Polynomial_info* tmp;
	for (int i = 0; i < count_of_variables; ++i) {
		tmp = this->data;
		while (tmp->next != NULL && tmp->power != pol.data->power)
			tmp = tmp->next;
		if (tmp->power == pol.data->power && tmp->coef == pol.data->coef) return 0;
	}

	return 1;
}

Polynomial& Polynomial::operator+(Polynomial& pol) { // для сложения полиномов
    Polynomial* tmp = new Polynomial;
	--tmp->current_count_of_pols;
	--tmp->count_of_pols;
	tmp->push(this->count_of_variables, this->data);
	tmp->push(pol.count_of_variables, pol.data);
	return *tmp;
}

Polynomial& Polynomial::operator-(Polynomial& pol) { // для вычитания полиномов
	Polynomial* tmp = new Polynomial;
	--tmp->current_count_of_pols;
	--tmp->count_of_pols;
	tmp->push<'+'>(this->count_of_variables, this->data);
	tmp->push<'-'>(pol.count_of_variables, pol.data);
	return *tmp;
}

float Polynomial::operator()(float x) { // для возврата значения полинома при заданном "х"
	if (!data) exit(1);
	float sum = 0;
	Polynomial_info* tmp = this->data;
	for (int i = 0; i < count_of_variables; ++i) {
		sum += tmp->coef *pow(x, tmp->power);
		tmp = tmp->next;
	}

	return sum;
}

float Polynomial::operator[](int id) { // для возврата коефициента "х" при указанном id
	if (!data) exit(2);
	id < 0 ? id *= -1 : id = id;
	if (!(id < count_of_variables)) exit(3);

	float coef;
	Polynomial_info* tmp = this->data;
	for (int i = 0; i < id; ++i)
		tmp = tmp->next;
	coef = tmp->coef;

    return coef;
}

Polynomial& operator+(Polynomial_info elem, const Polynomial& pol) { // для сложения полинома с числом слева
    Polynomial* tmp = new Polynomial;
	--tmp->current_count_of_pols;
	--tmp->count_of_pols;
	if (pol.data)
		tmp->push(pol.count_of_variables, pol.data);
	tmp->push(1, &elem);

    return *tmp;
}

Polynomial& operator+(const Polynomial& pol, Polynomial_info elem) { // для сложения полинома с числом справа
	Polynomial* tmp = new Polynomial;
	--tmp->current_count_of_pols;
	--tmp->count_of_pols;
	if (pol.data)
		tmp->push(pol.count_of_variables, pol.data);
	tmp->push(1, &elem);

	return *tmp;
}

Polynomial& operator*(float mult_coef, const Polynomial& pol) { // для умножения полинома на число слева
	Polynomial* tmp = new Polynomial;
	--tmp->current_count_of_pols;
	--tmp->count_of_pols;
	if (pol.data) {
		tmp->push(pol.count_of_variables, pol.data);
		Polynomial_info* tmp_for_mult = tmp->data;
		for (int i = 0; i < tmp->count_of_variables; ++i) {
			tmp_for_mult->coef *= mult_coef;
			tmp_for_mult = tmp_for_mult->next;
		}
	}

	return *tmp;
}

Polynomial& operator*(const Polynomial& pol, float mult_coef) { // для умножения полинома на число справа
	Polynomial* tmp = new Polynomial;
	--tmp->current_count_of_pols;
	--tmp->count_of_pols;
	if (pol.data) {
		tmp->push(pol.count_of_variables, pol.data);
		Polynomial_info* tmp_for_mult = tmp->data;
		for (int i = 0; i < tmp->count_of_variables; ++i) {
			tmp_for_mult->coef *= mult_coef;
			tmp_for_mult = tmp_for_mult->next;
		}
	}

	return *tmp;
}

std::ostream& operator<<(std::ostream& out, const Polynomial& pol) { // для вывода информации о полиноме
	out << "Polynomial #" << pol.p_num << " contains " << pol.count_of_variables << " variables : ";
	Polynomial_info* tmp = pol.data;
	if (tmp == NULL) {
		out << "0";
		out << "\nCurrent count of polynominals: " << pol.current_count_of_pols << "\n\n";
		return out;
	}
	else {
		if (tmp->coef < 0) { // меньше нуля
			switch (tmp->power) {
			case 0: // -...*1
				out << tmp->coef;
				tmp = tmp->next;
				break;
			case 1: // -...*х
				if (tmp->coef == 1.) { // -1*х
					out << "-x";
					tmp = tmp->next;
					break;
				}
				else { // -1.1*х
					out << tmp->coef << "x";
					tmp = tmp->next;
					break;
				}
			default: // -...*х^12
				if (tmp->coef == 1.) { // -1*х^12
					out << "-x^" << tmp->power;
					tmp = tmp->next;
					break;
				}
				else { // -1.1*х^12
					out << tmp->coef << "x^" << tmp->power;
					tmp = tmp->next;
					break;
				}
			}
		}
		else { // больше нуля
			switch (tmp->power) {
			case 0: // ...*1
				out << tmp->coef;
				tmp = tmp->next;
				break;
			case 1: // ...*x
				if (tmp->coef == 1.) { // 1*x
					out << "x";
					tmp = tmp->next;
					break;
				}
				else { // 1.1*x
					out << tmp->coef << "x";
					tmp = tmp->next;
					break;
				}
			default: // ...*x^12
				if (tmp->coef == 1.) { // 1*x^12
					out << "x^" << tmp->power;
					tmp = tmp->next;
					break;
				}
				else { // 1.2*x^12
					out << tmp->coef << "x^" << tmp->power;
					tmp = tmp->next;
					break;
				}
			}
		}
		while (tmp != NULL) {
			if (tmp->coef < 0) { // меньше нуля
				switch (tmp->power) {
				case 0: // -...*1
					out << " - " << abs(tmp->coef);
					tmp = tmp->next;
					break;
				case 1: // -...*х
					if (tmp->coef == -1.) { // -1*х
						out << " - x";
						tmp = tmp->next;
						break;
					}
					else { // -1.1*х
						out << " - " << abs(tmp->coef) << "x";
						tmp = tmp->next;
						break;
					}
				default: // -...*х^12
					if (tmp->coef == -1.) { // -1*х^12
						out << " - x^" << tmp->power;
						tmp = tmp->next;
						break;
					}
					else { // -1.1*х^12
						out << " - " << abs(tmp->coef) << "x^" << tmp->power;
						tmp = tmp->next;
						break;
					}
				}
			}
			else { // больше нуля
				switch (tmp->power) {
				case 0: // ...*1
					out << " + " << tmp->coef;
					tmp = tmp->next;
					break;
				case 1: // ...*x
					if (tmp->coef == 1.) { // 1*x
						out << " + x";
						tmp = tmp->next;
						break;
					}
					else { // 1.1*x
						out << " + " << tmp->coef << "x";
						tmp = tmp->next;
						break;
					}
				default: // ...*x^12
					if (tmp->coef == 1.) { // 1*x^12
						out << " + " << "x^" << tmp->power;
						tmp = tmp->next;
						break;
					}
					else { // 1.1*x^12
						out << " + " << tmp->coef << "x^" << tmp->power;
						tmp = tmp->next;
						break;
					}
				}
			}
		}
	}
	out << "\nCurrent count of polynominals: " << pol.current_count_of_pols << "\n\n";
	return out;
}