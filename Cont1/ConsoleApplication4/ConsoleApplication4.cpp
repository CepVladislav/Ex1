#include <iostream>
#include <string>
#include <array>

class Employee
{
private:
	std::string name;
	long number;
public:
	void getdata();
	void putdata();
};

void Employee::getdata()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Enter name: ";
	getline(std::cin, name);
	std::cout << "Enter number: ";
	std::cin >> number;
}

void Employee::putdata()
{
	std::cout << "Name: " << name << " ";
	std::cout << "Number: " << number << std::endl;
}

int main()
{
	std::array<Employee, 100> myarray;
	for (auto& element : myarray) element.getdata();
	for (auto& element : myarray) element.putdata();
	return 0;
}