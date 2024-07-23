class Solution {
public:
    /**
     * Approach:
     * - Use an unordered_map to count the frequency of each number in the input array.
     * - Use a map where the key is the frequency and the value is a set of numbers with that frequency.
     * - Iterate over the map and add each number to the result vector the number of times it appears.
     *
     * Complexity:
     * - Time Complexity: O(n logn), where n is the number of elements in the input array.
     * - Space Complexity: O(n)
     */
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int, int> valToCount;
        map<int, set<int>> countToVals;
        vector<int> result;
        
        for(auto val : nums)
            valToCount[val]++;
        
        for(auto [val, count] : valToCount)
            countToVals[count].insert(val);
        
        for(auto [count, vals] : countToVals)
        {
            auto itr = vals.rbegin();
            while(itr != vals.rend())
                addCount(result, *itr, count), itr++;
        }
        
        return result;
    }
    
    void addCount(vector<int>& result, int val, int count)
    {
        for(int i = 0 ; i < count ; ++i)
            result.push_back(val);
    }
};