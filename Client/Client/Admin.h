#pragma once
#include "Employee.h"
using namespace std;
class Seller : public Employee {

public:
	Seller() : Employee() {};
	Seller(int id, string l, string p) : Employee(id, l, p,/* Role::SELLER*/) {};
	Seller(const Seller& seller) : Employee(seller) {}

	~Seller() {
		Employee::~Employee();
}
	//void toString();

	friend ostream& operator<< (ostream& s, Seller& seller);
};
