#include <iostream>
#include <cstring>
#include <math.h>
#pragma warning(disable : 4996)

template<typename T>
void func(T& a, T& b)
{
    std::cout << "Enter value: ";
    std::cin >> a >> b;
    if (fmod(a, b) == 0) std::cout << a + b;
    else if (fmod(a, b) == 1) std::cout << (a > b ? a : b);
    else if (fmod(a, b) == 2) std::cout << (a < b ? a : b);
    else if (fmod(a, b) == 3) std::cout << a * b;
    std::cout << std::endl;
}

template<typename T>
void funks(T* a, T* b)
{
    std::cout << "Enter string: ";
    std::cin >> a >> b;
    if (fmod(sizeof(a), sizeof(b) == 0))
    {
        strcat(a, b);
        std::cout << a;
    }
    else if(fmod(sizeof(a), sizeof(b) == 1)) std::cout << (sizeof(a) > sizeof(b) ? a : b);
    else if (fmod(sizeof(a), sizeof(b) == 2)) std::cout << (sizeof(a) < sizeof(b) ? a : b);
    else if (fmod(sizeof(a), sizeof(b) == 3))
    {
        int j=0;
        char counter[90];
        for (int i = 0; i < (sizeof(a) > sizeof(b) ? sizeof(a) : sizeof(b)); i++)
        {
            if (a[i] == b[i])
            {
                counter[j] = a[i];
                j++;
            }
        }
        for (int i = 0; i < j; i++)
        {
            std::cout << counter[i] << '  ';
        }
    }
}

int main()
{
    float a, b;
    func(a, b);
    char c[90];
    char d[90];
    funks(c, d);
    return 0;
}