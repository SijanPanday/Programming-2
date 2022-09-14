//Name: Sijan Panday
//Program description: String Processing
//Date: 8/26/2022

#include<iostream>
#include<string>

using namespace std;

// Pretty functions

void getText(string& input);

void removeTags(string& input);

void output(string& input);



int main()
{

	//Variables

	string input;


	// Calling the functions
	getText(input);
	// Getting the text



	removeTags(input);
	// Removing the tags in the HTML code


	output(input);
	//Outputting the final updated text


	return 0;

}

// Actual functions that I'm calling

void getText(string& input)
{
	getline(cin, input);
}

void removeTags(string& input)
{
	for (int a = 0; a <= input.length(); a++)
	{
		if (input[a] == '<')
		{
			for (int b = a; b < input.length(); b++)
			{
				if (input[b] == '>')
				{
					input.erase(a, b - a + 1); // erases the text in between the tags, it was leaving one hanging, so the +1 went one over and corrected the code
					a--;
					break; // Breaks without break, literally
				}
			}
		}
	}
}

void output(string& input)
{
	cout << input << endl;
}