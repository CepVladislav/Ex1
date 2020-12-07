#include <iostream>

class Shape
{
public:
	virtual ~Shape() = 0 {};
	virtual double Square() = 0;
	virtual double Perimeter() = 0;
};

class Circle : public Shape
{
	double radius;
public:
	Circle(double r) :radius(r) {}
	double Square() override { return 3.14 * radius * radius; }
	double Perimeter() override { return 3.14 * 2 * radius; }
};

class Kvadrat : public Shape
{
	double lenght;
public:
	Kvadrat(int l) :lenght(l) {};
	double Square() override { return lenght * lenght; }
	double Perimeter() override { return 4 * lenght; }
};

class Rectangle : public Shape
{
	double lenght;
	double weight;
public:
	Rectangle(int l, int w) :lenght(l), weight(w) {};
	double Square() override { return lenght * weight; }
	double Perimeter() override { return 2 * lenght +  2 * weight; }
};

int main()
{
	Kvadrat k(10);
	Circle c(10);
	Rectangle r(10, 20);
	std::cout << "Kvadrat square: " << k.Square() << std::endl;
	std::cout << "Kvadrat perimeter: " << k.Perimeter() << std::endl;
	std::cout << "Circle square: " << c.Square() << std::endl;
	std::cout << "Circle perimeter: " << c.Perimeter() << std::endl;
	std::cout << "Rectangle square: " << r.Square() << std::endl;
	std::cout << "Rectangle perimeter: " << r.Perimeter() << std::endl;
    return 0;
}