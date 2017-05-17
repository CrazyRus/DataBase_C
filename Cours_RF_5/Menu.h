#pragma once//�������������� �������������� �����
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
	list *collection; //O�'��� ���� "������"
	//------------------------------------------------ ������ ---------------------------------
	static Menu& get_instance();//������������ ���������� ���������� ��� ������������
	void u_menu();
	void CreateHospital();
	void CreateClinic();
	void Watch();
	void SaveFile();
	void LoadFile();
	void Search();
	void Clear();
	void DeleteLast();
	//------------------------------------------------ ���������� ---------------------------------
	~Menu();
};


