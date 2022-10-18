class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        
        if(nums.size() == 1 || nums[0] != nums[1])
            return nums[0];
        
        for(int i = 1 ; i < (int)nums.size()-1 ; i++)
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
                return nums[i];
        
        return nums[(int)nums.size()-1];
    }
};