//#include <iostream>
//#include <string>
//#include <fstream>
//#include <vector>
//#include <algorithm>
//
//class Dofile
//{
//public:
//    Dofile() 
//    {
//        std::cout << "Enter file name: ";
//        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        for (line; getline(std::cin, line);)
//        {
//            input.open(line);
//            if (!input.is_open()) std::cout << "File \"" << line << "\" not open for read.\n";
//            else
//            {
//                std::cout << "Open" << std::endl;
//                break;
//            }
//        }
//    };
//	~Dofile();
//	void read(std::vector<Dofile> a);
//	void write(std::vector<Dofile> a);
//    void print(std::vector<Dofile> a);
//    std::string fileData;
//private:
//    std::fstream input;
//    std::string line = "None";
//    char* file_string = new char[2];
//    int string_count;
//};
//
//Dofile::~Dofile()
//{
//    delete[]file_string;
//}
//
//void Dofile::read(std::vector<Dofile> a)
//{
//    string_count = 0;
//    if(line == "None") 
//    {
//        std::cout << "Enter file name: ";
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        for (line; getline(std::cin, line);)
//        {
//            input.open(line);
//            if (!input.is_open()) std::cout << "File \"" << line << "\" not open for read.\n";
//            else
//            {
//                std::cout << "Open" << std::endl;
//                break;
//            }
//        }
//    }
//    else
//    {
//        int i = 0;
//        while (!input.eof())
//        {
//                input >> a[i].fileData;
//                input.getline(file_string, 2, '\n');
//                i++;
//                string_count++;
//        }
//    }
//    input.close();
//}
//
//void Dofile::write(std::vector<Dofile> a)
//{
//    if (line == "None")
//    {
//        std::cout << "Enter file name: ";
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        for (line; getline(std::cin, line);)
//        {
//            input.open(line);
//            if (!input.is_open()) std::cout << "File \"" << line << "\" not open for read.\n";
//            else
//            {
//                std::cout << "Open" << std::endl;
//                break;
//            }
//        }
//    }
//    else
//    {
//        input.open(line);
//        int z = 0;
//        while (z++!=string_count)
//        {
//            input << a[z].fileData;
//            input << std::endl;
//        }
//        input.close();
//    }
//}
//
//void Dofile::print(std::vector<Dofile> a)
//{
//    std::cout << "This is file data: "<< std::endl;
//    int z = 0;
//    while (z++ != string_count)
//    {
//        std::cout << a[z].fileData;
//        std::cout << std::endl;
//    }
//}
//
//std::ostream& operator << (std::ostream& out, std::string b)
//{
//    out << b;
//    return out;
//}
//
//std::istream& operator >> (std::istream& in, std::string b)
//{
//    in >> b;
//    return in;
//}
//
//int main()
//{
//    Dofile F;
//    std::vector<Dofile> file;
//    F.read(file);
//    F.print(file);
//    F.write(file);
//    return 0;
//}
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

class Dofile
{
public:
	Dofile()
	{
		name = "file.txt";
		file.open(name);
		if (!file.is_open()) 
		{
			std::cout << "Failed to open \"" << name << "\" for reading.\n";
			throw 1;
		}
		else
			std::cout << "File opened" << std::endl;
	};
	Dofile(std::string _name)
	{
		name = _name;
		file.open(name);
		if (!file.is_open())
			std::cout << "Failed to open \"" << name << "\" for reading.\n";
		else
			std::cout << "File opened" << std::endl;
	};
	~Dofile() 
	{
		std::cout << "File closed" << std::endl;
		file.close();
	};
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
	};
	void write()
	{
		file.open(name);
		v.push_back(name);
		for (auto a : v)
		{
			file << a;
			file << std::endl;
			v.pop_back();
		}
		file.close();
	};
	std::string fileString;
	std::vector<std::string> v;	
	std::string name;
private:
	std::fstream file;
};

class Exeption : public Dofile
{
public:
	Exeption() 
	{
	Again:
		try
		{
			read();
			write();
		}
		catch (int)
		{
			std::cout << "Enter file name: " << std::endl;
			getline(std::cin,name);
			goto Again;
		}
	};
	Exeption(int) 
	{
	One_more:
		try
		{
			read();
			write();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
			goto One_more;
		}
	};
	~Exeption() 
	{
		std::cout << "Exeption class killed" << std::endl;
	};
private:

};

int main()
{
	Dofile F("file.txt");
	F.read();
	F.write();
	Exeption E;
	Exeption E1(1);
    return 0;
}

//Класс dofile + класс исключений + методы чтения/записи. Конструктор берёт имя файла и открывает.