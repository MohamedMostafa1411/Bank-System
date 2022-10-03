#pragma once
#include "Person.h"
class Employee : public Person
{
protected:
	double salary;
public:
	static vector<Client> clientList;

	Employee()
	{
		salary = 5000;
	}

	Employee(int id, string name, string password, double salary) : Person(id, name, password)
	{
		this->salary = salary;
	}

	void setSalary(double salary)
	{
		this->salary = salary;
	}

	double getSalary()
	{
		return salary;
	}

	void display()
	{
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Password : " << password << endl;
		cout << "Salary : " << salary << endl;
	}

	void addClient(Client& client) {
		clientList.push_back(client);
	}

	Client* searchClient(int id) {
		for (int i = 0; i < clientList.size(); i++) {
			if (clientList[i].getID() == id) {
				return &clientList[i];
				break;
			}
		}
	}

	void listClients() {
		for (int i = 0; i < clientList.size(); i++) {
			clientList[i].display();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
	}

	void editClient(int id, string name, string password, double balance) {
		bool temp = false;
		for (int i = 0; i < clientList.size(); i++) {
			if (clientList[i].getID() == id) {
				clientList[i].setName(name);
				clientList[i].setPassword(password);
				clientList[i].setBalance(balance);
				temp = true;
				break;
			}
		}
		if (temp == false) {
			cout << "Client not found" << endl;
		}
	}
};
