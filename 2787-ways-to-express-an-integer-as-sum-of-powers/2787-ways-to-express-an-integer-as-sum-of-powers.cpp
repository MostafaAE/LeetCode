/*
* Approach:
* 1. Precompute all possible powers of integers (i^x) that are ≤ n and store them in nums.
* 2. Use top-down dynamic programming with memoization:
*      - State: (remaining sum, current index in nums)
*      - At each step, choose to either:
*           a) Pick the current power and reduce the remaining sum
*           b) Skip the current power and move to the next
* 3. Base cases:
*      - If remaining == 0 → valid way found → return 1
*      - If remaining < 0 or index is out of bounds → return 0
* 4. Return the total number of ways modulo 1e9+7.
*
* Time Complexity: O(N * M) 
* where:
*       N = target sum (n)
*       M = number of possible powers
*   Each state is computed once due to memoization.
*
* Space Complexity: O(N * M)
*/

class Solution 
{
private:
    static const int MAX = 301;           // Maximum possible 'n' value
    static const int MOD = 1e9 + 7;
    int memory[MAX][MAX];
    vector<int> nums;

public:
    int numberOfWays(int n, int x) 
    {
        // Precompute all powers i^x <= n
        for (int i = 2, val = 1; val <= n; ++i)
        {
            nums.push_back(val);
            val = pow(i, x);
        }

        memset(memory, -1, sizeof(memory));

        return cntWays(n, 0);
    }

private:
    int cntWays(int remaining, int idx) 
    {
        // If we exactly reach 0, we found a valid combination
        if (remaining == 0) 
            return 1;

        // If remaining becomes negative or we run out of numbers → invalid
        if (remaining < 0 || idx >= (int)nums.size())
            return 0;

        int &ret = memory[remaining][idx];
        if (ret != -1) 
            return ret;

        // Option 1: Pick current power
        int pick = cntWays(remaining - nums[idx], idx + 1);

        // Option 2: Skip current power
        int leave = cntWays(remaining, idx + 1);

        return ret = (pick + leave) % MOD;
    }
};