#pragma once
class FilesHelper
{
public:
	static void saveClient(string fileName, Client client) {
		string clientData = to_string(client.getID()) + ' ' + client.getName() + ' ' + client.getPassword() + ' ' + to_string(client.getBalance());
		ofstream clientIN(fileName, ios::app);
		if (clientIN.is_open()) {
			clientIN << clientData << endl;
		}
		else {
			cout << "Error!, file in not found" << endl;
		}
		clientIN.close();
	}

	static void saveEmployee(string fileName, Employee employee) {
		string employeeData = to_string(employee.getID()) + ' ' + employee.getName() + ' ' + employee.getPassword() + ' ' + to_string(employee.getSalary());
		ofstream employeeIN(fileName, ios::app);
		if (employeeIN.is_open()) {
			employeeIN << employeeData << endl;
		}
		else {
			cout << "Error!, file in not found" << endl;
		}
		employeeIN.close();
	}

	static void saveAdmin(string fileName, Admin admin) {
		string adminData = to_string(admin.getID()) + ' ' + admin.getName() + ' ' + admin.getPassword() + ' ' + to_string(admin.getSalary());
		ofstream adminIN(fileName, ios::app);
		if (adminIN.is_open()) {
			adminIN << adminData << endl;
		}
		else {
			cout << "Error!, file in not found" << endl;
		}
		adminIN.close();
	}

	static vector <Client> getClientsList() {
		FileManager manager;
		return manager.getAllClients();
	};

	static vector <Employee> getEmployeesList() {
		FileManager manager;
		return manager.getAllEmployees();
	};

	static vector <Admin> getAdminList() {
		FileManager manager;
		return manager.getAllAdmins();
	};

	static void getClients() {
		ifstream clientIN("Client.txt");
		if (clientIN.is_open()) {
			string temp;
			Client tempClient;
			while (getline(clientIN, temp)) {
				tempClient = Parser::parseToClient(temp);
				tempClient.display();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
		}
		else {
			cout << "Error! File not found" << endl;
		}
		clientIN.close();
	};

	static void getEmployees() {
		ifstream employeeIN("Employee.txt");
		if (employeeIN.is_open()) {
			string temp;
			Employee tempEmployee;
			while (getline(employeeIN, temp)) {
				tempEmployee = Parser::parseToEmployee(temp);
				tempEmployee.display();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
		}
		else {
			cout << "Error! File not found" << endl;
		}
		employeeIN.close();
	}

	static void getAdmins() {
		ifstream adminIN("Admin.txt");
		if (adminIN.is_open()) {
			string temp;
			Admin tempAdmin;
			while (getline(adminIN, temp)) {
				tempAdmin = Parser::parseToAdmin(temp);
				tempAdmin.display();
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
		}
		else {
			cout << "Error! File not found" << endl;
		}
		adminIN.close();
	}

	static void clearFile(string fileName) {
		FileManager manager;
		manager.removeAllAdmins();

	}

	static void updateData(string fileName) {
		for (int i = 0; i < Employee::clientList.size(); i++) {
			FilesHelper::saveClient("Temp.txt", Employee::clientList.at(i));
		}
		char tempFileName[] = "Client.txt";
		remove(tempFileName);
		rename("Temp.txt", tempFileName);
	}
};

