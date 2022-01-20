// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        vector<bool> mcst(v, false);
        vector<int> parent(v, -1);
        vector<int> keys(v, INT_MAX);

        keys[0] = 0;
        int low = INT_MAX, index = -1;

        for (int t = 0; t < v; t++)
        {
            low = INT_MAX;
            for (int i = 0; i < v; i++)
            {
                if (keys[i] < low && !mcst[i])
                {
                    low = keys[i];
                    index = i;
                }
            }

            mcst[index] = true;

            for (auto k : adj[index])
            {
                if (!mcst[k[0]]  && k[1] < keys[k[0]])
                {
                    parent[k[0]] = index;
                    keys[k[0]] = k[1];
                }
            }
        }

        return accumulate(keys.begin(), keys.end(),0);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
