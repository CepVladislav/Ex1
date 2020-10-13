#pragma once
#include <iostream>
#include "Telefon.h"

class Standart : public Telefon
{
private:
	int _call_price;
	int _model_price;
public:
	Standart();
	Standart(int call_price, int model_price);
	void out();
	void in();
	int summ();
	~Standart();
};

Standart::Standart()
{
	_call_price = 0;
	_model_price = 0;
}

Standart::Standart(int call_price, int model_price)
{
	_call_price = call_price;
	_model_price = model_price;
}

void Standart::in()
{
	std::cout << "Enter call price: ";
	std::cin >> _call_price;
	std::cout << "Enter model price: ";
	std::cin >> _model_price;
}

Standart::~Standart()
{
	_call_price;
	_model_price;
}

int Standart::summ()
{
	return _call_price;
}

void Standart::out()
{
	std::cout << "Call price: " << _call_price << " Model price: " << _model_price << std::endl;
}
