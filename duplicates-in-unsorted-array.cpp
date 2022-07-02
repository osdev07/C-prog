/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
//#include <malloc>
using namespace std;
/// C++ program to find
// duplicates in the given array
#include <bits/stdc++.h>
using namespace std;

// function to find and print duplicates
void printDuplicates(int arr[], int n)
{
	// unordered_map to store frequencies
	std::map<int, int> freq;
	for (int i=0; i<n; i++){
		freq[arr[i]]++;
		//freq.at(i) = arr[i];
		//req.insert({i, arr[i]});
	}
	bool dup = false;
	std::map<int, int>:: iterator itr;
	for (itr=freq.begin(); itr!=freq.end(); itr++)
	{
		// if frequency is more than 1
		// print the element
		if (itr->second > 1)
		{
			cout << itr->first << " ";
			dup = true;
		}
	}

	// no duplicates present
	if (dup == false)
		cout << "-1";
}

// Driver program to test above
int main()
{
	int arr[] = {12, 11, 40, 12, 5, 6, 5, 12, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	printDuplicates(arr, n);
	return 0;
}
