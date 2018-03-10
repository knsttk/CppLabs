#include <iostream>
#include <math.h>
#include <conio.h>
#include <cctype>
using namespace std;

class Figure {
	double vecx, vecy, axn, ayn, axn1, axn2, ayn1, ayn2, centerx, centery;
	double rad;
	int type;
public:
	void Choose();
	void Input();
	void Move();
	void Size();
	void Turn();
	void Output();
	void Separate();
};
void main()
{
	setlocale(LC_ALL, "Russian");
	Figure geom;
	system("cls");
	geom.Choose();
	geom.Input();
	geom.Move();
	geom.Size();
	geom.Turn();
	_getch();
}
void Figure:: Separate()
{
	cout << "==========================================" << endl;
}
void Figure::Choose()
{
	cout << "Выберите фигуру: 1 - Круг, 2 - Квадрат, 3 - Прямоугольник" << endl;
}
void Figure::Input()
{
	switch (_getch())
		{
	
		case '1' :
		{
			cout << endl; cout << "Введите параметры круга" << endl;
			cout << "ЦентрХ=";
			cin >> centerx;
			cout << "ЦентрY=";
			cin >> centery;
			cout << "r=";
			cin >> rad;
			cout << endl;
			type = 1;
			Separate();
			Output();
			Separate();
			break;
		}
		case '2' :
		{
			cout << endl; cout << "Введите параметры квадрата " << endl;
			cout << "Координаты центра: " << endl;
			cout << "ЦентрХ = ";
			cin >> centerx;
			cout << "ЦентрY=";
			cin >> centery;
			cout << "Вектор от центра до вершины:" << endl;
			cout << " ax=";
			cin >> vecx;
			cout << " ay=";
			cin >> vecy;
			type = 2;
			Separate();
			Output();
			Separate();
			break;
		}
		case '3' :
		{
			cout << endl; cout << "Введите параметры прямоугольника"; cout << endl;
			cout << "Координаты центра:" << endl;
			cout << "ЦентрХ = ";
			cin >> centerx;
			cout << "ЦентрY= ";
			cin >> centery;
			cout << "Вектор от центра до вершины:\n";
			cout << " ax=";
			cin >> vecx;
			cout << " ay=";
			cin >> vecy;
			type = 3;
			Separate();
			Output();
			Separate();
			break;
		}
		default :
		{
			cout << "Incorrect input. Try Again." << endl;
			_getch();
			system("cls");
			Choose();
			Input();
			break;
		}
	}
}
void Figure::Output()
{
	cout << "Параметры фигуры";
	cout << endl;
	if (type == 1)
	{
		cout << endl; cout << "ЦентрХ=" << centerx << " ЦентрY=" << centery << " r=" << rad;
		cout << endl;
	}
	if (type == 2)
	{
		cout << endl;
		cout << "ЦентрХ=" << centerx << " ЦентрY=" << centery << " ax=" << vecx << " ay=" << vecy;
		cout << endl; cout << endl;
	}
	if (type == 3)
	{
		cout << endl;
		cout << "ЦентрХ=" << centerx << " ЦентрY=" << centery << " ax=" << vecx << " ay=" << vecy;
		cout << endl;
	}
}
void Figure::Move()
{
	int Movex, Movey;
	cout << "Введите координаты смещения фигуры ";
	cout << endl;
	cout << "Смещение по X= "; cin >> Movex;
	cout << "Смещение по Y= "; cin >> Movey;
	centerx = centerx + Movex; centery = centery + Movey;
	vecx = vecx + Movex; vecy = vecy + Movey;
	Separate();
	Output();
	Separate();
}
void Figure::Size()
{
	double k;
	if (type == 1)
	{
		cout << "Коэффициент изменения радиуса круга= ";
		cout << endl;
		cin >> k;
		rad = rad*k;
	}
	if (type == 2)
	{
		cout << "Коэффициент изменения расстояния до вершины квадрата= ";
		cout << endl;
		cin >> k;
		vecx = vecx - centerx;
		vecx = vecy - centery;
		vecx = vecx*k;
		vecy = vecy*k;
		vecx = vecx + centerx;
		vecy = vecy + centery;
	}
	if (type == 3)
	{
		cout << "Коэффициент изменения расстояния до вершины прямоугольника= ";
		cout << endl;
		cin >> k;
		vecx = vecx - centerx;
		vecy = vecy - centery;
		vecx = vecx*k;
		vecy = vecy*k;
		vecx = vecx + centerx;
		vecy = vecy + centery;
	}
	if (type != 1)
	{
		Separate();
		Output();
		Separate();
	}
}
void Figure::Turn()
{
	if (type == 1)
	{
		return;
	}
	double degree, co, si;
	cout << "Введите угол поворота фигуры: ";
	cin >> degree;
		degree = degree* 3.1415 / 180;
		if (type == 2 || type == 3)
		{
			vecx = vecx - centerx;
			vecy = vecy - centery;
			co = cos(degree);
			si = sin(degree);
			axn1 = vecx*co;
			axn2 = vecy*si;
			axn = axn1 - axn2;
			ayn1 = vecx*si;
			ayn2 = vecy*co;
			ayn = ayn1 + ayn2;
			vecx = axn + centerx;
			vecy = ayn + centery;
		}
		Separate();
		Output();
		Separate();
	}
