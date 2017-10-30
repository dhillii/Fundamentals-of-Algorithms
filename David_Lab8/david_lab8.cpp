#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits.h>
#include <cmath>
#define INF INT_MAX

using namespace std;

string prettyPrint(vector<string> text, int line_size)
{
	int n = text.size();

	int  cost[n][n];

	for (int i = 0; i < n; i++)
	{
	 	cost[i][i] = line_size - text[i].size();

	 	for (int j = i + 1; j < n; j++)
        {
            cost[i][j] = cost[i][j - 1] - text[j].size() - 1;
        }
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			if(cost[i][j] < 0)
			{
				cost[i][j] = INT_MAX;
			}

			else
			{
				cost[i][j] = pow(cost[i][j], 2);
			}
		}
	}

	int minCost[n], result[n];

	for(int i = n-1; i >= 0; i--)
	{
		minCost[i] = cost[i][n-1];
		result[i] = text.size();

		for(int j = n-1; j>i; j--)
		{
			if(cost[i][j-1] == INT_MAX)
			{
				continue;
			}

			if(minCost[i] > minCost[j] + cost[i][j-1])
			{
				minCost[i] = minCost[j] + cost[i][j+i];
				result[i] = j;
			}
		}
	}

	int i = 0;
	int j;

	string pretty;

	do
	{
		j = result[i];
		for(int k = i; k < j; k++)
		{
			
			pretty.append(text[k] + " ");
		}
		
		pretty.append("\n");

		i = j;
	}while(j < n);

	return pretty;

}

vector <string> textToVector(istream& in)
{
	string word;
	vector<string> words;

	while(in)
	{
		in >> word;
		words.push_back(word);
	}

	return words;
}


int main()
{
	ifstream infile;
	infile.open("Test.txt");

	ofstream outfile;
	outfile.open("Result.txt");

	vector<string> words;

	words = textToVector(infile);

	outfile << prettyPrint(words, 40);



}