/*
Fundamentals of Algorithms Lab 3
Author: David Hill, Jr.
Due: 9/18/2017
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int readNumberAsArrayFromString(string &num_as_string, vector<int> &num_array) 
{
  for (int i = 0; i < num_as_string.length(); i++) 
  {
      num_array.push_back(static_cast<int>(num_as_string[i]-'0'));
  }
  return num_as_string.length();
}


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

void printNum(vector<int> inputArr)
{
	for(int idx = 0; idx < inputArr.size(); idx++)
	{
		cout << inputArr[idx];
	}

	cout << endl;
}


/*void createSeries(int n)
{
	vector<vector<int> > series_arr;

	for(int i = 1; i <= n+1; i++)
	{
		vector<int> temp;

		if(i == 1)
		{	
			temp.push_back(1);
			series_arr.push_back(temp);
		}

		else if(i == 2)
		{
			temp.push_back(1);
			temp.push_back(1);
			series_arr.push_back(temp);
		}

		else
		{
			vector<int> temp2;
			temp = series_arr[i-2];

			for(int j = 0; j < temp.size(); j++)
			{

				if(temp[j] == 1 && temp[j+1] == 1)
				{
					
					temp2.push_back(2);
					temp2.push_back(1);
					j = j+1;
				
					
				}

				else if(temp[j] == 2 && temp[j+1] == 2)
				{
					temp2.push_back(2);
					temp2.push_back(2);

					j = j+1;
				}

				else if(temp[j] == 1)
				{
					temp2.push_back(1);
					temp2.push_back(1);
				}

				else if(temp[j] == 2)
				{
					temp2.push_back(1);
					temp2.push_back(2);
				}

				
				
				
			}
			series_arr.push_back(temp2);

		}

		
	}

	printNum(series_arr[0]);
	printNum(series_arr[1]);
	printNum(series_arr[2]);
	printNum(series_arr[3]);
	printNum(series_arr[4]);
	printNum(series_arr[5]);

}*/

string createSeries(int n)
{

	string start_str = "11";

	if(n == 1)
	{
		return "1";
	}
	else if(n == 2)
	{
		return "2";
	}

	for(int i = 3; i <= n; i++)
	{
		

		start_str += " ";
		string temp;

		int length = start_str.length();
		int count = 1;

		for(int j = 1; j<length; j++)
		{
			if(start_str[j] != start_str[j-1])
			{

				temp += count + '0';
				temp += start_str[j-1];
				count = 1;
			}
			else
			{
				count = count + 1;

			}
		}

		start_str = temp;

	}


	return start_str;
}


int main()
{

	cout << createSeries(10);


	return 0;
}