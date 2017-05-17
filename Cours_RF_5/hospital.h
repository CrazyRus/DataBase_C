#pragma once
#include "medical_institution.h"
#include <iostream> 
#include <string>
using namespace std;

class hospital : public  medical_institution
{
private:
	string specialization;
	int number_of_chambers;

public:
	hospital();
	hospital(adres, string, int, int, empl*, string, int);
	//------------------------------------------------ Методи ---------------------------------
	void set_specialization(string);//Сеттер спеціалізації стаціонару 
	string get_specialization();//Геттер спеціалізації стаціонару  
	void set_number_of_chambers(int);//Сеттер кількості палат 
	int get_number_of_chambers();//Геттер кількості палат на 
	void input();//Віртуальна функція введення даних елемента колекції 
	void show();//Віртуальна функція виведення колекції на екран
	friend ostream& operator<<(ostream &out, hospital&);//Перегруження операції виводу данних з потоку
	friend istream& operator>>(istream &in, hospital&);//Перегруження операції вводу данних в потік
	//------------------------------------------------ Деструктор ---------------------------------
	~hospital();
};

