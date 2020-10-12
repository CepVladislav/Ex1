#include <iostream>
#include <cstdlib>
#include <math.h>

class Vector
{
private:
    int* arr;
    int N;
    int* nech;
    int* chet;
    int b = 0;
    int c = 0;
public:
    Vector(int n, int r)
    {
        N = n;
        arr = new int[N];
        for (int i = 0; i < N; i++) arr[i] = rand() % r - rand() % - r*2/3;
        chet = new int[N];
        nech = new int[N];
    }
    Vector(int a)
    {
        N = a;
        arr = new int[N];
        for (int i = 0; i < N; i++) arr[i] = rand() % 10;
        chet = new int[N];
        nech = new int[N];
    }
    void print()
    {
        for (int i = 0; i < N; i++) std::cout << arr[i] << "  ";
        std::cout << std::endl;
    }
    void new_print()
    {
        for (int i = 0; i < b; i++) std::cout << nech[i] << "  ";
        for (int i = 0; i < c; i++) std::cout << chet[i] << "  ";
        std::cout << std::endl;
    }
    void DataChange()
    {
        for (int i = 0; i < N; i++)
        {
            if (arr[i] > 0) arr[i] = sqrt(arr[i]);
        }
    }
    void DivideData()
    {
        for(int i = 0; i < N; i++)
        {
            if ((arr[i] + 1) / 2 == arr[i] / 2)
            {
                nech[b] = arr[i];
                b++;
            }
            else
            {
                chet[c] = arr[i];
                c++;
            }
        }
        for (int i = 0; i < b - 1; ++i)
        {
            int min_elem = i;
            for (int j = i + 1; j < b; ++j)
            {
                if (nech[j] < nech[min_elem]) min_elem = j;
            }
            std::swap(nech[i], nech[min_elem]);
        }
        for (int i = 0; i < c; i++)
        {
            for (int j = c - 1; j > i; j--)
            {
                if (chet[j-1] < chet[j]) 
                {
                    chet[c] = chet[j - 1];
                    chet[j - 1] = chet[j];
                    chet[j] = chet[c];
                }
            }
        }
    }
    int Min()
    {
        int min=arr[0];
        for (int i = 0; i < N; i++)
        {
            if (arr[i] <= min) min = arr[i];
        }
        return min;
    }
    int Max()
    {
        int max=arr[0];
        for (int i = 0; i < N; i++)
        {
            if (arr[i] >= max) max = arr[i];
        }
        return max;
    }
    ~Vector()
    {
        delete[]arr;
        delete[]chet;
        delete[]nech;
    }
};

int main()
{
    int sort = 1;
    int a, n, r;
    std::cout << "Enter array size: ";
    std::cin >> n;
    std::cout << "Enter rand number limit: ";
    std::cin >> r;
    Vector vector(n, r);
    std::cout << "Basic array: " << std::endl;
    vector.print();
    std::cout << "New array: " << std::endl;
    vector.DataChange();
    vector.print();
    std::cout << "Enter second array size: ";
    std::cin >> a;
    Vector array(a);
    std::cout << "Basic array: " << std::endl;
    array.print();
    std::cout << "New array: " << std::endl;
    array.DivideData();
    array.new_print();
    std::cout << std::endl << "Min value: " << array.Min() << std::endl;
    std::cout << "Max valuse: " << array.Max() << std::endl;
    return 0;
}