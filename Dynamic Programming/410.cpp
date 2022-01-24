// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    #define ll long long
    private:
    
    ll solve(int s[],int m , int n , ll t[][1001])
    {
        if(m==0 && n==0)return 1;
        
        if(n>0 && m==0)return 0;
        
        if(t[m][n] != -1)return t[m][n];
        
        if(s[m-1]<=n)
            return t[m][n] = solve(s,m,n-s[m-1],t) + solve(s,m-1,n,t);
            
        if(s[m-1]>n)
            return t[m][n] = solve(s,m-1,n,t);
    }
    
    
    
    
  public:
    long long int count(int S[], int m, int n) {

        // code here.
        ll t[1001][1001];
        memset(t,-1,sizeof(t));
        return solve(S,m,n,t);
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
