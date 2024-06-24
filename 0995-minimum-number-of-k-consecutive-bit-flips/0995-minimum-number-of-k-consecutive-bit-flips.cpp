class Solution {
public:
    /**
     * Approach:
     * - Use a queue to keep track of the indices where flips have been made.
     * - Iterate through the array, and for each element:
     *   - Check if the current index is outside the range of the earliest flip (remove from queue if necessary).
     *   - Determine if the current element needs to be flipped by checking the parity of the sum of the element and the size of the queue.
     *   - If a flip is needed and there are enough elements remaining to flip, increment the flipCount and add the index to the queue.
     *   - If a flip is needed but not enough elements remain to flip, return -1.
     * - The result is the total number of flips performed.
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the size of the nums array.
     * - Space Complexity: O(k), where k is the length of the flip.
     */
    int minKBitFlips(vector<int>& nums, int k) 
    {
        int flipCount = 0;
        queue<int> flipIndex;
        
        for (int i = 0; i < nums.size(); ++i) 
        {
            // Remove indices from the queue that are outside the current window of influence
            if (!flipIndex.empty() && i > flipIndex.front() + k - 1)
                flipIndex.pop();
            
            // Determine if a flip is needed at the current index
            if ((nums[i] + flipIndex.size()) % 2 == 0) 
            {
                // If not enough elements remain to flip, return -1
                if (i + k > nums.size())
                    return -1;
                
                // Increment the number of flips and add the current index to the queue
                ++flipCount;
                flipIndex.push(i);
            }
        }
        
        return flipCount;
    }
};
