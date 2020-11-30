#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <istream>
#include <ostream>
#include <algorithm>

struct Data
{
    std::string FIO;
    int day;
    int month;
    int year;
    std::string gender;
};

void getdata(std::vector<Data> &v)
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Введите ФИО: ";
    getline(std::cin, v[0].FIO);
    std::cout << "Введите день, месяц, год рождения: ";
    std::cin >> v[0].day >> v[0].month >> v[0].year;
    std::cout << "Введите пол: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(std::cin, v[0].gender);
}

void Message()
{
    std::cout 
        << "-----------------------------------------------------\t" << std::endl 
        << "Выберите действие: " << std::endl 
        << "1 - загрузить данные из файла" << std::endl 
        << "2 - ввести данные" << std::endl 
        << "3 - добавление данных" << std::endl 
        << "4 - сортировка базы данных по алфавиту(по фамилии)" << std::endl 
        << "5 - сортировка базы данных по возрасту" << std::endl 
        << "6 - вывод: список людей, родившихся в заданном месяце" << std::endl 
        << "7 - вывод: фамилию самого старшего мужчины" << std::endl 
        << "8 - вывод: все фамилии, начинающиеся с заданной буквы" << std::endl
        << "9 - вывести текущие данные" << std::endl
        << "10 - загрузить данные в файл" << std::endl
        << "0 - выход из программы" << std::endl 
        << "-----------------------------------------------------\t" << std::endl 
        << "Ваш выбор: ";
}

std::ostream& operator << (std::ostream& out, Data& b) 
{
    out << b.FIO << " " << b.day << " " << b.month << " " << b.year << " " << b.gender;
    return out;
}

std::istream& operator >> (std::istream& in, Data& b)
{
    in >> b.FIO >> b.day >> b.month >> b.year >> b.gender;
    return in;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    std::string line;
    std::fstream input(line);
    std::vector<Data> vec;
    std::vector<Data> temp(1);
    temp[0].FIO = "None";
    int file_str_count = 0;
    int add_count = 0;
    while (true)
    {
        Message();
        while (true)
        {
            std::cin >> n;
            if (n >= 0 && n <= 10) break;
            else std::cout << "Введите число от 0 до 10" << std::endl;
        }
        switch (n)
        {
        case(1):
        {
            //загрузить данные из файла
            std::cout << "Введите имя файла(с расширением): ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            for(line; getline(std::cin,line);)
            {
                input.open(line);
                if (!input.is_open()) std::cout << "Не удалось найти/открыть файл \"" << line << "\" для чтения.\n";
                else
                {
                    std::cout << "Данные загружены" << std::endl;
                    break;
                }
            }
            char* file_string = new char[1024];
            while (!input.eof())
            {
                vec.resize(file_str_count + 1 + add_count);
                input >> vec[file_str_count + add_count];
                //input << std::endl;
                input.getline(file_string, 1024, '\n');
                file_str_count++;
            }
            delete[]file_string;
            input.close();
            break;
        }
        case(2):
        {
            //ввести данные
            getdata(temp);
            std::cout << "Данные считаны" << std::endl;
            break;
        }
        case(3):
        {
            //добавление данных
            if(temp[0].FIO == "None")
            {
                std::cout << "Отсуствует введённая информация" << std::endl;
                break;
            }
            add_count++;
            vec.resize(file_str_count + add_count);
            std::copy(temp.begin(),temp.end(),vec.begin()+file_str_count+add_count-1);
            std::cout << "Данные добавленны" << std::endl;
            break;
        }
        case(4):
        {
            //сортировка базы данных по алфавиту(по фамилии)
            if (add_count == 0 && file_str_count == 0)
            {
                std::cout << "Отсуствуют данные" << std::endl;
                break;
            }
            std::sort(vec.begin(), vec.end(), [](const Data& d1, const Data& d2)
                {
                    return(d1.FIO < d2.FIO);
                });
            std::cout << "Отсортировано" << std::endl;
            break;
        }
        case(5):
        {
            //сортировка базы данных по возрасту
            if (add_count == 0 && file_str_count == 0)
            {
                std::cout << "Отсуствуют данные" << std::endl;
                break;
            }
            std::sort(vec.begin(), vec.end(), [](const Data& d1, const Data& d2) 
                {
                    return(d1.year < d2.year) || (d1.month < d2.month) || (d1.day < d2.day);
                });
            break;
        }
        case(6):
        {
            //вывод:список людей, родившихся в заданном месяце
            if (add_count == 0 && file_str_count == 0)
            {
                std::cout << "Отсуствуют данные" << std::endl;
                break;
            }
            int count = 0;
            int find = 0;
            int key;
            std::cout << "Введите число: ";
            std::cin >> key;
            for (auto a : vec)
            {
                if (vec[count].month == key)
                {
                    std::cout << vec[count].FIO << " " << vec[count].day << " " << vec[count].month << " " << vec[count].year << " " << vec[count].gender << std::endl;
                    find++;
                }
                count++;
            }
            if (find == 0) std::cout << "Ничего не найдено" << std::endl;
            break;
        }
        case(7):
        {
            //вывод: фамилию самого старшего мужчины
            if(add_count == 0 && file_str_count == 0)
            {
                std::cout << "Отсуствуют данные" << std::endl;
                break;
            }
            int count = 0;
            int max_year = 0;
            int max_month = 0;
            int max_day = 0;
            int iter_max_year = 0;
            for (auto a : vec)
            {
                if (vec[count].year > max_year && vec[count].gender == "male")
                {
                    max_year = vec[count].year;
                    iter_max_year = count;
                }
                else if(vec[count].year == max_year && vec[count].gender == "male" && vec[count].month > max_month)
                {
                    max_year = vec[count].year;
                    max_month = vec[count].month;
                    iter_max_year = count;
                }
                else if(vec[count].year == max_year && vec[count].gender == "male" && vec[count].month == max_month && vec[count].day > max_day)
                {
                    max_year = vec[count].year;
                    max_month = vec[count].month;
                    max_day = vec[count].day;
                    iter_max_year = count;
                }
                count++;
            }
            std::cout << "ФИО самого старшего мужчины: " << vec[iter_max_year].FIO << std::endl;
            break;
        }
        case(8):
        {
            //вывод: все фамилии, начинающиеся с заданной буквы
            if (add_count == 0 && file_str_count == 0)
            {
                std::cout << "Отсуствуют данные" << std::endl;
                break;
            }
            char key;
            std::cout << "Введите букву: ";
            std::cin >> key;
            int count = 0;
            int find = 0;
            for (auto a : vec)
            {
                if (vec[count].FIO[0] == key)
                {
                    std::cout << vec[count].FIO << " " << vec[count].day << " " << vec[count].month << " " << vec[count].year << " " << vec[count].gender << std::endl;
                    find++;
                }
                count++;
            }
            if (find == 0) std::cout << "Ничего не найдено" << std::endl;
            break;
        }
        case(9):
        {
            // вывод текущих данных в векторе
            if (add_count == 0 && file_str_count == 0)
            {
                std::cout << "Отсуствуют данные" << std::endl;
                break;
            }
            int count = 0;
            for (auto a : vec)
            {
                std::cout << vec[count].FIO << " " << vec[count].day << " " << vec[count].month << " " << vec[count].year << " " << vec[count].gender << std::endl;
                count++;
            }
            break;
        }
        case(10):
        {
            input.open(line);
            for(auto a : vec)
            {
                input << a;
                input << std::endl;
                vec.pop_back();
            }
            input.close();
            add_count = 0;
            file_str_count = 0;
            break;
        }
        case(0):
        {
            //выход
            std::cout << "Выход" << std::endl;
            break;
        }
        default: break;
        }
        if (n == 0) break;
    }
    return 0;
}