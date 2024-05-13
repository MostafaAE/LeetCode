class Solution {
public:
    /* 
    * Approach:
    * - To maximize the score, we need to ensure that the leftmost column has all 1s.
    * - Then, we iterate through each column starting from the second column.
    * - For each column, count the number of 1s. If the number of 0s is greater than the number of 1s, flip the column and add its decimal value to the score.
    *
    * Complexity:
    * - Time Complexity: O(m*n), where m is the number of rows and n is the number of columns.
    * - Space Complexity: O(1).
    */
    int matrixScore(vector<vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();
        
        int score = m * (1 << (n-1)); // Initialize score with the contribution from the leftmost column
        
        for(int c = 1 ; c < n ; ++c)
        {
            int bitsCount{};
            for(int r = 0 ; r < m ; ++r)
                bitsCount += grid[r][c] == grid[r][0]; // Increment count if the value in the current column matches the value in the leftmost column
            
            // If the number of 0s is greater than the number of 1s, flip the column
            bitsCount = max(bitsCount, m - bitsCount);
            // Update the score by adding the contribution from the current column
            score += bitsCount * (1 << (n-1-c));
        }
        
        return score;
    }
};