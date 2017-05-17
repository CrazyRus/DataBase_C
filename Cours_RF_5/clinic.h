#pragma once
#include "medical_institution.h"
#include <iostream> 
#include <string>
using namespace std;

class clinic : public  medical_institution
{
private:
	int ambulatory_treatment;

public:
	clinic();
	clinic(adres, string, int, int, empl*, int);
	//------------------------------------------------ Методи ---------------------------------
	void set_ambulatory_treatment(int);//Сеттер кількості пацієнтів на амбулаторному лікувані 
	int get_ambulatory_treatment();//Геттер кількості пацієнтів на амбулаторному лікувані 
	void input();//Віртуальна функція введення даних елемента колекції 
	void show();//Віртуальна функція виведення колекції на екран
	friend ostream& operator<<(ostream &out, clinic&);//Перегруження операції виводу данних з потоку
	friend istream& operator>>(istream &in, clinic&);//Перегруження операції вводу данних в потік
	//------------------------------------------------ Деструктор ---------------------------------
	~clinic();
};

