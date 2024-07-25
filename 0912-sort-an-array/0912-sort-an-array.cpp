class Solution {
public:
    /**
     * Approach:
     * - Use a counting sort algorithm.
     * - First, determine the minimum and maximum values in the input array.
     * - Create a count array to store the frequency of each number, adjusted by the minimum value.
     * - Fill the count array by iterating over the input array and incrementing the appropriate count.
     * - Reconstruct the sorted array from the count array.
     *
     * Complexity:
     * - Time Complexity: O(n + m), where n is the number of elements in the input array, m is the max value in the array.
     * - Space Complexity: O(m), where m is the max value in the array.
     */
    vector<int> sortArray(vector<int>& nums) 
    {
        int size = nums.size();
        int maxVal = nums[0], minVal = nums[0];
        
        // get the minimum and max values
        for(int i = 1 ; i < size ; i++)
        {
            if(nums[i] > maxVal)
                maxVal = nums[i];
            if(nums[i] < minVal)
                minVal = nums[i];
        }
        
        int newMax = maxVal - minVal;
        
        vector<int> count(newMax +1);
        
        for(int i = 0 ; i < size ; i++)
            count[nums[i]-minVal]++;
        
        int idx{};
        for (int i = 0; i <= newMax; i++)
        {
            for (int j = 0; j < count[i]; j++, idx++)
                nums[idx] = i+minVal;
        }
        return nums;
    }
};