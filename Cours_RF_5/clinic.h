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
	//------------------------------------------------ ������ ---------------------------------
	void set_ambulatory_treatment(int);//������ ������� �������� �� ������������� ������ 
	int get_ambulatory_treatment();//������ ������� �������� �� ������������� ������ 
	void input();//³�������� ������� �������� ����� �������� �������� 
	void show();//³�������� ������� ��������� �������� �� �����
	friend ostream& operator<<(ostream &out, clinic&);//������������ �������� ������ ������ � ������
	friend istream& operator>>(istream &in, clinic&);//������������ �������� ����� ������ � ����
	//------------------------------------------------ ���������� ---------------------------------
	~clinic();
};

