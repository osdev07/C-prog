// need to check how many times ith index will be present in any subarray
// start and end with i is [0,i]  
// start with i and end with other index is [i, n-1]
// num of element between [0,i] = i-0-(-1) = i+1 (x)
//num of element between  [i, n-1] = n-1-i+1 = n-i (y)
// total number will be  x*y = (n-i)*(i+1)

void printSum(int *A, int n) {
    
    int i , j;
    int sum = 0;
    int total = 0;
     sum = 0;
    for (i = 0; i < n; i++) {
        sum += A[i]*(i+1) *(n-i);
        
        //for (j = i; j < n; j++) {
           // sum += A[j];
            //total += sum;
        //}
        
    }
    printf("%d", sum);
}
int main()
{
    int A[4] = {3, 2,  -1, 5};
    
    printSum(A, 4);

    return 0;
}
