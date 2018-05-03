#include <iostream>
#include <conio.h>
using namespace std;

class Figure
{
public:
	virtual void Move()
	{

	}
	virtual void Size(short choose)
	{

	}
	virtual void Turn()
	{

	}
};
class Circle : public Figure
{
public:
	int  rad, drad, x, y, movex, movey;

	void Size(short choose, Circle &obj)
	{
		if (choose == 1)
		{
			rad += drad;
			cout << rad << "+" << drad << endl;
		}
		if (choose == 2)
		{
			rad -= drad;
		}
	}
	void Move()
	{
		cin >> movex;
		cin >> movey;
		x += movex;
		y += movey;
	}
	void Output()
	{
		cout << "Центр x = " << x << " Центр y = " << y << " Радиус = " << rad << endl;
	}
};
class Square : public Figure
{
	int x, y, movex, movey, edge, sizedge;
public:
	void Create()
	{
		cin >> x;
		cin >> y;
		cin >> edge;
	}

	void Move()
	{
		cin >> movex;
		cin >> movey;
		x += movex;
		y += movey;
	}
	void Size()
	{
		bool temp;
		cout << "Увеличить или уменьшить фигуру?" << endl;
		cout << "1 - Увеличить." << endl;
		cout << "2 - Уменьшить" << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "Увеличить на: ";
			cin >> sizedge;
			edge += sizedge;
			break;
		}
		case'2':
		{
			temp = false;
			while (temp == false)
			{
				cout << "Уменьшить на: ";
				cin >> sizedge;
				if (sizedge > edge)
				{
					cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
					continue;
				}
				edge -= sizedge;
				temp = true;
			}
			break;
		}
		default:
		{
			cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
			_getch();
			system("cls");
			Size();
		}
		break;
		}
	}
	void Turn()
	{
		double degree, co, si, axn1, axn2, ayn1, ayn2, axn, ayn, povorot;

		cout << "Введите угол поворота фигуры: ";
		cin >> povorot;
		degree = povorot * 3.1415 / 180;

		edge = edge - x;
		edge = edge - y;
		co = cos(degree);
		si = sin(degree);
		axn1 = edge*co;
		axn2 = edge*si;
		axn = axn1 - axn2;
		ayn1 = edge*si;
		ayn2 = edge*co;
		ayn = ayn1 + ayn2;
		edge = axn + x;
		edge = ayn + y;

		cout << "Фигура повернута на " << povorot << " градусов." << endl;
	}
	void Output()
	{
		cout << "Центр x = " << x << " Центр y = " << y << " Длина стороны = " << edge << endl;
	}
};
class Rectan : public Figure
{
	int x, y, movex, movey, height, width, sheight, swidth, perim, x1, x2, y1, y2;
public:
	void Create()
	{
		cin >> x;
		cin >> y;
		cin >> width;
		cin >> height;
		x1 = x - width / 2;
		x2 = x - width / 2;
		y1 = y - height / 2;
		y2 = y - height / 2;
	}
	void Move()
	{
		cin >> movex;
		cin >> movey;
		x += movex;
		y += movey;
		x1 += movex;
		x2 += movex;
		y1 += movey;
		y2 += movey;
	}
	void Size()
	{
		cout << "1 - Увеличить размер." << endl;
		cout << "2 - Уменьшить размер." << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "1 - Увеличить ширину." << endl;
			cout << "2 - Увеличить длину." << endl;
			cout << "3 - Увеличить и ширину и длину." << endl;
			switch (_getch())
			{
			case'1':
			{
				cout << "Увеличить ширину на ";
				cin >> swidth;
				width += swidth;
				break;
			}
			case '2':
			{

				cout << "Увеличить длину на ";
				cin >> sheight;
				height += sheight;
				break;

			}
			case '3':
			{
				cout << "Увеличить и ширину и длину на";
				cin >> sheight;
				height += sheight;
				width += swidth;
				break;
			}
			default:
			{
				cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
				_getch();
				system("cls");
				Size();
			}
			}
			break;
		}
		case'2':
		{
			bool temp;
			cout << "1 - Уменьшить ширину." << endl;
			cout << "2 - Уменьшить длину." << endl;
			cout << "3 - Уменьшить и ширину и длину." << endl;
			switch (_getch())
			{
			case'1':
			{
				temp = false;
				while (temp == false)
				{
					cout << "Уменьшить ширину на ";
					cin >> swidth;
					if (swidth > width)
					{
						cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
						continue;
					}
					width -= swidth;
					temp = true;
				}
				break;
			}
			case '2':
			{
				temp = false;
				while (temp == false)
				{
					cout << "Уменьшить длину на ";
					cin >> sheight;
					if (sheight > height)
					{
						cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
						continue;
					}
					height -= sheight;
					temp = true;
				}
				break;
			}
			case '3':
			{
				temp = false;
				while (temp == false)
				{
					cout << "Уменьшить и ширину и длину на ";

					cin >> sheight;
					if (sheight > height || swidth > width)
					{
						cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
						continue;
					}
					height -= sheight;
					width -= swidth;
					temp = true;
				}
				break;
			}
			default:
			{
				cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
				_getch();
				Size();
			}
			}
		}
		default:
		{
			cout << "Некорректный ввод. Попробуйте ещё раз." << endl;
			_getch();
			system("cls");
			Size();
		}
		break;
		}
	}
	void Turn()
	{
		double degree, co, si, axn1, axn2, ayn1, ayn2, axn, ayn, povorot;

		cout << "Введите угол поворота фигуры: ";
		cin >> povorot;
		degree = povorot* 3.1415 / 180;

		swidth = swidth - x;
		sheight = sheight - y;
		co = cos(degree);
		si = sin(degree);
		axn1 = swidth*co;
		axn2 = sheight*si;
		axn = axn1 - axn2;
		ayn1 = swidth*si;
		ayn2 = sheight*co;
		ayn = ayn1 + ayn2;
		swidth = axn + x;
		sheight = ayn + y;
		cout << "Фигура повернута на " << povorot << " градусов." << endl;
	}

	void Output()
	{
		cout << "Центр x = " << x << " Центр y = " << y << " Длина = " << height << " Ширина = " << width << endl;

	}
};
int main()
{
	setlocale(LC_ALL, "Russian");
	Figure **F = new Figure *[5];
	Circle *c = new Circle;
	Circle obj;
	Figure *cir = c;
	Square *s = new Square;
	Figure *sq = s;
	Rectan *r = new Rectan;
	Figure *rect = r;
	bool check = false;
	short type;
	bool temp, temp2;
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
				cin >> obj.x;
				cout << "Центр Y: ";
				cin >> obj.y;
				cout << "Введите радиус: ";
				cin >> obj.drad;
			}
		if (type == 2)
			{
				cout << "Введите координаты центра по X, Y, и Длину стороны: " << endl;
				
			}
		if (type == 3)
			{
				cout << "Введите координаты центра по X, Y, Ширину, Длину: " << endl;
				
			}
		int type2;
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
				type2 = 1;
				short choose;
				cout << "Увеличить или уменьшить фигуру?" << endl;
				temp = false;
				temp2 = false;
				while (temp == false)
				{
					cout << "1 - Увеличить." << endl;
					cout << "2 - Уменьшить." << endl;
					cin >> choose;
					if (choose == 1)
					{
						cout << "Увеличить на: ";
						cin >> obj.drad;
						F[type]->Size(choose, obj);
						temp = true;
						break;
					}
					if (choose == 2)
					{
						while(temp2 == false)
						{
							cout << "Уменьшить на: ";
							cin >> obj.drad;
							if (obj.drad > obj.rad)
							{
								cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
								continue;
							}
							F[type]->Size(choose, obj);
							temp2 = true;
						}
						break;
					}
					else
					{
						cout << "Некорректный ввод. Введите ещё раз." << endl;
						continue;
					}
				}
				obj.Output();
				break;
			}
			case'2':
			{
				type2 = 2;
				cout << "Сдвинуть на: " << endl;
				cout << "По X и Y ";
				F[type]->Move();
				break;
			}
			case'3':
			{
				type2 = 3;
				if (type == 1)
				{
					cout << endl << "Нет смысла вращать круг. Это же круг!" << endl << endl;
					break;
				}
				else
				{
					cout << "Повернуть на: " << endl;
					F[type]->Turn();
					break;
				}
			}
			case '4':
			{
				obj.Output();
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