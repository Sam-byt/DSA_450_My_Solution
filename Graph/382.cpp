// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    private:
    void topo(vector<int> adj[],vector<bool>&visited,int i, stack<int>&s)
    {
        visited[i] = true;
        
        for(auto j:adj[i])
        {
            if(!visited[j])
            {
                topo(adj,visited,j,s);
            }
        }
        
        s.push(i);
    }
    
    void solve(vector<int> adjtrans[],vector<bool>&visited,int i)
    {
        visited[i] = true;
        
        for(auto j:adjtrans[i])
        {
            if(!visited[j])
            {
                solve(adjtrans,visited,j);
            }
        }
        
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<bool>visited(V,false);
        stack<int>s;
        int cnt = 0;
        
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                topo(adj,visited,i,s);
            }
        }
        
        vector<int> adjtrans[V];
        
        for(int i=0;i<V;i++)
        {
            for(auto j:adj[i])
            {
                adjtrans[j].push_back(i);
            }
        }
        
        for(auto i:visited)i=false;
        int temp;
        
        while(!s.empty())
        {
            temp = s.top();
            s.pop();
            
            if(!visited[temp])
            {
                solve(adjtrans,visited,temp);
                cnt++;
            }
            
        }
        
        return cnt;
        
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
