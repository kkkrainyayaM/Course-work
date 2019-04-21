#include "Employee.h"
void Employee::setName(string name) {
	this->name = name;
}

string Employee::getName() {
	return this->name;
}

int Employee::getID() {
	return ID;
}
void Employee::setLog(string login) {
	this->login = login;
}

void Employee::setID(int id) {
	ID = id;
}

void Employee::setPas() {
	int q = 0;
	while (q == 0) {
		cout << "Введите пароль: ";
		cin >> password;
		if ((password.length() > 4) && (password.length() < 14)) {
			q = 1;
			break;
		}
		else {
			cout << "Повторите ввод! Длина пароля не должна быть меньше 5 и больше 15 символов!" << endl;
			cin.clear();
		}
	}
	Encryptor::codePassword(&password);
}

string Employee::getLogin() {
	return this->login;
}
string Employee::getPassword() {
	return this->password;
}

void Employee::setRole(Role role) {
	this->role = role;
}

void Employee::toString() {
	Encryptor::decodePassword(&password);
	cout << setw(8) << "Имя: " << setw(10) << name << endl
		<< setw(8) << "Логин: " << setw(10) << login << endl
		<< setw(8) << "Пароль: " << setw(10) << password << endl;
}

Role Employee::getRole() {
	return role;
}