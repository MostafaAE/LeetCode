class NumMatrix {
private:
vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        mat = matrix;
        
        // accumulate each row
        for(int i = 0 ; i < (int)mat.size() ; i++)
            for(int j = 1 ; j < (int)mat[0].size() ; j++)
                mat[i][j] += mat[i][j-1];
        
        // accumulate each column
        for(int j = 0 ; j < (int)mat[0].size() ; j++)
            for(int i = 1 ; i < (int)mat.size() ; i++)
                mat[i][j] += mat[i-1][j];
    }
    
    // O(1)
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        if(row1 == 0 && col1 == 0)
            return mat[row2][col2];
        else if(row1 == 0)
            return mat[row2][col2] - mat[row2][col1-1];
        else if(col1 == 0)
            return mat[row2][col2] - mat[row1-1][col2];
        else
            return mat[row2][col2] - mat[row1-1][col2] - mat[row2][col1-1] + mat[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */