#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int n;
		cout << "Enter N: " << endl; 
	int sum = 0; // ��������� ������������� ����������, ������� ����� �������� ������ ���� � N
		cin >> n; 
	while (n > 0) 
{		sum = sum + n % 10; // ���������� ���� ���������� ����� �� N � ������ ����� ���������
		n = n / 10; // ��������� ����� N �� ������ � ������ ����� ���������
}
	cout << "Summa =" << sum << endl; 
	return 0;
}