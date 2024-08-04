class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    /**
     * Approach:
     * - Create a new array to store all possible subarray sums.
     * - Iterate through each element of the nums array to compute all possible subarray sums.
     * - Sort the array of subarray sums.
     * - Compute the sum of elements from the 'left' to 'right' in the sorted array.
     *
     * Complexity:
     * - Time Complexity: O(n^2 * logn) for generating and sorting all subarray sums.
     * - Space Complexity: O(n^2) for storing all subarray sums.
     */
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        vector<int> newArr;
        for(int i = 0 ; i < n ; ++i)
        {
            int sum{};
            for(int j = i ; j < n ; ++j)
            {
                sum += nums[j];
                newArr.push_back(sum);
            }
        }
        
        sort(newArr.begin(), newArr.end());
        
        int result{};
        for(int i = left-1 ; i < right ; ++i)
            result =  (result + newArr[i]) % MOD;
        
        return result;
    }
};