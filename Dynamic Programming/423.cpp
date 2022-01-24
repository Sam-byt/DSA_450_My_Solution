// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    private:
    int solve(int x, int y, string s1, string s2, int t[][1001])
    {
        // your code here
        if(x==0 || y==0)return 0;
        
        if(t[x][y] != -1)return t[x][y];
        
        return t[x][y] = s1[x-1] == s2[y-1] ? 1 + solve(x-1,y-1,s1,s2,t) : max(solve(x,y-1,s1,s2,t),solve(x-1,y,s1,s2,t));
    }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        int t[1001][1001];
        memset(t,-1,sizeof(t));
        
        return solve(x,y,s1,s2,t);
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
