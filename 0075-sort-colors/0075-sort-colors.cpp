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
    void sortColors(vector<int>& nums) 
    {
        int left{}, right{}, cur{};
        
        while(left < nums.size())
        {
            while(nums[right] != cur)
            {
                right++;
                if(right == nums.size())
                {
                    cur++;
                    right = left;
                    continue;
                }
            }
            
            swap(nums[left], nums[right]);
            if(left == right)
                right++;
            left++;
        }
    }
};