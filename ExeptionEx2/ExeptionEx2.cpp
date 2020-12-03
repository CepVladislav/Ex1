//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//#include <algorithm>
//
//class Dofile
//{
//public:
//	Dofile()
//	{
//		name = "fil.txt";
//		file.open(name);
//		if (!file.is_open()) 
//		{
//			std::cout << "Failed to open \"" << name << "\" for reading.\n";
//			throw Exeption("Wrong name");
//		}
//		else
//			std::cout << "File opened" << std::endl;
//	};
//	//Dofile(std::string _name)
//	//{
//	//	name = _name;
//	//	file.open(name);
//	//	if (!file.is_open())
//	//		std::cout << "Failed to open \"" << name << "\" for reading.\n";
//	//	else
//	//		std::cout << "File opened" << std::endl;
//	//};
//	~Dofile() 
//	{
//		std::cout << "File closed" << std::endl;
//		file.close();
//	};
//	void read()
//	{
//		v.reserve(100);
//		char* file_string = new char[100];
//		while (!file.eof())
//		{
//			file >> fileString;
//			v.push_back(fileString);
//			file.getline(file_string, 100, '\n');
//		}
//		file.close();
//		delete[]file_string;
//	};
//	void write()
//	{
//		file.open(name);
//		v.push_back(name);
//		for (auto a : v)
//		{
//			file << a;
//			file << std::endl;
//			v.pop_back();
//		}
//		file.close();
//	};
//	std::string fileString;
//	std::vector<std::string> v;	
//	std::string name;
//private:
//	std::fstream file;
//};
//
//class Exeption
//{
//public:
//	Exeption(std::string error) : m_error(error){};
//	const char* getError() { return m_error.c_str(); };
//private:
//	std::string m_error;
//};
//
//int main()
//{
//	try
//	{
//		Dofile F;
//	}
//	catch (Exeption& exeption)
//	{
//		std::cerr << "Error (" << exeption.getError() << ")\n";
//	}
//    return 0;
//}
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

//класс-исключение
class ArrayException
{
private:
	std::string m_error;

public:
	ArrayException(std::string error)
		: m_error(error)
	{
	}

	const char* getError() { return m_error.c_str(); }
};

class ArrayInt
{
private:
	std::string fileString;
	std::string name;
	std::fstream file;
	std::vector<std::string> v;	
public:
	ArrayInt() 
	{
		name = "fil.txt";
		file.open(name);
		if (!file.is_open()) 
		{
			std::cout << "Failed to open \"" << name << "\" for reading.\n";
			throw ArrayException("Wrong name");
		}
		else
			std::cout << "File opened" << std::endl;
	}
	ArrayInt(std::string _name)
	{
		name = _name;
		file.open(name);
		if (!file.is_open())
		{
			std::cout << "Failed to open \"" << name << "\" for reading.\n";
			throw ArrayException("Wrong name");
		}
		else
			std::cout << "File opened" << std::endl;
	}
	void read() 
	{
		v.reserve(100);
		char* file_string = new char[100];
		while (!file.eof())
		{
			file >> fileString;
			v.push_back(fileString);
			file.getline(file_string, 100, '\n');
		}
		file.close();
		delete[]file_string;
		std::cout << "Readed" << std::endl;
	}
	void write(std::string _name) 
	{
		file.open(_name);
		for (auto a : v)
		{
			file << a;
			file << std::endl;
		}
		file.close();
		std::cout << "Writed" << std::endl;
	}
};

int main()
{
	try
	{
		ArrayInt array;
	}
	catch (ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}
	try
	{
		ArrayInt array("file.txt");
		array.read();
		array.write("output.txt");

	}
	catch (ArrayException& exception)
	{
		std::cerr << "An array exception occurred (" << exception.getError() << ")\n";
	}
	return 0;
}
//Класс dofile + класс исключений + методы чтения/записи. Конструктор берёт имя файла и открывает.