//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    
	    // code here
	    int k = pat.size();
	    
	     
	  
	    int i =0,j = 0;
	    map <char, int > pattern;
	    int count;
	    int ans = 0;
      // insert all element of pat to map and increase the count
       // key is char of pattern and value is occurence of char in pat
	    while(i < pat.size()) {
	        pattern[pat[i++]]++;
	        
	    }
	    i = 0;
	    count = pattern.size();
	    
	    while(j< txt.size()) {
	       // if char at j of txt is stored in map then decrese the value of occurence.
         // if vlaue is 0 then decrement count
         // count is the number of distinct  char in pat
	       if (pattern.find(txt[j])!=pattern.end()) {
	           pattern[txt[j]]--;
	           if (pattern[txt[j]] == 0) {
	               count--;
	           }
	         }
	          
	        
	        if((j-i+1)< k) {
	            j++;
	        }
        // if count is 0 then pat is found now in txt , increase the ans
	        else if ((j-i+1) == k) {
	          if (count == 0) {
	              ans++;
	          }
            // now if txt[i] was one of the char in pat then increment the count with 1 
            // and increment count as well
	          if (pattern.find(txt[i]) != pattern.end()) {
	              pattern[txt[i]]++;
	              if (pattern[txt[i]] == 1) {
	                  count++;
	               }
	          }
	     
	          i++; j++;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
