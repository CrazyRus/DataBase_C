#include <iostream> 
#include "Menu.h"
using namespace std;

void main()
{
	system("color F0");//������������ ����� ���� ������
	Menu::get_instance().u_menu();
	system("pause");
}