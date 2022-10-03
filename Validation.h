#pragma once
class Validation
{
public:
	static bool nameValidation(string const& name)
	{
		if (name.length() < 5 || name.length() > 20)
		{
			return false;
		}
		else
		{

			return name.find_first_not_of("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
				string::npos;
		}
	}

	static bool passwordValidation(string password)
	{
		if (password.length() < 8 || password.length() > 20)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	static bool balanceValidation(double balance)
	{
		if (balance < 1500)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	static bool salaryValidation(double salary)
	{
		if (salary < 5000)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

