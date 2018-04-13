#include <iostream>
#include <conio.h>
using namespace std;

class Figure
{
public:

	virtual void Create()
	{

	}
	virtual void Move()
	{

	}
	virtual void Size()
	{

	}
	virtual void Output()
	{

	}
	virtual void Turn()
	{

	}
protected:
	int x, y, rad, movex, movey, drad;
};
class Circle : public Figure
{
	void Create()
	{
		cout << "Введите координаты центра: " << endl;
		cout << "Центр X = ";
		cin >> x;
		cout << "Центр Y = ";
		cin >> y;
		cout << "Введите радиус" << endl;
		cout << "Радиус = ";
		cin >> rad;
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
		cout << "2 - Уменьшить." << endl;
		switch (_getch())
		{
		case '1':
		{
			cout << "Увеличить на: ";
			cin >> drad;
			rad += drad;
			break;
		}
		case'2':
		{
			temp = false;
			while (temp == false)
			{
				cout << "Уменьшить на: ";
				cin >> drad;
				if (drad > rad)
				{
					cout << "Некорректный ввод, уменьшаемая величина должна быть больше значения уменьшения." << endl;
					continue;
				}
				rad -= drad;
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
		cout << "Введите координаты центра: " << endl;
		cout << "Центр X = ";
		cin >> x;
		cout << "Центр Y = ";
		cin >> y;
		cout << "Введите длину стороны: " << endl;
		cout << "Длина стороны = ";
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
		double degree, co, si, axn1, axn2, ayn1, ayn2, axn, ayn;

		cout << "Введите угол поворота фигуры: ";
		cin >> degree;
		degree = degree* 3.1415 / 180;

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
		cout << "Введите координаты центра: " << endl;
		cout << "Центр X = ";
		cin >> x;
		cout << "Центр Y = ";
		cin >> y;
		cout << "Введите ширину:" << endl;
		cout << "Ширина = ";
		cin >> width;
		cout << "Введите длину:" << endl;
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
		double degree, co, si, axn1, axn2, ayn1, ayn2, axn, ayn;

		cout << "Введите угол поворота фигуры: ";
		cin >> degree;
		degree = degree* 3.1415 / 180;

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
	int next = -1;
	Circle *c = new Circle;
	Figure *cir = c;
	Square *s = new Square;
	Figure *sq = s;
	Rectan *r = new Rectan;
	Figure *rect = r;
	bool check = false;
	int type;
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
				next++;
				cir = c;
				F[next] = cir;
				check = true;
				break;
			}
			case '2':
			{
				type = 2;
				next++;
				sq = s;
				F[next] = sq;
				check = true;
				break;
			}
			case '3':
			{
				type = 3;
				next++;
				rect = r;
				F[next] = rect;
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
		F[next]->Create();
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
				F[next]->Size();
				F[next]->Output();
				break;
			}
			case'2':
			{
				type2 = 2;
				cout << "Сдвинуть на: " << endl;
				cout << "По X и Y ";
				F[next]->Move();
				F[next]->Output();
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
					F[next]->Turn();
					break;
				}
			}
			case '4':
			{
				F[next]->Output();
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