class Solution {
private:
    static const int MAX = 100 + 3;
    int memory[MAX][MAX];
    vector<int> cuts;

public:
    /*
     * Approach:
     * Dynamic Programming Memoization (Nested range pattern)
     * - Use dynamic programming with memoization (top-down).
     * - Add sentinel cuts at 0 and n to represent the full stick.
     * - Sort the cuts to ensure proper range segmentation.
     * - For each segment [startIdx, endIdx], try every possible cut between them.
     * - Choose the cut that results in the minimum total cost.
     * - Use a memoization table to cache results for overlapping subproblems.
     *
     * Time Complexity: O(N^3), where N = number of cuts.
     *   - O(N^2) subproblems, each taking O(N) to solve (trying all splits).
     * Space Complexity: O(N^2) for memoization.
     */
    int minCost(int n, vector<int>& _cuts) 
    {
        cuts = _cuts;
        cuts.push_back(0);   // Add start of the stick
        cuts.push_back(n);   // Add end of the stick
        sort(cuts.begin(), cuts.end());

        memset(memory, -1, sizeof(memory));

        return cutCost(0, (int)cuts.size() - 1);
    }

    // Recursive DP: find minimum cost to cut between cuts[startIdx] and cuts[endIdx]
    int cutCost(int startIdx, int endIdx)
    {
        // Base case: no cuts in between
        if (endIdx - startIdx == 1)
            return 0;

        int &ret = memory[startIdx][endIdx];
        if (ret != -1)
            return ret;

        ret = INT_MAX;
        int cost = cuts[endIdx] - cuts[startIdx];  // Current segment cost

        // Try all possible cuts between startIdx and endIdx
        for (int split = startIdx + 1; split < endIdx; ++split)
        {
            int leftCost = cutCost(startIdx, split);
            int rightCost = cutCost(split, endIdx);
            int totalCost = cost + leftCost + rightCost;
            ret = min(ret, totalCost);  // Take minimum
        }

        return ret;
    }
};