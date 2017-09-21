#include "stdafx.h"
#include <iostream>
#include <stdio.h>

using namespace std;
int main()
{
	int n;
		cout << "Enter N: " << endl; 
	int sum = 0; // Объявляем целочисленную переменную, которая будет являться суммой цифр в N
		cin >> n; 
	while (n > 0) 
{		sum = sum + n % 10; // Заставляем цикл прибавлять цифру из N с каждой новой итерацией
		n = n / 10; // Уменьшаем число N на разряд с каждой новой итерацией
}
	cout << "Summa =" << sum << endl; 
	return 0;
}