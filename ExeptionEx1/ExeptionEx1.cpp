#include <iostream>

template<typename T>
class Queue
{
private:
    int first, last, max_size, elem_count;
    T* ptr;
public:
    Queue(int = 10);
    ~Queue();
    void add_elem();
    T delete_elem();
    void print_queue();
};

template<typename T>
Queue<T>::Queue(int size)
{
    max_size = size;
    first = 0;
    last = 0;
    elem_count = 0;
    ptr = new T[max_size + 1];
}

template<typename T>
Queue<T>::~Queue() 
{
    delete[] ptr;
}

template<typename T>
void Queue<T>::add_elem()
{
    T el;
Again:
        try
        {
            std::cin >> el;
            if (std::cin.good() == true && elem_count < max_size)
            {
                ptr[last++] = el;
                elem_count++;
            }
            else if (std::cin.good() == true && elem_count >= max_size)
            {
                char c = 'a';
                std::cout << "Queue size exeeded" << std::endl << "Enter queue again" << std::endl;
                throw c;
            }
            if (std::cin.bad() == true || std::cin.fail() == true) throw 1;
        }
        catch (int)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Something wrong" << std::endl;
            goto Again;
        }
        catch (char)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            last = 0;
            elem_count = 0;
            goto Again;
        }
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

template<typename T>
T Queue<T>::delete_elem()
{
    try
    {
        if (first == 0 && last == 0)
        {
            std::cout << "Queue empty" << std::endl;
            throw 2;
        }
        T Value = ptr[first++];
        elem_count--;
        if (first > max_size) first -= max_size + 1;
        return Value;
    }
    catch (int e)
    {
        std::cout << "Delete can't be complete" << std::endl;
    }

}

template<typename T>
void Queue<T>::print_queue()
{
    if (first == 0 && last == 0) std::cout << "Queue empty" << std::endl;
    else 
    {
        for(int i = 0; i < elem_count; i++) std::cout << ptr[i] << " ";
        std::cout << std::endl;
    }
}

void Message()
{
    std::cout
        << "-----------------------------------------------------\t" << std::endl
        << "1 - Add queue elem" << std::endl
        << "2 - Delete queue elem" << std::endl
        << "3 - Display queue" << std::endl
        << "4 - Exit" << std::endl
        << "-----------------------------------------------------\t" << std::endl
        << "Your choice: ";
}

int main()
{
    int q;
    int z;
    std::cout << "Enter queue size: ";
    std::cin >> z;
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    Queue<int> Q(z);
    while (true)
    {
        Message();
        while (true)
        {
            std::cin >> q;
            if (q >= 1 && q <= 4) break;
            else std::cout << "Enter number: " << std::endl;
        }
        switch (q)
        {
        case(1):
            std::cout << "Enter element: " << std::endl;
            Q.add_elem();
            break;
        case(2):
            Q.delete_elem();
            break;
        case(3):
            Q.print_queue();
            break;
        case(4):
            std::cout << "Exit" << std::endl;
            break;
        default:
            break;
        }
        if (q == 4) break;
    }
    return 0;
}