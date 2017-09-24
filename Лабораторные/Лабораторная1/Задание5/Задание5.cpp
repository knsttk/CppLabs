#include <iostream>
using namespace std;

int main ()
{
	setlocale(LC_ALL, "Russian");
	int a;
	
	cout << "¬ведите а: " << endl;

	cin >> a;
	double num = 1;

	while (a > num)
	{
			num += (1 / ++num);
	}
	cout << num << " - первое число, большее, чем a: " << endl;
		system("pause");
	return 0;

}