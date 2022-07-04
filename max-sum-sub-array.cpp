#include <iostream>

using namespace std;

void findMaxSubArray(int arr[], int  size);

int main()
{
    int arr[] = {0, -4, -6, -8, 2, 10, -3,5,-1};
    int size = sizeof(arr)/sizeof(arr[0]);
    findMaxSubArray(arr, size);

    return 0;
}
void findMaxSubArray(int arr[], int  size)  {
    int max = -32768;
    int min = 0;
    int start = 0 , end = 0, s = 0;
    for (int i = 0 ; i < size; i++) {
        min += arr[i];
        
        if (max < min) {
            max = min;
            start = s;
            end = i;
            
        }
        if (min < 0) {
            min = 0;
            s = i+1;
        }
    }
    cout << "max sum in array " << max
         << "from index = " << start
         << " to index = " << end  <<std::endl;
    
}
