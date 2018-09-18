#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;
int get_choose();
bool IntCheck(char* str);
bool FloatCheck(char* str);
bool BoolCheck(char* str);
int get_Int();
float get_Float();
bool get_Bool();
int STRUCTnumget();
void outConsol(char* buf, int length);
void outFile(char* buffer, int length);
union Value
{
	int Valint;
	float Valfloat;
	bool Valbool;
};

enum DATAtype { Int = 1, Float, Bool };

class BaseCl
{
public:
	virtual bool Equals(BaseCl* current) = 0;
	virtual char* ToString(char *buffer, int &i) = 0;
	virtual int getType() { return -1; }

	virtual ~BaseCl()
	{
		delete this;
	}
};
struct ElementDate
{
	Value unionValue;
	DATAtype choose;
};
class Element : public BaseCl
{

	ElementDate elemDt;
public:
	bool Equals(BaseCl* eqls)
	{
		if (this->getType() != eqls->getType())
			return false;
		else
		{
			Element* newEQLS = new Element;
			newEQLS = (Element*)eqls;
			if (newEQLS->elemDt.unionValue.Valint == this->elemDt.unionValue.Valint)
				return true;
			else
				return false;
		}
	}
	char* ToString(char *buffer, int &i)
	{
		switch (this->elemDt.choose)
		{
		case 1:
		{
			char* tempBuf = new char[255];
			_itoa_s(this->elemDt.unionValue.Valint, tempBuf, 255, 10);
			for (int l = 0; l < strlen(tempBuf); l++)
			{
				buffer[i] = tempBuf[l];
				i++;
			}
		}
		break;

		case 2:
		{
			char* tempBuf = new char[255];
			sprintf_s(tempBuf, 255, "%f", this->elemDt.unionValue.Valfloat);

			int newStrlen = strlen(tempBuf);
			int y = strlen(tempBuf) - 1;
			for (y; y > 0; y--)
			{
				if (tempBuf[y] == '0')
				{
					newStrlen--;
				}
				else
				{
					break;
				}
			}
			for (int l = 0; l < newStrlen; l++)
			{
				buffer[i] = tempBuf[l];
				i++;
			}
			delete[] tempBuf;
		}
		break;

		case 3:
		{
			if (this->elemDt.unionValue.Valbool)
			{
				buffer[i] = 't';
				buffer[i + 1] = 'r';
				buffer[i + 2] = 'u';
				buffer[i + 3] = 'e';
				i += 4;
			}
			else
			{
				buffer[i] = 'f';
				buffer[i + 1] = 'a';
				buffer[i + 2] = 'l';
				buffer[i + 3] = 's';
				buffer[i + 4] = 'e';
				i += 5;
			}
		}
		}
		return buffer;
	}


	int getType()
	{
		return 1;
	}
	Value get_Value(DATAtype variant)
	{
		variant = elemDt.choose;
		return elemDt.unionValue;
	}
	void setInt(int i)
	{
		elemDt.unionValue.Valint = i;
		elemDt.choose = DATAtype::Int;
	}
	void setFloat(float i)
	{
		elemDt.unionValue.Valfloat = i;
		elemDt.choose = DATAtype::Float;
	}
	void setBool(bool i)
	{
		elemDt.unionValue.Valbool = i;
		elemDt.choose = DATAtype::Bool;
	}
};
class Container : public BaseCl
{
	int j;
	int length;
	Container* parent = nullptr;
	BaseCl** mas = new BaseCl*[length];
	void MasExpansion()
	{
		length *= 2;
		BaseCl** tempMas = new BaseCl*[length];
		for (int i = 0; i < length / 2; i++)
		{
			tempMas[i] = mas[i];
		}
		mas = tempMas;
		delete[] tempMas;
		delete tempMas;
	}
	int search(Container* cont, BaseCl* eqls)
	{
		int sum = 0;
		int t = cont->getContNum();
		for (int i = 0; i < t; i++)
		{
			if (cont->getMas()[i]->getType() != eqls->getType())
				continue;
			else
			{
				if (!eqls->getType())
				{
					Container* newEQLS = new Container, *secEQLS = new Container;
					newEQLS = (Container*)eqls;
					secEQLS = (Container*)cont->getMas()[i];
					if (newEQLS != secEQLS)
					{
						if (newEQLS->getContNum() == 0)
						{
							(secEQLS->getContNum() == 0) ? sum++ : sum = sum;
						}
						else
						{
							if (newEQLS->getContNum() == secEQLS->getContNum())
							{
								int tempSum = 0;
								for (int k = 0; k < newEQLS->getContNum(); k++)
								{
									tempSum += search(secEQLS, newEQLS->getMas()[k]);
								}
								if (tempSum == newEQLS->getContNum())
									sum++;
							}
							else
								continue;
						}
					}
				}
				else
				{
					Element* newEQLS = new Element, *secEQLS = new Element;
					newEQLS = (Element*)eqls;
					secEQLS = (Element*)cont->getMas()[i];
					DATAtype variant = Int;
					if (newEQLS->get_Value(variant).Valint == secEQLS->get_Value(variant).Valint && newEQLS != secEQLS)
					{
						sum++;
					}
					else
						continue;
					delete newEQLS, secEQLS;
				}
			}
		}
		return sum;
	}
	bool addMas(BaseCl*  eqls)
	{
		if (!search(this, eqls))
		{
			if (j < length)
				mas[j] = (BaseCl*)eqls;
			else
			{
				MasExpansion();
				mas[j] = (BaseCl*)eqls;
			}
			j++;
		}
		else
		{
			return false;
		}
		return true;
	}
public:
	void addContainer()
	{
		Container* newContainer = new Container;
		if (j < length)
		{
			mas[j] = (BaseCl*)newContainer;
			j++;
			newContainer->parent = this;
		}
		else
		{
			MasExpansion();
			mas[j] = (BaseCl*)newContainer;
			j++;
			newContainer->parent = this;
		}
	}
	void addElement(int choose)
	{
		Element* newElem = new Element;
		BaseCl* newEQLS = (BaseCl*)newElem;
		switch (choose)
		{
		case 1:
			newElem->setInt(get_Int());
			addMas(newEQLS);
			break;
		case 2:
			newElem->setFloat(get_Float());
			addMas(newEQLS);
			break;
		case 3:
			newElem->setBool(get_Bool());
			addMas(newEQLS);
			break;
		}
	}

	int getType()
	{
		return 0;
	}
	bool Equals(BaseCl* current)
	{
		if (this->getType() != current->getType())
			return false;
		else
		{
			Container* newEQLS = new Container, *secEQLS = new Container;
			newEQLS = (Container*)current;
			secEQLS = (Container*)this;
			if (newEQLS->getContNum() == secEQLS->getContNum())
			{
				int tempSum = 0;
				for (int i = 0; i < newEQLS->getContNum(); i++)
				{
					tempSum += search(secEQLS, newEQLS->getMas()[i]);
				}

				if (tempSum == newEQLS->getContNum() || newEQLS == secEQLS)
					return true;
				else
					return false;
			}
			else
				return false;
			delete newEQLS, secEQLS;
		}
	}
	char* ToString(char *buffer, int &i)
	{
		buffer[i] = '[';
		i++;
		for (int k = 0; k < j; k++)
		{
			if (k != 0)
			{
				buffer[i] = ',';
				i++;
			}
			if (this->mas[k]->getType())
			{
				Element* newEQLS = (Element*)this->mas[k];
				newEQLS->ToString(buffer, i);
			}
			else
			{
				Container* newEQLS = (Container*)mas[k];
				newEQLS->ToString(*&buffer, i);
			}
		}
		buffer[i] = ']';
		i++;
		return buffer;
	}
	int getContNum()
	{
		return j;
	}
	bool moveDown(Container* &current)
	{
		int i = STRUCTnumget() - 1;
		if (i < j)
		{
			if (!mas[i]->getType())
			{
				current = (Container*)mas[i];
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
		return true;
	}

	bool moveUp(Container* &current)
	{
		if (current->parent != nullptr)
			current = current->parent;
		else
		{
			return false;
		}
		return true;
	}
	BaseCl** getMas()
	{
		return this->mas;
	}
	Container()
	{
		j = 0;
		length = 8;
		parent = nullptr;
	}

	~Container()
	{
		for (int i = 0; i < j; i++)
		{
			delete[] mas[i];
		}
		delete[] mas;
		delete mas;
		delete parent;
	}
};
BaseCl * STRUCTchange(Container* &current)
{
	BaseCl * newCurrent = (BaseCl*)current;
	while (true)
	{
		cout << endl << "3 - Вывести." << endl;
		cout << "5 - Переместиться вниз." << endl;
		cout << "6 - Переместиться вверх." << endl;
		cout << "9 - Выбор." << endl;
		switch (get_choose())
		{
		case 3:
		{
			char* buf = new char[255];
			int i = 0;
			current->ToString(buf, i);
			outConsol(buf, i);
			break;
		}
		case 5:
			current->moveDown(current);
			break;
		case 6:
			current->moveUp(current);
			break;
		case 9:
		{
			short choose2;
			cout << "Введите 0 что бы выбрать текущую структуру или введите конкретный номер структуры" << endl;
			cin >> choose2;
			if (choose2)
			{
				newCurrent = current->getMas()[STRUCTnumget() - 1];
				return newCurrent;
			}
			else
			{
				return (BaseCl*)current;
			}
		}
		}
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Container root;
	Container* current = new Container;
	current = &root;
	while (1)
	{
		cout << "=======================" << endl;
		cout << "1 - Создать контейнер." << endl;
		cout << "2 - Создать элемент." << endl;
		cout << "3 - Проверить равенство." << endl;
		cout << "4 - Переместится вниз." << endl;
		cout << "5 - Переместится вверх." << endl;
		cout << "6 - Вывести." << endl;
		cout << "0 - Выход." << endl;
		cout << "=======================" << endl;
		switch (get_choose())
		{
			case 1:
			{
				current->addContainer();
				break;
			}
			case 2:
			{
				cout << "--------------------------" << endl;
				cout << "Выберите тип данных :" << endl;
				cout << "1 - Int." << endl;
				cout << "2 - Float." << endl;
				cout << "3 - Bool." << endl;
				cout << "--------------------------" << endl;

				int choose;
				cin >> choose;
				current->addElement(choose);
				break;
			}
			case 3:
			{
				BaseCl* fstEQLS = STRUCTchange(current);
				Element* newFstEQLSel = new Element;
				Container* newFstEQLSco = new Container;

				if (fstEQLS->getType())
				{
					newFstEQLSel = (Element*)fstEQLS;
					if (newFstEQLSel->Equals(STRUCTchange(current)))
						cout << "Структуры равны" << endl;
					else
						cout << "Структуры не равны" << endl;;
					delete newFstEQLSco;
				}
				else
				{
					newFstEQLSco = (Container*)fstEQLS;
					if (newFstEQLSco->Equals(STRUCTchange(current)))
						cout << "Структуры равны" << endl;
					else
						cout << "Структуры не равны" << endl;;
					delete newFstEQLSel;
				}
				break;
			}
			case 4:
			{
				if (!current->moveDown(current))
				{
					cout << "Некуда опускаться " << endl;
				}
				break;
			}
			case 5:
			{
				if (!current->moveUp(current))
				{
					cout << "Некуда подниматься" << endl;
				}
				break;
			}
			case 6:
			{
				char* buf = new char[255];
				int i = 0;
				current->ToString(buf, i);
				outConsol(buf, i);
				cout << endl;
				outFile(buf, i);
				break;
			}
			case 0:
			{
				cout << "Выход..." << endl;
				Sleep(2000);
				exit(0);
			}
			default:
			{
				cout << "Некорректный ввод, попробуйте снова." << endl;
				break;
			}
		}
	}
}
int get_choose()
{
	char* choose = new char[255];
	cin >> choose;
	return atoi(choose);
}
bool IntCheck(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}
bool FloatCheck(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '-' || str[i] == '.')
		{
			i++;
		}
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}
bool BoolCheck(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (!(str[i] >= '0' && str[i] <= '1') || str[i] == '-' || str[i] == '.')
		{
			return false;
		}
	}
	return true;
}
int get_Int()
{
	bool ok = false;
	while (ok == false)
	{
		char* enter = new char[255];
		cout << "Введите целочисленное значение" << endl;
		cin >> enter;

		if (IntCheck(enter))
		{
			ok = true;
			return atoi(enter);
		}
		else
		{
			cout << "Некорректный ввод! Попробуйте ещё раз." << endl;
		}
	}
}
float get_Float()
{
	bool ok = false;
	while (ok == false)
	{
		char* enter = new char[255];
		cout << "Введите значение с плавающей точкой" << endl;
		cin >> enter;

		if (FloatCheck(enter))
		{
			ok = true;
			return atof(enter);
		}
		else
		{
			cout << "Некорректный ввод! Попробуйте ещё раз." << endl;
		}

	}
}
bool get_Bool()
{
	bool ok = false;
	while (ok == false)
	{
		char* enter = new char[255];
		cout << "Введите значение логической переменной" << endl;
		cin >> enter;

		if (BoolCheck(enter))
		{
			int bOol = atoi(enter);
			if (bOol != 0)
			{
				ok = true;
				return true;
			}
			else
			{
				ok = true;
				return false;
			}
		}
		else
		{
			cout << "Некорректный ввод! Попробуйте ещё раз." << endl;
		}
	}
}
int STRUCTnumget()
{
	char* enter = new char[255];
	cout << "Введите номер структуры" << endl;
	cin >> enter;

	if (IntCheck(enter))
		return atoi(enter);
	else
		cout << "Неверный ввод! Попробуйте снова" << endl;
}
void outConsol(char* buf, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << buf[i];
	}
}
void outFile(char* buffer, int length)
{
	ofstream resfile("result.txt");
	for (int i = 0; i < (length); i++)
	{
		resfile << buffer[i];
	}
	resfile.close();
}