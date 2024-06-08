class Solution {
public:
    /*
    * Approach:
    * - Use a prefix sum and a hash map to store the remainder when the prefix sum is divided by k.
    * - If the same remainder is found again, it means there is a subarray whose sum is a multiple of k.
    * - When we find a subarray whose sum is a multiple of k, and its length is at least 2, then return true.
    *
    * Complexity:
    * - Time Complexity: O(n), where n is the number of elements in the nums array.
    * - Space Complexity: O(n)
    */
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
        int prefix = 0;
        unordered_map<int, int> hashMap;
        
        // Initialize with prefix sum 0 at index -1 to handle subarray starting from index 0
        hashMap.insert({0, -1}); 
        
        for(int i = 0; i < nums.size(); ++i)
        {
            prefix = (prefix + nums[i]) % k;
            if(hashMap.count(prefix))
            {
                // Ensure the subarray length is at least 2
                if(i - hashMap[prefix] > 1)
                    return true;
            }
            else
                hashMap[prefix] = i;
        }
        
        return false;
    }
};
