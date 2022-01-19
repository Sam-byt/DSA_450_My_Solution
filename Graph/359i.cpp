// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    bool solvedfs(vector<int> adj[],vector<bool>&visited,vector<bool>&dfsvisited, int i)
    {
        visited[i] = true;
        dfsvisited[i] = true;
        
        for(auto j:adj[i])
        {
            if(!visited[j] && !dfsvisited[j])
            {
                if(solvedfs(adj,visited,dfsvisited,j))return true;
            }
            
            else{
                
                if(visited[j] && dfsvisited[j])return true;
                
            }
            
        }
        
        dfsvisited[i] = false;
        
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        
        //Detection using dfs in non connected graphs
        vector<bool>visited(v,false);
        vector<bool>dfsvisited(v,false);
        for(int i=0;i<v; i++)
        {
            if(!visited[i])
            {
                if(solvedfs(adj,visited,dfsvisited,i))return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
