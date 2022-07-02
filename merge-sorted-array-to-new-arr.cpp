/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
//#include <malloc>
using namespace std;
// missing and repeating no in an array
// range of array is 0 to n-1
void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
 
        // Swap the found minimum element
        // with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}
void merge(int ar1[], int ar2[], int m , int n) {
    
    int i = 0, j = 0 ,l = 0, k = m-1;
    
    int *ar3 = (int*)malloc(sizeof(int)*(m+n));
    
    //int k = (m >n) ? m:n;
    while (i < m && j < n) {
        if(ar1[i] < ar2[j]) {
           ar3[l++] = ar1[i++]; 
        } else {
            ar3[l++] = ar2[j++];
        }
    }
    if (m >n) {
        while(i <m) {
            ar3[l++] = ar1[i++];
        }
    } else {
             while(j < n) {
            ar3[l++] = ar2[j++];
        } 
    }
    cout << "\n After Merging \n ";
    for (int i = 0; i < l; i++) {
        printf("%d ", ar3[i]);
    }
    cout << "\n";
    free(ar3);
}
int main()
{
    int ar1[] = { 1, 5, 9, 10, 15, 20 };
    int ar2[] = { 2, 3, 8, 13 };
    int m = sizeof(ar1) / sizeof(ar1[0]);
    int n = sizeof(ar2) / sizeof(ar2[0]);
    cout << "\nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << ar1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << ar2[i] << " ";
   
    merge(ar1, ar2, m, n);
 
     return 0;
}
