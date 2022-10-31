class Solution {
public:
    /* 
    * Approach:
    * binary search
    * 
    * Complexity:
    * Time Complexity : O((m+n)logn) where m is the maximum element in the array
    * Space Complexity : O(1)
    */
    int specialArray(vector<int>& nums) 
    {
        // O(nlogn)
        sort(nums.begin(), nums.end());
        
        // O(mlogn)
        for(int i = 1 ; i <= nums[(int)nums.size()-1] ; i++)
        {
            auto lb = lower_bound(nums.begin(), nums.end(), i);
            if(distance(lb, nums.end()) == i)
                return i;
        }
        return -1;
    }
    
};