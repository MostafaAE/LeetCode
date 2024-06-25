class Solution {
public:
    /**
     * Approach:
     * - Use bitwise operations to interleave the elements of the two halves of the array in place.
     * - First, encode both x_i and y_i into nums[i] for i in the range [0, n) using bitwise operations.
     * - Then, decode the elements and place them in the correct order for the shuffled array.
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the length of the input array.
     * - Space Complexity: O(1)
     */
    vector<int> shuffle(vector<int>& nums, int n) 
    {   
        // Step 1: Encode both parts of the array into the first half using bitwise operations
        for(int i = 0 ; i < n ; ++i)
        {
            // Shift left by 10 bits to make space for the second value
            nums[i] <<= 10;
            // Encode the second half element into the first half element
            nums[i] ^= nums[i + n];
        }

        // Step 2: Decode the elements and place them in the correct order
        for(int i = n - 1, j = 2*n - 1 ; i >= 0 ; --i, j -= 2)
        {
            // Extract the last 10 bits to get the original second half element (2^10 - 1 = 1023)
            int y = nums[i] & 1023;
            // Extract the first part which is the original first half element
            int x = nums[i] >> 10;
            
            // Place the second half element in the correct position
            nums[j] = y;
            // Place the first half element in the correct position
            nums[j - 1] = x;
        }

        return nums;
    }
};
