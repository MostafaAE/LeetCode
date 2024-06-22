class Solution {
public:
    /*
    * Approach:
    * - Use prefix sum to keep track of the number of odd numbers encountered so far.
    * - Use a hash map to store the frequency of each prefix sum.
    * - For each element in the array, update the current prefix sum and check if there exists a prefix sum that, when subtracted from the current prefix sum, equals k.
    * 
    * Complexity:
    * - Time Complexity: O(n)
    * - Space Complexity: O(n)
    */
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        int n = nums.size(), result = 0, curSum = 0;
        
        // Hash map to store the frequency of prefix sums
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;
        
        for(int i = 0; i < n; ++i)
        {
            // Increment current sum by 1 if the current number is odd
            curSum += (nums[i] & 1);
            
            if(curSum >= k && prefixSum.count(curSum - k))
                result += prefixSum[curSum - k];
            
            prefixSum[curSum]++;
        }
        
        return result;
    }
};
