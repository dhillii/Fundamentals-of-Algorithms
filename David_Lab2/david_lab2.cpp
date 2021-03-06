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

/*
This function parses a number as a string, saves each digit
in the num_array that is passed in, low-digits first, and
returns the number of digits in that number.
If we can't parse the number, returns -1.
Example: If num_as_string = "1234",
        Then num_array[] = {4, 3, 2, 1} and
        the return value is 4.
*/
int readNumberAsArrayFromString(string &num_as_string, vector<int> &num_array) 
{
  for (int i = 0; i < num_as_string.length(); i++) 
  {
      num_array.push_back(static_cast<int>(num_as_string[i]-'0'));
  }
  return num_as_string.length();
}


/*
Takes a number represented as an array with its digits,
low to heigh, as well as its length (i.e. number of digits)
and return a string representation of that number.
*/
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


/*
This function takes a interger as input and places its contents into a vector. A vector of integers is returned.
Example:
		int x = 123;
		vector<int> x_vector = intToVector(x);
*/
vector<int> intToVector(int input_num)
{
	vector<int> output_vector;
	string input_num_str = to_string(input_num);
	int sizeArr = readNumberAsArrayFromString(input_num_str, output_vector);
	return output_vector;

}

/*
This function takes a vector as input and converts the vector into an integer and returns the result.
*/
int vectortoInt(vector<int> input_num)
{
	string input_num_str = numberAsArrayToString(input_num, input_num.size());
	return stoi(input_num_str);
}


/*
Takes two vectors and an integer as input shifts input array by a number of 
positions with a power of 10. The output is stored in a output vector. This function
returns void.
*/
void shiftLeft(vector<int> inputArr, vector<int> &outputArr, int positions)
{
	string input_num_str = numberAsArrayToString(inputArr, inputArr.size());
	int input_num_lit = stoi(input_num_str);

	int shifted_result = input_num_lit * (pow(10, positions));

	input_num_str = to_string(shifted_result);					
	int input_num_size = readNumberAsArrayFromString(input_num_str, outputArr);				

}

	
/*
This function prints each element of a number vector.
*/
void printNum(vector<int> inputArr)
{
	for(int idx = 0; idx < inputArr.size(); idx++)
	{
		cout << inputArr[idx];
	}

	cout << endl;
}

/*
Uses Naive algorithm to add two numbers stored as vectors. Takes two
integer vectors as input and puts sum into a final vector called Sum
*/
void vectorSum(vector<int> inputArr1, vector<int> inputArr2, vector<int> &Sum)
{
	int carry_ = 0;
	int Largest;

	/*
	Find largest vector to know how many times to loop for addition.
	*/
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

		/*
		If vectors are not of same size, left-pad smaller vector with 0's
		*/
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

/*
Uses Naive algorithm to subtract two numbers stored as vectors. Takes two
integer vectors as input and puts result into a final vector called Result
*/
void vectorSub(vector<int> inputArr1, vector<int> inputArr2, vector<int> &Result)
{
	
	int Largest;

	/*
	Find largest vector to know how many times to loop for subtraction.
	*/
	if(inputArr1.size() > inputArr2.size())
	{
		Largest = inputArr1.size();
	}

	else
	{
		Largest = inputArr2.size();
	}

	/*
		If vectors are not of same size, left-pad smaller vector with 0's
	*/
	while(inputArr1.size() > inputArr2.size())
	{
		inputArr2.insert(inputArr2.begin(), 0);
	}

	while(inputArr1.size() < inputArr2.size())
	{
		inputArr1.insert(inputArr1.begin(), 0);
	}

	/*
	Logic to subtract if first vector is smaller than the second indicating a negative result.
	*/
	if(vectortoInt(inputArr1) < vectortoInt(inputArr2))
	{
		int neg_result = vectortoInt(inputArr2) - vectortoInt(inputArr1);
		vector<int> answer = intToVector(neg_result);

		int flip = answer[0];

		answer[0] = answer[0] - (2 * flip);

		Result = answer;		
	}

	/*
	Logic to subtract if first vector is larger than or equal to the second vector leading to a 
	positive result.
	*/
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



void vectorMult(vector<int> inputArr1, vector<int> inputArr2, vector<int> &outputArr)
{
	int result = 0;
	int max = vectortoInt(inputArr1);

	for(int i = 0; i < max; i++)
	{
		result = result + vectortoInt(inputArr2);
	}

	outputArr = intToVector(result);

}

void vectorMult_DnC(vector<int> inputArr1, vector<int> inputArr2, vector<int> &outputArr)
{


	while(inputArr1.size() > inputArr2.size())				
		{
			inputArr2.insert(inputArr2.begin(), 0);
		}

	while(inputArr1.size() < inputArr2.size())		
		{
			inputArr1.insert(inputArr1.begin(), 0);
		}

	vector<int> vec_xl, vec_xr, vec_yl, vec_yr;

	for(int i = 0; i<inputArr1.size(); i++)
	{
		if(i < inputArr1.size()/2)
		{
			vec_xl.push_back(inputArr1[i]);
			vec_yl.push_back(inputArr2[i]);
		}

		else
		{
			vec_xr.push_back(inputArr1[i]);
			vec_yr.push_back(inputArr2[i]);
		}
	}

	vector<int> xl_mult_yl;
	vector<int> xl_mult_yr;
	vector<int> xr_mult_yl;
	vector<int> xr_mult_yr;



	vectorMult(vec_xl, vec_yl, xl_mult_yl);
	vectorMult(vec_xl, vec_yr, xl_mult_yr);
	vectorMult(vec_xr, vec_yl, xr_mult_yl);
	vectorMult(vec_xr, vec_yr, xr_mult_yr);

	vector<int> num1, num2, num3;

	shiftLeft(xl_mult_yl, num1, inputArr1.size());

	vectorSum(xl_mult_yr, xr_mult_yl, num2);

	shiftLeft(num2, num3, inputArr1.size()/2);


	vector<int> result1;
	vector<int> result2;

	vectorSum(num1, num3, result1);
	vectorSum(result1, xr_mult_yr, result2);

	outputArr = result2;



}

void vectorMult_Rec(vector<int> inputArr1, vector<int> inputArr2, vector<int> &outputArr)
{
	while(inputArr1.size() > inputArr2.size())				
		{
			inputArr2.insert(inputArr2.begin(), 0);
		}

	while(inputArr1.size() < inputArr2.size())		
		{
			inputArr1.insert(inputArr1.begin(), 0);
		}

	return vectorMult_DnC(inputArr1, inputArr2, outputArr);

}


int main()
{ 
	
	vector<int> num1vec;
	vector<int> num2vec;

	vector<int> result1;
	vector<int> result2;
	vector<int> result3;

	int num1 = 12;
	int num2 = 12;


	num1vec = intToVector(num1);
	num2vec = intToVector(num2);

	vectorMult_DnC(num1vec, num2vec, result1);
	vectorMult(num1vec, num2vec, result2);
	vectorMult_Rec(num1vec, num2vec, result3);

	cout << " Div and Conc: " <<num1 << " x " << num2 << " = " << vectortoInt(result1) << endl;
	cout << " Naive: " <<num1 << " x " << num2 << " = " << vectortoInt(result2) << endl;
	cout << " Recursive: " <<num1 << " x " << num2 << " = " << vectortoInt(result3) << endl;

	return 0;

}
