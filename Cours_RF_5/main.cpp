#include <iostream> 
#include "Menu.h"
using namespace std;

void main()
{
	system("color F0");//Встановлення білого фону екрану
	Menu::get_instance().u_menu();
	system("pause");
}