// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int v, vector<int> adj[]) {
        // code here
        //cycle detection using BFS Algo Kahn's Algo
        
        vector<int> indegree(v,0);
        queue<int> q;
        int temp;
        
        int count =0;
        
        for(int i=0;i<v;i++)
        {
            for(auto j:adj[i])
            {
                indegree[j]++;
            }
        }
        
        for(int i=0;i<v;i++)
        {
            if(indegree[i]==0)q.push(i);
        }
        
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            count++;
            
            for(auto j : adj[temp])
            {
                indegree[j]--;
                if(indegree[j]==0)q.push(j);
            }
        }
        
        return count != v;
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
