class Solution {
public:
    /**
     * Approach:
     * - Initialize `count` to 0 to represent the current depth in the directory structure.
     * - Iterate through each log entry:
     *   - If the log entry is "../", decrement `count` by 1, ensuring it doesn't go below 0.
     *   - If the log entry is not "./", increment `count` by 1.
     *   - Ignore the log entry "./" as it represents staying in the same directory.
     * - The value of `count` at the end will be the minimum number of operations to return to the main folder.
     *
     * Complexity:
     * - Time Complexity: O(n)
     * - Space Complexity: O(1)
     */
    int minOperations(vector<string>& logs) 
    {
        int count{};
        
        for(auto log : logs)
        {
            if(log == "../")
                count = max(0, count - 1);
            else if(log != "./")
                ++count;
        }
        
        return count;
    }
};