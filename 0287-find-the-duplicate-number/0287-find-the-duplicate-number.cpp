class Solution {
public:
    /*
     * Approach:
     * Iterate over nums, for each value we find mark it as found by multiplying the value in its index by -1.
     * 
     * Another solution: Use a slow and fast pointer to find the intersection point (where they meet), then move the head and the intersection 1 step until they meet. (variant of Linked List Cycle II Problem)
     *
     * Another solution: Use a hash table to check if a number is repeated O(n) memory.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int findDuplicate(vector<int>& nums) 
    {
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            int idx = abs(nums[i]) - 1;
            // already marked as seen
            if(nums[idx] < 0)
                return abs(nums[i]);
            // mark this value as seen
            nums[idx] *= -1;
        }
        
        return -1;
    }
};