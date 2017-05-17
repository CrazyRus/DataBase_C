#pragma once
#include "List.h"
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <fstream>
using namespace std;

// Конструктор за замовчуванням
list::list() 
{
	cur = NULL;
	len = 0;
}

list::list(const list & obj) 
{
	cur = obj.cur;
	len = obj.len;
}

// Метод, який дозволяє перевірити колекцію на порожність
bool list::empty() const
{
	if (!len) return true;
	else return false;
}

// Метод, який дозволяє додати елемент до списку
void list::push(medical_institution **obj_inp) 
{
	node *tmp = new node;
	tmp->dat = *obj_inp;
	if (!cur) 
	{
		cur = tmp;
		cur->next = cur;
		cur->prev = cur;
	}
	else
	{
		// Розтавляємо вказівники в утвореному елементі
		tmp->next = cur->next;
		cur->next->prev = tmp;
		// Скріпюємо їх із уже створеними
		cur->next = tmp;
		tmp->prev = cur;
	}
	cur = cur->next;
	len++;
}

// Метод, який дозволяє видалити елемент зі списку
void list::pop() 
{
	node *tmp = cur;
	if (empty()) 
		cout << "Collection is empty!" << endl << endl;
	else 
	{
		if (len > 1)
		{
			cur = cur->prev;
			cur->next = tmp->next;
			tmp->next->prev = cur;
			delete tmp->dat; // Удаляємо елемент із пам'яті
			delete tmp; // Удаляємо вільно виділену пам'ять
		}
		else if (len == 1) 
		{
			tmp = cur;
			cur = NULL;
		}
		len--;
	}
}


// Метод, який дозволяє очистити список
void list::clear()
{
	if (!len) 
		cout << "Collection is empty" << endl << endl;
	else 
		while (len != 0) 
			this->pop();
}

// Метод, який дозволяє вивести весь список на екран 
void list::display() const 
{
	int tmp_len = len;
	node *tmp = cur;
	if (empty())
		cout << "Empty collection" << endl << endl;
	else 
		while (tmp_len--)
		{
			tmp->dat->show();
			tmp = tmp->prev;
		}
}


// Метод, який дозволяє зберегти дані в файл
void list::save() const
{
	node *temp = cur;
	int k = 0;
	if (empty()) 
		cout << "Can't write to file, because our collection is empty!" << endl << endl;
	else
	{
		ofstream out;
		out.open("info.dat");
		do 
		{
			if (typeid(*(temp->dat)) == typeid(hospital)) //Перевіряємо чи типи співпадають
			{
				out << 1 << ' '; //Записуємо ідентифікатор
				out << (*((hospital*)(temp->dat)));
				temp = temp->next;
				k++;
			}
			if (len == k)
				break;
			if (typeid(*(temp->dat)) == typeid(clinic)) //Якщо типи співпадають
			{
				out << 2 << ' '; //Записуємо ідентифікатор
				out << (*((clinic*)(temp->dat)));
				temp = temp->next;
				k++;
			}
			if (len == k)
				break;
		}
		while (temp != cur);
	}
	cout << " Collection save" << endl;
}

// Метод, який дозволяє зчитати дані з файла
void list::load()
{
	if (empty())
		cout << "Can't load from file, because our collection is empty!" << endl << endl;
	else
	{
		ifstream in;
		in.open("info.dat");
		hospital *hospital_obj;
		clinic *clinic_obj;
		medical_institution *dat;
		int k, count = 0;
		in >> k; //зчитуємо ідентифікатор
		while (!in.eof()) //поки не кінець файла
		{
			if (k == 1)
			{
				hospital_obj = new hospital();
				in >> (*hospital_obj);
				dat = hospital_obj;
				this->push(&dat);
				count++;
			}
			if (k == 2)
			{
				clinic_obj = new clinic();
				in >> (*clinic_obj);
				dat = clinic_obj;
				this->push(&dat);
				count++;
			}
			in >> k; //зчитуємо ідентифікатор
		}
		in.close();
	}
}

// Метод, який дозволяє виконати пошук 
int list::search(string str) 
{
	node *tmp = cur;
	int sum = 0;
	for (int i = 0; i < len-1; i++)
	{
		if (tmp->dat->get_city() == str) //якщо назви співпадають
			sum += tmp->dat->get_number_of_employees();
		tmp = tmp->next;
	}
	if (tmp->dat->get_city() == str) 
		sum += tmp->dat->get_number_of_employees();
	return sum;
}

// Деструктор
list::~list() 
{
	if (!len)
		cout << "Collection's dat was deleted" << endl;
	else 
	{
		while (len)
			this->pop();
	}
}




