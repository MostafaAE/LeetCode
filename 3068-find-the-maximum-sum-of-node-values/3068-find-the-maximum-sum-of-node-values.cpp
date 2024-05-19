class Solution {
public:
    /*
    * Approach:
    * - Calculate the initial sum of the nums array.
    * - For each element in nums, calculate the potential change (delta) in its value if it were XORed with k.
    *   - delta[i] = (nums[i] ^ k) - nums[i]
    *   - This delta represents how much the element would increase or decrease if we apply the XOR operation.
    * - Sort the delta array in descending order to prioritize the most beneficial changes first.
    * - Iterate over the delta array in pairs. If the sum of a pair of deltas is positive, update the total sum accordingly.
    * - Return the updated total sum after considering the beneficial changes.
    *
    * Complexity:
    * - Time Complexity: O(n log n), where n is the number of elements in nums.
    * - Space Complexity: O(n)
    */
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) 
    {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        
        vector<int> delta(nums.size());
        for(int i = 0 ; i < delta.size() ; ++i)
            delta[i] = (nums[i]^k) - nums[i];

        sort(delta.begin(), delta.end(), greater());
        
        for(int i = 0 ; i < delta.size() - 1 ; i+=2)
        {
            int pathDelta = delta[i] + delta[i + 1];
            if(pathDelta > 0)
                sum += pathDelta;
        }
        
        return sum;
    }
};