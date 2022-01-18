// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    bool cycledfs(vector<int> adj[],vector<bool> &visited, int i, int prev)
    {
        visited[i] = true;
        
        for(auto j: adj[i])
        {
            if(!visited[j]){
                if(cycledfs(adj,visited,j,i))return true;
            }
            else{
                if(j!=prev)return true;
            }
        }
        
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    //cycle detection in non connected graphs using dfs
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        vector<bool>visited(v,false);
        // pair<int,int> p;
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                int prev = -1;
                // p = make_pair(i,prev);
                
                if(cycledfs(adj,visited,i,prev))return true;
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
