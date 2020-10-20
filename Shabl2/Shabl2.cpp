#include <iostream>
#include <string>

template <typename T>
class Array
{
private:
	int N;
	T* array;
public:
	Array()
	{
		N = 0;
		array = NULL;
	}
	Array(int _N)
	{
		array = new T[_N];
		N = _N;
	}
	~Array()
	{
		delete[] array;
	}
	void Funktion()
	{
		std::cout << "Enter your array(max size " << N << "): ";
		for (int i = 0; i < N; i++)
		{
			std::cin >> array[i];
		}
		std::cout << "Your array: ";
		for (int i = 0; i < N; i++)
		{
			std::cout <<  array[i] << "  ";
		}
		std::cout << std::endl;
		int average_value = 0;
		for (int i = 0; i < N; i++)
		{
			average_value = average_value + array[i];
		}
		std::cout << "Average value: " << average_value / 2 << std::endl;
	}

};

int main()
{
	Array<char> chararr(10);
	chararr.Funktion();
	Array<double> doubarr(10);
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	doubarr.Funktion();
	//Array<std::string> strarr(10);
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	//strarr.Funktion();
    return 0;
}


//+ строки