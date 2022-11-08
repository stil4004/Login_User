#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <string>
#include "Person.h"
#include <iostream>
#include "Logs.h"

using namespace std;

class Authorization
{
public:

	void Register_User(Person *user)
	{

		// Inputing user account information
		cout << "select a username: "; cin >> user->username;
		cout << "select a password: "; cin >> user->password;


		// Making file in DB
		ofstream file;

		file.open("LogedUsers\\" + user->username + ".txt");
		file << user->username << endl << user->password << endl;
		file.close();

		// Loging registration
		Logs::log_Register_User(user);
	}

	bool Auth_User()
	{
		string username, password, _username, _password; // make different string for user input Un and Pw, and Data Base Un and Pw

		// User input
		cout << "Enter username: "; cin >> username; 
		cout << "Enter password: "; cin >> password;

		// Checking in DB
		ifstream read("LogedUsers\\" + username + ".txt");
		getline(read, _username);
		getline(read, _password);

		if (_username == username && _password == password)
		{
			Logs::log_Auth_User(Person(_username, _password)); // If right making log of authorization
			return true;
		}
		else
		{
			// Should make log of wrong auth
			return false;
		}

	}
};

