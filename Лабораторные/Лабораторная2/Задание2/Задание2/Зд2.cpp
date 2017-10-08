#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "¬ведите к-во элементов массива: " << endl;
	int size;
	cin >> size;
	int* mas = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "¬ведите " << i + 1 << "-ый элемент: " << endl;
		cin >> mas[i];
	}
	int t;
	for (int i = 0; i < size; i++)
	{
		for (int i = 0; i < size; i++)
		{
			if (mas[i] < mas[i + 1] && mas[i] < 0 && mas[i + 1] > 0)
			{
				t = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = t;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << "a[" << i << "] = " << mas[i] << endl;
	}
	delete[] mas;
	system("pause");
	return 0;
}