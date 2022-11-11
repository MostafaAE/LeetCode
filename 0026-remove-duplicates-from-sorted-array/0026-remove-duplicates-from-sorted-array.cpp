class Solution {
public:
    /* 
    * Approach:
    * two pointers
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int removeDuplicates(vector<int>& nums) 
    {
        int k{1}, lastVal = nums[0];
        for(int i = 1 ; i < (int)nums.size() ; i++)
            if(nums[i] != lastVal)
                nums[k++] = nums[i], lastVal = nums[i];
            
        return k;
    }
};