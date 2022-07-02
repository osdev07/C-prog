/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
//#include <malloc>
using namespace std;
/// C++ program to find
// sum in the given array
#include <bits/stdc++.h>
using namespace std;

// function to find and print duplicates
void printDuplicates(int arr[], int n)
{
   
	// Implementation is c++
	int sum1 = 23; 
	int t;
	unordered_set<int> s1;
	for (int i=0; i<n; i++){
	   t = sum1 - arr[i];
	   if(s1.find(t) != s1.end()) {
	       cout << "found sum pair with C++ " << "sum :" << sum1
	            << " first element " << t
	            << " second element " << arr[i] << "\n";
	       break;    
  	   }
  	   s1.insert(arr[i]);
	}

	
	// Implementation is c
	
	int sum = 23;
	int temp;
	int s[10000] = {0};
	bool isSum;
	for (int i = 0 ; i<n; i++)  {
	    temp = sum -  arr[i];
	    if(s[temp] == 1) {
	        cout << "sum with c =" << sum
	             << " el1 : " << arr[i]
	             << " el2 : " << temp;
	             isSum = true;
	             return;
	    }
	    s[arr[i]] = 1;
	}
	if(!isSum) {
	    cout << "Sum is not present";
	}
}

// Driver program to test above
int main()
{
	int arr[] = {12, 10, 40, 12, 5, 6, 5, 12, 11};
	int n = sizeof(arr) / sizeof(arr[0]);
	printDuplicates(arr, n);
	return 0;
}
