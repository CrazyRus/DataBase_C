#include "clinic.h"
#include <iostream> 
#include <string>
using namespace std;

clinic::clinic()
{
}

clinic::clinic(adres cur_address, string cur_name, int cur_number_of_employees, int cur_number_of_patients, empl* cur_employees, int cur_ambulatory_treatment)
	: medical_institution(cur_address, cur_name, cur_number_of_employees, cur_number_of_patients, cur_employees), ambulatory_treatment(cur_ambulatory_treatment)
{
}

void clinic::set_ambulatory_treatment(int cur_ambulatory_treatment)
{
	ambulatory_treatment = cur_ambulatory_treatment;
}
int clinic::get_ambulatory_treatment()
{
	return ambulatory_treatment;
}

//Віртуальна функція введення даних елемента колекції 
void clinic::input()
{
	cin.clear();
	medical_institution::input();
	while (ambulatory_treatment <= 0)
	{
		cout << "Input number of patients on ambulatory treatment:";
		cin >> ambulatory_treatment;
		cin.ignore(INT_MAX, '\n');
	}
	cout << "--------------------------------" << endl;
}

//Віртуальна функція виведення колекції на екран
void clinic::show()
{
	cout << "\nName of clinic: " << get_name() << ";";
	cout << "\nAddress of clinic: " << get_city() << ", " << get_street() << ", " << get_n() << ";";
	cout << "\nNumber of patients= " << get_number_of_patients() << ";";
	cout << "\nNumber of doctors= " << get_number_of_employees() << ";" << endl;
	for (int i = 0; i < number_of_employees; i++)
	{
		cout << "---------";
		cout << "\nNumber: " << i+1 << ":";
		cout << "\nP.I.B. of doctor: " << employees[i].pib << ";";
		cout << "\nPost of doctor: " << employees[i].post << ";";
		cout << "\nCategory of doctor: " << employees[i].category << ";" << endl;
		cout << "---------";
	}
	cout << "\nNumber of patients on ambulatory treatment= " << get_ambulatory_treatment() << ";" << endl;
	cout << "--------------------------------" << endl;
}

//Оператор виведення ostream & operator>>(istream &in, clinic &obj)
ostream& operator<<(ostream &out, clinic&obj)
{
	out << obj.name << endl;
	out << obj.address.city << endl;
	out << obj.address.street << endl;
	out << obj.address.n << endl;
	out << obj.number_of_patients << endl;
	out << obj.number_of_employees << endl;
	for (int i = 0; i <obj.number_of_employees; i++)
	{
		out << obj.employees[i].pib << endl;
		out << obj.employees[i].post << endl;
		out << obj.employees[i].category << endl;
	}
	out << obj.ambulatory_treatment << endl;
	return out;
}
//Оператор введення istream & operator>>(istream &in, clinic &obj)
istream& operator>>(istream &in, clinic &obj)
{
	in >> obj.name;
	in >> obj.address.city;
	in >> obj.address.street;
	in >> obj.address.n;
	in >> obj.number_of_patients;
	in >> obj.number_of_employees;
	obj.employees = new empl[obj.number_of_employees];
	for (int i = 0; i <obj.number_of_employees; i++)
	{
		in >> obj.employees[i].pib;
		in >> obj.employees[i].post;
		in >> obj.employees[i].category;
	}
	in >> obj.ambulatory_treatment;
	return in;
}

clinic::~clinic()
{
}
