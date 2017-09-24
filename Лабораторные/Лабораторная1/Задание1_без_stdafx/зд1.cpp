#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int x, y, z;
	cout << "¬ведите X :" << endl; 
	cin >> x;
	cout << "¬ведите Y :" << endl;
	cin >> y;
	cout << "¬ведите Z :" << endl;
	cin >> z;
	// ќбъ€вл€ю res1, который потом превратитс€ в a
	float res1 = log(abs((x - pow(abs(y), 0.5))*(x + y / (z + pow(x, 6) / 4))));
	
	if (res1 < 0)
	{
		cout << "ќшибка!" << endl;
	}
	else
	{

		float a = pow(res1, 0.2); //¬ынес общий корень в отдельную строку
		cout << "a = " << a << endl;
	}

	float b = -x + (x*x) / (1 * 2 * 3 * 4) - pow(x, 5) / (1 * 2 * 3 * 4 * 5 * 6);

	cout << "b = " << b << endl;
	system("pause");

	return 0;
}