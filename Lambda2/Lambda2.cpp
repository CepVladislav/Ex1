#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, k;
	std::vector<int> array;
	int num = 0;
	std::cout << "Enter array size: ";
	std::cin >> n;
	array.resize(n);
	for (auto& const element : array)
	{
		element = num;
		num++;
	}
	std::cout << "Array: ";
	for_each(array.begin(), array.end(), [](int _n)
		{
			std::cout << _n << " ";
		});
	std::cout << std::endl << "Enter k: ";
	std::cin >> k;
	int end_array;
	while (k!=0)
	{
		array.erase(array.begin());
		end_array = array.back();
		end_array++;
		array.push_back(end_array);
		k--;
	}
	std::cout << "Array: ";
	for_each(array.begin(), array.end(), [](int _n)
		{
			std::cout << _n << " ";
		});
	return 0;
}