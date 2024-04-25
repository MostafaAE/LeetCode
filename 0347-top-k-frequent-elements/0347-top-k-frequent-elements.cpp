class Solution {
public:
    /*
     * Approach:
     * Utilize a hashmap to count the frequency of each number in the array.
     * Then, use a max heap to store the numbers along with their frequencies.
     * Pop the top k elements from the heap and return them as the result.
     *
     * Complexity:
     * Time Complexity: O(n logn)
     * Space Complexity: O(n)
     */
    
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> numToCount;
        priority_queue<pair<int, int>> maxHeap;
        vector<int> result;
        
        for(auto num : nums)
            ++numToCount[num];
        
        for(auto [num, count] : numToCount)
            maxHeap.push({count, num});
        
        while(k--)
            result.push_back(maxHeap.top().second), maxHeap.pop();
        
        return result;
    }
};