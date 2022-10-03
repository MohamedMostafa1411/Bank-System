#pragma once
class Parser
{
public:
	static vector<string> split(string line, char delim, vector<string> vec) {
		stringstream ss(line);
		string token;
		while (getline(ss, token, delim)) {
			vec.push_back(token);
		}
		return vec;
	}

	static Client parseToClient(string line) {
		vector<string> tempVector;
		int tempID;
		double tempBalance;
		string tempName, tempPassword;
		//{1,"Mohamed","Mostafa","1234",5000}
		tempID = stoi(split(line, ' ', tempVector)[0]);
		tempName = split(line, ' ', tempVector)[1] + ' ' + split(line, ' ', tempVector)[2];
		tempPassword = split(line, ' ', tempVector)[3];
		tempBalance = stod(split(line, ' ', tempVector)[4]);
		Client client(tempID, tempName, tempPassword, tempBalance);
		return client;
	}

	static Employee parseToEmployee(string line) {
		vector<string> tempVector;
		int tempID;
		double tempSalary;
		string tempName, tempPassword;
		tempID = stoi(split(line, ' ', tempVector)[0]);
		tempName = split(line, ' ', tempVector)[1] + ' ' + split(line, ' ', tempVector)[2];
		tempPassword = split(line, ' ', tempVector)[3];
		tempSalary = stod(split(line, ' ', tempVector)[4]);
		Employee employee(tempID, tempName, tempPassword, tempSalary);
		return employee;
	}

	static Admin parseToAdmin(string line) {
		vector<string> tempVector;
		int tempID;
		double tempSalary;
		string tempName, tempPassword;
		tempID = stoi(split(line, ' ', tempVector)[0]);
		tempName = split(line, ' ', tempVector)[1] + ' ' + split(line, ' ', tempVector)[2];
		tempPassword = split(line, ' ', tempVector)[3];
		tempSalary = stod(split(line, ' ', tempVector)[4]);
		Admin admin(tempID, tempName, tempPassword, tempSalary);
		return admin;
	}

};

