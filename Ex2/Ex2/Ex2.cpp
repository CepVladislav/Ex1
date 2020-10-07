#include <iostream>
#include <string>

class Stroka
{
private:
	std::string str;
	int b, count;
	char last;
public:
	Stroka();
	void funkStroka()
	{
		std::cout << "Enter your string: " << std::endl;
		getline(std::cin, str);
		last = str[str.size() - 1];
		for (int i = 0; i < 250; i++)
		{
			b = str[i];
			if (b == 97)
			{
				str[i] = last;
				count++;
			}
			if (b == 00) break;
		}
		std::cout << "Replased string: " << str << std::endl;
		std::cout << "Count of replases: " << count;
	}
	~Stroka();
};

Stroka::Stroka()
{
	str = 'd';
	b = 0;
	count = 0;
	last = 0;
}

Stroka::~Stroka(){	}

int main()
{
	Stroka input1;
	input1.funkStroka();
	return 0;
}

