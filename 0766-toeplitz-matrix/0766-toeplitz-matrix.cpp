class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size(), cols = matrix[0].size();
        
        // We only need the current and previous rows
        for(int r = 1 ; r < rows ; ++r)
            for(int c = 1 ; c < cols ; ++c)
                if(matrix[r][c] != matrix[r-1][c-1])
                    return false;
        
        return true;
    }
};