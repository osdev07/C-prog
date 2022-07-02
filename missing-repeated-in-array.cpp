#include <iostream>

using namespace std;
// missing and repeating no in an array
// range of array is 0 to n-1
int main()
{
    int arr[] = {3,1,3,4,2};
    
    int i = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    
    while (i < size) {
        
       if (arr[abs(arr[i])-1] > 0) {
           arr[arr[i]-1] *= -1;
       }
       else {
           printf("repeating no = %d \n", abs(arr[i]));
       }
       i++;
    }
    i= 0;
    while (i < size) {
        if (arr[i] > 0) {
           printf("missing no =  %d ", i+1);
        }
        i++;
    }
}

