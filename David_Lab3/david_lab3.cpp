/*
Fundamentals of Algorithms Lab 3
Author: David Hill, Jr.
Due: 9/18/2017
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

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


double createSeries(int n)
{
	vector<vecor <int>> series_arr;

	for(int i = 1; i <=n; i++)
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
	}



}


int main()
{


	
}