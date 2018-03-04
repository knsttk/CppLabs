#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	char *buf = new char[255];
	cout << "Enter your word: ";
	cin.getline(buf, 255);
	return 0;
}