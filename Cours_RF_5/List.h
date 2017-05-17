#include "medical_institution.h"
#include "clinic.h"
#include "hospital.h"

struct node
{
	medical_institution *dat; //�������� �� ������� ��������
	node *next; //�������� �� ��������� �������
	node *prev; //�������� �� ��������� �������
};

class list
{
private:
	node *cur;
	int len;
public:
	list();
	list(const list&);
	//------------------------------------------------ ������ ---------------------------------
	void push(medical_institution **);
	void pop();
	bool empty() const;
	void clear();
	void display() const;
	void save() const;
	int search(string);
	void load();
	//------------------------------------------------ ���������� ---------------------------------
	~list();
};


