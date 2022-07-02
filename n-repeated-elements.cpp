include <iostream>

using namespace std;

int main()
{
    int arr[] = { 0, 4, 3, 4, 7, 3, 2, 2, 1 };
    
    int i = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    
    while (i < size) {
        
        arr[arr[i] % size] = arr[arr[i] % size] + size;
        
        i++;
    }
    i = 0;
    while (i < size) {
       
        if(arr[i] >= size*2) {
           printf("\n%d\n", i );
        }
        i++;
    }
  
    return 0;
}
