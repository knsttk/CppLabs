// Lab2, Variant 9, Ex.1
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
	for (int i = 0; i < size; i++)
	{
		if (mas[i] % 2 != 0 && mas[i + 1] % 2 == 0) // Запуск проверки на следование нечётного за чётным
		{
			for (int i = size - 1; i >= 0; i--)
			{
				if (mas[i] > 0)
				{
					cout << "a[" << i << "]=" << mas[i] << endl; // Организация вывода положительных элементов в обратном порядке
				}
			}
			break; // Останавливаем цикл, если один случай уже найден
		}
		else
		{
			for (int i = size - 1; i >= 0; i--)
			{
				if (mas[i] < 0)
				{
					cout << "a[" << i << "]=" << mas[i] << endl;
				}
			}
			break;
		}
	}
	delete [] mas;

	system("pause");
	return 0;
}
