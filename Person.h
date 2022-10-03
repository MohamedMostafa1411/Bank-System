#pragma once
using namespace std;
class Person
{
protected:
	string name, password;
	int id;
public:
	Person() {}
	Person(int id, string name, string password)
	{
		this->id = id;
		this->name = name;
		this->password = password;

	}
	void setName(string name)
	{
		this->name = name;
	}
	void setPassword(string password)
	{
		this->password = password;
	}
	void setID(int id)
	{
		this->id = id;
	}
	string getName()
	{
		return name;
	}
	string getPassword()
	{
		return password;
	}
	int getID()
	{
		return id;
	}
	virtual void display() = 0;
};

