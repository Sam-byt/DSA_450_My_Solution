#include<bits/stdc++.h>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    priority_queue<int>pq;
	int n = arr.size();    
    int sum ;
    for(int i=0;i<n; i++){
        sum =0;
        for(int j=i; j<n;j++){
            sum += arr[j];
            pq.push(sum);
        }
    }
    
    k--;
    
    while(k--)pq.pop();
    
    return pq.top();
}
