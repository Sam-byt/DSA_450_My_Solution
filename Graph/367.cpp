// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    typedef pair<int,int> pi;
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int src)
    {
        // Code here
        pi p;
        vector<int> distances(v,INT_MAX);
        priority_queue<pi,vector<pi>,greater<pi>>q;
        distances[src] = 0;
        
        
        q.push(make_pair(0,src));
        
        
        
        while(!q.empty())
        {
            p = q.top();
            q.pop();
            
            for(auto i : adj[p.second])
            {
                if(distances[p.second] + i[1] < distances[i[0]])
                {
                    distances[i[0]] = distances[p.second] + i[1];
                    q.push(make_pair(distances[i[0]],i[0]));
                }
                
            }
            
        }
        
        
        return distances;
        
        
        
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends
