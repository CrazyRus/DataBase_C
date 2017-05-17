#include "hospital.h"
#include <iostream> 
#include <string>
using namespace std;

hospital::hospital()
{
}

hospital::hospital(adres cur_address, string cur_name, int cur_number_of_employees, int cur_number_of_patients, empl* cur_employees, string cur_specialization, int cur_number_of_chambers)
	: medical_institution(cur_address, cur_name, cur_number_of_employees, cur_number_of_patients, cur_employees), specialization(cur_specialization), number_of_chambers(cur_number_of_chambers)
{
}

void hospital::set_specialization(string cur_specialization)
{
	specialization = cur_specialization;
}
string hospital::get_specialization()
{
	return specialization;
}

void hospital::set_number_of_chambers(int cur_number_of_chambers)
{
	number_of_chambers = cur_number_of_chambers;
}
int hospital::get_number_of_chambers()
{
	return number_of_chambers;
}

//Віртуальна функція введення даних елемента колекції 
void hospital::input()
{
	medical_institution::input();
	cout << "Input specialization of hospital: ";
	getline(cin, specialization, '\n');
	while (number_of_chambers <= 0)
	{
		cout << "Input number of chambers: ";
		cin >> number_of_chambers;
		cin.ignore(INT_MAX, '\n');
	}
	cout << "--------------------------------" << endl;
}

//Віртуальна функція виведення колекції на екран
void hospital::show()
{
	cout << "\nName of hospital: " << get_name() << ";";
	cout << "\nAddress of hospital: " << get_city() << ", " << get_street() << ", " << get_n() << ";";
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
	cout << "\nSpecialization: " << get_specialization() << ";";
	cout << "\nNumber of chambers= " << get_number_of_chambers() << ";" << endl;
	cout << "--------------------------------" << endl;
}

//Оператор виведення ostream & operator>>(istream &in, clinic &obj)
ostream& operator<<(ostream &out, hospital&obj)
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
	out << obj.specialization << endl;
	out << obj.number_of_chambers << endl;
	return out;
}

//Оператор введення istream & operator>>(istream &in, clinic &obj)
istream& operator>>(istream &in, hospital &obj)
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
	in >> obj.specialization;
	in >> obj.number_of_chambers;
	return in;
}

hospital::~hospital()
{
}
