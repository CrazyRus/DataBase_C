#include "medical_institution.h"
#include <iostream> 
#include <string>
using namespace std;

medical_institution::medical_institution()
{
}

medical_institution::medical_institution(adres cur_address, string cur_name, int cur_number_of_employees, int cur_number_of_patients, empl* cur_employees)
	: address(cur_address), name(cur_name), number_of_employees(cur_number_of_employees), number_of_patients(cur_number_of_patients)
{
	employees = new empl[number_of_employees];
	cur_employees = new empl[number_of_employees];
}

void medical_institution::set_employees(empl* cur_employees) 
{
	for (int i = 0; i < number_of_employees; i++)
		employees[i] = cur_employees[i];
}
empl medical_institution::get_employees() 
{
	return *employees;
}

void medical_institution::set_pib(empl* cur_employees)
{
	for (int i = 0; i < number_of_employees; i++)
		employees[i].pib = cur_employees[i].pib;
}
string medical_institution::get_pib()
{
	for (int i = 0; i < number_of_employees; i++)
		return employees[i].pib;
}

void medical_institution::set_category(empl* cur_employees)
{
	for (int i = 0; i < number_of_employees; i++)
		employees[i].category = cur_employees[i].category;
}
string medical_institution::get_category()
{
	for (int i = 0; i < number_of_employees; i++)
		return employees[i].category;
}

void medical_institution::set_post(empl* cur_employees)
{
	for (int i = 0; i < number_of_employees; i++)
		employees[i].post = cur_employees[i].post;
}
string medical_institution::get_post() 
{
	for (int i = 0; i < number_of_employees; i++)
		return employees[i].post;
}

void medical_institution::set_number_of_employees(int cur_number_of_employees) 
{
	number_of_employees = cur_number_of_employees;
}
int medical_institution::get_number_of_employees() 
{
	return number_of_employees;
}

void medical_institution::set_number_of_patients(int cur_number_of_patients) 
{
	number_of_patients = cur_number_of_patients;
}
int medical_institution::get_number_of_patients() 
{
	return number_of_patients;
}

void medical_institution::set_city(adres cur_address) 
{
	address.city = cur_address.city;
}
string medical_institution::get_city() 
{
	return address.city;
}

void medical_institution::set_street(adres cur_address) 
{
	address.street = cur_address.street;
}
string medical_institution::get_street() 
{
	return address.street;
}

void medical_institution::set_n(adres cur_address) 
{
	address.n = cur_address.n;
}
string medical_institution::get_n() 
{
	return address.n;
}

void medical_institution::set_name(string cur_name) 
{
	name = cur_name;
}
string medical_institution::get_name() 
{
	return name;
}

//Віртуальна функція введення даних елемента колекції 
void medical_institution::input() 
{
	cin.clear();
	cout << "Input name of medical institution: ";
	getline(cin, name,'\n');
	cout << endl;
	cout << "Input address. " << endl;
	cout << "Input city: ";
	getline(cin, address.city, '\n');
	cout << "Input street: ";
	getline(cin, address.street,'\n');
	cout << "Input number of house: ";
	getline(cin, address.n, '\n');
	cout << endl;
	cin.clear();
	while (number_of_patients <= 0)
	{
		cout << "Input number of patients: ";
		cin >> number_of_patients;
		cin.ignore(INT_MAX, '\n');
	}
	cin.clear();
	while (number_of_employees <= 0)
	{
		cout << "Input number of doctors: ";
		cin >> number_of_employees;
		cin.ignore(INT_MAX, '\n');
	}
		employees = new empl[number_of_employees];
		for (int i = 0; i < number_of_employees; i++)
		{
			cout << "Number: " << i + 1 << endl;
			cout << "Input P.I.B. of doctor: ";
			getline(cin, employees[i].pib, '\n');
			cout << "Input post of doctor: ";
			getline(cin, employees[i].post,'\n');
			cout << "Input number of category of doctor: ";
			cin >> employees[i].category;
			cin.ignore(INT_MAX, '\n');
			cout << endl;
		}
}

medical_institution::~medical_institution()
{
	delete employees;
}


