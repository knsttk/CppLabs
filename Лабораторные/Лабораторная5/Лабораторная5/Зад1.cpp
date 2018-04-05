#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

class Figure {
	double vecx, vecy, axn, ayn, axn1, axn2, ayn1, ayn2, centerx, centery;
	double rad;
	int type;
public:
	void Menu();
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
	geom.Menu();
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
			cout << "ЦентрХ = ";
			cin >> centerx;
			cout << "ЦентрY = ";
			cin >> centery;
			cout << "r=";
			cin >> rad;
			cout << endl;
			type = 1;
			break;
		}
		case '2' :
		{
			cout << endl; cout << "Введите параметры квадрата " << endl;
			cout << "Координаты центра: " << endl;
			cout << "ЦентрХ = ";
			cin >> centerx;
			cout << "ЦентрY = ";
			cin >> centery;
			cout << "Вектор от центра до вершины:" << endl;
			cout << "vecx= ";
			cin >> vecx;
			cout << "vecy= ";
			cin >> vecy;
			type = 2;
			break;
		}
		case '3' :
		{
			cout << endl; cout << "Введите параметры прямоугольника"; cout << endl;
			cout << "Координаты центра:" << endl;
			cout << "ЦентрХ = ";
			cin >> centerx;
			cout << "ЦентрY = ";
			cin >> centery;
			cout << "Вектор от центра до вершины:\n";
			cout << "vecx= ";
			cin >> vecx;
			cout << "vecy= ";
			cin >> vecy;
			type = 3;
			
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
	cout << "Смещение по X= "; 
	cin >> Movex;
	cout << "Смещение по Y= "; 
	cin >> Movey;
	centerx = centerx + Movex; centery = centery + Movey;
	vecx = vecx + Movex; vecy = vecy + Movey;
	
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
	if (type == 2 || type == 3)
	{
		cout << "Коэффициент изменения расстояния до вершины ";

		if(type == 2)
		{
			cout << "квадрата= ";
		}
		if (type==3)
		{
			cout << "прямоугольника= ";
		}
		
		cout << endl;
		cin >> k;
		vecx = vecx - centerx;
		vecx = vecy - centery;
		vecx = vecx*k;
		vecy = vecy*k;
		vecx = vecx + centerx;
		vecy = vecy + centery;
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
		
	}
void Figure::Menu()
{
	cout << "Выберите действие:" << endl;
	cout << "1 - Изменение размера" << endl;
	cout << "2 - Сдвиг Фигуры" << endl;
	cout << "3 - Поворот фигуры" << endl;
	cout << "4 - Текущие параметры фигуры" << endl;
	cout << "X - Выход" << endl;
	switch (_getch())
	{
	case '1' :
	{
		system("cls");
		Size();
		Menu();
	}
	case '2' :
	{
		system("cls");
		Move();
		Menu();
	}
	case '3':
	{
		system("cls");
		Turn();
		Menu();
	}
	case '4':
	{
		system("cls");
		Separate();
		Output();
		Separate();
		Menu();
	}
	case 'x':
	{
		system("cls");
		exit(0);
	}
	default:
	{
		cout << "Incorrect input. Try Again." << endl;
		_getch();
		system("cls");
		Menu();
	}
		break;
	}
}