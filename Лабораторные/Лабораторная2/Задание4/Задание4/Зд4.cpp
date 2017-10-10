// Lab2, Variant 9, Ex.4
#include <iostream>
using namespace std;
int main()
{
	const int n = 4, m = 4;
	setlocale(LC_ALL, "Russian");
	int mas[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "mas[" << i << "][" << j << "]= ";
			cin >> mas[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << "%d  " << mas[i][j] << endl;
	}
		

	delete mas;
	system("pause");
	return 0;
} 
