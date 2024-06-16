class Solution {
public:
    /*
    * Approach:
    * - Use a greedy algorithm to ensure every number up to n can be formed by the sum of the given numbers in nums and the numbers we might add.
    * - Track the smallest number that cannot be formed with the current set of numbers using 'miss'.
    * - Iterate through nums and add elements to 'miss' until 'miss' exceeds 'n'.
    * - If the current element in nums is larger than 'miss' or all elements in nums are used, double 'miss' and count it as an added number.
    * 
    * Complexity:
    * - Time Complexity: O(m + log n), where m is the size of nums, and n is the target value.
    * - Space Complexity: O(1).
    */
    int minPatches(vector<int>& nums, int n) 
    {
        int count = 0;
        int i = 0;
        long long miss = 1; // Smallest number that cannot be formed

        while(miss <= n)
        {
            // If current element in nums can be used to form 'miss'
            if(i < nums.size() && nums[i] <= miss)
            {
                miss += nums[i];
                ++i;
            }
            else
            {
                // If current element in nums cannot be used, add 'miss' itself and double 'miss'
                miss += miss;
                ++count;
            }
        }

        return count;
    }
};
