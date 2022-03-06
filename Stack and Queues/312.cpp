

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        typedef pair<int,int> pi;
        
        int n = heights.size();
        
        vector< pi > nextsmall(n), prevsmall(n);
        
       
        
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
};
