class Solution {
public:
    /*
    * Approach:
    * - Use a prefix sum and a hash map to store the frequency of remainders when the prefix sum is divided by k.
    * - For each prefix sum, if the remainder is found in the hash map, it means there are subarrays ending at the current index whose sums are divisible by k. We add the count of this remainder from the hash map to our result.
    *
    * Complexity:
    * - Time Complexity: O(n), where n is the number of elements in the nums array.
    * - Space Complexity: O(k), because the hash map stores at most k remainders.
    */
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        int prefix{}, count{};
        unordered_map<int, int> hashMap;
        
        // Initialize with prefix sum 0 occurring once
        hashMap.insert({0, 1}); 
        
        for(int i = 0; i < nums.size(); ++i)
        {
            // Calculate prefix sum modulo k, handle negative values by adding k and taking modulo k again
            prefix = (prefix + nums[i] % k + k ) % k;
            
            count += hashMap[prefix];
            
            ++hashMap[prefix];
        }
        
        return count;   
    }
};