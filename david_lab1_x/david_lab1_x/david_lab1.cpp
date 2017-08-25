/*

Author: David Hill, Jr
Class: Fundamentals of Algorithms
Assigmnent: Lab 1
Due: 8/28/2017

*/

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void bubbleSort(int Arr[]);
void bubbleSort_str(vector<string> Arr);


void bubbleSort(int Arr[], int size)
{

	for (int idx = 0; idx < size-1; idx++)
	{
		for(int idx2 = size; idx2 >= idx + 1; idx2--)
			{
				if( Arr[idx2] < Arr[idx2-1])
				{
					int temp1 = Arr[idx2];
					int temp2 = Arr[idx2-1];

					Arr[idx2] = temp2;
					Arr[idx2-1] = temp1;
				}
			}
		
	}
}

void bubbleSort_str(vector<string> strArr)
{

	int size = strArr.size();

	for (int idx = 0; idx < size-1; idx++)
	{
		for(int idx2 = size; idx2 >= idx + 1; idx2--)
		{
			if(strArr[idx2][0] < strArr[idx2-1][0])
			{
				string temp1 = strArr[idx2];
				string temp2 = strArr[idx2-1];

				strArr[idx2] = temp2;
				strArr[idx2-1] = temp1;
			}

		}
	}
}


int main()
{

	int A[10] = {8, 5, 3, 7, 2, 1, 25, 100, 12, 1000};

	vector<string> B;

	int names;

	cout << " ";

	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;

	bubbleSort(A, 10);

	cout << " ";

	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;

	cout << " How many times would you like to sort? > " ;
	cin >> names;
	cout << endl;

	for(int idx = 0; idx < names; idx++)
	{
		string name; 
		cout << " Please enter a name > ";
		cin >> name;

		B.push_back(name);

	}

	//bubbleSort_str(B);


	cout << B[0][0] << " " << B[1][0] <<endl;









	return(0);

}