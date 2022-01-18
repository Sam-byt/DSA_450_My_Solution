// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    bool solve(vector<int>adj[],vector<int> &color, int i,int prev)
    {
        color[i] = 1-prev;
        
        for(auto j: adj[i])
        {
            if(color[j]<0)
            {
                if(!solve(adj,color,j,color[i]))return false;
            }
            else{
                if(color[j]==color[i])return false;
            }
        }
        
        return true;
    }
public:
	bool isBipartite(int v, vector<int>adj[]){
	    // Code here
	    vector<int>color(v,-1);
	    
	    for(int i=0;i<v;i++)
	    {
	        if(color[i]<0)
	        {
	            if(!solve(adj,color,i,1))return false;
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
