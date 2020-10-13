#pragma once
#include <iostream>
#include <string>

class Telefon
{
private:
	std::string _fullName;
	std::string _model;
public:
	Telefon();
	Telefon(std::string fullName, std::string model);
	std::string getfullName();
	std::string getModel();
	void input();
	void output();
	~Telefon();
};

Telefon::Telefon(std::string fullName, std::string model)
{
	_fullName = fullName;
	_model = model;
}

Telefon::Telefon()
{
	_fullName = "None";
	_model = "None";
}

Telefon::~Telefon()
{
	_fullName;
	_model;
}

std::string Telefon::getfullName() { return _fullName; }

std::string Telefon::getModel() { return _model; }

void Telefon::output()
{
	std::cout << "Developer name: " << _fullName << " Device model: " << _model << std::endl;
}

void Telefon::input()
{
	std::cout << "Enter developer name: ";
	getline(std::cin, _fullName);
	std::cout << "Enter model name: ";
	getline(std::cin, _model);
}