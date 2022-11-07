#pragma once

#include <fstream>
#include <string>
#include "Person.h"
#include <iostream>

using namespace std;

class Authorization
{
public:

	void Register_User(Person *user) {
		cout << "select a username: "; cin >> user->username;
		cout << "select a password: "; cin >> user->password;

		ofstream file;

		file.open("Z:\\" + user->username + ".txt");
		file << user->username << endl << user->password;
		file.close();
	}

	bool Auth_User()
	{
		string username, password, _username, _password;

		cout << "Enter username: "; cin >> username;
		cout << "Enter password: "; cin >> password;

		ifstream read("Z:\\" + username + ".txt");
		getline(read, _username);
		getline(read, _password);

		if (_username == username && _password == password)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
};

