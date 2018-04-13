#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;
/*========================Основа====================*/
class Snake
{
public:
	char *buf = new char[255];
	bool gameOver;
	const int width = 16;
	const int height = 16;
	int x = width / 2;
	int y = height / 2;
	int scr;
	int Bx;
	int By;
	Snake()
	{
		Bx = rand() % (width - 1);
		By = rand() % height;
		scr = 0;
	}
	/*========================Победа====================*/
	void Win()
	{
		if (scr == width * height - 2)
		{
			system("cls");
			cout << "<3";
			Sleep(200);
			system("cls");
			cout << "=<3";
			Sleep(200);
			system("cls");
			cout << "~~<3";
			Sleep(200);
			system("cls");
			cout << "===<3";
			Sleep(200);
			system("cls");
			cout << "~~~~<3";
			Sleep(200);
			system("cls");
			cout << "=====<3";
			Sleep(200);
			system("cls");
			cout << "<~~~~~~<3" << endl;
			Sleep(200);
			cout << "Congratulations! You passed the game!" << endl << endl;

			cout << "~####~~##~~##~~####~~##~~##~#####" << endl;
			Sleep(500);
			cout << "##~~~~~###~##~##~~##~##~##~~##" << endl;
			Sleep(500);
			cout << "~####~~##~###~######~####~~~####" << endl;
			Sleep(500);
			cout << "~~~~##~##~~##~##~~##~##~##~~##" << endl;
			Sleep(500);
			cout << "~####~~##~~##~##~~##~##~~##~#####" << endl << endl;
			Sleep(500);
			gameOver = true;
		}
	}
	/*===================Таблица рекордов===============*/
	void Record()
	{
		
		cout << "Enter your name: " << endl;
		cin.getline(buf, 255);
		ofstream rec("record.txt", ios::app);
		rec << buf << " - - - - - " << scr << endl;
		rec.close();

	}
};
class GAME
{
public:
	
	GAME()
	{
		dir = STOP;
		Nt;
	}
	int Nt = 0;
	int Tx[50], Ty[50];
	enum motion { STOP = 0, LEFT, RIGHT, UP, DOWN };
	motion dir;
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
	void Logic(Snake &zmeyka, GAME &log)
	{

		int Prx = Tx[0];
		int Pry = Ty[0];
		int Pr2x, Pr2y;
		Tx[0] = zmeyka.x;
		Ty[0] = zmeyka.y;
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
			zmeyka.x--;
			break;
		}
		case RIGHT:
		{
			zmeyka.x++;
			break;
		}
		case UP:
		{
			zmeyka.y--;
			break;
		}
		case DOWN:
		{
			zmeyka.y++;
			break;
		}
		}
		if (zmeyka.x == zmeyka.Bx && zmeyka.y == zmeyka.By)
		{
			zmeyka.scr++;
			zmeyka.Bx = rand() % zmeyka.width;
			zmeyka.By = rand() % zmeyka.height;
			Nt++;
		}
		/*================Столкновение со стеной============*/
		if (zmeyka.x > zmeyka.width - 2 || zmeyka.x == 0 || zmeyka.y > zmeyka.height - 1 || zmeyka.y < 0)
		{
			system("cls");
			cout << "Game Over!" << endl;
			cout << endl << "Your score: " << zmeyka.scr << endl;
			zmeyka.gameOver = true;
		}
		/*================Столкновение с хвостом============*/
		for (int i = 0; i < Nt; i++)
		{
			if (Tx[i] == zmeyka.x && Ty[i] == zmeyka.y)
			{
				system("cls");
				cout << "Game Over!" << endl;
				cout << endl << "Your score: " << zmeyka.scr << endl;
				zmeyka.gameOver = true;
			}
		}
	}
	/*==============Логика с бесконечной картой=========*/
	void EndlessLogic(Snake &zmeyka, GAME &log)
	{

		int Prx = Tx[0];
		int Pry = Ty[0];
		int Pr2x, Pr2y;
		Tx[0] = zmeyka.x;
		Ty[0] = zmeyka.y;
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
			zmeyka.x--;
			break;
		}
		case RIGHT:
		{
			zmeyka.x++;
			break;
		}
		case UP:
		{
			zmeyka.y--;
			break;
		}
		case DOWN:
		{
			zmeyka.y++;
			break;
		}
		}
		/*======Перенос змейки на противоположную сторону===*/
		if (zmeyka.x >= zmeyka.width - 1)
		{
			zmeyka.x = 0;
		}
		else if (zmeyka.x == 0)
		{
			zmeyka.x = zmeyka.width - 1;
		}
		else if (zmeyka.y >= zmeyka.height)
		{
			zmeyka.y = 0;
		}
		else if (zmeyka.y < 0)
		{
			zmeyka.y = zmeyka.height - 1;
		}
		/*=============Начисление очков за фрукт============*/
		if (zmeyka.x == zmeyka.Bx && zmeyka.y == zmeyka.By)
		{
			zmeyka.scr++;
			zmeyka.Bx = rand() % zmeyka.width;
			zmeyka.By = rand() % zmeyka.height;
			Nt++;
		}
		/*==============Столкновение с хвостом==============*/
		for (int i = 0; i < Nt; i++)
		{
			if (Tx[i] == zmeyka.x && Ty[i] == zmeyka.y)
			{
				system("cls");
				cout << "Game Over!" << endl;
				cout << endl << "Your score: " << zmeyka.scr << endl;
				zmeyka.gameOver = true;
			}
		}

	}
	/*===================Прорисовка карты===============*/
	void Draw(Snake &zmeyka, GAME &log)
	{
		system("cls");
		cout << "Snake ~~~~~~~~~~~<3" << endl;
		for (int i = 0; i < zmeyka.width + 1; i++)
		{
			cout << "%";
		}
		cout << endl;
		for (int i = 0; i < zmeyka.height; i++)
		{
			for (int j = 0; j < zmeyka.width; j++)
			{
				if (j == 0 || j == zmeyka.width - 1)
				{
					cout << "%";

				}
				if (i == zmeyka.y && j == zmeyka.x)
				{
					cout << '\b';
					cout << "@";
				}
				else if (i == zmeyka.By && j == zmeyka.Bx)
				{
					cout << '\b';
					cout << "+";
				}
				else
				{

					for (int k = 0; k < log.Nt; k++)
					{
						if (log.Tx[k] == j && log.Ty[k] == i)
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
		for (int i = 0; i < zmeyka.width + 1; i++)
		{
			cout << "%";
		}
		cout << endl;
		cout << "Press 'x' to exit." << "     " << "Your Score: " << zmeyka.scr << endl;
		cout << "Press 'p' to pause." << endl;
		Sleep(300);
	}
};
/*===================Главная Функция================*/
int main()
{
	Snake zmeyka;
	GAME log;
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Hello! It's Snake!" << endl;
	cout << "Choose the field-style:" << endl;
	cout << "1 - Standart." << endl;
	cout << "2 - Endless." << endl << endl;
	cout << "Press 'x' to exit." << endl;
	zmeyka.gameOver = false;
	switch (_getch())
	{
	case '1':
	{
		
		while (zmeyka.gameOver == false)
		{
			log.Draw(zmeyka, log);
			log.Input();
			log.Logic(zmeyka, log);
			zmeyka.Win();
		}
		break;

	}
	case '2':
	{
		while (zmeyka.gameOver == false)
		{
			log.Draw(zmeyka, log);
			log.Input();
			log.EndlessLogic(zmeyka, log);
			zmeyka.Win();
		}
		break;
	}
	case 'x':
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
	
	zmeyka.Record();
	system("cls");
	cout << "HIGHSCORES..." << endl << endl;
	ifstream rec("record.txt");
	cout << "=====================================" << endl;
	while (!rec.eof())	
	{
		rec.getline(zmeyka.buf, 255);
		cout << zmeyka.buf << endl << endl;
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
		log.Nt = 0;
		zmeyka.gameOver = false;
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
		log.Nt = 0;
		zmeyka.gameOver = false;
		main();
	}
	}

	return 0;
	delete[] zmeyka.buf;
}
