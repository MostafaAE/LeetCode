class Solution {
public:
    /* 
    * Approach:
    * Rotate groups of four cells
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(1)
    */
    void rotate(vector<vector<int>>& matrix) 
    {
        int n{(int)matrix.size()};
        for(int i = 0 ; i < (n+1)/2 ; i++)
        {
            for(int j = 0 ; j < n/2 ; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
                matrix[j][n - 1 -i] = temp;
            }
        }
    }
};