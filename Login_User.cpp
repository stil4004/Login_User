#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include "Person.h"
#include "Authorization.h"

using namespace std;

int menu();

int main()
{
	menu();
}





int menu() {
	Authorization loger; // Creating object of Auth class

	int* choice = new int(); // User choice variable

	system("CLS"); // Sometimes clear console for beter experience

	cout << "1: Register\n2: Login\nYour choice: ";
	cin >> *choice;

	if (*choice == 1) {

		// If user want to register, we register it idk
		Person* user = new Person();

		system("CLS");
		loger.Register_User(user); // Using method of class
		system("CLS");

		menu(); // Recreating menu
		delete user;

	}
	else if (*choice == 2) {

		// Auth parametr of menu
		system("CLS");
		bool status = loger.Auth_User();
		system("CLS");

		if (!status)	
		{
			cout << "False Login!\nTry Again\n";
			menu();
		}
		else
		{
			cout << "Succesfully loged!";
			system("PAUSE");
			// Add some user features (now only return :3)
			return 1;
		}
	}

	delete choice;
}
