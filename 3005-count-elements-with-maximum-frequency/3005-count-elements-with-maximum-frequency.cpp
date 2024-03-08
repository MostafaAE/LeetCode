class Solution {
public:
    /*
     * Approach:
     * One-Pass count max frequencies.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    int maxFrequencyElements(vector<int>& nums) 
    {
        int maxFreqVal{}, maxFreqCount{};
        unordered_map<int, int> freq;
        
        for(int num : nums)
        {
            freq[num]++;
            if(freq[num] > maxFreqVal)
            {
                maxFreqVal = freq[num];
                maxFreqCount = 1;
            }
            else if(freq[num] == maxFreqVal)
                maxFreqCount++;
        }
        
        return maxFreqVal * maxFreqCount;
    }
};