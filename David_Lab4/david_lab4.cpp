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
#include <vector>

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
		return pow(operand1, operand2);

	else cout<<"Unexpected Error \n";
	return -1; 
}

bool isPalindrome(string inputstr)
{
	string compStr;
	char insert;


	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), ' '), inputstr.end());
	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), ','), inputstr.end());
	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), '.'), inputstr.end());
	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), '\''), inputstr.end());
	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), ':'), inputstr.end());
	inputstr.erase(std::remove(inputstr.begin(), inputstr.end(), ';'), inputstr.end());


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

void testPostfix()
{
	std::vector<string> inputs;

	inputs.push_back("1 2 +");
	inputs.push_back("3 1 -");
	inputs.push_back("2 3 *");
	inputs.push_back("4 5 * 3 +");
	inputs.push_back("5 1 2 + 4 * + 3 -");
	inputs.push_back("8 2 / 4 5 + 3 2 -");
	inputs.push_back("2 2 ^");
	inputs.push_back("8 2 %");
	inputs.push_back("20 3 %");


	for(int i = 0; i < inputs.size(); i++)
	{
		int test = postfixCalc(inputs[i]);
		cout << " " << inputs[i] << " = " << test << endl;
		

	}

}

void testPalindrome()
{
	std::vector<string> inputs;

	inputs.push_back("a");
	inputs.push_back("aa");
	inputs.push_back("aaa");
	inputs.push_back("aba");
	inputs.push_back("abba");
	inputs.push_back("Taco cat");
	inputs.push_back("Madam, I'm Adam");
	inputs.push_back("A man, a plan, a canal: Panama");
	inputs.push_back("Doc, note: I dissent. A fast never prevents a fatness. I diet on cod.");
	inputs.push_back("David");
	inputs.push_back("The Cow jumped over the Moon");
	inputs.push_back("Hello Howard University!");
	inputs.push_back("Sedan");
	inputs.push_back("Minivan");
	inputs.push_back("Bus");
	inputs.push_back("Racecar");

	for(int i = 0; i < inputs.size(); i++)
	{
		bool test = isPalindrome(inputs[i]);

		if(test)
			cout << endl << " The string \"" << inputs[i] << "\" is a Palindrome." << endl;
		else
			cout << endl <<" The string \"" << inputs[i] << "\" is not a Palindrome." << endl;

	}



}

	


int main()
{
	testPalindrome();

	testPostfix();

	
	

	return 0;
}

