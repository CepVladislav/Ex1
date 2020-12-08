#include <iostream>
#include <algorithm>
#include <vector>

class Data
{
public:
	Data();
	~Data();
	friend std::istream &operator >> (std::istream &in, Data &data);
	friend std::ostream &operator << (std::ostream &out, const Data &data);
	Data operator () (Data& a, Data& b) 
	{
		if (a.age > b.age) return a;
		else return b;
	}
	std::string student_info = "Empty";
	int age = 0;
	int course = 0;
	std::string group = "Empty";
};

bool ComparatorFunction(const Data* a, const Data* b)
{
	return a->course < b->course;
}

Data::Data()
{
	std::cout << "Constructor working" << std::endl;
}

Data::~Data()
{
	std::cout << "Destructor working" << std::endl;
}

std::istream &operator >> (std::istream &in, Data &data)
{
	std::cout << "Enter student info, age, course, group: " << std::endl;
	in >> data.student_info >> data.age >> data.course >> data.group;
	return in;
}

std::ostream &operator << (std::ostream &out, const Data &data)
{
	out << "Student - " << data.student_info 
		<< ", age - " << data.age 
		<< ", course - " << data.course 
		<< ", group - " << data.group << std::endl;
	return out;
}

int main()
{
	Data list[4];
	std::cin >> list[0] >> list[1] >> list[2] >> list[3];
	Data* ptr1 = &list[0];
	Data* ptr2 = &list[1];
	Data* ptr3 = &list[2];
	Data* ptr4 = &list[3];
	std::cout << "Funktor: " << (list[0],list[1]) << std::endl;
	std::vector<Data*> vec = { ptr1, ptr2, ptr3, ptr4 };
	sort(vec.begin(), vec.end(), ComparatorFunction);
	for(auto a : vec)
	{
		/*std::cout << a << std::endl;*/
		std::cout << *a << std::endl;
	}
}

//структурный тип, конструкторы, деструкторы, перегрузка + инициализация списка данными + функтор сравнения по любому полю + вектор структурного типа с указателем, заполнить + сортировка вектора по полю + утечка памяти