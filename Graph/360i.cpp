// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        //detection using bfs
        queue<pair<int,int>>q;
        pair<int,int> p;
        vector<bool> visited(v,false);
        
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                q.push(make_pair(i,-1));
                
                while(!q.empty())
                {
                    p = q.front();
                    q.pop();
                    
                    int x = p.first;
                    int y = p.second;
                    
                    for(auto j:adj[x])
                    {
                        if(!visited[j])
                        {
                            visited[j] = true;
                            q.push(make_pair(j,x));
                        }
                        
                        else{
                            if(j!=y)return true;
                        }
                    }
                }
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
