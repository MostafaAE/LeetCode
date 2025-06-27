/*
 * Approach:
 * - We use the two-pointer technique to solve this problem optimally.
 * - Start with two pointers, one at the beginning and one at the end of the height array.
 * - The area formed between the lines is determined by the shorter line and the distance between them.
 * - Move the pointer pointing to the shorter line inward, since moving the taller line would not help (as the height is limited by the shorter one).
 * - Repeat this process until the two pointers meet, tracking the maximum area seen so far.
 *
 * Time Complexity  : O(n), where n is the number of elements in the input vector.
 * Space Complexity : O(1), constant space is used.
 */

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = (int)height.size() - 1;
        int maxWater = 0;

        // Two-pointer approach: move inward from both ends
        while (left < right)
        {
            // Calculate the current area using the shorter of the two heights
            int curWater = (right - left) * min(height[left], height[right]);

            maxWater = max(maxWater, curWater);

            // Move the pointer pointing to the shorter height
            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return maxWater;
    }
};