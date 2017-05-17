#pragma once
#include "List.h"
#include <iostream>
#include <iomanip>
#include <typeinfo>
#include <string>
#include <fstream>
using namespace std;

// ����������� �� �������������
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

// �����, ���� �������� ��������� �������� �� ���������
bool list::empty() const
{
	if (!len) return true;
	else return false;
}

// �����, ���� �������� ������ ������� �� ������
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
		// ����������� ��������� � ���������� �������
		tmp->next = cur->next;
		cur->next->prev = tmp;
		// �������� �� �� ��� ����������
		cur->next = tmp;
		tmp->prev = cur;
	}
	cur = cur->next;
	len++;
}

// �����, ���� �������� �������� ������� � ������
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
			delete tmp->dat; // �������� ������� �� ���'��
			delete tmp; // �������� ����� ������� ���'���
		}
		else if (len == 1) 
		{
			tmp = cur;
			cur = NULL;
		}
		len--;
	}
}


// �����, ���� �������� �������� ������
void list::clear()
{
	if (!len) 
		cout << "Collection is empty" << endl << endl;
	else 
		while (len != 0) 
			this->pop();
}

// �����, ���� �������� ������� ���� ������ �� ����� 
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


// �����, ���� �������� �������� ��� � ����
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
			if (typeid(*(temp->dat)) == typeid(hospital)) //���������� �� ���� ����������
			{
				out << 1 << ' '; //�������� �������������
				out << (*((hospital*)(temp->dat)));
				temp = temp->next;
				k++;
			}
			if (len == k)
				break;
			if (typeid(*(temp->dat)) == typeid(clinic)) //���� ���� ����������
			{
				out << 2 << ' '; //�������� �������������
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

// �����, ���� �������� ������� ��� � �����
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
		in >> k; //������� �������������
		while (!in.eof()) //���� �� ����� �����
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
			in >> k; //������� �������������
		}
		in.close();
	}
}

// �����, ���� �������� �������� ����� 
int list::search(string str) 
{
	node *tmp = cur;
	int sum = 0;
	for (int i = 0; i < len-1; i++)
	{
		if (tmp->dat->get_city() == str) //���� ����� ����������
			sum += tmp->dat->get_number_of_employees();
		tmp = tmp->next;
	}
	if (tmp->dat->get_city() == str) 
		sum += tmp->dat->get_number_of_employees();
	return sum;
}

// ����������
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




