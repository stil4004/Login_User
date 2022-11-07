#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "Authorization.h"

using namespace std;

bool IsLoggedIn()
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

int menu();

int main()
{
	menu();
}


int menu() {
	Authorization loger;

	int* choice = new int();

	cout << "1: Register\n2: Login\nYour choice: ";
	cin >> *choice;

	if (*choice == 1) {
		Person* user = new Person();

		loger.Register_User(user);

		menu();
	}
	else if (*choice == 2) {
		bool status = loger.Auth_User();

		if (!status) {
			cout << "False Login!";
			system("PAUSE");
			return 0;
		}
		else
		{
			cout << "Succesfully loged!";
			system("PAUSE");
			return 1;
		}
	}

	delete choice;
}
