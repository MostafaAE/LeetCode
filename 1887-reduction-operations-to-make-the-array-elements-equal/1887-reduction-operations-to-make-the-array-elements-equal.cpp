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
        int opsCnt{}, numsCnt{};
        sort(nums.begin(), nums.end(), greater<int>());
        
        for(int i = 0 ; i < (int)nums.size()-1 ; i++)
        {
            numsCnt++;
            if(nums[i] > nums[i+1])
                opsCnt += numsCnt;
        }
        
        return opsCnt;
    }
};