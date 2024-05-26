class Solution {
private:
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> memory;
    int len;
public:
    /* 
    * Approach: 
    * - Dynamic Programming with Memoization
    * - We use a 3D vector `memory` to store intermediate results to avoid redundant calculations.
    * - The 3D vector dimensions are `[n+1][2][3]` where:
    *     - `n+1` represents the number of days from 0 to n.
    *     - `2` represents the possible values for the count of absences (0 or 1).
    *     - `3` represents the possible values for the count of consecutive lates (0, 1, or 2).
    * - The recursive function `countRecords` explores all possible attendance records by considering three choices at each step:
    *     1. Adding 'A' (Absent)
    *     2. Adding 'L' (Late)
    *     3. Adding 'P' (Present)
    * - Base cases handle the conditions where the sequence becomes invalid (too many absences or lates) or when all days have been processed.
    * - We use memoization to store results of subproblems to avoid recomputation.
    *
    * Complexity:
    * - Time Complexity : O(n)
    *   - Each state is visited at most once, and the number of states is `n * 2 * 3`.
    * - Space Complexity : O(n)
    *   - Space used by the memoization table and the recursion stack.
    */
    int checkRecord(int n) 
    {
        memory = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));
        len = n;
        
        return countRecords(0, 0, 0);
    }
    
    int countRecords(int idx, int absentCount, int lateCount)
    {
        // Base case: If there are 2 or more absences, or 3 or more consecutive lates, it's invalid
        if(absentCount >= 2 || lateCount >= 3)
            return 0;
        // Base case: If we've processed all days, return 1 as it's a valid sequence
        if(idx >= len)
            return 1;
        
        int ret = memory[idx][absentCount][lateCount];
        if(ret != -1)
            return ret;
        
        // Option 1: Add 'P' (Present) -> No change in absent count, reset late count
        int count = countRecords(idx + 1, absentCount, 0) % MOD;
        
        // Option 2: Add 'A' (Absent) -> Increment absent count, reset late count
        count = (count + countRecords(idx + 1, absentCount + 1, 0)) % MOD;
        
        // Option 3: Add 'L' (Late) -> No change in absent count, increment late count
        count = (count + countRecords(idx + 1, absentCount, lateCount + 1)) % MOD;
        
        return memory[idx][absentCount][lateCount] = count;
    }
};