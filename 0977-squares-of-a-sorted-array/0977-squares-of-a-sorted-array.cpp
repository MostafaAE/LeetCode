class Solution {
public:
    /* 
    * Approach: 
    * Get the idx of the first positive number while squaring all the values
    * all the values before this idx will be sorted in decreasing order and all the values after it will be sorted in increasing order.
    * use two pointers to merge these two paritions of the array in O(n).
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n{(int)nums.size()}, pos{n}, neg{};
        vector<int> result(n);
        
        for(int i = 0 ; i < n ; i++)
        {
            if(pos == n && nums[i] >= 0)
                pos = i;
            
            nums[i] = nums[i] * nums[i];
        }
        
        neg = pos - 1;
        for(int i = 0 ; i < n ; i++)
        {
            if(neg <= -1)
                result[i] = nums[pos++];
            else if(pos >= n)
                result[i] = nums[neg--];
            else if (nums[pos] <= nums[neg])
                result[i] = nums[pos++];
            else
                result[i] = nums[neg--];
        }
        
        return result;
    }
};