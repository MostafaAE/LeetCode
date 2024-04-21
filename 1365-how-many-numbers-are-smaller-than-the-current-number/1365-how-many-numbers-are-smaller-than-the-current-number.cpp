class Solution {
public:
    /* 
     * Approach:
     * - Create a copy of the input vector to sort it.
     * - Use a hash map to store the smallest index of each unique number after sorting.
     * - Iterate through the original vector and push the corresponding smallest index from the hash map into the result vector.
     *
     * Complexity:
     * Time Complexity: O(nlogn)
     * Space Complexity: O(n)
     */
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> sorted(nums.begin(), nums.end());
        vector<int> result;
        unordered_map<int, int> numToIdx;
        
        // O(nlogn)
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0 ; i < (int)sorted.size() ; i++)
            if(!numToIdx.count(sorted[i]))
                numToIdx[sorted[i]] = i;
        
        for(int num : nums)
            result.push_back(numToIdx[num]);
        
        return result;
    }
};