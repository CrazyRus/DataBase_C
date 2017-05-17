#pragma once//Унеможливлення перевизначення класу
#include "List.h"
#include <iostream> 
#include <string>
using namespace std;

class Menu
{
private:
	Menu();
	Menu(const Menu&);
public:
	list *collection; //Oб'єкт типу "Список"
	//------------------------------------------------ Методи ---------------------------------
	static Menu& get_instance();//Використання статичного екземпляру для самознищення
	void u_menu();
	void CreateHospital();
	void CreateClinic();
	void Watch();
	void SaveFile();
	void LoadFile();
	void Search();
	void Clear();
	void DeleteLast();
	//------------------------------------------------ Деструктор ---------------------------------
	~Menu();
};


