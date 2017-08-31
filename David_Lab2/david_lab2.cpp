/*

Author: David Hill, Jr
Class: Fundamentals of Algorithms
Assigmnent: Lab 2
Due: 9/4/2017

*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// This function parses a number as a string, saves each digit
// in the num_array that is passed in, low-digits first, and
// returns the number of digits in that number.
// If we can't parse the number, returns -1.
// Example: If num_as_string = "1234",
//          then num_array[] = {4, 3, 2, 1} and
//          the return value is 4.
int readNumberAsArrayFromString(string &num_as_string, vector<int> &num_array) 
{
  for (int i = 0; i < num_as_string.length(); i++) 
  {
      num_array.push_back(static_cast<int>(num_as_string[i]-'0'));
  }
  return num_as_string.length();
}


// Takes a number represented as an array with its digits,
// low to heigh, as well as its length (i.e. number of digits)
// and return a string representation of that number.
string numberAsArrayToString(vector<int> num_array, int length) {
  if (length <= 0 ) 
  {
    return "NaN";
  }
  string num_string;
  for (int i = 0; i < length; i++) 
  {
    num_string += static_cast<char>(num_array[i] + '0');
  }
  return num_string;
}




vector<int> intToVector(int input_num)
{
	vector<int> output_vector;
	string input_num_str = to_string(input_num);
	int sizeArr = readNumberAsArrayFromString(input_num_str, output_vector);
	return output_vector;

}

int vectortoInt(vector<int> input_num)
{
	string input_num_str = numberAsArrayToString(input_num, input_num.size());
	return stoi(input_num_str);
}

void shiftLeft(vector<int> inputArr, vector<int> &outputArr, int positions)
{
	string input_num_str = numberAsArrayToString(inputArr, inputArr.size());
	int input_num_lit = stoi(input_num_str);

	int shifted_result = input_num_lit * (pow(10, positions));

	input_num_str = to_string(shifted_result);					
	int input_num_size = readNumberAsArrayFromString(input_num_str, outputArr);				

}

	

void printNum(vector<int> inputArr)
{
	for(int idx = 0; idx < inputArr.size(); idx++)
	{
		cout << inputArr[idx];
	}

	cout << endl;
}

void vectorSum(vector<int> inputArr1, vector<int> inputArr2, vector<int> &Sum)
{
	int carry_ = 0;
	int Largest;

	if(inputArr1.size() > inputArr2.size())
	{
		Largest = inputArr1.size();
	}

	else
	{
		Largest = inputArr2.size();
	}

	for(int idx = Largest; idx > 0; idx--)
	{
		int carry = 0;

		while(inputArr1.size() > inputArr2.size())
		{
			inputArr2.insert(inputArr2.begin(), 0);
		}

		while(inputArr1.size() < inputArr2.size())
		{
			inputArr1.insert(inputArr1.begin(), 0);
		}

		int add = inputArr1[idx-1] + inputArr2[idx-1];
		
		if(add > 9)
		{
			carry = intToVector(add)[0];
			int add2 = intToVector(add)[1];
			Sum.insert(Sum.begin(), add2);
		}

		else
		{
			add = add + carry_;
			Sum.insert(Sum.begin(), add);
		}

		carry_ = carry;
	}

	if(carry_ > 0)
	{
		Sum.insert(Sum.begin(), carry_);
	}

}

void vectorSub(vector<int> inputArr1, vector<int> inputArr2, vector<int> &Result)
{
	
	int Largest;

	if(inputArr1.size() > inputArr2.size())
	{
		Largest = inputArr1.size();
	}

	else
	{
		Largest = inputArr2.size();
	}

	while(inputArr1.size() > inputArr2.size())
	{
		inputArr2.insert(inputArr2.begin(), 0);
	}

	while(inputArr1.size() < inputArr2.size())
	{
		inputArr1.insert(inputArr1.begin(), 0);
	}


	if(vectortoInt(inputArr1) < vectortoInt(inputArr2))
	{
		int neg_result = vectortoInt(inputArr2) - vectortoInt(inputArr1);
		vector<int> answer = intToVector(neg_result);

		int flip = answer[0];

		answer[0] = answer[0] - (2 * flip);

		Result = answer;		
	}

	else
	{
		for(int idx = Largest; idx > 0; idx--)
		{
		
			if(inputArr1[idx-1] < inputArr2[idx-1])
			{
				inputArr1[idx-2] = inputArr1[idx-2] - 1;
				int borrow = 10 + inputArr1[idx-1];
				int result = borrow - inputArr2[idx-1];
				Result.insert(Result.begin(), result);
			}
			else
			{
				int sub = inputArr1[idx-1] - inputArr2[idx-1];
				Result.insert(Result.begin(), sub);
			}

	
		}
	}

}

int main()
{
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(1);
	
	


	

	vector<int> B;
	B.push_back(1);
	B.push_back(2);
	B.push_back(3);
	B.push_back(1);
	



	vector<int> C;

	
	vectorSub(A, B, C);

	printNum(A);
	printNum(B);

	printNum(C);




	





}

