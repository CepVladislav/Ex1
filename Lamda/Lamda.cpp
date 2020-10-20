#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	int n;
	std::vector<int> array;
	size_t count = 0;
	std::cout << "Enter array size: ";
	std::cin >> n;
	array.resize(n);
	for (auto& const element : array)
	{
		std::cout << "Enter elem: ";
		std::cin >> element;
	}
	sort(array.begin(), array.end(), [&count](int& a, int& b) 
		{
		++count;
		return a < b;
		});
	std::cout << "Number of replases: " << count << std::endl;
	std::cout << "Array: ";
	for_each(array.begin(), array.end(), [](int _n)
		{
			std::cout << _n << " ";
		});
	std::cout << std::endl;


	std::vector<std::string> arr{ "apple", "banana", "walnut", "lemon" };
	std::string SearchName;
	std::cout << "Enter key word: ";
	std::cin >> SearchName;
	auto found (find_if(arr.begin(), arr.end(), [SearchName](std::string s)
		{
			return s.find(SearchName) != std::string::npos;
		}));
	if (found == arr.end())
	{
		std::cout << "Nothing founded\n";
	}
	else
	{
		std::cout << "Found " << *found << '\n';
	}
	return 0;
}