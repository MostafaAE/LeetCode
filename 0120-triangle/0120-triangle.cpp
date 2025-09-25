class Solution {
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (DP on Grid)
     *
     * Complexity:
     * Time Complexity : O(MN) 
     * Space Complexity : O(MN) where M is the rows, and N is the cols
     */
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>> memory(triangle.size());
        for(int i = 0 ; i < triangle.size() ; ++i)
            memory[i] = vector<int>(i + 1, INT_MAX);

        return minTotal(0, 0, memory, triangle);
    }

    int minTotal(int row, int col, vector<vector<int>>& memory, const vector<vector<int>>& triangle)
    {
        if(row >= triangle.size())
            return 0;

        if(memory[row][col] != INT_MAX)
            return memory[row][col];
        
        int choice1 = minTotal(row + 1, col, memory, triangle);
        int choice2 = minTotal(row + 1, col + 1, memory, triangle);

        return memory[row][col] = triangle[row][col] + min(choice1, choice2);
    }
};