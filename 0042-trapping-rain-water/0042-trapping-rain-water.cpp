/*
 * Approach:
 * Two-pointer technique from both ends of the array.
 * At each step, we move the pointer pointing to the shorter bar:
 * - Maintain a `maxWaterLevel` which is the maximum water level so far,
 *   calculated as the maximum of the minimum between height[left] and height[right].
 * - At each step, calculate the trapped water at left and right and add to the result
 *   using max(0, curHeight - height[pos]) to avoid negative contribution.
 * - Move the pointer with the smaller height, as it limits the trapped water.
 *
 * Time Complexity  : O(n), where n is the number of bars.
 * Space Complexity : O(1), constant space usage.
 */

class Solution {
public:
    int trap(vector<int>& height) 
    {
        int left = 0, right = (int)height.size() - 1;

        int maxWaterLevel = 0, result = 0;

        while (left < right)
        {
            maxWaterLevel = max(maxWaterLevel, min(height[left], height[right]));

            result += max(0, maxWaterLevel - height[left]);
            result += max(0, maxWaterLevel - height[right]);

            if (height[left] < height[right])
                ++left;
            else
                --right;
        }

        return result;
    }
};