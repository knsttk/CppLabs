#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cctype>
using namespace std;
bool Numerror = false;
void ErrorView();

double tempval;
double EnterError()
{

	tempval = 0;

		char *enter = new char[255];

		cin.getline(enter, 255);
		bool correct = false;
		while (correct == false)
		{
			const char *example = "0123456789";

			for (int i = 0; i <= strlen(enter); i++)
			{
				if (!strchr(example, enter[i]))
				{
					cout << "Ошибка! Введите число." << endl;
					return NULL;
				}
				else
				{
					correct = true;
				}
			}
		}
		double *okenter = new double[strlen(enter + 1)];
		for (int i = 0; i <= strlen(enter + 1); i++)
		{
			okenter[i] = atof(enter);
		}
		tempval = *okenter;
		return tempval;
	
}

class Circle
{
	double  rad, change, x, y;
public:	
	Circle(double x, double y, double rad) : x(x), y(y), rad(rad) {	}

	double getx() const { return x; }
	double gety() const { return y; }
	double getRad() const { return rad; }

	void Size(double change, short choose)
	{
			if (choose == 1)
			{
				if (change > rad)
				{		
					Numerror = true;
					return;
				}
				change /= -1;
				rad += change;
			}
			else
			{
				rad += change;
			}
		
	}
	void Move(double movex, double movey)
	{
		x += movex;
		y += movey;
	}


};
class Square
{
	double x, y, sizedge, degree;
public:
	Square(double x, double y, double sizedge) : x(x), y(y), sizedge(sizedge) {	}
	double getx() const { return x; }
	double gety() const { return y; }
	double getsizedge() const { return sizedge; }
	
	void Size(double change, short choose)
	{

		if (choose == 1)
		{
			if (change > sizedge)
			{
				Numerror = true;
				return;
			}
			change /= -1;
			sizedge += change;
		}
		else
		{
			sizedge += change;
		}
		
	}

	void Move(double movex, double movey)
	{
		x += movex;
		y += movey;
	}

	void Turn(int degree)
	{
		this->degree = degree;
	}

};
class Rectan
{
	double x, y, height, width;
public:
	Rectan(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) { }
	double getx() const { return x; }
	double gety() const { return y; }
	double getwidth() const { return width; }
	double getheight() const { return height; }

	void Size(short choose2, double change, short choose)
	{

		if (choose2 == 1)
		{
			if (choose == 1)
			{
				if (change > width)
				{
					Numerror = true;
					return;
				}
				change /= -1;
				width += change;
			}
			else
			{
				width += change;
			}
		}
		if (choose2 == 2)
		{
			if (choose == 1)
			{
				if (change > width)
				{
					Numerror = true;
					return;
				}
				change /= -1;
				height += change;
			}
			else
			{
				height += change;
			}
		}
		if (choose2 == 3)
			{
				if (choose == 1)
				{
					if (change > width || change > height)
					{
						Numerror = true;
						return ;
					}
					change /= -1;
					width += change;
					height += change;
				}
				else
				{
					width += change;
					height += change;
				}
			}
		
	}
	void Move(double movex, double movey)
	{
		x += movex;
		y += movey;
	}
	void Turn(int degree)
	{

	}
};

int main(int *okenter, char *enter)
{
	Circle *cir = new Circle(0, 0, 0);
	Square *sq = new Square(0, 0, 0);
	Rectan *rect = new Rectan(0, 0, 0, 0);
	setlocale(LC_ALL, "Russian");
	bool check = false;
	double movex, movey;
	int  degree = 0;
	int povor = 0;
	short type;
	bool temp, temp2;
	short choose = 0;
	double change = 0;
	double change2 = 0;
	while (!check)
	{
		check = false;
		cout << "Выберите Фигуру: " << endl;
		cout << "1 - Круг" << endl;
		cout << "2 - Квадрат" << endl;
		cout << "3 - Прямоугольник" << endl;
		switch (_getch())
		{
		case '1':
		{
			bool cor = false;
			while (cor == false)
			{
				cout << "Введите координаты: " << endl;
				cout << "Центр X: " << endl;

				if (EnterError() == NULL)
				{
					continue;
				}
				double x = tempval;
				cout << "Центр Y: " << endl;
				if (EnterError() == NULL)
				{
					continue;
				}
				double y = tempval;
				cout << "Введите Радиус: " << endl;
				if (EnterError() == NULL)
				{
					continue;
				}
				double rad = tempval;
				type = 1;
				Circle cirl(x, y, rad);
				cir = &cirl;
				check = true;
				cor = true;
			}
			delete[] enter;
			break;
		}
		case '2':
		{
			type = 2;
			bool cor = false;
			while (cor == false)
			{
				cout << "Введите координаты: " << endl;
				cout << "Центр X: ";
				if (EnterError() == NULL)
				{
					continue;
				}
				double x = tempval;
				cout << "Центр Y: ";
				if (EnterError() == NULL)
				{
					continue;
				}
				double y = tempval;
				cout << "Введите длину стороны: ";
				if (EnterError() == NULL)
				{
					continue;
				}
				double sizedge = tempval;
				Square sqr(x, y, sizedge);
				sq = &sqr;
				cor = true;
				check = true;
			}
			break;
		}
		case '3':
		{
			type = 3;
			bool cor = false;
			while (cor == false)
			{
				cout << "Введите координаты: " << endl;
				cout << "Центр X: ";
				if (EnterError() == NULL)
				{
					continue;
				}
				double x = tempval;
				cout << "Центр Y: ";
				if (EnterError() == NULL)
				{
					continue;
				}
				double y = tempval;
				cout << "Введите ширину: ";
				if (EnterError() == NULL)
				{
					continue;
				}
				double width = tempval;
				cout << "Введите длину: ";
				if (EnterError() == NULL)
				{
					continue;
				}
				double height = tempval;
				Rectan rectn(x, y, width, height);
				rect = &rectn;
				cor = true;
				check = true;
			}
			break;
		}
		default:
		{
			cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
			system("cls");
			break;
		}
		}
	}
	bool turnon = 0;
	bool check1 = false;
	while (!check1)
	{
		cout << "==================================" << endl;
		cout << "Выберите действие:" << endl;
		cout << "1 - Изменить размер." << endl;
		cout << "2 - Сдвинуть фигуру." << endl;
		cout << "3 - Повернуть фигуру." << endl;
		cout << "4 - Текущие характеристики фигуры" << endl;
		cout << "5 - Выйти." << endl;
		cout << "6 - Ввести новую фигуру." << endl;
		cout << "==================================" << endl;
		switch (_getch())
		{

		case'1':
		{

			cout << "Увеличить или уменьшить фигуру?" << endl;
			temp = false;
			temp2 = false;
			while (temp == false)
			{
				if (type == 1 || type == 2)
				{
					cout << "1 - Увеличить." << endl;
					cout << "2 - Уменьшить." << endl;
					switch (_getch())
					{
					case '1':
					{
						cout << "Увеличить на: ";
						break;
					}
					case '2':
					{
						choose = 1;
						cout << "Уменьшить на: ";
						break;
					}

					default:
					{
						cout << "Некорректный ввод. Введите ещё раз." << endl;
						break;
					}
					}
					while (temp2 == false)
					{

						bool cor = false;
						while (cor == false)
						{
							if (EnterError() == NULL)
							{
								continue;
							}
							change = tempval;
							cor = true;
						}
						if (type == 1)
						{
							cir->Size(change, choose);
							ErrorView();
						}
						
						if (type == 2)
						{
							sq->Size(change, choose);
							ErrorView();
						}
						choose = 0;
						temp2 = true;

					}
					temp = true;
				}
				break;
			}

			if (type == 3)
			{
				short choose2 = 0;
				cout << "1 - Увеличить" << endl;
				cout << "2 - Уменьшить" << endl;
				switch (_getch())
				{
				case '1':
				{
					cout << "------------------------" << endl;
					cout << "1 - Увеличить ширину." << endl;
					cout << "2 - Увеличить длину." << endl;
					cout << "3 - Увеличить и ширину и длину." << endl;
					cout << "------------------------" << endl;
					
					break;
				}
				case'2':
				{
					
					cout << "------------------------" << endl;
					cout << "1 - Уменьшить ширину." << endl;
					cout << "2 - Уменьшить длину." << endl;
					cout << "3 - Уменьшить и ширину и длину." << endl;
					cout << "------------------------" << endl;
					choose = 1;
					break;
				}
				default:
				{
					cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
					_getch();
					break;
				}
				}

				switch (_getch())
				{
				case'1':
				{
					choose2 = 1;
					if (choose == 1)
					{
						cout << "Уменьшить ширину на: ";
					}
					else
					{

						cout << "Увеличить ширину на: ";
					}

					bool temp2 = false;
					while (temp2 == false)
					{
						bool cor = false;
						while (cor == false)
						{
							if (EnterError() == NULL)
							{
								continue;
							}
							change = tempval;
							cor = true;
						}
						rect->Size(choose2, change, choose2);
						ErrorView();
						temp2 = true;
					}
					break;
				}

				case '2':
				{
					choose2 = 2;
					if (choose == 1)
					{
						cout << "Уменьшить длину на: ";
					}
					else
					{
						cout << "Увеличить длину на: ";
					}

					temp2 = false;
					while (temp2 == false)
					{
						bool cor = false;
						while (cor == false)
						{
							if (EnterError() == NULL)
							{
								continue;
							}
							change = tempval;
							cor = true;
						}
						rect->Size(choose2, change, choose);
						ErrorView();
						temp2 = true;
					}
					break;
				}
				case '3':
				{
					choose2 = 3;
					if (choose == 1)
					{
						cout << "Уменьшить и ширину и длину на: ";
					}
					else
					{
						cout << "Увеличить и ширину и длину на: ";
					}

					temp2 = false;
					while (temp2 == false)
					{
						bool cor = false;
						while (cor == false)
						{
							if (EnterError() == NULL)
							{
								continue;
							}
							cor = true;
							change = tempval;
						}
						rect->Size(choose2, change, choose);
						ErrorView();
						temp2 = true;
					}
					break;
				}
				default:
				{
					cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
					_getch();
				}
				}
			}
			break;
		}
		case'2':
		{
			cout << "Сдвинуть фигуру: " << endl;
			
			bool cor = false;
			while (cor == false)
			{
				cout << "По X :";
				if (EnterError() == NULL)
				{
					continue;
				}
				movex = tempval;
				cor = true;
			}
	
			cor = false;
			while (cor == false)
			{
				cout << "По Y :";
				if (EnterError() == NULL)
				{
					continue;
				}
				movey = tempval;
				cor = true;
			}
			if (type == 1)
			{
				cir->Move(movex, movey);
			}
			if (type == 2)
			{
				sq->Move(movex, movey);
			}
			if (type == 3)
			{
				rect->Move(movex, movey);
			}
			break;
		}
		case'3':
		{
			if (type == 1)
			{
				cout << endl << "Нет смысла вращать круг. Это же круг!" << endl << endl;
				break;
			}
			else
			{
				bool cor = false;
				while (cor == false)
				{
					cout << "Повернуть на: ";
					if (EnterError() == NULL)
					{
						continue;
					}
					degree = tempval;
					cor = true;
				}
				if (type == 2)
				{
					sq->Turn(degree);
				}
				if (type == 3)
				{
					rect->Turn(degree);
				}
				cout << "Фигура была повёрнута на " << degree;
				if ((degree < 10 || degree > 20) && degree % 10 == 1)
				{
					cout << " градус." << endl;
				}
				if ((degree < 10 || degree > 20) && degree % 10 >= 2 && degree % 10 <= 4)
				{
					cout << " градуса." << endl;
				}
				if (degree % 10 >= 5 && degree % 10 <= 9 || degree % 10 == 0 || (degree > 9 && degree < 21))
				{
					cout << " градусов." << endl;
				}
				povor += degree;
				turnon = 1;
				break;
			}
		}
		case'4':
		{
			if (type == 1)
			{
				cout << "Центр x = " << cir->getx() << " Центр y = " << cir->gety() << " Радиус = " << cir->getRad();
			}
			if (type == 2)
			{
			cout << "Центр x = " << sq->getx() << " Центр y = " << sq->gety() << " Длина стороны = " << sq->getsizedge();
			}
			if (type == 3)
			{
				cout << "Центр x = " << rect->getx() << " Центр y = " << rect->gety() << " Ширина = " << rect->getwidth() << " Длина = " << rect->getheight();
			}
			if (turnon == 1)
			{
				cout << " Градус поворота: " << povor;
			}
			cout << endl;
			break;
		}
		case'5':
		{
			delete[] okenter;
			exit(0);
		}
		case'6':
		{
			delete[] okenter;
			system("cls");
			main(okenter, enter);
		}
		default:
		{
			povor = 0;
			cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
			break;
		}
		}
	}

}

void ErrorView()
{
	if (Numerror == true)
	{
		cout << "Некорректный ввод. Уменьшаемая величина не должна быть меньше значения уменьшения!" << endl;
		Numerror = false;
	}
}