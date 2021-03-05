#pragma once
#include <iostream>
#include <iomanip>
#include <stdio.h>

class Queue
{
	int max_size;
	int* root;
	int i_bot = -1;
public:
	Queue();//ok
	Queue(const Queue& tmp);//ok
	Queue(int max_size);//ok
	Queue(int max_size, int elem);//ok
	Queue& operator=(const Queue& m2);//ok
	//Queue& operator+(const Queue& m2);//ok
	//Queue& operator+=(const Queue& m2);//ok
	//bool operator==(const Queue& m2) const;//ok
	bool Empty() { return i_bot == -1 ? 1 : 0; };//ok
	bool Push(int elem);//ok
	bool Push(int* elem, int size);//ok
	bool Pop();//ok
	bool Pop(int num);//ok
	bool Clear();//ok
	bool Show() const;//ok
	void Show_size() { std::cout << "Max size is: " << this->max_size << "\n"; }//ok
	void Show_i() { std::cout << "i_bot is: " << this->i_bot << "\n"; }//ok
	Queue& Unite(Queue& m2);//ok ~ +
	bool Compare(Queue& m2) const;//ok ~ ==
	~Queue();//ok
};

Queue::Queue() :max_size(0) {
	root = NULL;
	std::cout << "Queue created with 0 elements!\n";
}

Queue::Queue(const Queue &tmp) : max_size(tmp.max_size), i_bot(tmp.i_bot) {
	root = new int[tmp.i_bot + 1];
	for (int i = -1; i != tmp.i_bot; ++i) {
		root[i + 1] = tmp.root[i + 1];
	}
	std::cout << "Queue copyed with " << i_bot + 1 << " elements!\n";
}

Queue::Queue(int max_size) {
	max_size < 0 ? this->max_size = (max_size * -1) : this->max_size = (max_size);
	root = new int[this->max_size];
	std::cout << "Queue created with 0 elements!\n";
}

Queue::Queue(int max_size, int elem) {
	max_size < 0 ? this->max_size = (max_size * -1) : this->max_size = (max_size);
	root = new int[this->max_size];
	root[0] = elem;
	i_bot = 0;
	std::cout << "Queue created with 1 elements!\n";
}

Queue& Queue::operator=(const Queue& m2) {
	if (this == &m2) { std::cout << "You cannot assign an element to itself!\n"; return *this; }
	delete[] root;
	root = new int[m2.i_bot + 1];
	for (int i = -1; i != m2.i_bot; ++i) {
		root[i + 1] = m2.root[i + 1];
	}
	i_bot = m2.i_bot;
	max_size = m2.max_size;
	return *this;
}

//ok
/*Queue& Queue::operator+(const Queue& m2) {
	Queue* tmp = new Queue(this->max_size + m2.max_size);
	tmp->Push(root, i_bot + 1);
	tmp->Push(m2.root, m2.i_bot + 1);
	return *tmp;
}*/

//ok
/*Queue& Queue::operator+=(const Queue& m2) {
	this->Push(m2.root, m2.i_bot + 1);
	return *this;
}*/

//ok
/*bool Queue::operator==(const Queue& m2) const {
	if (i_bot == m2.i_bot) {
		bool cond_comp = 1;
		for (int i = -1; i + 1 != i_bot && i + 1 != m2.i_bot && cond_comp == 1; ++i)
			if (root[i + 1] != m2.root[i + 1])
				cond_comp = 0;
		if (cond_comp) return 1;
		else return 0;
	}
	return 0;
}*/

bool Queue::Push(int elem) {
	if (i_bot + 1 == max_size) { std::cout << "Queue is full!\n"; return 0; }
	root[i_bot + 1] = elem;
	++i_bot;
	std::cout << "Element succesfully pushed!\n";
	return 1;
}

bool Queue::Push(int* elem, int size) {
	if (i_bot + 1 == max_size) { std::cout << "Queue is full!\n"; return 0; }
	int i = 1;
	size < 0 ? size *= -1 : size = size;
	while ( size + 1 > i  && ((i_bot + i ) != max_size)) {
		root[i_bot + i ] = elem[i-1];
		++i;
	}
	std::cout << i - 1 << " elements succesfully pushed!!!!\n";
	i_bot += i - 1;
	return 1;
}

bool Queue::Show() const {
	if (i_bot == -1) { std::cout << "Queue is empty!\n"; return 0; }
	int i = i_bot + 1;
	std::cout << "Queue has " << i << " elements:\n";
	while (i) {
		std::cout << std::setw(4) << root[i_bot - i + 1];
		--i;
	} std::cout << std::endl;
	return 1;
}

bool Queue::Pop() {
	if (i_bot == -1) { std::cout << "You cannot delete an element because of queue emptyness!\n"; return 0; }
	if (i_bot + 2 == max_size)
		root = NULL;
	else
		++root;
	if (i_bot != -1)
		--i_bot;
	std::cout << "Element succesfully deleted!\n";
	return 1;
}

bool Queue::Pop(int num) {
	if (i_bot == -1) { std::cout << "You cannot delete an element because of queue emptyness!\n"; return 0; }
	num < 0 ? num *= -1 : num = num;
	if (i_bot + 1 + num == max_size)
		root = NULL;
	else
		root += num;
	int i = 0;
	while (num > i) {
		++i;
		if (i_bot != -1)
			--i_bot;
		else {
			std::cout << "All elements succesfully deleted!\n"; return 1;
		}
	}
	std::cout << "Deleted " << i << " elements!\n";
	return 1;
}

bool Queue::Clear() {
	if (i_bot != -1) {
		root = NULL;
		std::cout << "Queue cleared!\n";
		i_bot = -1;
		return 1;
	}
	std::cout << "Queue is alredy empty!\n";
	return 0;
}

Queue& Queue::Unite(Queue& m2) {
	Queue* tmp = new Queue(this->max_size + m2.max_size);
	tmp->Push(root, i_bot + 1);
	tmp->Push(m2.root, m2.i_bot + 1);
	return *tmp;
}

bool Queue::Compare(Queue& m2) const {
	if (i_bot == m2.i_bot) {
		bool cond_comp = 1;
		for (int i = -1; i + 1 != i_bot && i + 1 != m2.i_bot && cond_comp == 1; ++i)
			if (root[i + 1] != m2.root[i + 1])
				cond_comp = 0;
		if (cond_comp) return 1;
		else return 0;
	}
	return 0;
}

Queue::~Queue() {
	delete[] root;
}