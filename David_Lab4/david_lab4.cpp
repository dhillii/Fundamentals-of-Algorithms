#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

bool isPalindrome(string inputstr)
{
	string compStr;
	char insert;


	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), ' '), inputstr.end());


	for(int i = 0; i < inputstr.size(); i++)
		inputstr[i]  = tolower(inputstr[i]);

	
	Stack new_stack;

	for(int j = 0; j < inputstr.size(); j++)
		new_stack.Push(inputstr[j]);

	for(int j = 0; j < inputstr.size(); j++)
	{
		new_stack.Pop(insert);
		compStr.push_back(insert);

	}

	if(compStr == inputstr)
	{
		return true;
	}

	else
	{
		return false;
	}
}

int main()
{
	string input;

	cout << " Please input a string: ";
	getline(cin, input);


	bool test = isPalindrome(input);

	if(test)
		cout << endl << " The string " << input << " is a Palindrome." << endl;
	else
		cout << " The string " << input << " is not a Palindrome." << endl;

	return 0;
}