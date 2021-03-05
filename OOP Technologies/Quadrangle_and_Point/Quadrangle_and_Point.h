#pragma once
#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>

enum { rectangle, square, parallelogram, rhombus };

class Quadrangle;

class Point {
	float x, y;
public:
	Point();
	Point(float, float);
	void setCord(float, float);
	float* getCord() const;
	float distance_to_origin() const;
	float distance_btwn_points(Point&) const;
	friend bool isPointInQuadrangle(const Point& point, const Quadrangle& quad);
	friend class Quadrangle;
};

class Quadrangle {
	static int count_of_Quadrangle;
	int q_num;
	Point** points = new Point * [4];
public:
	Quadrangle();
	Quadrangle(Point&, Point&, Point&, Point&);
	Quadrangle(const Quadrangle&);
	Quadrangle(Quadrangle&&);
	Quadrangle& operator=(const Quadrangle&);
	Quadrangle& operator=(Quadrangle&&);
	float* getSides();
	void show();
	float getPerimeter();
	int getType();
	int getQ_id();
	friend bool isPointInQuadrangle(const Point& point, const Quadrangle& quad);
	~Quadrangle();
};
int Quadrangle::count_of_Quadrangle = 0;
//------------------------------------------------------------------------------------

Point::Point() : x(0), y(0) {
	;
}

Point::Point(float x, float y) {
	this->x = x; this->y = y;
}

void Point::setCord(float x, float y) {
	this->x = x; this->y = y;
}

float* Point::getCord() const {
	float* tmp = new float[2];
	tmp[0] = x; tmp[1] = y;
	return tmp;
}

float Point::distance_to_origin() const {
	return sqrt(x * x + y * y);
}

float Point::distance_btwn_points(Point& point) const {
	if (&point == NULL) return NULL;
	return abs(sqrt(pow((x - point.x), 2) + pow((y - point.y), 2)));
}

//------------------------------------------------------------------------------------

Quadrangle::Quadrangle() {
	q_num = ++count_of_Quadrangle;
	points = NULL;
}

Quadrangle::Quadrangle(Point& p1, Point& p2, Point& p3, Point& p4) {
	q_num = ++count_of_Quadrangle;
	points[0] = &p1, points[1] = &p2, points[2] = &p3, points[3] = &p4;
}

Quadrangle::Quadrangle(const Quadrangle& quad) { // конструктор копирования
	q_num = ++count_of_Quadrangle;
	points[0] = quad.points[0], points[1] = quad.points[1], points[2] = quad.points[2], points[3] = quad.points[3];
}

Quadrangle::Quadrangle(Quadrangle&& quad) { // конструктор перемещения
	q_num = ++count_of_Quadrangle;
	points = quad.points;
	quad.points = NULL;
}

Quadrangle& Quadrangle::operator=(const Quadrangle& quad) { // оператор копирования
	if (&quad == this)
		return *this;

	if (quad.points != NULL)
		points[0] = quad.points[0], points[1] = quad.points[1], points[2] = quad.points[2], points[3] = quad.points[3];
	else
		points = NULL;

	return *this;
}

Quadrangle& Quadrangle::operator=(Quadrangle&& quad) { // оператор перемещения
	if (&quad == this)
		return *this;

	points = quad.points;
	quad.points = NULL;

	return *this;
}

float* Quadrangle::getSides() {
	float* tmp = new float[4];
	if (points == NULL) { tmp[0] = tmp[1] = tmp[2] = tmp[3] = 0; return tmp; }
	tmp[0] = points[0]->distance_btwn_points(*points[1]);
	tmp[1] = points[1]->distance_btwn_points(*points[2]);
	tmp[2] = points[2]->distance_btwn_points(*points[3]);
	tmp[3] = points[3]->distance_btwn_points(*points[0]);
	return tmp;
}

void Quadrangle::show() {
	std::cout << "Quadrangle num is: " << q_num << "\n";
	std::cout << "Static value is: " << count_of_Quadrangle << "\n";
	if (points == NULL)
	{
		std::cout << "Quadrangle is empty.\n\n";
	}
	else {
		std::cout << *(points[0]->getCord()) << " " << *(points[0]->getCord() + 1) << std::endl;
		std::cout << *(points[1]->getCord()) << " " << *(points[1]->getCord() + 1) << std::endl;
		std::cout << *(points[2]->getCord()) << " " << *(points[2]->getCord() + 1) << std::endl;
		std::cout << *(points[3]->getCord()) << " " << *(points[3]->getCord() + 1) << std::endl;
		std::cout << "Distanse between points:";
		float* tmp = new float[4];
		tmp = this->getSides();
		std::cout << std::setw(9) << tmp[0] << std::setw(9) << tmp[1] << std::setw(9) << tmp[2] << std::setw(9) << tmp[3] << "\n";
		delete[] tmp;
		std::cout << "Perimeter is: " << this->getPerimeter() << "\n\n";
	}
}
float Quadrangle::getPerimeter() {
	float* tmp = new float[4];
	tmp = this->getSides();
	float perimeter = tmp[0] + tmp[1] + tmp[2] + tmp[3];

	delete[] tmp;
	return perimeter;
}

int Quadrangle::getType() {
	if (points == NULL) { std::cout << "Quadrangle is empty!\n\n"; return -1; }
	this->show();
	/*на паралельность*/
	if (abs((points[1]->x - points[0]->x) / (points[3]->x - points[2]->x)) == abs((points[1]->y - points[0]->y) / (points[3]->y - points[2]->y))
		|| abs((points[1]->x - points[0]->x) / (points[3]->x - points[2]->x)) == abs((points[2]->y - points[1]->y) / (points[0]->y - points[3]->y))
		|| abs((points[2]->x - points[1]->x) / (points[0]->x - points[3]->x)) == abs((points[2]->y - points[1]->y) / (points[0]->y - points[3]->y))
		|| abs((points[1]->x - points[0]->x) / (points[3]->x - points[2]->x)) == abs((points[2]->y - points[1]->y) / (points[0]->y - points[3]->y))) {
		float* sides = this->getSides();
		/*прямой угол*/
		if (0 == (((points[1]->x - points[0]->x) * (points[2]->x - points[1]->x) + (points[1]->y - points[0]->y) * (points[2]->y - points[1]->y)))) {
			std::cout << "rectangle or square\n";
			/*a=b=c=d*/
			if (sides[0] == sides[1] && sides[0] == sides[2] && sides[0] == sides[3] && sides[1] == sides[2] && sides[1] == sides[3] && sides[2] == sides[3]) {
				std::cout << "square\n\n\n"; return square;
			}
			/*!(a=b=c=d)*/
			else {
				std::cout << "rectangle\n\n\n"; return rectangle;
			}
		}
		/*непрямой угол*/
		else {
			std::cout << "parallelogram or rhombus\n";
			/*a=b=c=d*/
			if (sides[0] == sides[1] && sides[0] == sides[2] && sides[0] == sides[3] && sides[1] == sides[2] && sides[1] == sides[3] && sides[2] == sides[3]) {
				std::cout << "rhobmus\n\n\n"; return rhombus;
			}
			/*!(a=b=c=d)*/
			else {
				std::cout << "parallelogram\n\n\n"; return parallelogram;
			}
		}
	}
	/*непаралелен*/
	else { std::cout << "simple quadrangle\n\n\n"; return 5; }

	return 0;
}

int Quadrangle::getQ_id() {
	return q_num;
}

Quadrangle::~Quadrangle() {
	delete[] points;
	--count_of_Quadrangle;
}

bool isPointInQuadrangle(const Point& point, const Quadrangle& quad) {
	if (point.x == quad.points[0]->x && point.y == quad.points[0]->y || point.x == quad.points[1]->x && point.y == quad.points[1]->y
		|| point.x == quad.points[2]->x && point.y == quad.points[2]->y || point.x == quad.points[3]->x && point.y == quad.points[3]->y) return 1;
	else return 0;
}