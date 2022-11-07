#pragma once
#include <string>

using namespace std;

class Person
{
public:
	string username;
	string password;
	string auth_time;

	Person() {
		username = "";
		password = "";
	}

	Person(string name, string _password) {
		username = name;
		password = _password;
	}

	Person(string name, int _password) {
		username = name;
		password = to_string(_password);
	}
};

