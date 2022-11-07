class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    void moveZeroes(vector<int>& nums) 
    {
        for(int insertPos = 0, i = 0 ; i < (int)nums.size() ; i++)
            if(nums[i] != 0)
                swap(nums[insertPos++], nums[i]);
    }
};