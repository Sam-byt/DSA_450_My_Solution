// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/
typedef pair<int,int> pi;
class Solution{
    private:
    
    int largestRectangleArea(int *heights, int n) {
        
        
        
        // int n = heights.size();
        
        pi nextsmall[n] , prevsmall[n];
        
       
        
        stack<pi> s;
        
        s.push(make_pair(-1,-1));
        
        for(int i = n-1; i>=0 ; i--)
        {
            while(s.top().first>=heights[i])s.pop();
            
            nextsmall[i] = s.top();
            
            s.push({heights[i],i});
        }
        
        while(!s.empty())s.pop();
        
        s.push(make_pair(-1,-1));
        
        for(int i = 0;i<n; i++)
        {
            while(s.top().first>=heights[i])s.pop();
            
            prevsmall[i] = s.top();
            
            s.push({heights[i],i});
        }
        
        int maxarea = 0;
        int area,next,prev;
        
        for(int i = 0; i<n ; i++)
        {
            
            prev = prevsmall[i].first<0? i : i - 1 - prevsmall[i].second ;
            
            next = nextsmall[i].first<0? n - i - 1 : nextsmall[i].second - 1 - i;
        
            
            area = (next + prev + 1)*heights[i];
            
            maxarea = max(area,maxarea);
        }
        
        return maxarea;
        
    }
    
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
       int area = largestRectangleArea(M[0],m);
       
       for(int i=1; i<n; i++){
           for(int j =0;j<m;j++){
               M[i][j] = M[i][j] == 0?0 : M[i][j] + M[i-1][j];
           }
           area = max(area,largestRectangleArea(M[i],m) );
       }
       
       return area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends
