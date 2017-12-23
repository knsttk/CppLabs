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

struct list
{
	Student *names;
	list *next;
	list *prev;
};