#include <iostream>
#include <array>
#include <vector>

int main()
{
    int a, b;
	std::cout << "Enter 2 values: " << std::endl;
    std::cin >> a >> b;
	try
	{
		if (b == 0) throw 911;
		std::cout << "Result: " << static_cast<double>(a)/b << std::endl;
	}
	catch (int c)
	{
		std::cout << "Error " << c << ": division by zero" << std::endl;
	}
    return 0;
}