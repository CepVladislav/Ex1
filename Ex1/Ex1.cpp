#include <iostream>
#include <string>
#include <limits>
#include <math.h>
#include <assert.h>

struct info
{
	char Name[20];
	char Last_Name[20];
	int mark[3] = {0,0,0};
};

struct chet
{
	char Name[20];
	char Last_Name[20];
	double mark[3] = {0,0,0};
};

struct nech
{
	char Name[20];
	char Last_Name[20];
	double mark[3] = { 0,0,0 };
};

void output(char Name[20], char Last_Name[20], double a, double b, double c)
{
	std::cout << "Name: " << Name << std::endl << "Last Name: " << Last_Name << std::endl << "Marks: " << a << ", " << b << ", " << c << std::endl;
}

int raise(const void* a, const void* b)
{
	return(*(int*)a - *(int*)b);
}

int decrease(const void* a, const void* b)
{
	return(*(int*)b - *(int*)a);
}

int Name_Count(const char* name)
{
	assert(name);
	double leight = 0;
	while (*name++)
	{
		++leight;
	}
	return leight;
}

double max(double a, double b, double c)
{
	double max;
	if (a >= b && a >= c) max = a;
	else if (a>= b && a <=c)
	{
		max = c;
	}
	else if(a <= b && a >= c)
	{
		max = b;
	}
	if (b >= a && b >= c) max = b;
	else if (b >= a && b <= c)
	{
		max = c;
	}
	else if (b <= a && b >= c)
	{
		max = a;
	}
	if (c >= b && c >= a) max = c;
	else if (c >= b && c <= a)
	{
		max = a;
	}
	else if (c <= b && c >= a)
	{
		max = b;
	}
	return max;
}

double min(double a, double b, double c)
{
	double min;
	if (a <= b && a <= c) min = a;
	else if (a <= b && a >= c)
	{
		min = c;
	}
	else if (a >= b && a <= c)
	{
		min = b;
	}
	if (b <= a && b <= c) min = b;
	else if (b <= a && b >= c)
	{
		min = c;
	}
	else if (b >= a && b <= c)
	{
		min = a;
	}
	if (c <= b && c <= a) min = c;
	else if (c <= b && c >= a)
	{
		min = a;
	}
	else if (c >= b && c <= a)
	{
		min = b;
	}
	return min;
}

int main()
{
	int n, s, a = 0, b = 0;
	double sort = 1;
	double j = 0;
	std::cout << "Enter structure limit (>=5)" << std::endl;
	while (true)
	{
		std::cin >> n;
		if (n >= 5) break;  
		else
		{
			std::cout << "Invalid numer" << std::endl;
		}
	}
	info* base = new info[n];
	info* chet = new info[n];
	info* nech = new info[n];
	for (int i = 0; i != n; i++)
	{
		std::cout << "Member num " << i << std::endl;
		std::cout << "Enter Name" << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.getline(base[i].Name,20);
		std::cout << "Enter Last Name" << std::endl;
		std::cin.getline(base[i].Last_Name,20);
		std::cout << "Enter marks" << std::endl;
		std::cin >> base[i].mark[0] >> base[i].mark[1] >> base[i].mark[2];
	}
	std::cout << "Basic data: " << std::endl;
	for (int i = 0; i != n; i++)
	{
		output(base[i].Name, base[i].Last_Name, base[i].mark[0], base[i].mark[1], base[i].mark[2]);
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	for (int i = 0; i != n; i++)
	{
		if (fmod(j, 2.0) == 0)
		{
			chet[a] = base[i];
			a++;
		}
		if (fmod(j, 2.0) == 1)
		{
			nech[b] = base[i];
			b++;
		}
		j++;
	}
	while (sort)
	{
		for (int i = 0; i < a ; i++) 
		{
			qsort(chet[i].mark, 3, sizeof(int), raise);
		}
		for (int i = 0; i < b ; i++)
		{
			qsort(nech[i].mark, 3, sizeof(int), decrease);
			sort = 1;
		}
		sort = 0;
	}
	std::cout << "Ex 5(a)" << std::endl << "Display sorted data (1 - not even; 2- even): " << std::endl;
	while (true)
	{
		std::cin >> s;
		if (s == 1 || s == 2) break;
		else
		{
			std::cout << "Invalid numer" << std::endl;
		}
	}

	switch (s)
	{
		case(1):
		{
			for (int i = 0; i < a; i++)
			{
				output(nech[i].Name, nech[i].Last_Name, nech[i].mark[0], nech[i].mark[1], nech[i].mark[2]);
			}
			break;
		}
		case(2):
		{
			for (int i = 0; i < b; i++)
			{
				output(chet[i].Name, chet[i].Last_Name, chet[i].mark[0], chet[i].mark[1], chet[i].mark[2]);
			}
			break;
		}
		default: 
		{
			std::cout << "Error" << std::endl;
			break;
		}
	}
	std::cout << "-------------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Ex 5(b): " << std::endl;
	for (int i = 0; i != n; i++) 
	{
		std::cout << "Member num " << i << std::endl;
		if (fmod(Name_Count(base[i].Name), 4.0) == 0)
		{
			std::cout << "Ex 5(b)(i), average ball: " << (base[i].mark[0] + base[i].mark[1] + base[i].mark[2]) / 3 << std::endl;
		}
		if (fmod(Name_Count(base[i].Name), 4.0) == 1)
		{
			std::cout << "Ex 5(b)(ii), max: " << max(base[i].mark[0], base[i].mark[1], base[i].mark[2]) << std::endl;
		}
		if (fmod(Name_Count(base[i].Name), 4.0) == 2)
		{
			std::cout << "Ex 5(b)(iii), min: " << min(base[i].mark[0], base[i].mark[1], base[i].mark[2]) << std::endl;
		}
		if (fmod(Name_Count(base[i].Name), 4.0) == 3)
		{
			std::cout << "Ex 5(b)(iv), sum: " << base[i].mark[0] + base[i].mark[1] + base[i].mark[2] << std::endl;
		}
		if (fmod(Name_Count(base[i].Name), 4.0) != 0 && fmod(Name_Count(base[i].Name), 4.0) != 1 && fmod(Name_Count(base[i].Name), 4.0) != 2 && fmod(Name_Count(base[i].Name), 4.0) != 3)
		{
			std::cout << "Member num " << i << "has name, that not divided on 4 with remainder of the division 0/1/2/3 " << std::endl;
		}
	}
	delete[] base;
	delete[] chet;
	delete[] nech;
	return 0;
}