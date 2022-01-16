// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int v, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        vector<bool> visited(v,false);
        queue<int>q;
        
        //for all non connected components if exists
        // for(int i=0;i<v;i++)
        // {
        //     if(!visited[i])
        //     {
        //         q.push(i);
        //         visited[i] = true;
        //         ans.push_back(i);
                
        //         while(!q.empty())
        //         {
        //             int x = q.front();
        //             q.pop();
                    
        //             for(auto j:adj[x])
        //             {
        //                 if(!visited[j])
        //                 {
        //                     visited[j]= true;
        //                     q.push(j);
        //                     ans.push_back(j);
        //                 }
        //             }
        //         }
        //     }
            
        // }
        
        
        //only for the connected component required starting from 0 as asked in gfg
        
        q.push(0);
        ans.push_back(0);
        visited[0] = true;
        
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            
            for(auto i:adj[x])
            {
                if(!visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        return ans;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
