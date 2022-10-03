#pragma once
#include "DataSourceInterface.h"
class FileManager :
    public DataSourceInterface
{
public:
	void addClient(Client& client) {
		string clientData = to_string(client.getID()) + ' ' + client.getName() + ' ' + client.getPassword() + ' ' + to_string(client.getBalance());
		ofstream clientIN("Client.txt", ios::app);
		if (clientIN.is_open()) {
			clientIN << clientData << endl;
		}
		else {
			cout << "Error!, file in not found" << endl;
		}
		clientIN.close();
	}

	void addEmployee(Employee& employee) {
		string employeeData = to_string(employee.getID()) + ' ' + employee.getName() + ' ' + employee.getPassword() + ' ' + to_string(employee.getSalary());
		ofstream employeeIN("Employee.txt", ios::app);
		if (employeeIN.is_open()) {
			employeeIN << employeeData << endl;
		}
		else {
			cout << "Error!, file in not found" << endl;
		}
		employeeIN.close();
	}

	void addAdmin(Admin& admin) {
		string adminData = to_string(admin.getID()) + ' ' + admin.getName() + ' ' + admin.getPassword() + ' ' + to_string(admin.getSalary());
		ofstream adminIN("Admin.txt", ios::app);
		if (adminIN.is_open()) {
			adminIN << adminData << endl;
		}
		else {
			cout << "Error!, file in not found" << endl;
		}
		adminIN.close();
	}

	vector<Client> getAllClients() {
		vector<Client> clientList;
		ifstream clientOUT("Client.txt");
		if (clientOUT.is_open()) {
			string temp;
			Client tempClient;
			while (getline(clientOUT, temp)) {
				tempClient = Parser::parseToClient(temp);
				clientList.push_back(tempClient);
			}
		}
		else {

		}
		clientOUT.close();
		return clientList;
	}

	vector<Employee> getAllEmployees() {
		vector<Employee> employeeList;
		ifstream employeeOUT("Employee.txt");
		if (employeeOUT.is_open()) {
			string temp;
			Employee tempEmployee;
			while (getline(employeeOUT, temp)) {
				tempEmployee = Parser::parseToEmployee(temp);
				employeeList.push_back(tempEmployee);
			}
		}
		else {

		}
		employeeOUT.close();
		return employeeList;
	}

	vector<Admin> getAllAdmins() {
		vector<Admin> adminList;
		ifstream adminOUT("Admin.txt");
		if (adminOUT.is_open()) {
			string temp;
			Admin tempAdmin;
			while (getline(adminOUT, temp)) {
				tempAdmin = Parser::parseToAdmin(temp);
				adminList.push_back(tempAdmin);
			}
		}
		else {

		}
		adminOUT.close();
		return adminList;
	}

	void removeAllClients() {
		ofstream clientList("Client.txt", ios::trunc);
		clientList.close();
	}

	void removeAllEmployees() {
		ofstream employeeList("Employee.txt", ios::trunc);
		employeeList.close();
	}

	void removeAllAdmins() {
		ofstream adminList("Admin.txt", ios::trunc);
		adminList.close();
	}
};

