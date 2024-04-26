class Solution {
public:
    /*
     * Approach:
     * Count the frequency of each number using a hashmap.
     * Create buckets to store numbers with the same frequency.
     * Iterate through the buckets starting from the highest frequency, and add the numbers to the result vector until it reaches size k.
     * Finally, return the result vector.
     *
     * Complexity:
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        int maxCount{INT_MIN};
        unordered_map<int, int> numToCount;
        vector<int> result;
        
        for(auto num : nums)
        {
            ++numToCount[num];
            maxCount = max(maxCount, numToCount[num]);
        }
        
        vector<vector<int>> buckets(maxCount+1);
        for(auto [num, count] : numToCount)
            buckets[count].push_back(num);
        
        
        for(int i = maxCount ; result.size() < k && i >= 0 ; --i)
            for(int j = 0 ; result.size() < k && j < buckets[i].size() ; j++)
                result.push_back(buckets[i][j]);
        
        return result;
    }
};