/**
 * Approach:
 * - Each cuboid can be rotated such that its dimensions are sorted in ascending order,
 *   i.e., width ≤ length ≤ height. This ensures consistent comparisons.
 * - After sorting all cuboids (internally and globally), the problem reduces to finding
 *   the **Longest Increasing Subsequence (LIS)** based on cuboid dimensions.
 * - We solve it using a top-down recursive DP (memoization) approach where for each cuboid,
 *   we try stacking the next cuboids that can go on top and recursively compute the max height.
 *
 * Time Complexity: O(N^2)
 * - For each of the N cuboids, we consider all other cuboids after it for stacking, resulting in O(N^2).
 *
 * Space Complexity: O(N)
 * - A DP memoization array of size N is used to store results.
 */

class Solution {
private:
    const static int MAX = 100 + 1;  // Max number of cuboids + 1 (for 0-indexed base)
    int memory[MAX];  // Memoization array for DP

public:
    int maxHeight(vector<vector<int>>& cuboids) 
    {
        // Step 1: Sort dimensions of each cuboid to enforce width ≤ length ≤ height
        for (auto& v : cuboids)
            sort(v.begin(), v.end());

        // Step 2: Sort all cuboids to enforce global order (so LIS is valid)
        sort(cuboids.begin(), cuboids.end());

        // Step 3: Clear memoization array
        memset(memory, -1, sizeof(memory));

        // Step 4: Insert a dummy cuboid at the beginning (base cuboid)
        cuboids.insert(cuboids.begin(), {0, 0, 0});

        // Step 5: Start LIS DP from the dummy cuboid
        return LISHeight(cuboids, 0);
    }

    // Recursively find the LIS height starting from index `idx`
    int LISHeight(vector<vector<int>>& cuboids, int idx)
    {
        if (idx == (int)cuboids.size())
            return 0;

        int& ret = memory[idx];
        if (ret != -1)
            return ret;

        ret = 0;

        // Try to place each cuboid after the current one
        for (int j = idx + 1; j < (int)cuboids.size(); ++j)
        {
            if (canStack(cuboids[idx], cuboids[j]))
            {
                // Take the max height possible by stacking this cuboid
                ret = max(ret, LISHeight(cuboids, j));
            }
        }

        // Add current cuboid's height
        ret += cuboids[idx][2];
        return ret;
    }

    // Check if cuboid c2 can be placed on top of c1
    bool canStack(vector<int>& c1, vector<int>& c2)
    {
        return c1[1] <= c2[1] && c1[2] <= c2[2];
    }
};