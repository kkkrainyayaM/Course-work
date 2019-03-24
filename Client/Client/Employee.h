#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
//#include "IDGenerator.h"
//#include "Encryptor.cpp"
//#include "Role.h"
using namespace std;
using std::string;
#if defined(max)
#undef max
#endif

class Employee {
private:

	int ID;
	string login;
	string password;
	//Role role;

public:
	Employee() {
		login = "";
		password = "";
	};

	Employee(int id, string l, string p, /*Role role*/) {
		ID = id;
		login = l;
		password = p;
		/*this->role = role*/;
	}

	Employee(const Employee &user) {
		ID = user.ID;
		login = user.login;
		password = user.password;
		/*role = user.role*/;
	}
	virtual ~Employee() {}
	//void toString();
	void setLog();
	void setPas();
	//void setRole(Role role);
	int getID();
	void setID(int id);
	string getLogin();
	string getPassword();
	//Role getRole();
};
