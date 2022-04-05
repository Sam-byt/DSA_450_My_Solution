// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range

class Info{
  public :
    int data;
    int row;
    int col;
  
    Info(int data, int i, int j){
        this ->data = data;
        row = i;
        col = j;
    }
    
};


class compare{
    public:
        bool operator()(Info a, Info b){return a.data>b.data;}
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
       int high = INT_MIN, low = INT_MAX;
       priority_queue<Info, vector<Info>, compare>pq;
       
       int element;
       
       for(int i=0; i<k; i++){
           element = KSortedArray[i][0];
           low = min(low,element);
           high = max(high,element);
           Info temp(element,i,0);
           pq.push(temp);
       }
       
       
       int start = low,end = high;
       
       while(!pq.empty()){
           Info temp = pq.top();
           pq.pop();
           
           low = temp.data;
           
           if(high - low < end - start){
               start = low;
               end = high;
           }
           
           
           if(temp.col + 1< n){
               high = max(high,KSortedArray[temp.row][temp.col+1]);
               Info arb(KSortedArray[temp.row][temp.col+1],temp.row,temp.col+1);
               pq.push(arb);
           }
           
           else break;
       }
       
       return {start,end};
       
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
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends
