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
        int left{}, right{(int)nums.size()-1}, cur{};
        
        while(cur <= right)
        {
            if(nums[cur] == 0)
            {
                swap(nums[cur], nums[left]);
                left++;
            }
            else if(nums[cur] == 2)
            {
                swap(nums[cur], nums[right]);
                right--;
                cur--;
            }
           cur++;
        }
    }
};