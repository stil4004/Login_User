#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

 class Logs
{
public:
	static void log_Auth_User(Person user)
	{
		// Getting moment time
		time_t now = time(0);
		char* dt = ctime(&now);

		// Add log of auth in Logs.txt file
		ofstream file;

		file.open("Logs\\Logs.txt", ios::app);
		file << user.username + " authorized at << " + dt << endl;
		file.close();
	}

	static void log_Register_User(Person* user)
	{
		// Getting moment time
		time_t now = time(0);
		char* dt = ctime(&now);

		// Add log of register in Logs.txt file
		ofstream file;

		file.open("Logs\\Logs.txt", ios::app);
		file << user->username + " registered at << " + dt << endl;
		file.close();
	}

};

