// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        
        vector<int>ans;
        
        int i;
        priority_queue<pair<int,int>>q;
        
        
        for(i=0;i<k-1;i++){
            
            q.push(make_pair(arr[i],i));
            
            
        }
        
        
        int j =0;
        
        
        while(i<n){
            
            q.push(make_pair(arr[i],i));
            
            while(q.top().second<j)q.pop();
            
            ans.push_back(q.top().first);
            
            i++;
            j++;
            
            
            
        }
        
        
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
