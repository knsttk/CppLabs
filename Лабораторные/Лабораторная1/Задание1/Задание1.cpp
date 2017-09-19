#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int x, y, z;
	cout << "Enter X :" << endl; //Просим вводить переменные x, y, z
	cin >> x;
	cout << "Enter Y :" << endl;
	cin >> y;
	cout << "Enter Z :" << endl;
	cin >> z;
	// Объявляю res1, который потом превратится в a
	float res1 = log(abs((x - pow(abs(y), 0.5))*(x + y / (z + pow(x, 6) / 4))));

	float a = pow (res1, 0.2); //Вынес общий кв. корень в отдельную строку
	cout << "a = " << a << endl;

	float b = -x + (x*x) / (1*2*3*4) - pow(x, 5) / (1*2*3*4*5*6);
	
	cout << "b = " << b << endl;
	system("pause");

	return 0;
}