// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
private:
    int solve(int N, int W, int val[], int wt[], int t[][1001])
    {
        if(N<=0 || W<=0)return 0;
        
        if(t[N][W] != -1)return t[N][W];
        
        if(wt[N-1]<=W)
            return t[N][W]=max(val[N-1]+solve(N,W-wt[N-1],val,wt,t),solve(N-1,W,val,wt,t));
        
        if(wt[N-1]>W)
            return t[N][W]=solve(N-1,W,val,wt,t);
            
    }   
    
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        int t[1001][1001];
        memset(t,-1,sizeof(t));
        return solve(N,W,val,wt,t);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
