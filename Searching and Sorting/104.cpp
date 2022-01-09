class Solution {
public:
    int mySqrt(int x) {
        
        long long int s = 0, e = x, ans =-1;
        
        
        while(s<=e)
        {
            long long int mid = s+(e-s)/2;
            
            mid * mid <= x? ans =  mid, s= mid +1:e = mid -1;
        }
        
        
        return ans;
        
    }
};
