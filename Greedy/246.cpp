// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    typedef pair<int,int>pi;
    
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pi>v;
        for(int i=0; i<n ; i++)v.push_back({price[i],i+1});
        sort(v.begin(),v.end());
        int cnt =0,j;
        for(int i=0; i<n && k>0; i++){
            j =1;
            while(j<=v[i].second ){
                if(k-v[i].first>=0){
                    k-=v[i].first;
                    cnt++;
                }
                else break;
                j++;
            }
        }
        return cnt;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends
