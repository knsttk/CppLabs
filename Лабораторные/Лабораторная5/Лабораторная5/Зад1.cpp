#include <iostream>
#include <conio.h>

using namespace std;

class Circle
{
	double  rad, change, x, y;
public:	
	double outx, outy, outrad;
	void Set()
	{
		cout << "Введите координаты: " << endl;
		cout << "Центр X: ";
		cin >> x;
		cout << "Центр Y: ";
		cin >> y;
		cout << "Введите радиус: ";
		cin >> rad;
	}
	
	void Size(double change, short choose)
	{
			if (choose == 1)
			{
				if (change > rad)
				{
					cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
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
	void Output()
	{
		outx = x;
		outy = y;
		outrad = rad;
	}

};
class Square
{
	double x, y, sizedge, degree;
public:
	double outx, outy, outsizedge;
	void Set()
	{
		cout << "Введите координаты: " << endl;
		cout << "Центр X: ";
		cin >> x;
		cout << "Центр Y: ";
		cin >> y;
		cout << "Введите длину стороны: ";
		cin >> sizedge;
	}
	void Size(double change, short choose)
	{

		if (choose == 1)
		{
			if (change > sizedge)
			{
				cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
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
	void Output()
	{

		outx = x;
		outy = y;
		outsizedge = sizedge;
	}
};
class Rectan
{
	double x, y, height, width;
public:
	double outx, outy, outwidth, outheight;
	void Set()
	{
		cout << "Введите координаты: " << endl;
		cout << "Центр X: ";
		cin >> x;
		cout << "Центр Y: ";
		cin >> y;
		cout << "Введите ширину: ";
		cin >> width;
		cout << "Введите длину: ";
		cin >> height;
	}
	void Size(short choose2, double change, short choose)
	{

		if (choose2 == 1)
		{
			if (choose == 1)
			{
				if (change > width)
				{
					cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
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
			{
				if (choose == 1)
				{
					if (change > width)
					{
						cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
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
						cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
						return;
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
	}
	void Move(double movex, double movey)
	{
		x += movex;
		y += movey;
	}
	void Turn(int degree)
	{

	}
	void Output()
	{

		outx = x;
		outy = y;
		outwidth = width;
		outheight = height;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Circle cir;
	Square sq;
	Rectan rect;
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

			type = 1;
			cir.Set();
			check = true;
			break;
		}
		case '2':
		{
			type = 2;
			sq.Set();
			check = true;
			break;
		}
		case '3':
		{
			type = 3;
			rect.Set();
			check = true;
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
						cin >> change;
						if (type == 1)
						{
							cir.Size(change, choose);
						}
						
						if (type == 2)
						{
							sq.Size(change, choose);
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
				short choose2;
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
					choose = 1;
					cout << "------------------------" << endl;
					cout << "1 - Уменьшить ширину." << endl;
					cout << "2 - Уменьшить длину." << endl;
					cout << "3 - Уменьшить и ширину и длину." << endl;
					cout << "------------------------" << endl;
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
						cin >> change;
						
						rect.Size(choose2, change, choose2);
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
						cin >> change;
						rect.Size(choose2, change, choose);
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
						cin >> change;
						rect.Size(choose2, change, choose);
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
			cout << "По X :";
			cin >> movex;
			cout << "По Y :";
			cin >> movey;
			if (type == 1)
			{
				cir.Move(movex, movey);
			}
			if (type == 2)
			{
				sq.Move(movex, movey);
			}
			if (type == 3)
			{
				rect.Move(movex, movey);
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
				cout << "Повернуть на: ";
				cin >> degree;
				if (type == 2)
				{
					sq.Turn(degree);
				}
				if (type == 3)
				{
					rect.Turn(degree);
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
			cir.Output();
				cout << "Центр x = " << cir.outx << " Центр y = " << cir.outy << " Радиус = " << cir.outrad;
			}
			if (type == 2)
			{
				sq.Output();
				cout << "Центр x = " << sq.outx << " Центр y = " << sq.outy << " Длина стороны = " << sq.outsizedge;
			}
			if (type == 3)
			{
				rect.Output();
				cout << "Центр x = " << rect.outx << " Центр y = " << rect.outy << " Ширина = " << rect.outwidth << " Длина = " << rect.outheight;
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
			exit(0);

		}
		case'6':
		{
			system("cls");
			main();
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
