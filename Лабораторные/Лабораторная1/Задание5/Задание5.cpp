#include <iostream>
using namespace std;

int main ()
{
	setlocale(LC_ALL, "Russian");
	int a;
	
	cout << "������� �: " << endl;

	cin >> a;
	double num = 1;

	while (a > num)
	{
			num += (1 / ++num);
	}
	cout << num << " - ������ �����, �������, ��� a: " << endl;
		system("pause");
	return 0;

}