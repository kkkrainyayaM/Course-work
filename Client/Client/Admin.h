#pragma once
#include "Employee.h"
using namespace std;
class Admin : public Employee {

public:
	Admin() : Employee() {
	};
	Admin(int id, string n, string l, string p) : Employee(id, n, l, p, Role::ADMIN) {
	};

	Admin(const Admin& Admin) : Employee(Admin) {
	}

	~Admin() {
		Employee::~Employee();
	}
	void toString();

	void printInfo() {
		cout << "Èìÿ: " << getName() << endl;
	}

	friend ostream& operator<< (ostream& s, Admin& Admin);
};
