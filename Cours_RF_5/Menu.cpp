#include "Menu.h"
#include <iostream>//ϳ��������� �������� ��������
#include <string>
#include <windows.h>
using namespace std;//������������ �������� �������� std

Menu::Menu()
{
	collection = new list;
}

Menu& Menu::get_instance()
{
	static Menu instance;
	return instance;
}

void Menu::u_menu()
{
	int i;
	char s[10];
	do
	{
		system("cls");//������� ������
		cout << "---------------- MENU ----------------" << endl;
		cout << "<1>. Create hospital's object" << endl;
		cout << "<2>. Create clinic's object" << endl;
		cout << "<3>. Show the medical institution" << endl;
		cout << "<4>. Remove the medical_institution" << endl;
		cout << "<5>. Save to the file" << endl;
		cout << "<6>. Load from the file" << endl;
		cout << "<7>. Do request" << endl;
		cout << "<8>. Clear the collection" << endl;
		cout << "<9>. Leave the program" << endl << endl;
		cin.getline(s, 10);
		i = atoi(s);//����������� ���� char � int
		switch (i)
		{
		case 1:
		{
			system("cls");
			CreateHospital();
			system("pause");
			break;
		}
		case 2:
		{
			system("cls");
			CreateClinic();
			system("pause");
			break;
		}
		case 3:
		{
			system("cls");
			Watch();
			system("pause");
			break;
		}
		case 4:
		{
			system("cls");
			DeleteLast();
			cout << "Last element was deleted! " << endl;
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			SaveFile();
			system("pause");
			break;
		}
		case 6:
		{
			system("cls");
			LoadFile();
			system("pause");
			break;
		}
		case 7:
		{
			system("cls");
			Search();
			system("pause");
			break;
		}
		case 8:
		{
			system("cls");
			Clear();
			cout << "Collection was cleared! " << endl;
			system("pause");
			break;
		}
		case 9:
		{
			system("cls");
			exit(0);
			system("pause");
			break;
		}
		default:
		{
			if (i > 9 || i < 1)
			{
				cout << "Your choise is not correct..." << endl;
				system("pause");
			}
			break;
		}
		}
	} 
	while (i != 10);
	delete collection;
}

// ����� ��������� ���� ������� �������� - ����������
void Menu::CreateHospital()
{
	medical_institution* hosp;
	hosp = new hospital();
	hosp->input();
	collection->push(&hosp);
	u_menu();
}

// ����� ��������� ���� ������� �������� - ��������
void Menu::CreateClinic()
{
	medical_institution* clin;
	clin = new clinic();
	clin->input();
	collection->push(&clin);
	u_menu();
}

// �����, ���� �������� ���������� ��� ��������� �������� �������
void Menu::Watch()
{
	collection->display();
}

// �����, ���� �������� �������� ������� ������ ������� ��������
void Menu::DeleteLast()
{
	collection->pop();
}

// �����, ���� �������� �������� ��������� � ����
void Menu::SaveFile()
{
	collection->save();
}

// �����, ���� �������� ����������� ��������� �������� � �����
void Menu::LoadFile()
{
	collection->load();
}

// �����, ���� �������� �������� ����� �������� ������� ����� � �������� ���
void Menu::Search()
{
	string str;
	cout << "Input city for searching number of doctors: ";
	getline(cin, str);
	cout << "Num of doctors in " << str << " : " << collection->search(str)<<endl;
}

// �����, ���� �������� �������� ��� ��������
void Menu::Clear()
{
	collection->clear();
}

Menu::~Menu()
{
}
