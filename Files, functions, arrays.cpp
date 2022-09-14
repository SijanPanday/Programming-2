// Name: Sijan Panday
// Program description: Files, Fuctions and Arrays
// Date: 8/18/2022

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

// fuctions

void fileOpenCheck(ifstream& fInput);
void ClassnameData(ifstream& fInput, ofstream& fOutput, string classNames[], int& counter);
void OutputData(ofstream& fOutput, string classNames[], int& counter);
void OutputDataReverse(ofstream& fOutput, string classNames[], int& counter);
void CloseFiles(ifstream& fInput, ofstream& fOutput);


int main() {
	
	// making variables

	ifstream fInput;
	ofstream fOutput;

	int const x = 50;
	int counter = 0;
	string classNames[x];

	// opening files

	fInput.open("ClassNames.txt");
	fOutput.open("DataOutput.txt");


	 // calling fuctions

	fileOpenCheck(fInput);
	ClassnameData(fInput, fOutput, classNames, counter);
	OutputData(fOutput, classNames, counter);
	OutputDataReverse(fOutput, classNames, counter);
	CloseFiles(fInput, fOutput);

	return 0;
}


// loops

void fileOpenCheck(ifstream& fInput)
{
	if (!fInput.is_open())
	{
		cout << "Input file not found" << endl;
		exit(1);
	}
}

void ClassnameData(ifstream& fInput, ofstream& fOutput, string classNames[], int& counter)
{
	while (
		!fInput.eof()
		)
	{
		getline(fInput, classNames[counter]);
		counter++;
	}
}

void OutputData(ofstream& fOutput, string classNames[], int& counter)
{
	for (int a = 0; a < counter; a++)
	{
		cout << classNames[a] << endl;
	}
	cout << endl;
}

void OutputDataReverse(ofstream& fOutput, string classNames[], int& counter)
{
	for (int a = counter - 1; a >= 0; a--)
	{
		cout << classNames[a] << endl;
	}
	cout << endl;
}

void CloseFiles(ifstream& fInput, ofstream& fOutput)
{
	fInput.close();
	fOutput.close();
}