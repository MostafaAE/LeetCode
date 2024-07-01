class Solution {
public:
    /**
     * Approach:
     * - Traverse the array and maintain a counter for consecutive odd numbers.
     * - If the current number is odd, increment the counter.
     * - If the current number is even, reset the counter to 0.
     * - If the counter reaches 3, return true.
     * - If the loop completes without the counter reaching 3, return false.
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the length of the array.
     * - Space Complexity: O(1)
     */
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        int consecutiveOdds = 0;

        for(int val : arr) 
        {
            if(val & 1)
                ++consecutiveOdds;
            else
                consecutiveOdds = 0;

            if(consecutiveOdds == 3)
                return true;
        }

        return false;
    }
};