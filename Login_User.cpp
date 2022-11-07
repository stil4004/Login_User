#include <iostream>
#include <fstream>
#include <string>

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

void menu(int *var);

int main()
{
	int *choice = new int();
	menu(choice);
	if (*choice == 1) {
			string username, password;

			cout << "select a username: "; cin >> username;
			cout << "select a password: "; cin >> password;

			ofstream file;

			file.open("Z:\\" + username + ".txt");
			file << username << endl << password;
			file.close();

			main();
	}
	else if (*choice == 2){
		bool status = IsLoggedIn();

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


void menu(int *var) {
	cout << "1: Register\n2: Login\nYour choice: ";
	cin >> *var;
	//cout << var;
	//cout << *var;
}
