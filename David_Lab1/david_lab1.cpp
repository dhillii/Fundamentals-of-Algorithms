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
	int ArrSize = sizeof(Arr);

	for (int idx = 0; idx < ArrSize-1; idx++)
	{
		for(int idx2 = ArrSize; idx2 >= idx + 1; idx2--)
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

	int A[8] = {8, 5, 3, 7, 2, 1, 25, 100};


	int ArrSize = sizeof(A)/4;

	
	for (int i = 0; i < ArrSize; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;

	bubbleSort(A);

	for (int i = 0; i < ArrSize; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;

	return(0);

}