#include <iostream>
#include <array>
#include <vector>

struct Data
{
    char Name;
    char LastName;
    std::string Faculty;
    char Group;
    char Email;
};

struct Data1
{
    std::string Faculty = "Empty";
    char Name[20]{ "Empty" };
    char LastName[20]{ "Empty" };
    char Group[20]{ "Empty" };
    char Email[20]{ "Empty" };
};

int main()
{
    //std::cout << sizeof(std::string) << std::endl;
    //std::cout << sizeof(char) << std::endl;
    std::array<Data, 30> arr;
    std::vector<Data> vec;
    int a;
    std::cout << "Enter second array size: " << std::endl;
    std::cin >> a;
    vec.resize(a);
    *vec.begin();
    *arr.begin();
    std::cout << "First struct size:  " << sizeof(arr) << std::endl;
    std::cout << "Second struct size: " << sizeof(vec) << std::endl;
    std::cout << "First struct address:  " << &arr.begin() << std::endl;
    std::cout << "Second struct address: " << &vec.begin() << std::endl;
    std::cout << "Second struct address of next element: " << &(vec.begin() + 1) << std::endl;
    std::array<Data1, 30> arr1;
    std::vector<Data1> vec1;
    int b;
    std::cout << "Enter new second array size: " << std::endl;
    std::cin >> b;
    vec1.resize(b);
    std::cout << "First struct size:  " << sizeof(arr1) << std::endl;
    std::cout << "Second struct size: " << sizeof(vec1) << std::endl;
    return 0;
}