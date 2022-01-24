// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int t[1001][1001];
        
        for(int i=0;i<x+1;i++)t[0][i] = 0;
        for(int i=0;i<y+1;i++)t[i][0] = 0;
        
        
        for(int i=1;i<x+1;i++){
            for(int j=1; j<y+1; j++){
                
                t[i][j] = s1[i-1] == s2[j-1]?1 + t[i-1][j-1] : max(t[i-1][j],t[i][j-1]);      
            }
        }
        
        return t[x][y];
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends