/*

Author: David Hill, Jr
Class: Fundamentals of Algorithms
Assigmnent: Lab 1
Due: 8/28/2017

*/

#include <iostream>

using namespace std;

void bubbleSort(int Arr[]);


void bubbleSort(int Arr[])
{
	for (int idx = 0; idx < sizeof(Arr)-1; idx++)
	{
		for(int idx2 = sizeof(Arr); idx2 >= idx + 1; idx2--)
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


int main()
{

	int A[9] = {9,1,8,2,7,3,6,4,5};

	for (int i = 0; i < 9; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;

	bubbleSort(A);

	for (int i = 0; i < 9; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;



}