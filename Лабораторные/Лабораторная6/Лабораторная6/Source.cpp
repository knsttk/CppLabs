#include<iostream>
#include <conio.h>
#include<windows.h>

using namespace std;


class Complex
{
private:
	double real, imag;

public:


	Complex()
	{

		this->real = 0;
		this->imag = 0;
	}

	Complex(const Complex &other)
	{
		this->real = other.real;
		this->imag = other.imag;
	}

	Complex & operator = (Complex &other)
	{
		this->real = other.real;
		this->imag = other.imag;
		return *this;
	}

	void Set()
	{
		double Re, Im;
		cout << "Введите целую часть : ";
		cin >> Re;
		cout << "Введите мнимую часть : ";
		cin >> Im;
		this->real = Re;
		this->imag = Im;
	}

	Complex operator + (const Complex &other)
	{
		Complex temp;
		temp.real = this->real + other.real;
		temp.imag = this->imag + other.imag;
		return temp;
	}

	Complex operator - (const Complex &other)
	{
		Complex temp;
		temp.real = this->real - other.real;
		temp.imag = this->imag - other.imag;
		return temp;
	}

	Complex operator * (const Complex &other)
	{
		Complex temp;
		temp.real = this->real * other.real - this->imag * other.imag;
		temp.imag = this->real * other.imag + this->imag * other.real;
		return temp;

	}

	friend ostream &operator<<(ostream &out, Complex &n)

	{
		out << "Результат : " << n.real << " + " << n.imag << " * i" << endl;
		return out;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Complex a, b, z;
	bool end = false;
	while (end == false)
	{                  
		cout << "Работа с комплексными числами." << endl;
		cout << " ____________________________________________ " << endl;
		cout << "1.Задать комплексное число" << endl;
		cout << "2.Сложение" << endl;
		cout << "3.Вычитание" << endl;
		cout << "4.Умножение" << endl;
		cout << "5.Выход" << endl;
		cout << " ____________________________________________ " << endl;

		switch (_getch())
		{
		case '1':
		{
			cout << "Первое число." << endl;
			a.Set();
			cout << endl;
			cout << "Второе число." << endl;
			b.Set();
			break;
		}

		case '2':
		{
			z = a + b;
			cout << z;

			break;
		}

		case '3':
		{
			z = a - b;
			cout << z;

			break;
		}

		case '4':
		{
			z = a * b;
			cout << z;

			break;
		}

		case '5':
		{
			cout << "Выход..." << endl;
			Sleep(2000);
			end = true;
			break;
		}

		default:
		{
			cout << "Некорректный ввод. Введите ещё раз." << endl;
			break;
		}

		}
	}
}