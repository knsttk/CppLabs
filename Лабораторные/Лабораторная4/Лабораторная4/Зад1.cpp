/* Lab4, Var1. Описать структуру с именем student, содержащую следующие поля:
•	фамилия, имя, отчество;
•	номер группы;
•	успеваемость по 5 предметам (массив оценок).*/
#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;

struct Student
{
	char Lname[20];
	char Fname[20];
	char Patr[20];
	char smena[20];
	int grp;
	int mark[5];
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	short n = 0, t = 10;
	Student *names = new Student[t]; // создаётся массив массивов
	double sum = 0;
	double *aver = new double[t];
	int cnt = 0;
	char choose;
	for (int i = 1; i <= t; i++)
	{
		if (i != 1)
		{
			cin.get();
		}
		cout << "Введите Фамилию " << i << "-го студента: ";
		cin.getline(names[i].Lname, 20);

		cout << "Введите Имя " << i << "-го студента: ";
		cin.getline(names[i].Fname, 20);

		cout << "Введите Отчество " << i << "-го студента: ";
		cin.getline(names[i].Patr, 20);
	
		cout << endl << "Введите номер группы " << i << "-го студента: ";
		cin >> names[i].grp;
		cout << names[i].grp;
		cout << endl << "Введите оценки " << i << "-го студента : ";
		
		
		for (int j = 1; j <= 5; j++) 
		{
			cin >> names[i].mark[j];
			sum += names[i].mark[j];
		}
		aver[i] = sum / 5.0; // Находим средний балл
		sum = 0;
		cout << endl;
		n++;
		cout << "Продолжить (Y/N)? ";
		cin >> choose;
			if (choose == 'y' || choose == 'Y')
			{
				continue;
			}
			if (choose == 'n' || choose == 'N')
			{
				break;
			}
	}
	cout << endl;
	int temp;
	Student *smena = new Student[20];
	for (int i = 1; i < n; i++) // Сортировка по возрастанию группы
	{
		if (names[i].grp > names[i+1].grp)
		{
			temp = names[i].grp;
			names[i].grp = names[i + 1].grp;
			names[i + 1].grp = temp;
			cout << names[i + 1].grp;
			for (int j = 1; j <= 20; j++)
			{
				names[i].smena[j] = names[i].Lname[j];
				names[i].grp = names[i + 1].Lname[j];
				names[i + 1].grp = temp;
			}
		}
	}
	for (int i = 1; i <= n; i++) // Вывод фамилии, инициалов и группы
	{
		if (aver[i] >= 4)
		{		
			cout << names[i].Lname << " ";
			cout << names[i].Fname[0] << ".";
			cout << names[i].Patr[0] << ". ";
			cout << names[i].grp << endl;
		}
		if (aver[i] < 4) //Количество студентов с баллом ниже 4.0
		{
			cnt++;
		}
	}
	if (cnt == n) // Если у всех балл ниже 4.0
	{
		cout << "Средний балл всех студентов ниже 4.0" << endl;
	}
	
	cout << endl;
	system("pause");
	return 0;
}
