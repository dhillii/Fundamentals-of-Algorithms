/*
Fundamentals of Algorithms Lab 3
Author: David Hill, Jr.
Due: 9/18/2017
*/

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>

using namespace std;



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

vector<int> createRandArr()
{
	vector<int> randArr;

	mt19937 rng;
	rng.seed(random_device()());
	uniform_int_distribution<std::mt19937::result_type> dist(5,14);

	for(int i = 0; i < 10; i ++)
	{
		randArr.push_back(dist(rng));
	}

	return randArr;

}

vector<string> populateRandArr(vector<int> randArr)
{
	vector<string> result;

	for(int i = 0; i < randArr.size(); i ++)
	{
		string temp = createSeries(randArr[i]);
		result.push_back(temp);
	}

	return result;
}

void mergeSort(vector<int> &unsortedArr)
{
    if (unsortedArr.size() <= 1) {
        return;
    }

    vector<int>::size_type middle = unsortedArr.size() / 2;
    vector<int> left(unsortedArr.begin(), unsortedArr.begin() + middle);
    vector<int> right(unsortedArr.begin() + middle, unsortedArr.end());

    mergeSort(left);
    mergeSort(right);

    merge(left.begin(), left.end(), right.begin(), right.end(), unsortedArr.begin());
}

typedef std::vector<int>::iterator vec_iter;
void merge(vec_iter left, vec_iter left_end, vec_iter right, vec_iter right_end, vec_iter numArr)
{
    while (left != left_end) 
    {
        if (*left < *right || right == right_end) 
        {
            *numArr = *left;
            ++left;
        } 
        else 
        {
            *numArr = *right;
            ++right;
        }

        ++numArr;
    }

    while (right != right_end) 
    {
        *numArr = *right;
        ++right;
        ++numArr;
    }
}


int main()
{
	vector<int> vect;
	vector<string> randseries;
	vector<int> randseries2;

	//cout << " F(10) = " << createSeries(10) << endl;

	vect = createRandArr();

    cout << " [ ";
	for(int i = 0; i < 10; i ++)
	{
		cout << vect[i] << ", ";
	}
	cout << "] " << endl;

	mergeSort(vect);

	cout << " [ ";
	for(int i = 0; i < 10; i ++)
	{
		cout << vect[i] << ", ";
	}
	cout << "] " << endl;

	randseries = populateRandArr(vect);

	cout << " [ ";
	for(int i = 0; i < 10; i ++)
	{
		cout << randseries[i] << ", ";
		 
	}
	cout << "] " << endl;



	return 0;
}