// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    void solve(vector<vector<int>>m,int n,int x,int y,string path, vector<string> &ans)
    {
        if(x<0 || x>=n || y<0 || y>=n || m[x][y] == 0)return;
        
        if(x == n-1 && y == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        m[x][y]  = 0;
        
        solve(m,n,x+1,y,path+"D",ans);
        solve(m,n,x,y-1,path+"L",ans);
        solve(m,n,x,y+1,path+"R",ans);
        solve(m,n,x-1,y,path+"U",ans);
        
        m[x][y] = 1;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0)return ans;
        
        solve(m,n,0,0,"",ans);
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
