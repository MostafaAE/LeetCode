class Solution {
public:
    /*
     * Approach:
     * - Iterate through the array to calculate the degree of each number and store the first and last occurrence of it in a hashmap, and determine the highest degree.
     * - Iterate through the occurrences of numbers with the highest degree, calculating the length of each subarray and return the shortest of them.
     *
     * Complexity:
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    int findShortestSubArray(vector<int>& nums) 
    {
        int result{INT_MAX}, highestDegree{INT_MIN};
        unordered_map<int, int> numToCount;
        unordered_map<int, pair<int, int>> numToStartEnd;
        
        for(int i = 0 ; i < (int)nums.size() ; i++)
        {
            ++numToCount[nums[i]];
            
            if(numToCount[nums[i]] == 1)
                numToStartEnd[nums[i]].first = i;
            numToStartEnd[nums[i]].second = i;
            
            highestDegree = max(highestDegree, numToCount[nums[i]]);
        }
        
        for(auto &[num, count] : numToCount)
            if(count == highestDegree)
                result = min(result, numToStartEnd[num].second - numToStartEnd[num].first + 1);
    
        return result;
    }
};