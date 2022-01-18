// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    
	    //Bipartite check if the graph is non connected or connected
	    queue<int>q;
	    int temp;
	    vector<int>color(v,-1);
	    for(int i=0; i<v ; i++)
	    {
	        if(color[i]<0)
	        {
	            color[i] = 0;
	            q.push(i);
	            
	            
	            while(!q.empty())
	            {
	                temp = q.front();
	                q.pop();
	                
	                
	                for(auto j : adj[temp])
	                {
	                    if(color[j]<0)
	                    {
	                        color[j] = 1 - color[temp];
	                        q.push(j);
	                        
	                    }
	                    
	                    else{
	                        if(color[j]==color[temp])return false;
	                    }
	                    
	                    
	                }
	                
	            }
	        }
	    }
	    
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends
