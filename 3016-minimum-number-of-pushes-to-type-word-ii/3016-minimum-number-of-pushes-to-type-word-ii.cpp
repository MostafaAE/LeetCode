class Solution {
public:
    /**
     * Approach:
     * - Count the frequency of each character in the given word using an unordered_map.
     * - Use a max heap (priority_queue) to store these frequencies in descending order.
     * - For each character frequency in the max heap, calculate the required key presses based on how many keys have been mapped (greedy).
     * - Return the total result after processing all frequencies.
     *
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(1), number of distinct characters = 26 (constant).
     */
    int minimumPushes(string word) 
    {
        int result{}, mappedKeys{};
        unordered_map<int, int> charToCount;
        priority_queue<int> freq;
        
        for(auto c : word)
            ++charToCount[c];
        
        for(auto [c, count] : charToCount)
            freq.push(count);
        
        while(!freq.empty())
        {
            result += ((mappedKeys / 8) + 1) * freq.top();
            freq.pop();
            ++mappedKeys;
        }
        
        return result;
    }
};