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
	//------------------------------------------------ ������������ ---------------------------------
	medical_institution();
	medical_institution(adres, string, int, int, empl*);
	//------------------------------------------------ ������ ---------------------------------
	void set_city(adres);//������ ����, �� ����������� ������� �������� 
	string get_city();//������ ����, �� ����������� ������� �������� 
	void set_street(adres);//������ ������, �� ����������� ������� ��������  
	string get_street();//������ ������, �� ����������� ������� �������� 
	void set_n(adres);//������ ������ �������, �� ����������� ������� ��������  
	string get_n();//������ ������ �������, �� ����������� ������� �������� 
	void set_pib(empl*);//������ ϲ� ����� 
	string get_pib();//������ ϲ� �����
	void set_post(empl*);//������ ����� ����� 
	string get_post();//������ ����� �����
	void set_category(empl*);//������ ����� ����� 
	string get_category();//������ ����� �����
	void set_number_of_employees(int);//������ ������� ����� 
	int get_number_of_employees();//������ ������� �����
	void set_number_of_patients(int);//������ ������� �������� 
	int get_number_of_patients();//������ ������� ��������
	void set_name(string);//������ ����� ������� �������� 
	string get_name();//������ ����� ������� ��������
	void set_employees(empl*);//������ ����� 
	empl get_employees();//������ �����
	virtual void input();//³�������� ������� �������� ����� �������� �������� 
	virtual void show() = 0;//³�������� ������� ��������� �������� �� �����
	//------------------------------------------------ ���������� ---------------------------------
	virtual ~medical_institution();
};

