// Name: Sijan Panday
// Date: 9/11/2022
//Program Description: Data Sorting


#include<iostream>
#include<string>
#include<fstream>

using namespace std;

//pretty functions 

void fileCheck(ifstream& iFile, string text); // the file name for example iFile here, is irrelevant when using this to call a function

int getData(ifstream& iFile, string text[]);

void sortData(string text[], string text2[], int counter);

int outputMenu(string text[], string text2[]);

void output(int counter, string text[], string text2[]);

void closeFiles(ifstream& firstName, ifstream& lastName);

// the neat and gritty

int main()
{
	//declaring the files
	ifstream firstName, lastName;

	//opening the files
	firstName.open("firstname.txt");
	lastName.open("lastname.txt");

	//checking if the files are open
	fileCheck(firstName, "firstname.txt");
	fileCheck(lastName, "lastname.txt");

	//declaring the variables
	string fName[100], lName[100];

	//getting data from the files
	int fCounter = getData(firstName, fName);
	int lCounter = getData(lastName, lName);

	//output menu
	int choice = outputMenu(fName, lName);

	//letting them choose
	if (choice == 1)
	{
		cout << "Sort on First Name: " << endl;
		sortData(fName, lName, fCounter);
		output(fCounter, fName, lName);
	}
	else if (choice == 2)
	{
		cout << "Sort on Last Name: " << endl;
		sortData(lName, fName, lCounter);
		output(lCounter, lName, fName);
	}

	//closing the files
	closeFiles(firstName, lastName);
}


// function definitions 
void closeFiles(ifstream& firstName, ifstream& lastName)
{
	firstName.close();
	lastName.close();
}


void fileCheck(ifstream& iFile, string text) // the file name for example iFile here, is irrelevant when using this to call a function
{
	if (!iFile.is_open())
	{
		cout << text << "Input file not found :(" << endl;
		exit(1);
	}
}

int getData(ifstream& iFile, string text[])
{
	int counter = 0;

	while (!iFile.eof())
	{
		iFile >> text[counter];
		counter++;
	}

	return counter;
}

void sortData(string text[], string text2[], int counter)
{
	string temp;

	for (int a = 0; a < counter; a++)
	{
		for (int b = 0; b < counter - 1; b++)
		{
			if (text2[b] > text2[b + 1])
			{
				temp = text[b];
				text[b] = text[b + 1];
				text[b + 1] = temp;

				temp = text2[b];
				text2[b] = text2[b + 1];
				text2[b + 1] = temp;
			}
		}

	}
}

int outputMenu(string text[], string text2[])
{
	int choice = 0;

	while (choice != 1 && choice != 2)
	{
		cout << "1. To sort on first name" << endl;
		cout << "2. To sort on last name" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
	}

	return choice;
}

void output(int counter, string text[], string text2[])
{
	for (int a = 0; a < counter; a++)
	{
		cout << text[a] << " " << text2[a] << endl;
	}
}