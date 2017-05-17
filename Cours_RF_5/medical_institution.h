#pragma once
#include <iostream> 
#include <string>
using namespace std;

struct empl 
{
	string pib;
	string post;
	string category;
};

struct adres
{
	string city;
	string street;
	string n;
};

class medical_institution
{
protected:
	adres address;
	string name;
	int number_of_employees;
	int number_of_patients;
	empl *employees;

public:
	//------------------------------------------------ Конструктори ---------------------------------
	medical_institution();
	medical_institution(adres, string, int, int, empl*);
	//------------------------------------------------ Методи ---------------------------------
	void set_city(adres);//Сеттер міста, де знаходиться медична установа 
	string get_city();//Геттер міста, де знаходиться медична установа 
	void set_street(adres);//Сеттер вулиці, де знаходиться медична установа  
	string get_street();//Геттер вулиці, де знаходиться медична установа 
	void set_n(adres);//Сеттер номера будинку, де знаходиться медична установа  
	string get_n();//Геттер номера будинку, де знаходиться медична установа 
	void set_pib(empl*);//Сеттер ПІБ лікаря 
	string get_pib();//Геттер ПІБ лікаря
	void set_post(empl*);//Сеттер посту лікаря 
	string get_post();//Геттер посту лікаря
	void set_category(empl*);//Сеттер категоії лікаря 
	string get_category();//Геттер категоії лікаря
	void set_number_of_employees(int);//Сеттер кількості лікарів 
	int get_number_of_employees();//Геттер кількості лікарів
	void set_number_of_patients(int);//Сеттер кількості пацієнтів 
	int get_number_of_patients();//Геттер кількості пацієнтів
	void set_name(string);//Сеттер назви медичної установи 
	string get_name();//Геттер назви медичної установи
	void set_employees(empl*);//Сеттер лікаря 
	empl get_employees();//Геттер лікаря
	virtual void input();//Віртуальна функція введення даних елемента колекції 
	virtual void show() = 0;//Віртуальна функція виведення колекції на екран
	//------------------------------------------------ Деструктор ---------------------------------
	virtual ~medical_institution();
};

