class Solution {
public:
    /*
    * Approach:
    * - Use a frequency array to count occurrences of each value in the input array.
    * - Traverse the frequency array to handle duplicates:
    *   - If a value occurs more than once, increment the next value(s) to make them unique.
    *   - Accumulate the number of increments needed to make the values unique.
    * - Handle the maximum value in the frequency array to manage any remaining duplicates.
    *
    * Complexity:
    * - Time Complexity: O(n + m), where `n` is the length of the input array, and `m` is the max value in the input array.
    * - Space Complexity: O(m)
    */
    int minIncrementForUnique(vector<int>& nums) 
    {
        int result = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        
        vector<int> freq(maxVal + 1, 0);
        
        // Count the frequency of each value in the array
        for(auto val : nums)
            ++freq[val];
        
        // Traverse the frequency array to handle duplicates
        for(int i = 0; i < maxVal; ++i)
        {
            if(freq[i] > 1)
            {
                result += freq[i] - 1;
                freq[i + 1] += freq[i] - 1;
            }
        }
        
        // Handle duplicates for the maximum value in the array
        if(freq[maxVal] > 1)
        {
            int count = freq[maxVal] - 1;
            result += count * (count + 1) / 2;
        }
        
        return result;
    }
};
