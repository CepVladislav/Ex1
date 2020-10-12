#include <iostream>
#include <iomanip>

class Array
{
private:
    int* arr;
    int N;
public:
    Array(int n)
    {
        std::cout << "Enter array limit: ";
        std::cin >> n;
        N = n;

        arr = new int[n];
        for (int i = 0; i < N; i++)
        {
            std::cout << "Enter elem number " << i+1 << " : ";
            std::cin >> arr[i];
        }
    };
    void Print()
    {
        std::cout << "| ";
        for (int i = 0; i < N; i++)
        {
            std::cout << arr[i] << " | ";
        }
        std::cout << std::endl;
    }
    friend int DataSumm(Array &Array);
    ~Array()
    {
        delete[]arr;
    };
};

int DataSumm(Array &Array)
{
    int sum=NULL;
    for (int i = 0; i < Array.N; i++) sum += Array.arr[i];
    for (int i = 0; i < Array.N; i++) if (Array.arr[i] < 0) sum=NULL;
    return sum;
}

int main()
{
    int n=0;
    Array num1(n);
    num1.Print();
    std::cout << "Summ: " << DataSumm(num1) << std::endl;
    return 0;
}