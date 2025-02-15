class Solution {
public:
    /**
     * Approach:
     * 1. Iterate through each number from 1 to `n`.
     * 2. For each number `i`, calculate its square (`num`).
     * 3. Recursively check if the square can be split into parts whose sum equals `i`.
     *    - Use the helper function `isPunishment` to explore all partitions.
     *    - Accumulate digits one by one and check if the sum equals the target.
     *    - If a valid partition is found, set `isPunishmentNum` to true.
     * 4. If `num` is a punishment number, add it to the result.
     * 5. Return the total sum of all punishment numbers.
     *
     * Complexity:
     * - Time Complexity: O(n * 2^m), where `n` is the upper limit and `m` is the length of the square as a string.
     *   - Checking partitions involves exploring all subsets of digits, leading to an exponential complexity of O(2^m).
     * - Space Complexity: O(m) for the recursion stack depth, where `m` is the number of digits in the squared number.
     **/
    int punishmentNumber(int n) 
    {
        int result{};

        for(int i = 1 ; i <= n ; ++i)
        {
            int num = i * i;

            // Check if num can be partitioned to sum to i
            if(isPunishment(to_string(num), i, 0, 0))
                result += num;
        }

        return result;
    }

private:
    /**
     * Recursive helper function to check if numSquared can be partitioned into parts that sum to num.
     * - `numSquared`: The current string of digits to partition.
     * - `num`: The target value to match with the sum of partitions.
     * - `curSum`: The accumulated sum of the current partition.
     * - `idx`: The current index being processed in numSquared.
     **/
    bool isPunishment(string numSquared, int num, int curSum, int idx)
    {
        // Base Case: If all digits are processed, check if the sum equals num
        if(idx == numSquared.size() && curSum == num)
            return true;

        // Pruning Conditions:
        // - If index is out of bounds
        // - If current sum exceeds num
        if(idx > numSquared.size() || num < curSum)
            return false;

        string curStr{};
        // Try all partitions by extending the current substring
        for(int i = idx ; i < numSquared.size() ; ++i)
        {
            curStr += numSquared[i];

            // Recursively check the next partition
            if(isPunishment(numSquared, num, curSum + stoi(curStr), i + 1))
                return true;
        }

        return false;
    }
};