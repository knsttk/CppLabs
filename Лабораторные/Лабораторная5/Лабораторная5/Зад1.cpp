#include <iostream>
#include <conio.h>

using namespace std;

struct  Output
{
	const double *x, *y, *rad, *degree, *height, *sizedge, *width;
};
class Figure
{
public:
	virtual void Move(double movex, double movey)
	{

	}
	virtual void Size(short choose, short choose2, double change, double change2)
	{

	}
	virtual void Turn(double degree)
	{

	}
};
class Circle : public Figure
{
public:
	double  rad, change, x, y;
	Circle(double x, double y, double rad)
	{
		this->x = x;
		this->y = y;
		this->rad = rad;
	}
	void Size(short choose, short choose2, double change, double change2)
	{
		if (choose == 1)
		{
			rad += change;

		}
		if (choose == 2)
		{
			rad -= change;
		}
	}
	void Move(double movex, double movey)
	{
		x += movex;
		y += movey;
	}
	Output output()
	{
		Output o;
		o.x = &(this->x);
		o.y = &(this->y);
		o.rad = &(this->rad);
		return o;
	}
};
class Square : public Figure
{

public:
	double x, y, sizedge, degree;
	Square(double x, double y, double sizedge)
	{
		this->x = x;
		this->y = y;
		this->sizedge = sizedge;
	}

	void Size(short choose, short choose2, double change, double change2)
	{
		if (choose == 1)
		{
			sizedge += change;

		}
		if (choose == 2)
		{
			sizedge -= change;
		}
	}

	void Move(double movex, double movey)
	{
		x += movex;

		y += movey;
	}

	void Turn(double degree)
	{
		this->degree = degree;
	}
	Output output()
	{
		Output o;
		o.x = &(this->x);
		o.y = &(this->y);
		o.sizedge = &(this->sizedge);
		return o;
	}
};
class Rectan : public Figure
{
	double x, y, movex, movey, height, width, change, change2, degree;
public:
	Rectan(double x, double y, double height, double width)
	{
		this->x = x;
		this->y = y;
		this->height = height;
		this->width = width;
	}
	void Size(short choose, short choose2, double change, double change2)
	{
		if (choose == 1)
		{
			if (choose2 == 1)
			{
				width += change;
			}
			if (choose2 == 2)
			{
				height += change2;
			}
			if (choose2 == 3)
			{
				width += change;
				height += change;
			}
		}
		if (choose == 2)
		{
			if (choose2 == 1)
			{
				width -= change;
			}
			if (choose2 == 2)
			{
				height -= change2;
			}
			if (choose2 == 3)
			{
				width -= change;
				height -= change;
			}
		}
	}
	void Move(double movex, double movey)
	{
		x += movex;
		y += movey;
	}
	void Turn(double degree)
	{
		this->degree = degree;
	}
	Output output()
	{
		Output o;
		o.x = &(this->x);
		o.y = &(this->y);
		o.width = &(this->width);
		o.height = &(this->height);
		return o;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Figure **F = new Figure *[10];
	Circle *c = new Circle(0, 0, 0);
	Figure *cir = c;
	Square *s = new Square(0, 0, 0);
	Figure *sq = s;
	Rectan *r = new Rectan(0, 0, 0, 0);
	Figure *rect = r;
	bool check = false;
	double  x, y, rad, sizedge, movex, movey, height, width, degree;
	short type;

	bool temp, temp2;
	Output rez;
	while (1)
	{
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
				cir = c;
				F[type] = cir;
				check = true;
				break;
			}
			case '2':
			{
				type = 2;
				sq = s;
				F[type] = sq;
				check = true;
				break;
			}
			case '3':
			{
				type = 3;
				rect = r;
				F[type] = rect;
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
		if (type == 1)
		{
			cout << "Введите координаты: " << endl;
			cout << "Центр X: ";
			cin >> x;
			cout << "Центр Y: ";
			cin >> y;
			cout << "Введите радиус: ";
			cin >> rad;
			*c = Circle(x, y, rad);
			rez = c->output();
		}
		if (type == 2)
		{
			cout << "Введите координаты: " << endl;
			cout << "Центр X: ";
			cin >> x;
			cout << "Центр Y: ";
			cin >> y;
			cout << "Введите длину стороны: ";
			cin >> sizedge;
			*s = Square(x, y, sizedge);
			rez = s->output();

		}
		if (type == 3)
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
			*r = Rectan(x, y, width, height);
			rez = r->output();
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
					short choose = 0;
					short choose2 = 0;
					double change = 0;
					double change2 = 0;
					if (type == 1 || type == 2)
					{
						cout << "1 - Увеличить." << endl;
						cout << "2 - Уменьшить." << endl;

						switch (_getch())
						{
						case '1':
						{
							choose = 1;
							cout << "Увеличить на: ";
							cin >> change;
							F[type]->Size(choose, choose2, change, change2);
							temp = true;
							break;
						}

						case '2':
						{
							choose = 2;
							while (temp2 == false)
							{
								cout << "Уменьшить на: ";
								cin >> change;
								if (type == 1)
								{
									if (change > *(rez.rad))
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
								}
								else
								{
									if (change > *(rez.sizedge))
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
								}
								F[type]->Size(choose, choose2, change, change2);
								temp2 = true;
							}
							break;
						}

						default:
						{
							cout << "Некорректный ввод. Введите ещё раз." << endl;
							break;
						}

						}
						break;
					}
					if(type == 3)
					{

						cout << "1 - Увеличить" << endl;
						cout << "2 - Уменьшить" << endl;
						switch (_getch())
						{
						case '1':
						{
							choose = 1;
							cout << "------------------------" << endl;
							cout << "1 - Увеличить ширину." << endl;
							cout << "2 - Увеличить длину." << endl;
							cout << "3 - Увеличить и ширину и длину." << endl;
							cout << "------------------------" << endl;
							switch (_getch())
							{
							case'1':
							{
								choose2 = 1;
								cout << "Увеличить ширину на ";
								change = 0;
								cin >> change;
								F[type]->Size(choose, choose2, change, change2);
								temp = true;
								break;
							}
							case '2':
							{
								choose2 = 2;
								cout << "Увеличить длину на ";
								change2 = 0;
								cin >> change2;
								F[type]->Size(choose, choose2, change, change2);
								temp = true;
								break;

							}
							case '3':
							{
								choose2 = 3;
								cout << "Увеличить и ширину и длину на ";
								change = 0;
								cin >> change;
								F[type]->Size(choose, choose2, change, change2);
								temp = true;
								break;
							}
							default:
							{
								cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
								_getch();
								F[type]->Size(change, choose2, change2, change2);
								temp = true;
								break;
							}
							}
							break;
						}
						case'2':
						{
							choose = 2;
							cout << "------------------------" << endl;
							cout << "1 - Уменьшить ширину." << endl;
							cout << "2 - Уменьшить длину." << endl;
							cout << "3 - Уменьшить и ширину и длину." << endl;
							cout << "------------------------" << endl;
							switch (_getch())
							{
							case'1':
							{
								bool temp2;
								choose2 = 1;
								temp2 = false;
								while (temp2 == false)
								{
									cout << "Уменьшить ширину на ";
									change = 0;
									cin >> change;
									if (change > *(rez.width))
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
									F[type]->Size(choose, choose2, change, change2);
									temp2 = true;
								}
								temp = true;
								break;

							}
							case '2':
							{
								choose2 = 2;
								temp2 = false;
								while (temp2 == false)
								{
									cout << "Уменьшить длину на ";
									change2 = 0;
									cin >> change2;
									if (change2 > *(rez.height))
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
									F[type]->Size(choose, choose2, change, change2);
									temp2 = true;
									break;
								}
								temp = true;
								break;
							}
							case '3':
							{
								choose2 = 3;
								temp2 = false;
								while (temp2 == false)
								{
									cout << "Уменьшить и ширину и длину на ";
									change = 0;
									cin >> change;
									if (change > *(rez.height) || change > *(rez.width))
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
									F[type]->Size(choose, choose2, change, change2);
									temp2 = true;
								}
								temp = true;
								break;
							}
							default:
							{
								cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
								_getch();
								F[type]->Size(choose, choose2, change, change2);
							}
							}
							break;
						}
						default:
						{
							cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
							_getch();
							F[type]->Size(choose, choose2, change, change2);
							break;
						}
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
				F[type]->Move(movex, movey);
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
					F[type]->Turn(degree);
					cout << "Фигура была повёрнута на " << degree << " градусов." << endl;
					turnon = 1;
					break;
				}
			}
			case'4':
			{
				if (type == 1)
				{
					cout << "Центр x = " << *(rez.x) << " Центр y = " << *(rez.y) << " Радиус = " << *(rez.rad);
					
				}
				if (type == 2)
				{
					cout << "Центр x = " << *(rez.x) << " Центр y = " << *(rez.x) << " Длина стороны = " << *(rez.sizedge);
				}
				if (type == 3)
				{
					cout << "Центр x = " << *(rez.x) << " Центр y = " << *(rez.y) << " Длина = " << *(rez.height) << " Ширина = " << *(rez.width);
				}
				if (turnon == 1)
				{
					cout << " Градус поворота: " << degree;
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
				cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
				break;
			}
			}
		}
	}
}