#pragma once
#include <string>

using namespace std;

// For better experience of using parametres of users made class for them
class Person
{
public:

	// Typical parametres of user
	string username;
	string password;

	// Some constructors
	Person()
	{
		username = "";
		password = "";
	}

	Person(string name, string _password)
	{
		username = name;
		password = _password;
	}

	Person(string name, int _password)
	{
		username = name;
		password = to_string(_password);
	}

	~Person()
	{

	}
};

