class Solution {
public:
    /* 
    * Approach:
    * Use a count variable that is incremented by 1 every 1 encountered and decremented by 1 every 0 encountered
    * Start traversing the array If at any moment count becomes 0, it implies that we've encountered equal number of zeros and ones from the beginning till the current
    * or if we encountered the same count twice, it means that the number of zeros and ones are equal between the indices corresponding to the equal count values
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int findMaxLength(vector<int>& nums) 
    {
        unordered_map<int, int> prefixToIdx;
        int maxLen{}, curSum{};
        
        prefixToIdx.insert({0, -1});
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            curSum += nums[i] ? 1 : -1;

            if(prefixToIdx.count(curSum))
                maxLen = max(maxLen, i - prefixToIdx[curSum]);
            else
                prefixToIdx[curSum] = i;
        }
        
        return maxLen;
    }
};