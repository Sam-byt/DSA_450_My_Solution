// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
private:
    void dfs( int i,vector<int> adj[], vector<int> &ans,vector<bool> &visited)
    {
        if(!visited[i])
        {
            visited[i] = true;
            ans.push_back(i);
            for(auto j : adj[i])
            {
                dfs(j,adj,ans,visited);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    vector<int> dfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(v,false);
        
        //for all non connected components
        // for(int i=0;i<v;i++)
        // {
        //     if(!visited[i])
        //     {
        //         dfs(i,adj,ans,visited);
        //     }
        // }
        
        //only for connnected graph
        int i=0;
        dfs(i,adj,ans,visited);
        
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
