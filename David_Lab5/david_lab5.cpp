
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

string naiveCombo(vector<int>, int sum);
string hashCombo(vector<int>, int sum);
int excelIndexToColumn(string);
string excelColumnToIndex(int);

string naiveCombo(vector<int> Arr, int sum)
{
	string numbers;

	
	for(int i = 0; i < Arr.size(); i++)
	{
		for(int j = i + 1; j < Arr.size(); j++)
		{
			if(Arr[i] + Arr[j] == sum)
			{
				string insert = "(";
				insert += to_string(Arr[i]);
				insert += ", ";
				insert += to_string(Arr[j]);
				insert += ") ";
				numbers += insert;
			}

		}
	}

	return numbers;
}

string hashCombo(vector<int> Arr, int sum)
{
	unordered_map<int, int> Table;
	unordered_map<int, int>::iterator it;
	string numbers;

	for(int i = 0; i < Arr.size(); i++)
	{
		Table.insert(pair<int, int> (i, Arr[i]));
	}

	for(int j = 0; j < Table.size(); j++)
	{

		int num = sum - Table.find(j)->second;

		size_t repeat = numbers.find(to_string(num));

		if(repeat != std::string::npos)
			continue;
		else
		{

			it = Table.find(num);
			if(it != Table.end())
			{
				if(num == Table.find(j)->second || num == 0)
					continue;
				else
				{
					string insert = "(";
					insert += to_string(Arr[j]);
					insert += ", ";
					insert += to_string(num);
					insert += ") ";
				numbers += insert; 


				}
			
			}
		}
				
	}

	return numbers;


}

int excelIndexToColumn(string idx)
{
	int column = 0;

	for(int i = 0; i < idx.size(); i++)
		column = column * 26 + idx[i] - 64;

	return column;

}

string excelColumnToIndex(int col)
{
	string idx;

	while(col > 0)
	{
		idx = (char)(65 + (col-1) % 26) + idx;
		col = (col - 1)/26;
	}

	return idx;
}

string printVector(vector<int> vec)
{
	string str;
	str += " [";
	for(int i = 0; i < vec.size(); i++)
	{
		str += " "; 
		str += to_string(vec[i]);
		str += " ";	
	}
	str += "] ";
	return str;	

}

void test_all()
{
	cout <<endl << " ______Test naiveCombo()______________________________" << endl;
	vector<int> A; 

	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	A.push_back(5);
	A.push_back(6);
	A.push_back(7);
	A.push_back(8);
	A.push_back(9);
	A.push_back(10);

	cout << endl <<" Test Vector: " << printVector(A) << endl << endl; 

	cout << " ____Sum_____" << "    " << "_____Nums_____" << endl << endl;

	cout << "      16" << "    " << "   " <<naiveCombo(A, 16) << endl;

	cout << "      17" << "    " << "   " <<naiveCombo(A, 17) << endl;

	cout << "      20" << "    " << "   " <<naiveCombo(A, 20) << endl;

	cout << "      12" << "    " << "   " <<naiveCombo(A, 12) << endl;

	cout << "       9" << "    " << "   " <<naiveCombo(A, 9) << endl;

	cout << "       8" << "    " << "   " <<naiveCombo(A, 8) << endl;

	cout << "      19" << "    " << "   " <<naiveCombo(A, 19) << endl;

	cout << "       5" << "    " << "   " <<naiveCombo(A, 5) << endl;

	cout << "      15" << "    " << "   " <<naiveCombo(A, 15) << endl;

	cout << "      0" << "    " << "   " <<naiveCombo(A, 0) << endl;

	cout << "      10" << "    " << "   " <<naiveCombo(A, 10) << endl;

	cout << "       7" << "    " << "   " <<naiveCombo(A, 7) << endl;

	cout << "       6" << "    " << "   " <<naiveCombo(A, 6) << endl;

	cout << "      13" << "    " << "   " <<naiveCombo(A, 13) << endl;



	cout << endl << endl <<" ______Test hashCombo()______________________________" << endl;
	
	cout << endl <<" Test Vector: " << printVector(A) << endl << endl; 

	cout << " ____Sum_____" << "    " << "_____Nums_____" << endl << endl;

	cout << "      16" << "    " << "   " <<hashCombo(A, 16) << endl;

	cout << "      17" << "    " << "   " <<hashCombo(A, 17) << endl;

	cout << "      20" << "    " << "   " <<hashCombo(A, 20) << endl;

	cout << "      12" << "    " << "   " <<hashCombo(A, 12) << endl;

	cout << "       9" << "    " << "   " <<hashCombo(A, 9) << endl;

	cout << "       8" << "    " << "   " <<hashCombo(A, 8) << endl;

	cout << "      19" << "    " << "   " <<hashCombo(A, 19) << endl;

	cout << "       5" << "    " << "   " <<hashCombo(A, 5) << endl;

	cout << "      15" << "    " << "   " <<hashCombo(A, 15) << endl;

	cout << "      0" << "    " << "   " <<hashCombo(A, 0) << endl;

	cout << "      10" << "    " << "   " <<hashCombo(A, 10) << endl;

	cout << "       7" << "    " << "   " <<hashCombo(A, 7) << endl;

	cout << "       6" << "    " << "   " <<hashCombo(A, 6) << endl;

	cout << "      13" << "    " << "   " <<hashCombo(A, 13) << endl;



	cout << endl << endl <<" ______Test excelIndexToColumn() and excelColumnToIndex()______________________________" << endl;

	cout << " ____Index_____" << "    " << "_____Column_____" << endl << endl;

	for(int i = 1; i <= 100; i++)
	{
		string str = excelColumnToIndex(i);
		int num = excelIndexToColumn(str);

		cout << "        " << str <<"       " << "           " << num << endl;


	}



}

int main()
{

	test_all();

	return 0;
}