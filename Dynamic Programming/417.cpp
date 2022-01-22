// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
                // code here
        int sum = accumulate(arr,arr+N,0);
        if(sum&1)return false;
        
        
        else
        {
            sum/=2;
            bool t[N+1][sum+1];
            
            for(int i=0;i<N+1;i++)t[0][i] = false;
            for(int i=0;i<N+1;i++)t[i][0] = true;

        
            for(int i =1 ; i < N+1 ; i++){
                for(int j =1 ; j < sum+1 ; j++){
    
                    if(arr[i-1] <= j)
                    {
                        t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
                    }
                    else{
    
                        t[i][j] = t[i-1][j];
                    }
    
                }
            }
    
            return t[N][sum];
                
        }
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
