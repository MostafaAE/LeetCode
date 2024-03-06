class NumMatrix {
private:
    vector<vector<int>> prefixSum;
public:
    
    // O(n^2)
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int rows{(int)matrix.size()}, cols{(int)matrix[0].size()};
        prefixSum = matrix;
        
        // accumulate each row
        for(int r = 0 ; r < rows ; r++)
            for(int c = 1 ; c < cols ; c++)
                prefixSum[r][c] += prefixSum[r][c-1];
        
        // accumulate each column
        for(int c = 0 ; c < cols ; c++)
            for(int r = 1 ; r < rows ; r++)
                prefixSum[r][c] += prefixSum[r-1][c];
    }
    
    int cellSum(int row, int col)
    {
        if(row < 0 || col < 0)
            return 0;
        return prefixSum[row][col];
    }
    
    // O(1)
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return cellSum(row2, col2) - cellSum(row1-1, col2) - cellSum(row2, col1-1) + cellSum(row1-1, col1-1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */