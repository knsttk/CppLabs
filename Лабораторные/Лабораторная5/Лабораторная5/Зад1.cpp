#include <iostream>
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
