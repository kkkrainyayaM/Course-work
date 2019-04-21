#pragma once
#include "Employee.h"
class User : public Employee {
public:
	User() {
	}
	User(int id, string n, string l, string p) : Employee(id, n, l, p, Role::USER) {
	}
	~User() {
		Employee::~Employee();
	}
	void myBuy();

	void toString();
	friend ostream& operator<< (ostream& s, User& p);
};