class Solution {
public:
    /*
    * Approach:
    * - We need `n` unique integers that sum up to 0.
    * - Idea:
    *   - If n is odd → include 0 in the result.
    *   - Then for i = 1 to n/2, include both +i and -i.
    *   - This guarantees:
    *       • All numbers are unique.
    *       • They sum to 0 (since each +i cancels with -i, and 0 adds nothing).
    *
    * Time Complexity: O(n)
    * Space Complexity: O(1), ignoring output space
    */
    vector<int> sumZero(int n) 
    {
        vector<int> result;

        // If n is odd, include 0
        if (n & 1)
            result.push_back(0);

        // Add pairs (i, -i) to ensure sum = 0
        for (int i = 1; i <= n / 2; ++i) 
        {
            result.push_back(i);
            result.push_back(-i);
        }

        return result;
    }
};