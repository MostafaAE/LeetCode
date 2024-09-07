class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int maxConsecutiveOnes{}, maxSoFar{nums[0]};
        
        for(int i = 1 ; i < nums.size() ; ++i)
        {
            if(nums[i] == 0)
                maxConsecutiveOnes = max(maxConsecutiveOnes, maxSoFar), maxSoFar = 0;
            else
                ++maxSoFar;
        }
        
        return max(maxConsecutiveOnes, maxSoFar);
    }
};