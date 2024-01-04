#include<stdio.h>
#include<string>
#include<cctype>
#include<iostream>
#include<fstream>
using namespace std;



string** Account(string** Students, int& r)
{
	int newsize = r + 1;
	string** newAccount = nullptr;
	newAccount = new string * [newsize];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			newAccount[i][j] = Students[i][j];
		}
	}
	cout << "Enter name: ";
	getline(cin, newAccount[newsize - 1][0]);

	cout << "Enter DOB: ";
	getline(cin, newAccount[newsize - 1][1]);

	cout << "Enter Username: ";
	getline(cin, newAccount[newsize - 1][2]);

	cout << "Enter Password: ";
	getline(cin, newAccount[newsize - 1][3]);

	long range = 1599999 - 1500000 + 1;
	long ID = 1500000 + rand() % (range);
	newAccount[newsize - 1][4] = to_string(ID);
	r = newsize;
	return newAccount;

}

void resetPassword(string** Students, int r)
{
	string newPassword;
	do
	{
		cout << "Enter the new Password: ";
		getline(cin, newPassword);
	} while (newPassword.compare(Students[r][3]) == 0);

	Students[r][3] = newPassword;
}


void Display(string** Students, int r)
{
	cout << "Name" << Students[r][0];
	cout << "DOB" << Students[r][1];
	cout << "Username" << Students[r][2];
	cout << "Password" << Students[r][3];
	cout << "Id" << Students[r][4];

}

void login(string** Students, int& r)
{
	string response;
	string usernameInput;
	string passwordInput;

	for (int i = 0; i < r; i++)
	{
		if (Students[r][2] == usernameInput)
		{
			if (Students[r][3] == passwordInput)
			{
				Display(Students, r);
				break;
			}
			else
			{
				cout << "Do you want to reset Password, y or n.";
				cin >> response;
				if (response == "y")
				{
					resetPassword(Students, r);
				}
				break;

			}

		}
	}
	if (Students[r][2] != usernameInput)
	{
		cout << "You are not in the Data Base. ";
		Students = Account(Students, r);
	}

}

void  saveInfo(string** Students, int r)
{
	ofstream ofile;
	ofile.open("login_DB.CSV");
	
	string date;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			date += Students[i][j];
			if (j < 4)
				date += ",";
		}
		date += "\n";
	}
	ofile << date;
}

int main()
{
	
	int r = 1;
	string** Students = nullptr;
	Students = new string * [r];
	Students[0][0] = "Rick";
	Students[0][1] = "7/21/1892";
	Students[0][2] = "Rick1892";
	Students[0][3] = "1234";
	Students[0][4] = "1500001";
	int choice;
	bool online = true;
	while (online)
	{
		cout << "Pick which option" << endl;
		cout << "1.)login\n2.)save students\n3.)exit";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 1:
			login(Students, r);
			break;
		case 2:
			saveInfo(Students, r);
			break;
		case 3:
			online = false;
			break;
		default:
			cout << "Invalid input" << endl;
		}

	}
	
}

