#pragma once
class ClientManager
{
public:
	static void printClientMenu() {
		cout << "Please choose between :" << endl << "1)Withdraw" << endl << "2)Deposit" << endl << "3)Transfer" << endl
			<< "4)Check Balance" << endl << "5)Display" << endl << "6)Exit Program" << endl;
	}
	/*static void updateClient(Client client) {
		int counter = 1;
		string temp;
		string newData = to_string(client.getID()) + ' ' + client.getName() + ' ' + client.getPassword() + ' ' + to_string(client.getBalance());
		ifstream oldFile("Client.txt");
		ofstream newFile("Temp.txt");
		if (!oldFile.is_open() || !newFile.is_open()) {
			cout << "Error! Files not open" << endl;
		}
		while (getline(oldFile, temp)) {
			if (counter == client.getID()) {
				temp = newData;
			}
			counter++;
			temp += "\n";
			newFile << temp;
		}
		oldFile.close();
		newFile.close();
		char fileName[] = "Client.txt";
		remove(fileName);
		rename("Temp.txt", fileName);
	}*/

	static void updatePassword(Client client) {
		for (int i = 0; i < client.getID(); i++) {
			if (Employee::clientList.at(i).getID() == client.getID()) {
				Employee::clientList.at(i) = client;
				break;
			}
		}
	}

	//must check in main if the id is smaller than the number of clients in clientList
	//must check if the return client is empty to make sure the password is correct
	static Client* Login(int id, string password) {
		Client client;
		for (int i = 0; i >= 0; i++) {
			if (Employee::clientList.at(i).getID() == id) {
				if (Employee::clientList.at(i).getPassword() == password) {
					return &Employee::clientList.at(i);
					break;
				}
				else {
					return &client;
				}
			}
		}
	}

	static Client* getClient(int id) {
		for (int i = 0; i < Employee::clientList.size(); i++) {
			if (Employee::clientList.at(i).getID() == id) {
				return &Employee::clientList.at(i);
				break;
			}
		}
	}

	/*static Client login(int id, string password) {
		FileManager manager;
		Client client;
		for (int i = 0; i < id; i++) {
			if (manager.getAllClients().at(i).getID() == id) {
				if (manager.getAllClients().at(i).getPassword() == password) {
					return manager.getAllClients().at(i);
				}
				else {
					return client;
				}
			}
		}
	}*/

};

