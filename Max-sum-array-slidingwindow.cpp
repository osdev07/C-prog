//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   

public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        int i =0;
        int j = 0;
        long max = -32767;
        long sum = 0;
        
        while (j < N) {
             sum += Arr[j];
             //check for window size
            if ((j-i+1) < K) {
                j++;
            // if window size is equal then
            // check the max sum. if it is max till now then retain max else replace with sum
            // slide the window to next subarray and subtract the previous sum obtained from
            //arr[i]
            } else if ((j-i+1) ==K) {
                max = maximum(max, sum);
                sum = sum - Arr[i];
                i++;
                j++;
            }
        }
        return max;
    }
    long maximum(long a, long b) {
        long val =  (a >=b) ? a: b;
        return val;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
