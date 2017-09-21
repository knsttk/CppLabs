#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int count = 0;
	cout << "Введите количество элементов последовательности" << endl;
	int n;
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Введите " << i + 1 << "-ый элемент: " << endl;
		cin >> mas[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			count++;
	}
	if (count % 10 == 1)
	{
		cout << "В вашей последовательности всего " << count << " чётный порядковый номер." << endl;
	}
	if (count % 10 > 1 && count % 10 < 5)
	{
		cout << "В вашей последовательности всего " << count << " чётных порядковых номера." << endl;
	}
	if (count % 10 > 4 && count % 10 <= 9 || count % 10 == 0)
	{
		cout << "В вашей последовательности всего " << count << " чётных порядковых номеров." << endl;
	}
	

	system("pause");
	return 0;
}