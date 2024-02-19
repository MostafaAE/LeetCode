class Solution {
public:
    /* 
    * Approach:
    * Rotate the given matrix two times, first time with respect to the main diagonal, next time rotate the resultant matrix with respect to the middle column (transpose then reflect).
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(1)
    */
    void rotate(vector<vector<int>>& matrix) 
    {
        // First rotation with respect to main diagonal (transpose)
        transpose(matrix);
            
        // Second rotation with respect to middle column (reflect)
        reflect(matrix);     
    }
    
    void transpose(vector<vector<int>>& matrix)
    {
        int n{(int)matrix.size()};
        for(int i = 1 ; i < n ; i++)
            for(int j = i -1 ; j >= 0 ; j--)
                swap(matrix[i][j], matrix[j][i]);
    }
    
    void reflect(vector<vector<int>>& matrix)
    {
        int n{(int)matrix.size()};
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n/2 ; j++)
                swap(matrix[i][j], matrix[i][n-1-j]);
    }
};