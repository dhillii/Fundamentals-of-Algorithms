#include "Queue.h"
#include "Stack.h"
#include "Stack.cpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

using namespace std;


int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+') 
		return operand1 +operand2;
	else if(operation == '-') 
		return operand1 - operand2;
	else if(operation == '*') 
		return operand1 * operand2;
	else if(operation == '/') 
		return operand1 / operand2;
	else if(operation == '%') 
		return operand1 % operand2;
	else if(operation == '^') 
		return operand1 ^ operand2;

	else cout<<"Unexpected Error \n";
	return -1; 
}

bool isPalindrome(string inputstr)
{
	string compStr;
	char insert;


	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), ' '), inputstr.end());


	for(int i = 0; i < inputstr.size(); i++)
		inputstr[i]  = tolower(inputstr[i]);

	
	Stack<char> new_stack;

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





int postfixCalc(string inputstr)
{
	Stack<int> numContainer;
	int result;

	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), ' '), inputstr.end());

	for(int i = 0; i < inputstr.size(); i++)
	{
		if(isdigit(inputstr[i]))
		{
			string numchar;
			numchar.push_back(inputstr[i]);
			int num = stoi(numchar);
			numContainer.Push(num);
		}

		else if(inputstr[i] == '+' || inputstr[i] == '-' || inputstr[i] == '*' || inputstr[i] == '^' || inputstr[i] == '%' ||inputstr[i] == '/' )
		{
			int op1;
			int op2;
			
			numContainer.Pop(op1);
			numContainer.Pop(op2);

			result = PerformOperation(inputstr[i], op2, op1);

			numContainer.Push(result);
	
		}

	}

	int answer = 0;
	int size = numContainer.getSize();

	for(int j = 0; j < size; j++)
	{
		int num2 = 0;

		numContainer.Pop(num2);

		answer = answer + num2;

	}


	return answer;

}

	



int main()
{
	

	string input;

	cout << " Please input a string: ";
	getline(cin, input);

	int result = postfixCalc(input);


	cout << " " << input << " = " << result << endl;

	/*bool test = isPalindrome(input);

	if(test)
		cout << endl << " The string " << input << " is a Palindrome." << endl;
	else
		cout << " The string " << input << " is not a Palindrome." << endl;
	*/

	return 0;
}

