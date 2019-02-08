// курсач 3 сем.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "iostream"
#include "string"
#include "conio.h"
#include "iomanip"
#include "Menu.h"
#include "MyCrt.h"
#include "vector"
#include <fstream>
#include <iterator>
#include <windows.h>

using namespace std;

void show_vector(vector<char>&a)
{
	for (vector<char>::iterator it = a.begin(); it != a.end(); ++it)
		cout << *it;
}


struct Tree
{

	Tree *parent;
	Tree *left;
	Tree *right;
	vector <char> Fam;
	double Ngroup;
	double Ozenka;
};

Tree BBoD();

void Pechat(vector<Tree> &Mass,int El)//печать на экран
{
	system("cls");

	GoToXY(5, 5);
	for (int i = 0; i < El;i++)
	{
		cout << endl << endl << "Фамилия студента: "; show_vector(Mass[i].Fam);
		cout << endl << "Номер группы: " << Mass[i].Ngroup << endl;
		cout << "Средний балл: " << Mass[i].Ozenka << endl;
	}
}

vector<Tree> Izmenenie(vector<Tree> &Mass)
{
	vector <char> str;
	vector<Tree> Prover = Mass;
	bool er = 0;
	char a;
	cout << "Введите фамилию студента данные которого хотите изменить\n";
	do
	{
		cin.sync();

		if (er){
			cout << "Введите фамилию студента данные которого хотите изменить\n";
			str.clear();
		}

		while (((a = getchar()) != '\n'))
		{
			er = 0;
			if ((isalpha(a)))//Если символ - буква
			{
				str.push_back(a);
				continue;
			}
			else if (isdigit(a))//Если символ - цифра
			{
				er = 1;
				cout << "Ошибка ввода данных! Введены цифры(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				cout << "Введите фамилию студента данные которого хотите изменить\n";
				continue;

			}
			else if (isspace(a))//Если пробельный символ
			{
				str.push_back(a);
				continue;
			}

			else if (ispunct(a)) //Если знак пунктуации
			{
				er = 1;
				cout << "Ошибка ввода данных! Введены знаки препинания(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				continue;
			}
			else
			{
				er = 1;
				cout << "Ошибка ввода данных! Неизвестная ошибка(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				a = 0;
				continue;
			}
		}
	} while (er);

	int Max = Prover.size();
	int i = 0;
	while (i < Max)
	{
		if (Prover[i].Fam == str)
		{
			Prover[i] = BBoD();
			break;
		}
		i++;
	}

	if (i == Max)
	{
		cout << "Такого студента в списке нет" << endl;
	}

	return Prover;
}
int Proverka1()
{
	int Num;
	bool er = 0;
	do
	{
		er = 0;
		cout << "Колличество студентов" << endl;
		cin >> Num;
		if (!cin || (Num <= 0))
		{
			cout << "Ошибка введенных данных! Колличество студентов должено быть неотрицателено" << endl;
			er = 1;
			cin.sync();
			cin.clear();
		}
	} while (er);
	return Num;
}
vector <char> Proverka()
{
	vector <char> str;
	bool er = 0;
	char a;
	cout << "Введите фамилию студента\n";
	do
	{
		cin.sync();

		if (er)
			cout << "Введите фамилию студента\n";


		while (((a = getchar()) != '\n'))
		{
			er = 0;
			if ((isalpha(a)))//Если символ - буква
			{
				str.push_back(a);
				continue;
			}
			else if (isdigit(a))//Если символ - цифра
			{
				er = 1;
				cout << "Ошибка ввода данных! Введены цифры(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				cin.clear();
				cout << "Введите фамилию студента\n";
				continue;

			}
			else if (isspace(a))//Если пробельный символ
			{
				str.push_back(a);
				continue;
			}

			else if (ispunct(a)) //Если знак пунктуации
			{
				er = 1;
				cout << "Ошибка ввода данных! Введены знаки препинания(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				cin.clear();
				continue;
			}
			else
			{
				er = 1;
				cout << "Ошибка ввода данных! Неизвестная ошибка(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				cin.clear();
				a = 0;
				continue;
			}
		}
	} while (er);
	return str;
}

vector<Tree> Udalenie(vector<Tree> &Mass)

{
	vector <char> str;
	vector<Tree> Prover = Mass;
	bool er = 0;
	char a;
	cout << "Введите фамилию удаляемого студента\n";
	do
	{
		cin.sync();

		if (er)
			cout << "Введите фамилию удаляемого студента\n";


		while (((a = getchar()) != '\n'))
		{
			er = 0;
			if ((isalpha(a)))//Если символ - буква
			{
				str.push_back(a);
				continue;
			}
			else if (isdigit(a))//Если символ - цифра
			{
				er = 1;
				cout << "Ошибка ввода данных! Введены цифры(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				cin.clear();
				cout << "Введите фамилию удаляемого студента\n";
				continue;

			}
			else if (isspace(a))//Если пробельный символ
			{
				str.push_back(a);
				continue;
			}

			else if (ispunct(a)) //Если знак пунктуации
			{
				er = 1;
				cout << "Ошибка ввода данных! Введены знаки препинания(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				cin.clear();
				continue;
			}
			else
			{
				er = 1;
				cout << "Ошибка ввода данных! Неизвестная ошибка(Должно быть введено слово или несколько слов)" << endl;
				cin.sync();
				cin.clear();
				a = 0;
				continue;
			}
		}
	} while (er);
	
	int Max = Prover.size();
	int i = 0;
	while (i < Max)
	{
		if (Prover[i].Fam == str)
		{
			Prover.erase(Prover.begin() + i);
			return Prover;
		}
		i++;
	}

	return Prover;
}



Tree BBoD()//ввод данных с клавиатуры
{
	bool er = 0;
	char a;
	vector <char> str;


	Tree obj;
	Tree *Nul = new Tree;

		cout << "Введите фамилию студента\n";
		do
		{
			cin.sync();

			if (er)
				cout << "Введите фамилию студента\n";


			while (((a = getchar()) != '\n'))
			{
				er = 0;
				if ((isalpha(a)))//Если символ - буква
				{
					str.push_back(a);
					continue;
				}
				else if (isdigit(a))//Если символ - цифра
				{
					er = 1;
					cout << "Ошибка ввода данных! Введены цифры(Должно быть введено слово или несколько слов)" << endl;
					cin.sync();
					cin.clear();
					cout << "Введите фамилию студента\n";
					continue;

				}
				else if (isspace(a))//Если пробельный символ
				{
					str.push_back(a);
					continue;
				}

				else if (ispunct(a)) //Если знак пунктуации
				{
					er = 1;
					cout << "Ошибка ввода данных! Введены знаки препинания(Должно быть введено слово или несколько слов)" << endl;
					cin.sync();
					cin.clear();
					continue;
				}
				else
				{
					er = 1;
					cout << "Ошибка ввода данных! Неизвестная ошибка(Должно быть введено слово или несколько слов)" << endl;
					cin.sync();
					cin.clear();
					a = 0;
					continue;
				}
			}
		} while (er);
		obj.Fam = str;


		double Num;
		do
		{
			er = 0;
			cout << "Введите номер группы" << endl;
			cin >> Num;
			if (!cin || (Num <= 0))
			{
				cout << "Ошибка введенных данных! Номер группы должен быть неотрицателен" << endl;
				er = 1;
				cin.sync();
				cin.clear();
			}
		} while (er);
		obj.Ngroup = Num;

		double Ozenka;
		do
		{
			er = 0;
			cout << "Введите средний балл" << endl;
			cin >> Ozenka;
			if (!cin || (Ozenka <= 0))
			{
				cout << "Ошибка введенных данных! Средний балл должен быть неотрицателен" << endl;
				er = 1;
				cin.sync();
				cin.clear();
			}
		} while (er);
		obj.Ozenka = Ozenka;
		return obj;

}

vector<Tree> Mass(int n)//массив всех элементов(какой же он классный)
{
	int H=n;
	vector<Tree> Mass;
	Tree end;
	for (int i = 0; i < n; i++)
	{
		end = BBoD();
		Mass.push_back(end);
	}
	return Mass;
}

int NaytiStrelka(Tree *&Begin, vector <char> Am)//поиск по фамилии через дерево
{
	Tree *newItem;
	newItem = new Tree;
	newItem->Fam = Am;

	if (!Begin)
		return 0;

	if (Begin->Fam > newItem->Fam)
		NaytiStrelka(Begin->left, Am);
	else
	{
		if (newItem->Fam == Begin->Fam)
		{
			cout << endl << endl << "Фамилия студента: "; show_vector(Begin->Fam);
			cout << endl << "Номер группы: " << Begin->Ngroup << endl;
			cout << "Средний балл: " << Begin->Ozenka << endl;
			NaytiStrelka(Begin->right, Am);
		}
		else
			NaytiStrelka(Begin->right, Am);
	}

}

int NaytiStrelka1(Tree *&Begin, double Am)//поиск по группе через дерево
{
	Tree *newItem;
	newItem = new Tree;
	newItem->Ngroup = Am;

	if (!Begin)
		return 0;

	if (Begin->Ngroup > newItem->Ngroup)
	{
		NaytiStrelka1(Begin->left, Am);
	}
	else
	{
		if (newItem->Ngroup == Begin->Ngroup)
		{
			cout << endl << endl << "Фамилия студента: "; show_vector(Begin->Fam);
			cout << endl << "Номер группы: " << Begin->Ngroup << endl;
			cout << "Средний балл: " << Begin->Ozenka << endl;
			NaytiStrelka1(Begin->right, Am);
		}
		else
			NaytiStrelka1(Begin->right, Am);
	}

}

int NaytiStrelka2(Tree *&Begin, double Am)//поиск по группе через дерево
{
	Tree *newItem;
	newItem = new Tree;
	newItem->Ozenka = Am;

	if (!Begin)
		return 0;

	if (Begin->Ozenka > newItem->Ozenka)
		NaytiStrelka2(Begin->left, Am);
	else
	{
		if (newItem->Ozenka == Begin->Ozenka)
		{
			cout << endl << endl << "Фамилия студента: "; show_vector(Begin->Fam);
			cout << endl << "Номер группы: " << Begin->Ngroup << endl;
			cout << "Средний балл: " << Begin->Ozenka << endl;
			NaytiStrelka2(Begin->right, Am);
		}
		else
			NaytiStrelka2(Begin->right, Am);
	}

}


void Dobavlenie(vector <char> Am, double GR, double Oz, Tree *&newItem)// дерево ключ фамилия
{

	if (!newItem)
	{
		newItem = new Tree;
		newItem->Fam = Am;
		newItem->Ngroup = GR;
		newItem->Ozenka = Oz;
		newItem->parent = NULL;
		newItem->left = NULL;
		newItem->right = NULL;
		return;
	}
	else
	{
		if (Am >= newItem->Fam)
		{
			Dobavlenie(Am, GR, Oz, newItem->right);
		}
		else
		{
			Dobavlenie(Am, GR, Oz, newItem->left);
		}

	}
}

void Dobavlenie1(vector <char> Am, double GR, double Oz, Tree *&newItem) // дерево ключ номер группы
{

	if (!newItem)
	{
		newItem = new Tree;
		newItem->Fam = Am;
		newItem->Ngroup = GR;
		newItem->parent = NULL;
		newItem->left = NULL;
		newItem->right = NULL;
		newItem->Ozenka = Oz;
		return;
	}
	else
	{
		if (newItem->Ngroup<=GR)
		{
			Dobavlenie1(Am, GR, Oz, newItem->right);
		}
		else
		{
			Dobavlenie1(Am, GR, Oz, newItem->left);
		}

	}
}

void Dobavlenie2(vector <char> Am, double GR, double Oz, Tree *&newItem) // дерево ключ средний балл
{

	if (!newItem)
	{
		newItem = new Tree;
		newItem->Fam = Am;
		newItem->Ngroup = GR;
		newItem->parent = NULL;
		newItem->left = NULL;
		newItem->right = NULL;
		newItem->Ozenka = Oz;
		return;
	}
	else
	{
		if (newItem->Ozenka<=Oz)
		{
			Dobavlenie2(Am, GR, Oz, newItem->right);
		}
		else
		{
			Dobavlenie2(Am, GR, Oz, newItem->left);
		}

	}
}

void Sortirovka(Tree *&Begin)//общая сортировка (просто обход созданных деревьев)
{
	if (!Begin)
		return;
	Sortirovka(Begin->left);
	cout << endl << endl << "Фамилия студента: "; show_vector(Begin->Fam);
	cout << endl << "Номер группы: " << Begin->Ngroup << endl;
	cout << "Средний балл: " << Begin->Ozenka << endl;
	Sortirovka(Begin->right);
}

void FailyZapis(vector<Tree> &Mass,int El)//запись в файл
{
	int n = El;
	ofstream File;
	File.open("C:\\Users\\HP\\Desktop\\Kursach\\Data.txt");
	if (!File.is_open())
	{
		cout << "не удалось открыть файл" << endl;
		return;
	}
	vector<Tree>::iterator Kun;
	for (Kun = Mass.begin(); Kun != Mass.end(); Kun++)
	{
		GoToXY(5, 5);
		cout << "Файл открылся" << endl;
		File << "G" << Kun->Ngroup << "O" << Kun->Ozenka << "E";
		copy(begin((*Kun).Fam), end((*Kun).Fam), ostream_iterator<char>(File));
		File << "#";
		cout << "Запись завершена" << endl;
	}
	File.close();
	return;
}

int ProstoMneLen()//зачем перелопачивать код, если можно впилить костыль? (╯°□°）╯︵ ┻━┻
{
	ifstream File;
	char a = 1;
	int El = 0;
	File.open("C:\\Users\\HP\\Desktop\\Kursach\\Data.txt",ios::beg);
	if (!File.is_open())
	{
		cout << "не удалось открыть файл" << endl;
	}
	while ((a = File.get()) != EOF)
	{
		if (a == '#')
		{
			El++;
		}
	}
	return El;
}


vector<Tree> FailyChtenie()
{
	ifstream File;
	int a = 1;
	double Groop = 0, Ozenka = 0;
	vector<char> str;
	vector<Tree> Mass;
	File.open("C:\\Users\\HP\\Desktop\\Kursach\\Data.txt", ios::beg);
	if (!File.is_open())
	{
		cout << "не удалось открыть файл" << endl;
	}
	while ((a = File.get()) != EOF)
	{
		if (a == '#')
		{
			a = File.get();
			continue;
		}

		if (a == 'G')
		{
			a = File.get();

			while (a != 'O')
			{
				Groop = Groop * 10;
				Groop = Groop + a - '0';
				a = File.get();
			}
		}
		if (a == 'O')
		{
			a = File.get();

			while (a != 'E')
			{
				Ozenka = Ozenka * 10;
				Ozenka = Ozenka + a - '0';
				a = File.get();
			}
		}
		if (a == 'E')
		{
			a = File.get();
			while (a != '#')
			{
				str.push_back(a);
				a = File.get();
			}
			if (a == '#')
			{
				Tree obj;
				obj.Fam = str;
				obj.Ngroup = Groop;
				obj.Ozenka = Ozenka;
				Mass.push_back(obj);
			}
		}
		str.clear();
		Groop = 0;
		Ozenka = 0;
	}
	
	cout << "Ввод окончен" << endl;
	return Mass;
}
Menu T1, T2, T3, T4, T5;

void Menupower()
{
	setlocale(0, "");
	static char Data1[5][50] = { "Ввод данных", "Работа с программой", "Сортировка","Поиск", "Выход" };
	InitMenu(T1, 5, 1, 0, true, 0xF1, 0x2F, 5, 50, *Data1);
	static char Data2[2][50] = { "С клавиатуры", "Из Файла" };
	InitMenu(T2, T1.Items[0].Pos, T1.Y + T1.MenuHeight - 1, 0, false, 0xF1, 0x2F, 2, 50, *Data2);
	static char Data3[4][50] = { "Добавить студента", "Удалить студента", "Сохранить данные в файл", "Изменить данные" };
	InitMenu(T3, T1.Items[1].Pos, T1.Y + T1.MenuHeight - 1, 0, false, 0xF1, 0x2F, 4, 50, *Data3);
	static char Data4[3][50] = { "По фамилии", "По номеру группы", "По среднему баллу" };
	InitMenu(T4, T1.Items[2].Pos, T1.Y + T1.MenuHeight - 1, 0, false, 0xF1, 0x2F, 3, 50, *Data4);
	static char Data5[3][50] = { "По фамилии", "По номеру группы", "По среднему баллу" };
	InitMenu(T5, T1.Items[2].Pos, T1.Y + T1.MenuHeight - 1, 0, false, 0xF1, 0x2F, 3, 50, *Data5);
}

int CommandChoice()		
{
	int Command = -1;
	Show_Menu(T1);
	do
	{
		if (ItemChoice(T1))			// Работа с основным меню
			switch (T1.Item)
		{//далее работа с подменю
			case 0:
				Show_Menu(T2);
				if (ItemChoice(T2))			
				{
					Command = (T1.Item + 1) * 10 + T2.Item + 1;
					HideMenu(T2, 0x0F);
					HideMenu(T1, 0x0F);
				}
				else
					HideMenu(T2, 0x0F);

				break;
			case 1:
				Show_Menu(T3);
				if (ItemChoice(T3))			
				{
					Command = (T1.Item + 1) * 10 + T3.Item + 1;
					HideMenu(T3, 0x0F);
					HideMenu(T1, 0x0F);
				}
				else
					HideMenu(T3, 0x0F);
				break;
			case 2:
				Show_Menu(T4);
				if (ItemChoice(T4))			
				{
					Command = (T1.Item + 1) * 10 + T4.Item + 1;
					HideMenu(T4, 0x0F);
					HideMenu(T1, 0x0F);
				}
				else
					HideMenu(T4, 0x0F);
				break;
			case 3:
				Show_Menu(T5);
				if (ItemChoice(T5))
				{
					Command = (T1.Item + 1) * 10 + T5.Item + 1;
					HideMenu(T5, 0x0F);
					HideMenu(T1, 0x0F);
				}
				else
					HideMenu(T5, 0x0F);
				break;

			default:
				Command = T1.Item + 1;
				HideMenu(T1, 0x0F);
		}
	} while (Command == -1);
	return Command;
}





int _tmain()
{

	Menupower();
	int Comands;


	int i,n,Elements = 0;
	double Groop,Srznach,size1,size2;
	Tree *Students = NULL;
	Tree end;
	vector <Tree> Obsh,Obsh1;
	
		do
		{
			Comands = CommandChoice();
			switch (Comands)
			{
			case 11: system("cls"); cout << endl;//первоначальный ввод с клавиатуры
				Elements = Proverka1();  Obsh = Mass(Elements); Pechat(Obsh, Elements); break;

			case 12:system("cls"); Obsh.clear();Elements = 0 ; Elements = Elements + ProstoMneLen(); Obsh = FailyChtenie(); Pechat(Obsh, Elements); break;
				//первоначальное чтение из файла

			case 21:system("cls"); cout << endl; n = Proverka1();//добавление элементов
		         for ( i = 0; i < n; i++)
			      {
				    end = BBoD();
				    Obsh.push_back(end);
				 }; Elements = Elements + n; Pechat(Obsh, Elements); break;

			case 22: if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
					 system("cls"); Obsh1 = Udalenie(Obsh); size1 = Obsh.size(); size2 = Obsh1.size();
					 if (size1 != size2)
					 {
						 Elements = Elements - 1;
					 }
					 Obsh = Obsh1;
					 Pechat(Obsh, Elements);
					 if (size1 == size2)
					 {
						 GoToXY(5, 5); cout << "Такого студента в списке нет" << endl;
					 } break;//удаление данных

			case 23:if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
					system("cls");  FailyZapis(Obsh, Elements); break; //сохранение в файл

			case 24:if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
					system("cls"); Obsh = Izmenenie(Obsh); Pechat(Obsh, Elements); break;//изменение данных
				
			case 31:if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
				system("cls");//сортировка по фамилии
				for (i = 0; i < Elements; i++)
			{
				Dobavlenie(Obsh[i].Fam, Obsh[i].Ngroup, Obsh[i].Ozenka, Students);
			} 
				GoToXY(5, 5);	Sortirovka(Students); Students = NULL; break;

			case 32:if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
				system("cls");//сортировка по номеру группы
				for (i = 0; i < Elements; i++)
				{
					Dobavlenie1(Obsh[i].Fam, Obsh[i].Ngroup, Obsh[i].Ozenka, Students);
				}
				GoToXY(5, 5);	Sortirovka(Students); Students = NULL; break;

			case 33:if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
				system("cls");//сортировка по среднему баллу
				for (i = 0; i < Elements; i++)
				{
					Dobavlenie2(Obsh[i].Fam, Obsh[i].Ngroup, Obsh[i].Ozenka, Students);
				}
				GoToXY(5, 5);	Sortirovka(Students); Students = NULL; break;

			case 41:if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
				system("cls");//поиск по фамилии
				for (i = 0; i < Elements; i++)
			{
				Dobavlenie(Obsh[i].Fam, Obsh[i].Ngroup, Obsh[i].Ozenka, Students);
			}
				NaytiStrelka(Students, Proverka()); Students = NULL; break;

			case 42:if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
				system("cls");//поиск по номеру группы 
				for (i = 0; i < Elements; i++)
				{
					Dobavlenie1(Obsh[i].Fam, Obsh[i].Ngroup, Obsh[i].Ozenka, Students);
				}
				cout << "Введите номер группы, студентов которой хотите найти" << endl;
				cin >> Groop;
				NaytiStrelka1(Students, Groop); Students = NULL; break;

			case 43:if (Elements == 0){ cout << "Введите хоть какие то данные" << endl; break; }
				system("cls");//поиск по среднему баллу
				for (i = 0; i < Elements; i++)
				{
					Dobavlenie2(Obsh[i].Fam, Obsh[i].Ngroup, Obsh[i].Ozenka, Students);
				}
				cout << "Введите искомый средный балл" << endl;
				cin >> Srznach;
				NaytiStrelka2(Students, Srznach); Students = NULL; break;

			}
		} while (Comands != 5);
	
	return 0;
}

