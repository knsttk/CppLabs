#include <iostream>
#include <cstring>
#include <windows.h>
#include <cstdlib>

using namespace std;

	struct Student
	{
		char *Lname;
		char *Fname;
		char *Patr;
		int grp;
		int mark[5];
		double aver;
	};
	struct List
	{
		struct list
		{
			Student data;

			list* next;
			list* prev;
		};
		list* head = nullptr;
	
		void addFirst(Student names)
		{
			list* temp = new list;
			temp->data = names;
			temp->next = NULL;
			temp->prev = NULL;

			if (head == NULL)
			{
				head = temp;
				return;
			}

			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		
		void printgood()
		{
			list* temp = head;
			for (list* i = head; i != NULL; i = i->next)
			{
				for (list* i = head; i != NULL; i = i->next)
				{
					if (temp->data.grp < temp->next->data.grp)
					{
						swap(temp->data.grp, temp->next->data.grp);
						swap(temp->data.Lname, temp->next->data.Lname);
						swap(temp->data.Fname, temp->next->data.Fname);
						swap(temp->data.Patr, temp->next->data.Patr);
						swap(temp->data.aver, temp->next->data.aver);
					}
				}
			}
			for (list* i = head; i != NULL; i = i->next)
			{
				if (temp->data.aver >= 4)
				{
					
					cout << temp->data.Lname << " " << temp->data.Fname[0] << ". " << temp->data.Patr[0] << ". " << temp->data.grp << endl;
				}
				temp = temp->next;
			}
		}
		void clear()
		{

			while (head != nullptr)
			{

				delete[] head->data.Lname;
				delete[] head->data.Fname;
				delete[] head->data.Patr;
				list* temp = head;
				head = head->next;
				delete temp;
			}
		}
	};

	int main()
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		setlocale(LC_ALL, "Russian");

		List list;
		short n = 0, t = 10;
		char choose;
		double sum = 0;
		short cnt = 0;
		for (int i = 1; i <= t; i++)
		{
			system("cls");
			Student names;

			char* buf = new char[255];
			cout << "Введите Фамилию " << i << "-го студента: ";
			cin >> buf;
			int k = strlen(buf) + 1;
			names.Lname = new char[k];
			strcpy(names.Lname, buf);
			names.Lname[k] = '\0';
//===============================================================================)
			cout << "Введите Имя " << i << "-го студента: ";
			cin >> buf;
			k = strlen(buf) + 1;
			names.Fname = new char[k];
			strcpy(names.Fname, buf);
			names.Fname[k] = '\0';
//===============================================================================)
			cout << "Введите Отчество " << i << "-го студента: ";
			cin >> buf;
			k = strlen(buf) + 1;
			names.Patr = new char[k];
			strcpy(names.Patr, buf);
			names.Patr[k] = '\0';
//===============================================================================)
			cout << endl << "Введите номер группы " << i << "-го студента: ";
			cin >> names.grp;
			
			cout << endl << "Введите оценки " << i << "-го студента : ";
//===============================================================================)
				for (int j = 1; j <= 5; j++)
				{
					cin >> names.mark[j];
					sum += names.mark[j];
				}

			names.aver = sum / 5.0; // Находим средний балл
			sum = 0;
			n++;
			if (names.aver < 4)
				{
					cnt++;
				}
			list.addFirst(names);
//===============================================================================)
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
		if (cnt == n)
		{
			cout << "Средний балл всех студентов ниже 4.0" << endl;
		}
		if(cnt < n)
		{
			list.printgood();
		}
		list.clear();
		system("pause");
		return 0;
	}
