#include <iostream>
#include <algorithm>
#include <deque>

struct Autobus
{
    int number_autobus = 0;
    std::string FIO = "None";
    int number_marshrut = 0;
};

void print(Autobus &a)
{
    std::cout << "---------------------------------------------\t\n";
    std::cout << "Autobus number:  " << a.number_autobus << std::endl;
    std::cout << "Driver info:     " << a.FIO << std::endl;
    std::cout << "Marshrut number: " << a.number_marshrut << std::endl;
    std::cout << "---------------------------------------------\t" << std::endl;
}

void add_in_begin(std::deque<Autobus> &a, Autobus &b)
{
    a.push_front(b);
}

void add_in_position(std::deque<Autobus> &a, Autobus& b, int pos)
{
    a.push_back(b); 
    std::swap(a[pos], a.back());
}

void park_way(std::deque<Autobus> &a, std::deque<Autobus> &b, int pos)
{
    print(a[pos]);
    b.push_back(a[pos]);
    a.erase(a.begin() + pos);
}

int main()
{
    std::deque<Autobus> Park = { {1000,"Mister1",1}, {1001,"Mister2",2}, {1002,"Mister3",3}, {1003,"Mister4",4}, {1004,"Mister5",5} };
    std::deque<Autobus> Way;
    std::cout << "In park: " << std::endl;
    for(auto a : Park)
    {
        print(a);
    }
    std::cout << "On the way: " << std::endl;
    for (auto a : Way)
    {
        print(a);
    }
    park_way(Park, Way, 0);
    std::cout << "In park: " << std::endl;
    for (auto a : Park)
    {
        print(a);
    }
    std::cout << "On the way: " << std::endl;
    for (auto a : Way)
    {
        print(a);
    }
    return 0;
}

//вывод всех + добавление в начало + добавление в позицию + вывод в пути/в парке + выезжает из парка, выводит информацию, записывает в список маршрута, удаляет из парка + наоборот