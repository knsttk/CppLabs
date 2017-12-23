/* Lab4, Var1. ������� ��������� � ������ student, ���������� ��������� ����:
�	�������, ���, ��������;
�	����� ������;
�	������������ �� 5 ��������� (������ ������).
�������� ���������, ����������� ��������� ��������:
�	���� � ���������� ������ � ������, ��������� �� �������� 10 ��������� ���� student, ������ ������� ����������� �������� ����, ����� ����� ���� �� ������� ��� 10 ���������; ����� ��������� ����� ������������� �������� ������� �� ����������� ������ ������;
�	����� � ������� ������� � ���������, � ����� ������� ����� ���� ���������, ���������� � ������, ���� ������� ���� �������� ������ 4.0;
�	���� ����� ��������� ���, ������� ��������������� ���������;
*/
#include <iostream>
#include <clocale>
#include <windows.h>
#include <cstring>
using namespace std;

struct Student
{
	char *buf = new char[255]; 
	char *Lname;
	char *Fname;
	char *Patr;
	int grp;
	int mark[5];
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	short n = 0, t = 10;
	Student *names = new Student[t]; // �������� ������ ��������
	double sum = 0;
	double *aver = new double[t];
	char choose;

	for (int i = 1; i <= t; i++)
	{
		system("cls");
		cout << "������� ������� " << i << "-�� ��������: ";
		cin >> names[1].buf; 
		int k = strlen(names[1].buf);
		names[i].Lname = new char[k];
			for (int j = 0; j <= k; j++)
			{
				names[i].Lname[j] = names[1].buf[j];
			}
			memset(names[1].buf, 0, sizeof(names[1].buf));

		cout << "������� ��� " << i << "-�� ��������: ";
		cin >> names[1].buf;
		k = strlen(names[1].buf);
	

		names[i].Fname = new char[k];
			for (int j = 0; j <= k; j++)
			{
				names[i].Fname[j] = names[1].buf[j];
			}
	
				memset(names[1].buf, 0, sizeof(names[1].buf));

		cout << "������� �������� " << i << "-�� ��������: ";
		cin >> names[1].buf;
		k = strlen(names[1].buf);

		names[i].Patr = new char[k];
			for (int j = 0; j <= k; j++)
			{
				names[i].Patr[j] = names[1].buf[j];
			}
				
				memset(names[1].buf, 0, sizeof(names[1].buf));
	
		cout << endl << "������� ����� ������ " << i << "-�� ��������: ";
		cin >> names[i].grp;

		cout << endl << "������� ������ " << i << "-�� �������� : ";

		for (int j = 1; j <= 5; j++) 
		{
			cin >> names[i].mark[j];
			sum += names[i].mark[j];
		}
		
		aver[i] = sum / 5.0; // ������� ������� ����
		sum = 0;
		cout << endl;
		n++;
		cout << "���������� (Y/N)? ";
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
	for (int i = 1; i < n; i++) // ���������� �� ����������� ������
	{
		for (int i = 1; i < n; i++)
		{
			if (names[i + 1].grp < names[i].grp)
			{
				swap(names[i].grp, names[i + 1].grp);
				swap(names[i].Lname, names[i + 1].Lname);
				swap(names[i].Fname, names[i + 1].Fname);
				swap(names[i].Patr, names[i + 1].Patr);
				swap(aver[i], aver[i + 1]);
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) // ����� �������, ��������� � ������
	{
		
		if (aver[i] < 4) //���������� ��������� � ������ ���� 4.0
		{
			cnt++;
		}
		
		if (aver[i] >= 4)
		{		
			cout << names[i].Lname << " ";
			cout << names[i].Fname[0] << ".";
			cout << names[i].Patr[0] << ". ";
			cout << names[i].grp << endl;
		}
		
	}
	if (cnt == n) // ���� � ���� ���� ���� 4.0
	{
		cout << "������� ���� ���� ��������� ���� 4.0" << endl;
	}
	delete aver;
	delete names;
	system("pause");
	return 0;
}