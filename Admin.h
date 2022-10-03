#pragma once
#include "Employee.h"
class Admin : public Employee
{
public:
	static vector<Employee> employeeList;
	static vector<Admin> adminList;
	Admin() {}

	Admin(int id, string name, string password, double salary) : Employee(id, name, password, salary) {}

	void addEmployee(Employee& employee) {
		employeeList.push_back(employee);
	}

	Employee* searchEmployee(int id) {
		for (int i = 0; i < employeeList.size(); i++) {
			if (employeeList[i].getID() == id) {
				return &employeeList[i];
				break;
			}
		}
	}

	void listEmployees() {
		for (int i = 0; i < employeeList.size(); i++) {
			employeeList[i].display();
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
	}

	void editEmployee(int id, string name, string password, double salary) {
		bool test = false;
		for (int i = 0; i < employeeList.size(); i++) {
			if (employeeList[i].getID() == id) {
				employeeList[i].setName(name);
				employeeList[i].setPassword(password);
				employeeList[i].setSalary(salary);
				test = true;
				break;
			}
		}
		if (test == false) {
			cout << "Client not found" << endl;
		}
	}
};

