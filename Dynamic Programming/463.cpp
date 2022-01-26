// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
#define m 1003
class Solution{
    
private:

unordered_map<string,int>umap;

int solve(string str, int i, int j, bool b)
{
    int ans =0;
    
    if(i>j)return 0;
    
    if(i == j){
        if(b)return str[i] == 'T';
        else return str[i] == 'F';
    }
    
    string key = to_string(i) + " " + to_string(j) + " " + to_string(b);
    
    if(umap.find(key) != umap.end())return umap[key];
    
    for(int k = i+1; k<j; k+=2){
        
        int lt = solve(str, i, k-1, true)%m;
        
        int lf = solve(str, i, k-1, false)%m;
        
        int rt = solve(str, k+1, j, true)%m;
        
        int rf = solve(str, k+1, j, false)%m;
        
        if(str[k] == '&'){
            
            if(b){
                
                ans += (lt * rt)%m;
                
            }
            
            else ans += ((lt * rf)%m + (rt * lf)%m + (lf * rf)%m)%m;
            
            
            
        }
        
        else if(str[k] == '|')
        {
            
            if(b){
                
                ans += ((lt*rt)%m + (lt *rf)%m + (rt*lf)%m)%m;
                
            }
            
            else ans += (lf * rf)%m;
            
        }
        
        
        else if(str[k] == '^')
        {
            
            if(b){
                
                ans += ((lt * rf)%m + (lf * rt)%m)%m;
            }
            
            else ans += ((lf * rf)%m + (rt * lt)%m)%m;
            
        }
        
        
        
        
        
        
    }
    
    return umap[key] = ans % m;
    
    
    
}

public:
    int countWays(int N, string S){
        // code here
        umap.clear();
        return solve(S,0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
