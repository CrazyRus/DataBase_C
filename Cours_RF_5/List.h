#include "medical_institution.h"
#include "clinic.h"
#include "hospital.h"

struct node
{
	medical_institution *dat; //Вказівник на медичну установу
	node *next; //Вказівник на наступний елемент
	node *prev; //Вказівник на попередній елемент
};

class list
{
private:
	node *cur;
	int len;
public:
	list();
	list(const list&);
	//------------------------------------------------ Методи ---------------------------------
	void push(medical_institution **);
	void pop();
	bool empty() const;
	void clear();
	void display() const;
	void save() const;
	int search(string);
	void load();
	//------------------------------------------------ Деструктор ---------------------------------
	~list();
};


