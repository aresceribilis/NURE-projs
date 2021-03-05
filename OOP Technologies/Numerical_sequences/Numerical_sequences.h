#pragma once
#include <iostream>
#include <cmath>
#include <utility>

class Num_seq {
public:
	virtual float Calculate(int) = 0;
	virtual void setValue(float, float) = 0;
	virtual float get_a0() = 0;
	virtual float get_d() = 0;
	virtual void Show(int) = 0;
	virtual ~Num_seq() { std::cout << "Num_seq is deleted!\n\n"; }
};

class Arithmetic : public Num_seq {
	float a0;
	float d;
public:
	~Arithmetic() override { std::cout << "Arithmetic is deleted!\n"; };
	virtual void Show(int n) override {
		float result = a0, tmp = a0;
		std::cout << "Arithmetic\nS" << n << " = " << result;
		for (int i = 0; i < n; ++i) {
			tmp += d;
			result += tmp;
			std::cout << " + " << tmp;
		}
		std::cout << " = " << result << "\na0 = " << a0 << " , d = " << d << " , n = " << n << "\n\n";
	}
	virtual float get_a0() override { return a0; };
	virtual float get_d() override { return d; };
	void setValue(float a0, float d) override { this->a0 = a0; this->d = d; }
	Arithmetic() :a0(0), d(0) {}
	Arithmetic(float a0, float d) { this->a0 = a0; this->d = d; }
	Arithmetic(Arithmetic& num_seq) {
		a0 = num_seq.a0;
		d = num_seq.d;
	}
	Arithmetic& operator=(Arithmetic& num_seq) {
		if (this == &num_seq) return *this;
		this->a0 = num_seq.a0;
		this->d = num_seq.d;

		return *this;
	}
	float Calculate(int n) override {
		return a0 + (n +1- 1) * d;
	}
};

class Geometric : public Num_seq {
	float a0;
	float d;
public:
	~Geometric() override { std::cout << "Geometric is deleted!\n"; };
	virtual void Show(int n) override {
		float result = a0, tmp = a0;
		std::cout << "Geometric\nS" << n << " = " << result;
		for (int i = 0; i < n; ++i) {
			tmp *= d;
			result += tmp;
			std::cout << " + " << tmp;
		}
		std::cout << " = " << result << "\na0 = " << a0 << " , d = " << d << " , n = " << n << "\n\n";
	}
	virtual float get_a0() override { return a0; };
	virtual float get_d() override { return d; };
	void setValue(float a0, float d) override { this->a0 = a0; this->d = d; }
	Geometric() : a0(0), d(0) {}
	Geometric(float a0, float d) { this->a0 = a0; this->d = d; }
	Geometric(Geometric& num_seq) {
		a0 = num_seq.a0;
		d = num_seq.d;
	}
	Geometric& operator=(Geometric& num_seq) {
		if (this == &num_seq) return *this;
		this->a0 = num_seq.a0;
		this->d = num_seq.d;

		return *this;
	}
	float Calculate(int n) override {
		return a0 * pow(d, n + 1 - 1);
	}
};

class Fibonacci : public Num_seq {
	float a0;
	float d;
public:
	~Fibonacci() override { std::cout << "Fibonacci is deleted!\n"; };
	virtual void Show(int n) override {
		float a1 = a0 + d, result = a0, tmp = a0, tmpp = result;
		std::cout << "Fibonacci\nS" << n << " = " << result;
		for (int i = 0; i < n; ++i) {
			tmpp = tmp + a1;
			result += tmpp;
			tmp = a1;
			a1 = tmpp;
			std::cout << " + " << tmpp;
		}
		std::cout << " = " << result << "\na0 = " << a0 << " , d = " << d << " , n = " << n << "\n\n";
	}
	virtual float get_a0() override { return a0; };
	virtual float get_d() override { return d; };
	void setValue(float a0, float d) override { this->a0 = a0; this->d = d; }
	Fibonacci() : a0(0), d(0) {}
	Fibonacci(float a0, float d) { this->a0 = a0; this->d = d; }
	Fibonacci(Fibonacci& num_seq) {
		this->a0 = num_seq.a0;
		this->d = num_seq.d;
	}
	Fibonacci& operator=(Fibonacci& num_seq) {
		if (this == &num_seq) return *this;
		this->a0 = num_seq.a0;
		this->d = num_seq.d;

		return *this;
	}
	float Calculate(int n) override {
		float result = a0, tmp = result, a1 = a0 + d;
		for (int i = 0; i < n; ++i) {
			result = tmp + a1;
			tmp = a1;
			a1 = result;
		}
		return result;
	}
};

struct Element {
	Num_seq* item;
	Element* next;
};

class Container {
	Element* head;
public:
	bool operator==(Container& cont) {
		if (head == NULL && cont.head == NULL) return 1;
		if (head == cont.head) return 1;
		if (typeid(*this->head->item).name() != typeid(*cont.head->item).name()) return 0;
		if (this->head->item->get_a0() == cont.head->item->get_a0() && this->head->item->get_d() == cont.head->item->get_d()) return 1;
		return 0;
	}
	bool operator!=(Container& cont) {
		return !(*this == cont);
	}
	Container& operator=(Container&& container) {
		if (&container == this) return *this;
		if (!container.head) { head = NULL; }
		else {
			head = container.head;
			container.head = NULL;
		}
		return *this;
	}
	Container(Container&& container) {
		if (!container.head) { head = NULL; }
		else {
			head = container.head;
			container.head = NULL;
		}
	}
	~Container() {
		if (head) {
			Element* tmp = head;
			while (tmp) {
				delete[] tmp->item;
				tmp = tmp->next;
			}
		}
		head = NULL;
		std::cout << "Container's content is deleted!\n\n";
	}
	Container() : head(NULL) {}
	Container(Container& container) {
		if (!container.head) { head->item = NULL; head->next = NULL; }
		else {
			this->~Container();
			Element* tmp_cont = container.head;
			Element* tmp;
			while (tmp_cont) {
				tmp = NULL;
				tmp = new Element;
				if (!strcmp(typeid(*tmp_cont->item).name(), "class Fibonacci"))
					tmp->item = new Fibonacci;
				else if (!strcmp(typeid(*tmp_cont->item).name(), "class Geometric"))
					tmp->item = new Geometric;
				else
					tmp->item = new Arithmetic;
				tmp->item->setValue(tmp_cont->item->get_a0(), tmp_cont->item->get_d());
				tmp->next = head;
				head = tmp;
				tmp_cont = tmp_cont->next;
			}
		}
	}
	Container& operator=(Container& container) {
		if (this == &container) return *this;
		if (!container.head) { head->item = NULL; head->next = NULL; }
		else {
			this->~Container();
			Element* tmp_cont = container.head;
			Element* tmp;
			while (tmp_cont) {
				tmp = NULL;
				tmp = new Element;
				if (!strcmp(typeid(*tmp_cont->item).name(), "class Fibonacci"))
					tmp->item = new Fibonacci;
				else if (!strcmp(typeid(*tmp_cont->item).name(), "class Geometric"))
					tmp->item = new Geometric;
				else
					tmp->item = new Arithmetic;
				tmp->item->setValue(tmp_cont->item->get_a0(), tmp_cont->item->get_d());
				tmp->next = head;
				head = tmp;
				tmp_cont = tmp_cont->next;
			}
		}
		return *this;
	}
	void Push(Num_seq& num_seq) {
		Element* tmp = new Element;
		if (!strcmp(typeid(num_seq).name(), "class Fibonacci"))
			tmp->item = new Fibonacci;
		else if (!strcmp(typeid(num_seq).name(), "class Geometric"))
			tmp->item = new Geometric;
		else
			tmp->item = new Arithmetic;
		tmp->item->setValue(num_seq.get_a0(), num_seq.get_d());
		tmp->next = head;
		head = tmp;
	}
	void Pop() {
		if (head != NULL) {
			Element* tmp = head;
			head = head->next;
			tmp->item->~Num_seq();
			tmp = NULL;
		}
	}
	void Show(int n) {
		if (head == NULL) { std::cout << "Container is empty!\n\n"; }
		else {
			std::cout << "Container contain:\n\n";
			Element* tmp = head;
			while (tmp != NULL) {
				tmp->item->Show(n);
				tmp = tmp->next;
			}
			std::cout << "\n";
		}
	}
	void FindMaxValue(int n) {
		if (!head) { std::cout << "Container is empty!\n\n"; }
		else {
			Element* tmp = head;
			std::cout << "List of values with n = " << n << ":\n";
			for (int i = 0; tmp; ++i) {
				std::cout << "container[" << i << "] = ";
				std::cout << tmp->item->Calculate(n) << "\n";
				tmp = tmp->next;
			}
			tmp = head;
			std::cout << "\n";
			float max_i = 0, max_value = tmp->item->Calculate(n);
			for (int i = 0; tmp; i++) {
				if (max_value < tmp->item->Calculate(n)) {
					max_i = i + 1;
					max_value = tmp->item->Calculate(n);
				}
				tmp = tmp->next;
			}

			std::cout << "container[" << max_i << "] has the biggest value = " << max_value << "\n\n";
		}
	}
};