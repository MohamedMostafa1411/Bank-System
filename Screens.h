#pragma once
class Screens
{
public:
	static void bankName() {
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << "\t\tRoute Bank" << endl << flush;
	}

	static void welcome() {
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "  Welcome To Route Bank" << endl << flush;
		Sleep(2000);
	}
	static void loginOptions() {
		cout << "Please Choose a Login Option:" << endl;
		cout << "1)Client" << endl << "2)Employee" << endl << "3)Admin" << endl;
	}

	static int loginAs() {
		int x;
		cin >> x;
		return x;
	}

	static void invalid() {
		cout << "Invalid Input" << endl;
	}

	static void loginScreen(int& id, string& password) {
		int tempID;
		string tempPassword;
		cout << "Please Enter Your ID:" << endl;
		cin >> tempID;
		cout << "Please Enter Your Password" << endl;
		cin >> tempPassword;
		id = tempID;
		password = tempPassword;
	}
};

