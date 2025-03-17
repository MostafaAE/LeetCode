class Solution {
public:
    /**
     * Approach:
     * - Count the occurrences of each number using an **unordered_map**.
     * - If any number appears an **odd number of times**, return `false`.
     * - Otherwise, return `true`, as all numbers can be paired.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n)  
     * - **Space Complexity**: O(n)  
     */
    bool divideArray(vector<int>& nums) 
    {
        unordered_map<int, int> valToCount;

        // Count occurrences of each number
        for(int num : nums)
        {
            ++valToCount[num];
        }
        
        // Check if all numbers have even occurrences
        for(auto& [val, count] : valToCount)
        {
            if(count & 1)
                return false;
        }
        
        return true;
    }
};
