#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;
int Sum(int mas[], const int k, int i);
int Num(int mas[], const int k, int i);
void Create(int mas[], const int k, const int min, const int max, int i);
void Print(int mas[], const int k, int i);
void Print1(int mas[], const int k, int i);

int main()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int min = -40;
	const int max = 20;

	const int n = 26;
	int a[n] = {};

	Create(a, n, min, max, 0);
	Print(a, n, 0);
	cout << "Сума = " << Sum(a, n, 0) << endl;
	cout << "Кількість = " << Num(a, n, 0) << endl;
	cout << endl;
	Print1(a, n, 0);
	Print(a, n, 0);
	return 0;
}
int Sum(int mas[], const int k, int i)
{
	if (i < k)
	{
		if (!(mas[i] > 0 || i % 2 != 0))
			return mas[i] + Sum(mas, k, i + 1);
		else
			return Sum(mas, k, i + 1);
	}
	else
		return 0;
}


int Num(int mas[], const int k, int i)
{
	if (i < k)
	{
		if (!(mas[i] > 0 || i % 2 != 0))
			return 1 + Num(mas, k, i + 1);
		else
			return Num(mas, k, i + 1);
	}
	else
		return 0;
}



void Create(int mas[], const int k, const int min, const int max, int i)
{
	mas[i] = min + rand() % (max - min + 1);
	if (i < k - 1) {
		Create(mas, k, min, max, i + 1);
	}
}

void Print(int mas[], const int k, int i)
{
	cout << setw(4) << mas[i];
	if (i < k - 1)
		Print(mas, k, i + 1);
	else
		cout << endl;
}

void Print1(int mas[], const int k, int i)
{
	if (i == k)
		return;
	if (!(mas[i] > 0 || i % 2 != 0))
		mas[i] = 0;
	Print1(mas, k, i + 1);
}
