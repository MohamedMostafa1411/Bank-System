#pragma once
#include "Person.h"
class Client : public Person
{
private:
	double balance;
public:
	Client()
	{
		this->balance = 1500;
	}
	Client(int id, string name, string password, double balance) :Person(id, name, password)
	{
		this->balance = balance;
	}
	void setBalance(double balance)
	{
		this->balance = balance;
	}
	double getBalance()
	{
		return balance;
	}
	void display()
	{
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Password : " << password << endl;
		cout << "Balance : " << balance << endl;
	}
	void deposit(double amount)
	{
		balance += amount;
	}
	void withdraw(double amount)
	{
		balance -= amount;
	}
	void checkBalance()
	{
		cout << "Balance = " << balance << endl;
	}
	void transferTo(double amount, Client* recipient)
	{
		balance -= amount;
		recipient->balance += amount;
	}
};

