class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    void moveZeroes(vector<int>& nums) 
    {
        int insertPos{};
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
            if(nums[i] != 0)
                nums[insertPos++] = nums[i];
        
        for(int i = insertPos ; i < (int)nums.size() ; i++)
            nums[i] = 0;
    }
};