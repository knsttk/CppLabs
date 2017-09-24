#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите N: " << endl;
	int sum = 0; 
	cin >> n;
	while (n > 0)
	{
		sum = sum + n % 10; 
		n = n / 10; 
	}
	cout << "—умма = " << sum << endl;

	system("pause");
	return 0;
}