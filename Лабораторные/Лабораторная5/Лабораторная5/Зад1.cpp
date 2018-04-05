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
	cout << "�������� ������: 1 - ����, 2 - �������, 3 - �������������" << endl;
}
void Figure::Input()
{
	switch (_getch())
		{
	
		case '1' :
		{
			cout << endl; cout << "������� ��������� �����" << endl;
			cout << "������ = ";
			cin >> centerx;
			cout << "�����Y = ";
			cin >> centery;
			cout << "r=";
			cin >> rad;
			cout << endl;
			type = 1;
			break;
		}
		case '2' :
		{
			cout << endl; cout << "������� ��������� �������� " << endl;
			cout << "���������� ������: " << endl;
			cout << "������ = ";
			cin >> centerx;
			cout << "�����Y = ";
			cin >> centery;
			cout << "������ �� ������ �� �������:" << endl;
			cout << "vecx= ";
			cin >> vecx;
			cout << "vecy= ";
			cin >> vecy;
			type = 2;
			break;
		}
		case '3' :
		{
			cout << endl; cout << "������� ��������� ��������������"; cout << endl;
			cout << "���������� ������:" << endl;
			cout << "������ = ";
			cin >> centerx;
			cout << "�����Y = ";
			cin >> centery;
			cout << "������ �� ������ �� �������:\n";
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
	cout << "��������� ������";
	cout << endl;
	if (type == 1)
	{
		cout << endl; cout << "������=" << centerx << " �����Y=" << centery << " r=" << rad;
		cout << endl;
	}
	if (type == 2)
	{
		cout << endl;
		cout << "������=" << centerx << " �����Y=" << centery << " ax=" << vecx << " ay=" << vecy;
		cout << endl; cout << endl;
	}
	if (type == 3)
	{
		cout << endl;
		cout << "������=" << centerx << " �����Y=" << centery << " ax=" << vecx << " ay=" << vecy;
		cout << endl;
	}
}
void Figure::Move()
{
	int Movex, Movey;
	cout << "������� ���������� �������� ������ ";
	cout << endl;
	cout << "�������� �� X= "; 
	cin >> Movex;
	cout << "�������� �� Y= "; 
	cin >> Movey;
	centerx = centerx + Movex; centery = centery + Movey;
	vecx = vecx + Movex; vecy = vecy + Movey;
	
}
void Figure::Size()
{
	double k;
	if (type == 1)
	{
		cout << "����������� ��������� ������� �����= ";
		cout << endl;
		cin >> k;
		rad = rad*k;
	}
	if (type == 2 || type == 3)
	{
		cout << "����������� ��������� ���������� �� ������� ";

		if(type == 2)
		{
			cout << "��������= ";
		}
		if (type==3)
		{
			cout << "��������������= ";
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
	cout << "������� ���� �������� ������: ";
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
	cout << "�������� ��������:" << endl;
	cout << "1 - ��������� �������" << endl;
	cout << "2 - ����� ������" << endl;
	cout << "3 - ������� ������" << endl;
	cout << "4 - ������� ��������� ������" << endl;
	cout << "X - �����" << endl;
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