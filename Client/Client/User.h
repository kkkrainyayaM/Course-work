#pragma once
#include "Employee.h"
class Participant : public Employee {
public:
	Participant() {
	}
	Participant(int id, string l, string p) : Employee(id, l, p, /*Role::PARTICIPANT*/) {
	}
	~Participant() {
		Employee::~Employee();
	}
	//void toString();

	friend ostream& operator<< (ostream& s, Participant& p);
};