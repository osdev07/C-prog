#include <iostream>
// number should be in range 0 to n-1
using namespace std;

int main()
{
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    
    int i = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    
    while (i < size) {
        
       if (arr[abs(arr[i])] > 0) {
           arr[arr[i]] *= -1;
       }
       else {
           printf("%d ", abs(arr[i]));
       }
       i++;
    }
}
