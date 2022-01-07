// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


int FirstOccurance(int arr[], int n , int x )
{
    
    int s = 0, e = n-1, ans = -1;
    
    while(s<=e){
        
        int mid = s + (e-s)/2;
        
        if(x == arr[mid]){
             ans = mid;
             e = mid -1;
        }
        
        else if(x > arr[mid])s = mid +1;
        
        else e = mid -1;
    }
    
    return ans;
}

int LastOccurance(int arr[], int n , int x )
{
    
    int s = 0, e = n-1, ans = -1;
    
    while(s<=e){
        
        int mid = s + (e-s)/2;
        
        if(x == arr[mid]){
             ans = mid;
             s = mid + 1;
        }
        
        else if(x > arr[mid])s = mid +1;
        
        else e = mid -1;
    }
    
    return ans;
}


vector<int> find(int arr[], int n , int x )
{
    // code here
    vector<int>v;
    
    v.push_back(FirstOccurance(arr,n,x));
    v.push_back(LastOccurance(arr,n,x));
    
    return v;
    
    
}
