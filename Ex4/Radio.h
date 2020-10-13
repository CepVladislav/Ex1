#pragma once
#include <iostream>
#include "Telefon.h"

class Radio : public Telefon
{
private:
	int _call_price;
	int _model_price;
public:
	Radio();
	Radio(int call_price, int model_price);
	void out();
	void in();
	int summ();
	~Radio();
};

Radio::Radio()
{
	_call_price = 0;
	_model_price = 0;
}

Radio::Radio(int call_price, int model_price)
{
	_call_price = call_price;
	_model_price = model_price;
}

Radio::~Radio()
{
	_call_price;
	_model_price;
}

int Radio::summ()
{
	return _call_price;
}

void Radio::out()
{
	std::cout << "Call price: " << _call_price << " Model price: " << _model_price << std::endl;
}

void Radio::in()
{
	std::cout << "Enter call price: ";
	std::cin >> _call_price;
	std::cout << "Enter model price: ";
	std::cin >> _model_price;
}