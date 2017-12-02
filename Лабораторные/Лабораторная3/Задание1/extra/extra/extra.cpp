/*Дан файл INPUT.txt. В нем записаны показания счетчиков электроэнергии граждан.
Необходимо найти ФИО и среднее потребление граждан, у которых среднее значение
потребления больше, чем у остальных. Ответ выведите в файл OUTPUT.txt*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("INPUT.txt");
	ofstream fout("OUTPUT.txt");
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
			if (buf[i] == ';')
			{
				j++;
			}
			if (buf[i] >= '0' && buf[i] <= '9')
			{
				
				if (mas[j] == 0)
				{
					mas[j] = atoi(buf + i);

				}
			}
		}
	}
	double num1 = 1, num2 = 2, num3 = 3;
		for (int i = 0; i <= j; i++)
		{
			if (mas[i] != 0 && mas[i+1] !=0)
			{
				mas[i] = mas[i+1] - mas[i];

			}
			else if (mas[i] != 0 && mas[i - 3] != 0)
			{
				mas[i] = (mas[i - 1] + mas[i - 2] + mas[i - 3]);
				mas[i - 1] = 0;
				mas[i - 2] = 0;
				mas[i - 3] = 0;
				if (mas[i - 4] != 0)
				{
					mas[i] = (mas[i] + mas[i - 4]);
					mas[i - 4] = 0;
				}
			}
		}

		for (int i = 0; i <= j; i++)
		{
			if (mas[i] != 0 && num1 == 1)
			{
				num1 = mas[i];
				mas[i] = 0;
			}
			else if (mas[i] != 0 && num2 == 2)
			{
				num2 = mas[i];
				mas[i] = 0;
			}
			else if (mas[i] != 0 && num3 == 3)
			{
				num3 = mas[i];
			}
		}
		double max = (num1 / 3);
		int count = 1;
		double avr2 = (num2 / 3);
		double avr3 = (num3 / 4);
		if (max < avr2)
		{
			max = avr2;
			count = 2;
		}
		if (max < avr3)
		{
			max = avr3;
			count = 3;
		}
		
		if (count == 1)
		{
			fout << "Иванов Иван Иванович" << " " << max;
		}
		if (count == 2)
		{
			fout << "Сидоров Сидр Сидорович" << " " << max;
		}
		if (count == 3)
		{
			fout << "Богатырев Богатырь Богатырович" << " " << max;
		}
		fin.close();
		fout.close();
		system("pause");
		return 0;
}