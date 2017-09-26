#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	float f;
	cout << "Введите a: " << endl;
	cin >> a;
	if (a < -1)
	{
		f = -1 / (a * a);
		cout << "Функция f(a) равна " << f << endl;
	}
	else if (a >= -1 && a <= 2)
	{
		f = a * a;
		cout << "Функция f(a) равна " << f << endl;
	}
	else if (a > 2)
	{
		f = 4;
		cout << "Функция f(a) равна " << f << endl;
	}
	system("pause");
	return 0;
}