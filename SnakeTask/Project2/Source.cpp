#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

bool gameOver;
const int width = 16;
const int height = 16;
int x, y, Bx, By, scr = 0;
int Tx[50], Ty[50];
int Nt;
char *buf = new char[255];
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
/*========================Основа====================*/
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2 - 1;
	y = height / 2 - 1;
	Bx = rand() % width;
	By = rand() % height;
	scr = 0;
}
/*===================Прорисовка карты===============*/
void Draw()
{
	system("cls");
	cout << "Snake ~~~~~~~~~~~<3" << endl;
	for (int i = 0; i < width + 1; i++)
	{
		cout << "%";
	}
	cout << endl;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0 || j == width - 1)
			{
				cout << "|";
				if (i == height / 2 && j == width - 1) 
				{
					cout << "Your score: " << scr;
				}
			}
			if (i == y && j == x)
			{
				cout << '\b';
				cout << "@";
			}
			else if (i == By && j == Bx)
			{
				cout << '\b';
				cout << "+";
			}
			else
			{

				for (int k = 0; k < Nt; k++)
				{
					if (Tx[k] == j && Ty[k] == i)
					{
						cout << '\b';
						cout << "o";
					}
				}
			}
			cout << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < width + 1; i++)
	{
		cout << "%";
	}
	cout << endl;
	cout << "Press 'x' to exit." << endl;
	cout << "Press 'p' to pause." << endl;
	Sleep(50);
}
/*======================Управление==================*/
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
		{
			dir = LEFT;
			break;
		}
		case 's':
		{
			dir = DOWN;
			break;
		}
		case 'd':
		{
			dir = RIGHT;
			break;
		}
		case 'w':
		{
			dir = UP;
			break;
		}
		case 'p':
		{
			system("cls");
			cout << "PAUSE" << endl << endl;
			cout << "Press any key to continue..." << endl;
			_getch();
			break;
		}
		case 'x':
		{
			system("cls");
			cout << "Do u want to exit? (Y/N)" << endl;
			switch (_getch())
			{
			case 'y':
			{
				gameOver = true;
				exit(0);
			}
			case 'n':
			{
				break;
			}
			}
			break;
		}
		case 'з':
		{
			system("cls");
			cout << "PAUSE" << endl << endl;
			cout << "Press any key to continue..." << endl;
			_getch();
			break;
		}
		}
	}
}
/*================Логика с обычной картой===========*/
void Logic()
{

	int Prx = Tx[0];
	int Pry = Ty[0];
	int Pr2x, Pr2y;
	Tx[0] = x;
	Ty[0] = y;
	for (int i = 1; i < Nt; i++)
	{
		Pr2x = Tx[i];
		Pr2y = Ty[i];
		Tx[i] = Prx;
		Ty[i] = Pry;
		Prx = Pr2x;
		Pry = Pr2y;
	}
	switch (dir)
	{
	case LEFT:
	{
		x--;
		break;
	}
	case RIGHT:
	{
		x++;
		break;
	}
	case UP:
	{
		y--;
		break;
	}
	case DOWN:
	{
		y++;
		break;
	}
	}
	if (x == Bx && y == By)
	{
		scr++;
		Bx = rand() % width;
		By = rand() % height;
		Nt++;
	}
	/*================Столкновение со стеной============*/
	if (x > width - 1 || x < 0 || y > height - 1 || y < 0)
	{
		system("cls");
		cout << "Game Over!" << endl;
		cout << endl << "Your score: " << scr << endl;
		gameOver = true;
	}
	/*================Столкновение с хвостом============*/
	for (int i = 0; i < Nt; i++)
	{
		if (Tx[i] == x && Ty[i] == y)
		{
			system("cls");
			cout << "Game Over!" << endl;
			cout << endl << "Your score: " << scr << endl;
			gameOver = true;
		}
	}
}
/*==============Логика с бесконечной картой=========*/
void EndlessLogic()
{

	int Prx = Tx[0];
	int Pry = Ty[0];
	int Pr2x, Pr2y;
	Tx[0] = x;
	Ty[0] = y;
	for (int i = 1; i < Nt; i++)
	{
		Pr2x = Tx[i];
		Pr2y = Ty[i];
		Tx[i] = Prx;
		Ty[i] = Pry;
		Prx = Pr2x;
		Pry = Pr2y;
	}
	switch (dir)
	{

	case LEFT:
	{
		x--;
		break;
	}
	case RIGHT:
	{
		x++;
		break;
	}
	case UP:
	{
		y--;
		break;
	}
	case DOWN:
	{
		y++;
		break;
	}
	}
	/*======Перенос змейки на противоположную сторону===*/
	if (x >= width)
	{
		x = 0;
	}
	else if (x < 0)
	{
		x = width - 1;
	}
	else if (y >= height)
	{
		y = 0;
	}
	else if (y < 0)
	{
		y = height - 1;
	}
	/*=============Начисление очков за фрукт============*/
	if (x == Bx && y == By)
	{
		scr++;
		Bx = rand() % width;
		By = rand() % height;
		Nt++;
	}
	/*==============Столкновение с хвостом==============*/
	for (int i = 0; i < Nt; i++)
	{
		if (Tx[i] == x && Ty[i] == y)
		{
			system("cls");
			cout << "Game Over!" << endl;
			cout << endl << "Your score: " << scr << endl;
			gameOver = true;
		}
	}
}
/*===================Таблица рекордов===============*/
void Record()
{
	
	cout << "Enter your name: " << endl;
	cin.getline(buf, 255);
	ofstream rec("record.txt", ios :: app);
	rec << buf << " - - - - - " << scr << endl;
	rec.close();
	
}
/*===================Главная Функция================*/
int main()
{

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Hello! It's Snake!" << endl;
	cout << "Choose the field-style:" << endl;
	cout << "1 - Standart." << endl;
	cout << "2 - Endless." << endl << endl;
	cout << "Press 'x' to exit." << endl;
	switch (_getch())
	{
		case '1':
		{
			Setup();
			while (!gameOver)
			{
				Draw();
				Input();
				Logic();
			}
			break;
			
		}
		case '2':
		{
			Setup();
			while (!gameOver)
			{
				Draw();
				Input();
				EndlessLogic();
			}
			break;
		}
		case 'x' :
		{
			exit(0);
		}
		default:
		{
			cout << endl << "Incorrect input. Try Again." << endl;
			cout << "Press any key to restart." << endl;
			_getch();
			system("cls");
			main();
		}
	}
	Record();
	system("cls");
	cout << "HIGHSCORES..." << endl << endl;
	ifstream rec("record.txt");
	cout << "=====================================" << endl;
		while (!rec.eof())	//Вывод рекордов на экран
		{
			rec.getline(buf, 255);
			cout << buf << endl << endl;
		}
	rec.close();
	cout << "=====================================" << endl;
	cout << "Press '1' to exit." << endl;
	cout << "Press '2' to restart." << endl;
	cout << "Press 'e' to erase all records." << endl;
		switch (_getch())
			{
			case '1':
			{
				break;
			}
			case '2':
			{
				system("cls");
				Nt = 0;
				gameOver = false;
				main();
			}
			case 'e':
			{
				ofstream rec("record.txt");
				rec << "\0";
				rec.close();

				system("cls");
				cout << "All records has erased.";
				_getch();
				system("cls");
				Nt = 0;
				gameOver = false;
				main();
			}
		}
	
	return 0;
	delete[] buf;
}
