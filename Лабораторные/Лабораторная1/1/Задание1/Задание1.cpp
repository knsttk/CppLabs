#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	int x, y, z;
	cout << "Введите X" << endl; //Просим вводить переменные x, y, z
	cin >> x;
	cout << "Введите Y" << endl;
	cin >> y;
	cout << "Введите Z" << endl;
	cin >> z;
	// Объявляю res1, который потом превратится в a
	float res1 = log(abs((x - pow(abs(y), 0.5))(x + y / (z + pow(x, 6) / 4))));

	float a = pow(res1, 0.2);
	
	cout << "a = " << a << endl;

	
	return 0;
}