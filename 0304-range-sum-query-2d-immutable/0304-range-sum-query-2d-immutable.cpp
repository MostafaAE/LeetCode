class NumMatrix {
private:
vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int row{(int)matrix.size()}, col{(int)matrix[0].size()};
        prefix = vector<vector<int>>(row+1, vector<int>(col+1, 0));
        
        // accumulate each row
        for(int i = 1 ; i <= row ; i++)
            for(int j = 1 ; j <= col ; j++)
                prefix[i][j] += matrix[i-1][j-1] + prefix[i][j-1];

        // accumulate each column
        for(int j = 1 ; j <= col ; j++)
            for(int i = 1 ; i <= row ; i++)
                prefix[i][j] += prefix[i-1][j];
    }
    
    // O(1)
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return prefix[row2+1][col2+1] - prefix[row1][col2+1] - prefix[row2+1][col1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
