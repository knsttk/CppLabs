<<<<<<< HEAD
﻿#include <iostream>
#include <conio.h>

using namespace std;

class Circle
{
public:
	double  rad, change, x, y;

	void Size(double change)
	{
			rad += change;
	}
	void Move(double movex, double movey)
	{
		x += movex;
		y += movey;
	}

};
class Square
{

public:
	double x, y, sizedge, degree;

	void Size(double change)
	{
			sizedge += change;
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
public:
	double x, y, height, width;
	void Size(short choose2, double change)
	{
		
			if (choose2 == 1)
			{
				width += change;
			}
			if (choose2 == 2)
			{
				height += change;
			}
			if (choose2 == 3)
			{
				width += change;
				height += change;
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
				cout << "Введите координаты: " << endl;
				cout << "Центр X: ";
				cin >> cir.x;
				cout << "Центр Y: ";
				cin >> cir.y;
				cout << "Введите радиус: ";
				cin >> cir.rad;
				check = true;
				break;
			}
			case '2':
			{
				type = 2;
				cout << "Введите координаты: " << endl;
				cout << "Центр X: ";
				cin >> sq.x;
				cout << "Центр Y: ";
				cin >> sq.y;
				cout << "Введите длину стороны: ";
				cin >> sq.sizedge;
				check = true;
				break;
			}
			case '3':
			{
				type = 3;
				cout << "Введите координаты: " << endl;
				cout << "Центр X: ";
				cin >> rect.x;
				cout << "Центр Y: ";
				cin >> rect.y;
				cout << "Введите ширину: ";
				cin >> rect.width;
				cout << "Введите длину: ";
				cin >> rect.height;
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
=======
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
	~Circle()
	{
		return;
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
	~Square()
	{
		return;
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
	~Rectan()
	{
		return;
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
>>>>>>> master
						switch (_getch())
						{
						case '1':
						{
<<<<<<< HEAD
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
								if (choose == 1)
								{
									if (change > cir.rad)
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
									change /= -1;
								}
							
								cir.Size(change);
							}
							if (type == 2)
							{
								if (choose == 1)
								{
									if (change > sq.sizedge)
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
									change /= -1;
								}
								sq.Size(change);
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
									if (choose == 1)
									{
										if (change > rect.width)
										{
											cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
											continue;
										}
										change /= -1;
									}
									rect.Size(choose2, change);
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
								if (choose == 1)
								{
									if (change > rect.height)
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
									change /= -1;
								}
								rect.Size(choose2, change);
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
								if (choose == 1)
								{
									if (change > rect.width || change > rect.height)
									{
										cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
										continue;
									}
									change /= -1;
								}
								rect.Size(choose2, change);
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
					cout << "Центр x = " << cir.x << " Центр y = " << cir.y << " Радиус = " << cir.rad;
				}
				if (type == 2)
				{
					cout << "Центр x = " << sq.x << " Центр y = " << sq.y << " Длина стороны = " << sq.sizedge;
				}
				if (type == 3)
				{
					cout << "Центр x = " << rect.x << " Центр y = " << rect.y << " Ширина = " << rect.width << " Длина = " << rect.height;
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
=======
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
>>>>>>> master
