#include <iostream>
#include <vector>
#include <algorithm>

struct DataBase
{
    std::string FIO = "---";
    std::string email = "---";
    int purchases_count = 0;
    double purchases_prise = 0;
};

int main()
{
    std::vector<DataBase> v = { {"FIO1","email1",11,220.22 },{"FIO2","email2",50,320.22},{"FIO3","email3",5,1000.22},{"FIO4","email4",30,5220.22},{"FIO5","email5",3,120.22},{"FIO6","email6",14,920.22} };
    int n, count = 0, i;
    std::cout << "Enter struct size: ";
    std::cin >> n;
    v.reserve(n);
    sort(v.begin(), v.end(), [&count](DataBase& a, DataBase& b)
        {
            ++count;
            return a.purchases_count < b.purchases_count;
        });
    std::cout << "Pass count: " << count << std::endl;
    std::cout << "All buyers: " << std::endl;
    for_each(v.begin(), v.end(), [](DataBase _n)
        {
            std::cout << _n.FIO << std::endl;
        });
    std::cout << "Enter number of buyers for removing: ";
    std::cin >> i;
    while (i!=0)
    {
        v.pop_back();
        i--;
    }
    std::cout << "Remaining buyers: " << std::endl;
    for_each(v.begin(), v.end(), [](DataBase _n)
        {
            std::cout << _n.FIO << std::endl;
        });
    return 0;
}