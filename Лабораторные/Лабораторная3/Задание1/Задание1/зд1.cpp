/*Lab 3. Var 9. ¬ текстовом файле INPUT.TXT записаны целые числа через пробел,
возможно, в несколько строк. «а один просмотр файла сформировать список этих чисел.
—формировать на основе данного списка два дополнительных, содержащих соответственно
четные и нечетные элементы исходного списка. 
ѕолученные списки занести в текстовые файлы ODD.TXT и EVEN.TXT.*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("INPUT.txt");
	ofstream fodd("ODD.txt");
	ofstream feven("EVEN.txt");
	int* mas = new int[255];
	for (int i = 0; i < 255; i++)
	{
		mas[i] = 0;
	}
	int j = 0;
	while (!fin.eof())
	{
		char* buf = new char[255];
		fin.getline(buf, 255);

		for (int i = 0; i < 255; i++)
		{
			if (buf[i] == '\0')
			{
				break;
			}
			if (buf[i] == ' ')
			{
				j++;
			}
			else
			{
				if (mas[j] == 0)
				{
					mas[j] = atoi(buf + i);

					if (mas[j] % 2 != 0)
					{
						fodd << mas[j] << " ";
					}
					else if (mas[j] % 2 == 0)
					{
						feven << mas[j] << " ";
					}
				}
			}

		}

	}
	for (int i = 0; i <= j; i++)
	{
		cout << mas[i] << " ";
	}
	fodd.close();
	feven.close();
	fin.close();
	system("pause");
	return 0;
}