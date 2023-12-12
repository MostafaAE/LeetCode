class Solution {
public:
    /* 
    * Approach:
    * Two pointers technique
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    void moveZeroes(vector<int>& nums) 
    {
        int left{}, n{(int)nums.size()};
        
        for(int right = 0 ; right < n ; right++)
            if(nums[right])
                nums[left++] = nums[right];
        
        while(left < n)
            nums[left++] = 0;
    }
};