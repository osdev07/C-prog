//You have given a string A having Uppercase English letters.

//You have to find how many times subsequence "AG" is there in the given string.

//NOTE: Return the answer modulo 109 + 7 as the answer can be very large.
#if 0

Example Input
Input 1:

 A = "ABCGAG"
Input 2:

 A = "GAB"


Example Output
Output 1:

 3
Output 2:

 0

#endif

int Solution::solve(string A) {
    long sum =0;
    int count =0;
    for (int i=0 ; i<A.length();i++){
        if ( A[i] == 'A')
            count++;
        if ( A[i] == 'G')
            sum = sum + count ;

    }
    return (int)(sum%1000000007);
}
