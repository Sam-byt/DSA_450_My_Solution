// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        string X = A;
        reverse(A.begin(),A.end());
        string B = A;
        
        int n = A.length();
        
        int t[1001][1001];
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<n+1;j++){
                
                if(i==0 || j==0)t[i][j] = 0;
                
                else if(X[i-1] == B[j-1])t[i][j] = 1 + t[i-1][j-1];
                
                else t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
        
        return t[n][n];
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
