#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int x, y, z;
	cout << "������� X :" << endl; 
	cin >> x;
	cout << "������� Y :" << endl;
	cin >> y;
	cout << "������� Z :" << endl;
	cin >> z;
	// �������� res1, ������� ����� ����������� � a
	float res1 = log(abs((x - pow(abs(y), 0.5))*(x + y / (z + pow(x, 6) / 4))));
	
	if (res1 < 0)
	{
		cout << "������!" << endl;
	}
	else
	{

		float a = pow(res1, 0.2); //����� ����� ������ � ��������� ������
		cout << "a = " << a << endl;
	}

	float b = -x + (x*x) / (1 * 2 * 3 * 4) - pow(x, 5) / (1 * 2 * 3 * 4 * 5 * 6);

	cout << "b = " << b << endl;
	system("pause");

	return 0;
}