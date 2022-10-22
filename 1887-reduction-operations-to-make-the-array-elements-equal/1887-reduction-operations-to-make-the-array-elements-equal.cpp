class Solution {
public:
    /* 
    * Approach:
    * Complexity:
    * Time Complexity : O(nlogn)
    * Space Complexity : O(1)
    */
    int reductionOperations(vector<int>& nums) 
    {
        int opsCnt{};
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 1 ; i < (int)nums.size() ; i++)
            if(nums[i-1] > nums[i])
                opsCnt += i;
        
        return opsCnt;
    }
};