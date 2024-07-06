class Solution {
public:
    /**
     * Approach:
     * - Determine the direction of the pillow based on how many full passes (n-1 steps) have been made.
     * - If the number of full passes is even, the pillow is moving forward.
     * - If the number of full passes is odd, the pillow is moving backward.
     * - Calculate the current position of the pillow based on the remainder of the time divided by (n-1).
     * - Adjust the index accordingly based on the direction.
     *
     * Complexity:
     * - Time Complexity: O(1)
     * - Space Complexity: O(1)
     */
    int passThePillow(int n, int time) 
    {
        // Determine if the current direction is forward or backward
        bool isForward = (time / (n - 1)) % 2 == 0;
        
        // Calculate the current index in the pass sequence
        int idx = time % (n - 1);
        
        // Adjust the index based on the direction
        if (isForward)
            return idx + 1;
        else
            return n - idx;
    }
};
