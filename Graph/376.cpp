// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	     // Code here
        vector<int> distances(n, INT_MAX);
        int src = 0;
        int u, v, w;

        distances[src] = 0;

        for (int r = 0; r < n - 1; r++)
        {
            for (int i = 0; i < edges.size(); i++)
            {
                u = edges[i][0];
                v = edges[i][1];
                w = edges[i][2];
                
                if(distances[u] == INT_MAX)continue;

                if (distances[u] + w < distances[v])
                    distances[v] = distances[u] + w;
            }
        }

        for (int i = 0; i < edges.size(); i++)
        {
            u = edges[i][0];
            v = edges[i][1];
            w = edges[i][2];

            if (distances[u] + w < distances[v]){
                return true;
            }
        }

        return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
