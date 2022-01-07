int pivotindex(vector<int>& nums, int n)
{
    int s = 0,  e = n-1;
    
    while(s<e)
    {
        int mid = s + (e-s)/2;
        
        nums[mid]>=nums[0]?s = mid +1:e = mid;
    }
    
    return s;
}


int BinarySearch(vector<int>& nums, int target, int s, int e)
{
    while(s<=e)
    {
        
        int mid =  s+ (e-s)/2;
        
        if(nums[mid] == target)return mid;
        
        else if(nums[mid]>target)e = mid-1;
        
        else s = mid +1;
    }
    
    return -1;
}






class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int k = pivotindex(nums,n);
        
        
        return target>=nums[k] && target<=nums[n-1]?BinarySearch(nums,target,k,n-1):BinarySearch(nums,target,0,k-1);
        
    }
};
