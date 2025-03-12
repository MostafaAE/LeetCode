class Solution 
{
public:
    /**
     * Approach:
     * - We use **binary search** to find the number of negative and positive elements in the sorted array.
     * - The **lower bound** of `0` gives the first position of `0` or the first positive number.
     * - The **upper bound** of `0` gives the position just after the last occurrence of `0` (i.e., the first strictly positive number).
     * - The count of **negative numbers** is given by `lowerBoundIdx`, as all elements before it are negative.
     * - The count of **positive numbers** is given by `n - upperBoundIdx`, as all elements after it are positive.
     * - The result is the **maximum count** of either negative or positive numbers.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(log n), as both `lowerBound` and `upperBound` are implemented using binary search.
     * - **Space Complexity**: O(1)
     */
    int maximumCount(vector<int>& nums) 
    {
        int n = nums.size();
        int lowerBoundIdx = lowerBound(nums, 0); // First occurrence of 0 or first positive number
        int upperBoundIdx = upperBound(nums, 0); // First strictly positive number

        return max(n - upperBoundIdx, lowerBoundIdx);
    }

private:
    /**
     * Finds the first position >= `target` (lower bound).
     */
    int lowerBound(vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size() - 1;

        while (start <= end) 
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] < target) 
            {
                start = mid + 1;
            } 
            else 
            {
                end = mid - 1;
            }
        }
        return start;
    }

    /**
     * Finds the first position > `target` (upper bound).
     */
    int upperBound(vector<int>& nums, int target) 
    {
        int start = 0, end = nums.size() - 1;

        while (start <= end) 
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] <= target) 
            {
                start = mid + 1;
            } 
            else 
            {
                end = mid - 1;
            }
        }
        return start;
    }
};
