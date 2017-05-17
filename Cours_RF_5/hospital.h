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
	//------------------------------------------------ ������ ---------------------------------
	void set_specialization(string);//������ ������������ ���������� 
	string get_specialization();//������ ������������ ����������  
	void set_number_of_chambers(int);//������ ������� ����� 
	int get_number_of_chambers();//������ ������� ����� �� 
	void input();//³�������� ������� �������� ����� �������� �������� 
	void show();//³�������� ������� ��������� �������� �� �����
	friend ostream& operator<<(ostream &out, hospital&);//������������ �������� ������ ������ � ������
	friend istream& operator>>(istream &in, hospital&);//������������ �������� ����� ������ � ����
	//------------------------------------------------ ���������� ---------------------------------
	~hospital();
};

