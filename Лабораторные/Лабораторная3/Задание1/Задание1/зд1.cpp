/* Lab 3. Var 9. � ��������� ����� INPUT.TXT �������� ����� ����� ����� ������,
��������, � ��������� �����. �� ���� �������� ����� ������������ ������ ���� �����.
������������ �� ������ ������� ������ ��� ��������������, 
���������� �������������� ������ � �������� �������� ��������� ������.
���������� ������ ������� � ��������� ����� ODD.TXT � EVEN.TXT.*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL,  "Russian");
	ifstream fin("INPUT.txt");
	char nums []= fin.get(fin, 100);

		int count = 0, mas[100], j = 0;

		for (int i = 0; i < 100; i++)
		{
			fin.get(nums,25);
			if (atoi(nums) != 0)
			{
				mas[j] = atoi(nums);
				count = ++count;
				j = ++j;
			}
		}
	fin.close();
	ofstream fodd("ODD.txt");
	ofstream feven("EVEN.txt");

		for (int i = 0; i < count; i++)
		{

			if (mas[i] % 2 != 0)
			{

				fodd << mas[i] << " ";
			}
			else if (mas[i] % 2 == 0)
			{
				feven << mas[i] << " ";
			}
		}
		fodd.close();
		feven.close();
		delete [] nums;

	return 0;
}