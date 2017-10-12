// Lab2, Variant 9, Ex.4
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите n - строк: " << endl;
	cin >> n;
	int m = n;
	int** mas = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cout << "Введите mas[" << i << "][" << j << "]: " << endl;
			cin >> mas[i][j];
		}
	}
	cout << "Ваш массив:" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << "  ";
			if (j == m - 1)
			{
				cout << endl;
			}
		}

	}
	cout << endl;
	int t; // Начинаем менять местами блоки
	for (int i = 0; i < n/2; i++)
	{
		for (int j = 0; j < m / 2; j++) // Меняем местами 1 и 2 блоки
		{
			t = mas[i][j + n / 2];
			mas[i][j + n / 2] = mas[i][j];
			mas[i][j] = t;
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++) // Меняем местами 3 и 4 блоки
		{
			t = mas[i + n / 2][j + n / 2];
			mas[i + n / 2][j + n / 2] = mas[i + n / 2][j];
			mas[i + n / 2][j] = t;
		}
	}
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = 0; j < m / 2; j++) // Меняем местами 1 и 4 блоки
		{
			t = mas[i + n / 2][j + n / 2];
			mas[i + n / 2][j + n / 2] = mas[i][j];
			mas[i][j] = t;
		}
	}
	cout << "Новый массив: " << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mas[i][j] << "  ";
			if (j == m-1)
			{
				cout << endl;
			}
		}

	}
	delete [] mas;
	system("pause");
	return 0;
} 
