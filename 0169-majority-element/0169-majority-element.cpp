class Solution {
public:
    /* 
    * Approach:
    * Boyer-Moore Majority Voting Algorithm
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int majorityElement(vector<int>& nums) 
    {
        int count{}, res{};
        
        for(int num : nums)
        {
            if(!count)
                res = num;
                
            count += (num == res) ? 1 : -1;
        }
        return res;
    }
};