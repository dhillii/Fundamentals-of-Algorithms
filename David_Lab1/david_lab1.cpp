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
void bubbleSort_str(vector<string> &strArr);


void bubbleSort(int Arr[], int size)
{
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size - x - 1; y++)
        {
            if (Arr[y] > Arr[y+1])
            {
                swap(Arr[y], Arr[y+1]);
            }
        }
        
    }

}

void bubbleSort(vector<string> &strArr)
{
    int size = strArr.size();

    
    for (int x = 0; x < size; x++)
    {
        for (int y = 0; y < size - x - 1; y++)
        {
            int L1 = int(tolower(strArr[y][0]));
            int L2 = int(tolower(strArr[y+1][0]));
            
            if (L1 > L2)
            {
                swap(strArr[y], strArr[y+1]);
            
            }
        }
        
    }
}


int main()
{

	int A[11] = {8, 5, 3, 7, 2, 1, 25, 100, 12, 1000, 0};

	vector<string> B;

	int names;

	cout << " ";

	for (int i = 0; i < 11; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;

	bubbleSort(A, 11);

	cout << " ";

	for (int i = 0; i < 11; i++)
	{
		cout << A[i] << " ";
	}

	cout << endl;

	cout << " How many names would you like to sort? > " ;
	cin >> names;
	cout << endl;

	for(int idx = 0; idx < names; idx++)
	{
		string name; 
		cout << " Please enter a name > ";
		cin >> name;

		B.push_back(name);

	}
    
    cout << endl;

    cout << " Unsorted: " ;
    
    for(int idx = 0; idx < names; idx++)
    {
        cout << " " << B[idx] << " ";
    }
    

    bubbleSort(B);
    
    cout << endl;

    cout << " Sorted: ";
    
    for(int idx = 0; idx < names; idx++)
    {
        cout << " " << B[idx] << " ";
    }
    
    cout << endl;

    
	return(0);

}