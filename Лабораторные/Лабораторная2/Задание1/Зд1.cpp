// Lab2, Variant 9, Ex.1
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
		cout << "������� �-�� ��������� �������: " << endl;
	int size;
		cin >> size;
	int* mas = new int[size];
	for (int i = 0; i < size; i++)
	{
		cout << "������� " << i + 1 << "-�� �������: " << endl;
		cin >> mas[i];
	}
	for (int i = 0; i < size; i++)
	{
		if (mas[i] % 2 != 0 && mas[i + 1] % 2 == 0) // ������ �������� �� ���������� ��������� �� ������
		{
			for (int i = size - 1; i >= 0; i--)
			{
				if (mas[i] > 0)
				{
					cout << "a[" << i << "]=" << mas[i] << endl; // ����������� ������ ������������� ��������� � �������� �������
				}
			}
			break; // ������������� ����, ���� ���� ������ ��� ������
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
