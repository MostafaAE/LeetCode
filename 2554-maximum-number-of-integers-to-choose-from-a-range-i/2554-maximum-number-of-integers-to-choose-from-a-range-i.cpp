class Solution {
public:
    /**
     * Approach:
     * 1. Insert all banned numbers into a hash set (`bannedNums`) for quick lookup.
     * 2. Initialize `count` to track the count of valid integers and `remainingSum` to the maximum allowed sum (`maxSum`).
     * 3. Iterate over integers from `1` to `n`:
     *    - If the current integer is not in `bannedNums` and can fit within `remainingSum`, include it:
     *      - Deduct the integer's value from `remainingSum`.
     *      - Increment `count`.
     *    - If `remainingSum` becomes less than the current integer, stop the iteration.
     * 4. Return `count` as the number of valid integers that can be included without exceeding `maxSum`.
     * 
     * Complexity:
     * Time Complexity: O(n + m)
     * - O(m) to insert all banned numbers into the hash set (`m` is the size of the `banned` array).
     * - O(n) to iterate through integers from `1` to `n`.
     * Space Complexity: O(m)
     * - Space for the hash set `bannedNums`.
     */
    int maxCount(vector<int>& banned, int n, int maxSum) 
    {
        int count{}, remainingSum{maxSum};
        
        unordered_set<int> bannedNums(banned.begin(), banned.end());
        
        for(int i = 1 ; i <= n && remainingSum >= i ; ++i)
        {
            if(!bannedNums.count(i))
            {
                remainingSum -= i;
                ++count;
            }
        }
        
        return count;
    }
};