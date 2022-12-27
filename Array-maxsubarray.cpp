/ C++ implementation of above approach

#include <bits/stdc++.h>
using namespace std;
// Function to return length of
// smallest subarray containing both
// maximum and minimum value


// solution- carry forward min_index/max_index
// till you get atleast max/min element.
// max and min is on edge. 
// only one max or min should be there in a subarray
int minSubarray(int A[], int n)
{

	// find maximum and minimum
	// values in the array
	int minValue = *min_element(A, A + n);
	int maxValue = *max_element(A, A + n);
    if ( minValue == maxValue)
      	return -1;
	int pos_min = -1, pos_max = -1, ans = INT_MAX;

	// iterate over the array and set answer
	// to smallest difference between position
	// of maximum and position of minimum value
	for (int i = 0; i < n; i++) {

		// last occurrence of minValue
		if (A[i] == minValue) {
			  pos_min = i;
        if (pos_max >0)
          	ans = min(ans, i-pos_max+1); 
    }
		// last occurrence of maxValue
		if (A[i] == maxValue) {
			pos_max = i;
     	if (pos_min >0)
          ans = min(ans, i-pos_min+1); 
     }
	
	}

	return ans;
}

// Driver code
int main()
{
	int A[] = {1, 5, 9, 7, 1, 9, 4 };
	int n = sizeof(A) / sizeof(A[0]);

	cout << minSubarray(A, n);

	return 0;
