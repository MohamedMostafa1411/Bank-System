#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdio>
#include <Windows.h>
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Parser.h"
#include "Validation.h"
#include "DataSourceInterface.h"
#include "FileManager.h"
#include "FilesHelper.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "Screens.h"

using namespace std;
vector<Client> Employee::clientList = FilesHelper::getClientsList();
vector<Employee> Admin::employeeList = FilesHelper::getEmployeesList();
vector<Admin> Admin::adminList = FilesHelper::getAdminList();

int main()
{
	Screens::bankName();
	Screens::welcome();
	while (true) {
		system("CLS");
		Screens::loginOptions();
		int choice;
		cin >> choice;
		system("CLS");
		if (choice == 1) {
			int id;
			string password;
			Client* tempClient;
			//Must Validate the id and password manually
			system("CLS");
			while (true) {
				Screens::loginScreen(id, password);
				if (id <= 0 || id > Employee::clientList.size()) {
					cout << "Wrong ID or Password" << endl << "Please Try Again" << endl;
					continue;
				}
				else {
					bool check;
					tempClient = ClientManager::Login(id, password);
					if (tempClient->getName().size() == 0) {
						cout << "Wrong ID or Password" << endl << "Please Try Again" << endl;
						check = false;
					}
					else {
						check = true;
					}
					if (check == false) {
						continue;
					}
					else {
						break;
					}
				}
			}
			while (true) {
				system("CLS");
				ClientManager::printClientMenu();
				int temp;
				cin >> temp;
				if (temp == 1) {
					system("CLS");
					int tempAmount;
					cout << "Please Enter The Amount You Want To Withdraw:" << endl;
					cin >> tempAmount;
					if (tempAmount > tempClient->getBalance()) {
						cout << "Error! Cannot Withdraw That Amount" << endl;
					}
					tempClient->withdraw(tempAmount);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 2) {
					system("CLS");
					int tempAmount;
					cout << "Please Enter The Amount You Want To Deposit:" << endl;
					cin >> tempAmount;
					tempClient->deposit(tempAmount);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 3) {
					system("CLS");
					double tempAmount;
					int tempID;
					cout << "Please Enter The Amount You Want To Transfer:" << endl;
					cin >> tempAmount;
					while (true) {
						cout << "Please Enter The ID Of The Account You Want To Transfer To" << endl;
						cin >> tempID;
						if (tempID <= 0 || tempID > Employee::clientList.size()) {
							cout << "Error!" << endl << "Please ReEnter The ID" << endl;
							continue;
						}
						else
							break;
					}
					Client* temp = ClientManager::getClient(tempID);
					tempClient->transferTo(tempAmount, temp);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 4) {
					system("CLS");
					tempClient->checkBalance();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 5) {
					system("CLS");
					tempClient->display();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 6) {
					break;
				}
				else {
					Screens::invalid();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
			}
			FilesHelper::updateData("Client.txt");
			break;
		}
		else if (choice == 2) {
			int id;
			string password;
			Employee* tempEmployee;
			//Must Validate the id and password manually
			system("CLS");
			while (true) {
				Screens::loginScreen(id, password);
				if (id <= 0 || id > Admin::employeeList.size()) {
					cout << "Wrong ID or Password" << endl << "Please Try Again" << endl;
					continue;
				}
				else {
					bool check;
					tempEmployee = EmployeeManager::Login(id, password);
					if (tempEmployee->getName().size() == 0) {
						cout << "Wrong ID or Password" << endl << "Please Try Again" << endl;
						check = false;
					}
					else {
						check = true;
					}
					if (check == false) {
						continue;
					}
					else {
						break;
					}
				}
			}
			while (true) {
				system("CLS");
				EmployeeManager::printEmployeeMenu();
				int temp;
				cin >> temp;
				if (temp == 1) {
					string tempName, tempPassword;
					double tempBalance;
					int tempID = Employee::clientList.back().getID() + 1;
					while (true) {
						cout << "Please Enter The Client Name" << endl;
						cin.ignore();
						getline(cin, tempName);
						if (Validation::nameValidation(tempName)) {
							break;
						}
						else {
							cout << "Name Must Be Between 5 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The CLient Password" << endl;
						cin >> tempPassword;
						if (Validation::passwordValidation(tempPassword)) {
							break;
						}
						else {
							cout << "Password Must Be Between 8 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The CLient Balance" << endl;
						cin >> tempBalance;
						if (Validation::balanceValidation(tempBalance)) {
							break;
						}
						else {
							cout << "Balance Must Be At Least 1500" << endl;
							continue;
						}
					}
					Client tempClient(tempID, tempName, tempPassword, tempBalance);
					EmployeeManager::newClient(tempClient);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 2) {
					int tempID;
					while (true) {
						cout << "Please Enter The Client ID" << endl;
						cin >> tempID;
						if (tempID <= 0 || tempID > Employee::clientList.size()) {
							cout << "Wrong ID" << endl << "Please Try Again!" << endl;
							continue;
						}
						else {
							break;
						}
					}
					EmployeeManager::searchForClient(tempID)->display();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 3) {
					EmployeeManager::listAllClients();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 4) {
					int tempID;
					double tempBalance;
					string tempName, tempPassword;
					while (true) {
						bool check = false;
						cout << "Please Enter The Client ID" << endl;
						cin >> tempID;
						for (int i = 0; i < Employee::clientList.size(); i++) {
							if (Employee::clientList.at(i).getID() == tempID) {
								check = true;
								break;
							}
						}
						if (check == true) {
							break;
						}
						else {
							cout << "Wrong ID!" << endl << "Please Try Again" << endl;
							continue;
						}
					}

					while (true) {
						cout << "Please Enter The Client New Name" << endl;
						cin.ignore();
						getline(cin, tempName);
						if (Validation::nameValidation(tempName)) {
							break;
						}
						else {
							cout << "Name Must Be Between 5 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The CLient New Password" << endl;
						cin >> tempPassword;
						if (Validation::passwordValidation(tempPassword)) {
							break;
						}
						else {
							cout << "Password Must Be Between 8 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The CLient New Balance" << endl;
						cin >> tempBalance;
						if (Validation::balanceValidation(tempBalance)) {
							break;
						}
						else {
							cout << "Balance Must Be At Least 1500" << endl;
							continue;
						}
					}
					EmployeeManager::editClientInfo(tempID, tempName, tempPassword, tempBalance);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 5) {
					tempEmployee->display();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}

				}
				else {
					Screens::invalid();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
			}
			FilesHelper::updateData("Employee.txt");
			break;
		}
		else if (choice == 3) {
			int id;
			string password;
			Admin* tempAdmin;
			//Must Validate the id and password manually
			system("CLS");
			while (true) {
				Screens::loginScreen(id, password);
				if (id <= 0 || id > Admin::adminList.size()) {
					cout << "Wrong ID or Password" << endl << "Please Try Again" << endl;
					continue;
				}
				else {
					bool check;
					tempAdmin = AdminManager::Login(id, password);
					if (tempAdmin->getName().size() == 0) {
						cout << "Wrong ID or Password" << endl << "Please Try Again" << endl;
						check = false;
					}
					else {
						check = true;
					}
					if (check == false) {
						continue;
					}
					else {
						break;
					}
				}
			}
			while (true) {
				system("CLS");
				AdminManager::printAdminMenu();
				int temp;
				cin >> temp;
				if (temp == 1) {
					string tempName, tempPassword;
					double tempBalance;
					int tempID = Employee::clientList.back().getID() + 1;
					while (true) {
						cout << "Please Enter The Client Name" << endl;
						cin.ignore();
						getline(cin, tempName);
						if (Validation::nameValidation(tempName)) {
							break;
						}
						else {
							cout << "Name Must Be Between 5 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The CLient Password" << endl;
						cin >> tempPassword;
						if (Validation::passwordValidation(tempPassword)) {
							break;
						}
						else {
							cout << "Password Must Be Between 8 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The CLient Balance" << endl;
						cin >> tempBalance;
						if (Validation::balanceValidation(tempBalance)) {
							break;
						}
						else {
							cout << "Balance Must Be At Least 1500" << endl;
							continue;
						}
					}
					Client tempClient(tempID, tempName, tempPassword, tempBalance);
					EmployeeManager::newClient(tempClient);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 2) {
					int tempID;
					while (true) {
						cout << "Please Enter The Client ID" << endl;
						cin >> tempID;
						if (tempID <= 0 || tempID > Employee::clientList.size()) {
							cout << "Wrong ID" << endl << "Please Try Again!" << endl;
							continue;
						}
						else {
							break;
						}
					}
					EmployeeManager::searchForClient(tempID)->display();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 3) {
					EmployeeManager::listAllClients();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 4) {
					int tempID;
					double tempBalance;
					string tempName, tempPassword;
					while (true) {
						bool check = false;
						cout << "Please Enter The Client ID" << endl;
						cin >> tempID;
						for (int i = 0; i < Employee::clientList.size(); i++) {
							if (Employee::clientList.at(i).getID() == tempID) {
								check = true;
								break;
							}
						}
						if (check == true) {
							break;
						}
						else {
							cout << "Wrong ID!" << endl << "Please Try Again" << endl;
							continue;
						}
					}

					while (true) {
						cout << "Please Enter The Client New Name" << endl;
						cin.ignore();
						getline(cin, tempName);
						if (Validation::nameValidation(tempName)) {
							break;
						}
						else {
							cout << "Name Must Be Between 5 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The CLient New Password" << endl;
						cin >> tempPassword;
						if (Validation::passwordValidation(tempPassword)) {
							break;
						}
						else {
							cout << "Password Must Be Between 8 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The CLient New Balance" << endl;
						cin >> tempBalance;
						if (Validation::balanceValidation(tempBalance)) {
							break;
						}
						else {
							cout << "Balance Must Be At Least 1500" << endl;
							continue;
						}
					}
					EmployeeManager::editClientInfo(tempID, tempName, tempPassword, tempBalance);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 5) {
					string tempName, tempPassword;
					double tempSalary;
					int tempID = Admin::employeeList.back().getID() + 1;
					while (true) {
						cout << "Please Enter The Employee Name" << endl;
						cin.ignore();
						getline(cin, tempName);
						if (Validation::nameValidation(tempName)) {
							break;
						}
						else {
							cout << "Name Must Be Between 5 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The Employee Password" << endl;
						cin >> tempPassword;
						if (Validation::passwordValidation(tempPassword)) {
							break;
						}
						else {
							cout << "Password Must Be Between 8 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The Employee Salary" << endl;
						cin >> tempSalary;
						if (Validation::balanceValidation(tempSalary)) {
							break;
						}
						else {
							cout << "Salary Must Be At Least 5000" << endl;
							continue;
						}
					}
					Employee tempEmployee(tempID, tempName, tempPassword, tempSalary);
					tempAdmin->addEmployee(tempEmployee);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 6) {
					int tempID;
					while (true) {
						cout << "Please Enter The Employee ID" << endl;
						cin >> tempID;
						if (tempID <= 0 || tempID > Admin::employeeList.size()) {
							cout << "Wrong ID" << endl << "Please Try Again!" << endl;
							continue;
						}
						else {
							break;
						}
					}
					tempAdmin->searchEmployee(tempID)->display();

					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 7) {
					tempAdmin->listEmployees();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 8) {
					int tempID;
					double tempSalary;
					string tempName, tempPassword;
					while (true) {
						bool check = false;
						cout << "Please Enter The Employee ID" << endl;
						cin >> tempID;
						for (int i = 0; i < Admin::employeeList.size(); i++) {
							if (Admin::employeeList.at(i).getID() == tempID) {
								check = true;
								break;
							}
						}
						if (check == true) {
							break;
						}
						else {
							cout << "Wrong ID!" << endl << "Please Try Again" << endl;
							continue;
						}
					}

					while (true) {
						cout << "Please Enter The Employee New Name" << endl;
						cin.ignore();
						getline(cin, tempName);
						if (Validation::nameValidation(tempName)) {
							break;
						}
						else {
							cout << "Name Must Be Between 5 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The Employee New Password" << endl;
						cin >> tempPassword;
						if (Validation::passwordValidation(tempPassword)) {
							break;
						}
						else {
							cout << "Password Must Be Between 8 & 20 chars." << endl;
							continue;
						}
					}
					while (true) {
						cout << "Please Enter The Employee New Salary" << endl;
						cin >> tempSalary;
						if (Validation::balanceValidation(tempSalary)) {
							break;
						}
						else {
							cout << "Salary Must Be At Least 5000" << endl;
							continue;
						}
					}
					tempAdmin->editEmployee(tempID, tempName, tempPassword, tempSalary);
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else if (temp == 9) {
					tempAdmin->display();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				else {
					Screens::invalid();
					cout << "Please Choose Between:" << endl << "1)Do Another Operation" << endl << "2)Exit Program" << endl;
					int x;
					cin >> x;
					if (x == 1) {
						continue;
					}
					else if (x == 2) {
						break;
					}
					else {
						Screens::invalid();
						continue;
					}
				}
				FilesHelper::updateData("Admin.txt");
			}
			break;
		}
		else {
			Screens::invalid();
			cout << "Please Choose Between:" << endl << "1)Try Again" << endl << "2)Exit Program" << endl;
			int x;
			cin >> x;
			if (x == 1) {
				continue;
			}
			else if (x == 2) {
				break;
			}
			else {
				Screens::invalid();
				continue;
			}
		}
	}

	return 0;
}

