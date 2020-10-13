#include <iostream>
#include "Telefon.h"
#include "Standart.h"
#include "Mobile.h"
#include "Radio.h"

void print(int a)
{
	std::cout << "Total calls price: " << a << std::endl;
}

void print(int a, int b, int c)
{
	std::cout << "Total calls price for all devices: " << a + b + c << std::endl;
}

int main()
{
	int a, b, c, d, sum_sta = 0, sum_mob = 0, sum_rad = 0;
	std::cout << "Enter array size of class Telefon: ";
	std::cin >> a;
	Telefon* tel = new Telefon[a];
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (int i = 0; i < a; i++)
	{
		tel[i].input();
	}
	for (int i = 0; i < a; i++)
	{
		tel[i].output();
	}
	std::cout << "Enter array size of class Standart: ";
	std::cin >> b;
	Standart* sta = new Standart[b];
	for (int i = 0; i < b; i++)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		sta[i].input();
		sta[i].in();
	}
	for (int i = 0; i < b; i++)
	{
		sta[i].output();
		sta[i].out();
	}
	for (int i = 0; i < b; i++)
	{
		sum_sta = sum_sta + sta[i].summ();
	}
	print(sum_sta);
	std::cout << "Enter array size of class Mobile: ";
	std::cin >> c;
	Mobile* mob = new Mobile[c];
	for (int i = 0; i < c; i++)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		mob[i].input();
		mob[i].in();
	}
	for (int i = 0; i < c; i++)
	{
		mob[i].output();
		mob[i].out();
	}
	for (int i = 0; i < c; i++)
	{
		sum_mob = sum_mob + mob[i].summ();
	}
	print(sum_mob);
	std::cout << "Enter array size of class Radio: ";
	std::cin >> d;
	Radio* rad = new Radio[d];
	for (int i = 0; i < d; i++)
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		rad[i].input();
		rad[i].in();
	}
	for (int i = 0; i < d; i++)
	{
		rad[i].output();
		rad[i].out();
	}
	for (int i = 0; i < d; i++)
	{
		sum_rad = sum_rad + rad[i].summ();
	}
	print(sum_rad);
	print(sum_sta, sum_mob, sum_rad);
	delete[]tel;
	delete[]sta;
	delete[]mob;
	return 0;
}