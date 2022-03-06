// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int i = 0, j = n-1;
        
        while(i<j){
            M[j][i] == 1?j--:i++;
        }
        
        int temp = i;
        
        for(int i =0;i<n;i++)
        {
            if(i != temp)
            {
                if(M[i][temp] == 0 || M[temp][i] == 1)return -1;
            }
        }
        
        return M[temp][temp] == 0?temp : -1;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends
