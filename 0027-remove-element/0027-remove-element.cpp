class Solution {
public:
    /*
     * Approach
     * Two pointers approach
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(1)
     */
    int removeElement(vector<int>& nums, int val) 
    {
        int k{};
        for(int i = 0 ; i < (int)nums.size() ; ++i)
            if(nums[i] != val)
                nums[k++] = nums[i];
            
        return k;
    }
};