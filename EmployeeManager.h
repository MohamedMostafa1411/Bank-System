#pragma once
class EmployeeManager
{
public:
	static void printEmployeeMenu() {
		cout << "Please choose between :" << endl << "1)Add Client" << endl << "2)Search For Client" << endl
			<< "3)List All Clients" << endl << "4)Edit Client" << endl << "5)Display" << endl;
	}

	static void newClient(Client& client) {
		Employee e;
		e.addClient(client);
	}

	static void listAllClients() {
		Employee e;
		e.listClients();
	}

	static Client* searchForClient(int id) {
		Employee e;
		return e.searchClient(id);
	}

	static void editClientInfo(int id, string name, string password, double salary) {
		Employee e;
		e.editClient(id, name, password, salary);
	}

	static Employee* Login(int id, string password) {
		Employee employee;
		for (int i = 0; i <= 0; i++) {
			if (Admin::employeeList.at(i).getID() == id) {
				if (Admin::employeeList.at(i).getPassword() == password) {
					return &Admin::employeeList.at(i);
					break;
				}
				else {
					return &employee;
				}
			}
		}
	}

};

