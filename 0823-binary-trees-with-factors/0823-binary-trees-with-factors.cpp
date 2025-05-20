class Solution {
private:
    const int MOD = 1e9 + 7;
    unordered_set<int> numSet;
    unordered_map<int, long long> memory;

public:
    /*
     * Approach:
     * - This problem counts the number of **binary trees** that can be formed using array elements
     *   where for every node, the product of its two children equals the node's value.
     * - Use **Dynamic Programming + Hashing**:
     *   1. Iterate over each number `num` in the input set.
     *   2. For each `num`, check if it can be formed by multiplying two numbers `x` and `y` from the set.
     *   3. If so, the number of trees with `num` as root is increased by the number of trees with `x` and `y`
     *      as roots, i.e., `cntTrees(x) * cntTrees(y)`.
     *   4. Use memoization to avoid recomputation.
     *
     * Time Complexity: O(N^2)
     * - N = number of elements in the array.
     * - For each number, we may loop through all other numbers to find factors.
     *
     * Space Complexity: O(N)
     * - For the set and memoization map.
     */
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        numSet.insert(arr.begin(), arr.end());

        int result = 0;
        for (int num : numSet)
        {
            result = (result + cntTrees(num)) % MOD;
        }

        return result;
    }

    long long cntTrees(int num)
    {
        if (memory.count(num))
            return memory[num];

        long long cnt = 1; // Single-node tree

        for (int x : numSet)
        {
            if (num % x == 0 && numSet.count(num / x))
            {
                long long subTree = cntTrees(x) + cntTrees(num / x);
                cnt = (cnt + subTree % MOD) % MOD;
            }
        }

        return memory[num] = cnt;
    }
};