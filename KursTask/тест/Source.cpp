#include<iostream>
#include<string>
#include <conio.h>
#include <windows.h>
#include<fstream>

using namespace std;

short Translation = 0, choose = 0;
bool succ;
template<class TKey, class TValue>

class MAP
{
private:
	struct Collection
	{
		TKey key;
		TValue value;
	};

	int size;
	int len;
	Collection *array;
public:
	MAP()
	{
		len = 0;
		size = 5;
		array = new Collection[size];
	}

	void Expansion()
	{
		int temp;
		temp = size * 2;
		Collection *tempArray = new Collection[temp];
		for (int i = 0; i < len; i++)
		{
			tempArray[i] = array[i];
		}
		delete[]array;
		array = tempArray;
		size = temp;
	}
	void Add(TKey Nkey, TValue Nvalue)
	{
		if (len == size)
		{
			Expansion();
		}
		array[len].key = Nkey;
		array[len].value = Nvalue;


		len++;
	}
	TValue Search(TKey Nkey)
	{
		for (int i = 0; i < len; i++)
		{
			if (array[i].key == Nkey)
			{
				succ = true;
				return array[i].value;
			}
		}

		succ = false;
		return NULL;
	}
	int getLen()
	{
		return len;
	}

	TKey getKey(int num)
	{
		return array[num].key;
	}
	TValue getValue(int num)
	{
		return array[num].value;
	}
	friend ostream& operator << (ostream& out, MAP& map)
	{
		for (int i = 0; i < map.getLen(); i++)
		{
			out << map.getKey(i);
			out << map.getValue(i) << endl;
		}
		return out;
	}

	friend istream& operator >> (istream& in, MAP& map)
	{
		TKey key;
		TValue value;

		in >> key;
		in >> value;

		map.Add(key, value);
		return in;
	}
	~MAP()
	{
		delete[] array;
	}

};

class Word
{
private:

	char *Fword;
public:
	Word()
	{
		Fword = "empty";

	}

	Word(char* Fword)

	{

		this->Fword = Fword;
	}

	friend ostream &operator<<(ostream &out, Word &word)

	{

		out << " " << word.Fword;

		return out;

	}

	friend istream& operator >> (istream& in, Word& word)

	{
		char* secWord = new char[255];

		in >> secWord;

		word.Fword = secWord;

		return in;

	}

	~Word()

	{

	}

};
void MainMenu(MAP<string, Word> &MY);


int main()

{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "------АНГЛО-РУССКИЙ и РУССКО-АНГЛИЙСКИЙ СЛОВАРЬ------" << endl;
	MAP<string, Word> MY;
	ifstream file("DICTIONARY.txt");

	if (file.is_open())
	{
		while (true)
		{
			auto* key = new char[255];
			string str1;
			file >> str1;
			if (file.eof())
				break;
			file >> key;
			Word temp(key);
			MY.Add(str1, temp);
		}
	}

	file.close();

	MainMenu(MY);
}
char* Enter() {
	switch (Translation)
	{
	case 1:
	{
		char *buff = new char[255];
		bool ok = false;

		const char *alphabet = "абвгдеёжзийклмнопрстуфцчшщъыьэюя";
		while (ok == false)
		{
			cin.getline(buff, 255);

			for (int i = 0; i <= strlen(buff); i++)
			{
				if (!strchr(alphabet, buff[i]))
				{
					cout << "Некорректный ввод! Введите слово на русском языке строчными буквами: ";
					break;
				}
				if (i == strlen(buff))
				{
					ok = true;
				}
			}
		}
		return buff;
	}
	case 2:
	{

		char *buff = new char[255];
		bool ok = false;
		const char *alphabet = "abcdefghijklmnopqrstuvwxyz";
		while (ok == false)
		{
			cin.getline(buff, 255);

			for (int i = 0; i <= strlen(buff); i++)
			{
				if (!strchr(alphabet, buff[i]))
				{
					cout << "Некорректный ввод! Введите слово на английском языке строчными буквами: ";
					break;
				}
				if (i == strlen(buff))
				{
					ok = true;
				}

			}
		}
		return buff;
	}
	}
}

void MainMenu(MAP<string, Word> &MY)
{

	while (true)

	{
		cout << "----------------------------" << endl;
		cout << "1 - Перевести слово." << endl;
		cout << "2 - Добавить слово в словарь." << endl;
		cout << "3 - Просмотреть словарь." << endl;
		cout << "4 - Сохранить изменения в словаре." << endl;
		cout << "0 - Выйти." << endl;
		switch (_getch())

		{

		case '1':

		{
			cout << "----------ПЕРЕВЕСТИ СЛОВО----------" << endl;
			cout << "Выберите язык: " << endl;
			cout << "1 - Русский." << endl;
			cout << "2 - Английский" << endl;
			cout << "0 - Назад." << endl;
				switch (_getch())
					{
					case'1':
					{
						cout << "Введите слово на русском языке строчными буквами: ";
						Translation = 1;
						char* FiWord = new char[255];
						FiWord = Enter();
						MY.Search(FiWord);
						if (succ != false)
						{
							cout << "Перевод:" << MY.Search(FiWord) << endl;
						}
						else
						{
							cout << "Ваше слово не найдено в словаре." << endl;
						}
						break;
					}
					case '2':
					{
						Translation = 2;
						cout << "Введите слово на английском языке строчными буквами: ";
						char* FiWord = new char[255];
						FiWord = Enter();
						MY.Search(FiWord);
						if (succ != false)
						{
							cout << "Перевод:" << MY.Search(FiWord) << endl;
						}
						else
						{
							cout << "Ваше слово не найдено в словаре." << endl;
						}
						break;
					}
					case '0':
					{
						break;
					}
					default:
					{
						cout << "Некорректный ввод, попробуйте ещё раз!" << endl;
						break;
					}
				}

				break;
		}
		case '2':

		{
			cout << "----------ДОБАВИТЬ СЛОВО----------" << endl;
			cout << "Выберите язык: " << endl;
			cout << "1 - Русский." << endl;
			cout << "2 - Английский" << endl;
			cout << "0 - Назад." << endl;
			switch (_getch())
			{
			case'1':
			{
				cout << "Введите слово на русском языке и его перевод на английском для добавления в словарь: ";
				cin >> MY;
				cout << "Слова были добавлены в Русско-Английский словарь." << endl;
				break;
			}
			case '2':
			{
				cout << "Введите слово на английском языке и его перевод на русском для добавления в словарь: ";
				cin >> MY;
				cout << "Слова были добавлены в Англо-Русский словарь." << endl;

				break;
			}
			case '0':
			{
				break;
			}
			default:
			{
				cout << "Некорректный ввод, попробуйте ещё раз!" << endl;
				break;
			}
			}
			break;

		}

		case '3':

		{
			cout << "--------------СЛОВАРЬ----------------" << endl;
			cout << MY;
			cout << "-------------------------------------" << endl;
			break;

		}

		case '4':
		{
			auto *dict = new char[1000];
			ofstream File;
			File.open("DICTIONARY.txt");
			File << MY;
			cout << "Словарь сохранен." << endl;
			File.close();
			break;
		}
		case '0':
		{
			return;
		}

		

		default:
		{
			cout << "Некорректный ввод. Попробуйте снова!" << endl;
			break;
		}

		}

	}
}