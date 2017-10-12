// Lab2, Variant 9, Ex.3
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите к-во элементов массива: " << endl;
	int size;
	cin >> size;
	int* mas = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "Введите " << i + 1 << "-ый элемент: " << endl;
		cin >> mas[i];
	}
	int t;
	for (int i = 0; i < size; i++)
	{
		for (int i = 0; i < size; i++)
		{
			if (mas[i] < mas[i + 1])
			{
				t = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = t;

			}
		}		
	}
	for (int t = 0; t < size; t++)
	{
		cout << "mas[" << t << "]" << mas[t] << endl;
	}
	delete [] mas;
	system("pause");
	return 0;
}