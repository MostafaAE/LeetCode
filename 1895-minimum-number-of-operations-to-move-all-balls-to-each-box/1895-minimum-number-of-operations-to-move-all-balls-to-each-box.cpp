class Solution {
public:
    /**
     * Approach:
     * - The goal is to calculate the number of moves required to move all balls to each box.
     * - Perform two passes:
     *   1. Left-to-right: Calculate the number of moves needed to move balls from the left.
     *   2. Right-to-left: Calculate the number of moves needed to move balls from the right.
     * - Maintain running counts of the number of balls and the cumulative moves in each direction.
     * - Combine the results from both passes to get the final result for each box.
     *
     * Complexity:
     * Time Complexity: O(n), where `n` is the number of boxes. Each pass traverses the string once.
     * Space Complexity: O(1)
     */
    vector<int> minOperations(string boxes) 
    {
        int n = boxes.size();
        vector<int> result(n, 0);

        // Variables to track balls and moves to the left and right
        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        for (int i = 0, j = n - 1; i < n; ++i, --j) {
            // Left-to-right pass
            result[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';  // Increment balls count
            movesToLeft += ballsToLeft;    // Update moves count

            // Right-to-left pass
            result[j] += movesToRight;
            ballsToRight += boxes[j] - '0'; // Increment balls count
            movesToRight += ballsToRight;   // Update moves count
        }

        return result;
    }
};
