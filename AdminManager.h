#pragma once
class AdminManager
{
public:
	static void printAdminMenu() {
		cout << "Please choose between :" << endl << "1)Add Client" << endl << "2)Search For Client" << endl
			<< "3)List All Clients" << endl << "4)Edit Client" << endl << "5)Add Employee" << endl << "6)Search For Employee" << endl
			<< "7)List All Employees" << endl << "8)Edit Employee" << endl << "9)Display" << endl;
	}

	static Admin* Login(int id, string password) {
		Admin admin;
		for (int i = 0; i <= 0; i++) {
			if (Admin::adminList.at(i).getID() == id) {
				if (Admin::adminList.at(i).getPassword() == password) {
					return &Admin::adminList.at(i);
					break;
				}
				else {
					return &admin;
				}
			}
		}
	}
};

