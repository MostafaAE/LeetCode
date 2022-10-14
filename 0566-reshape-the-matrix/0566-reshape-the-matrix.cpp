class Solution {
public:
    
    /* 
    * Approach:
    * iterate over the input matrix and insert each element
    * in its new position in the output matrix
    * 
    * Complexity:
    * Time Complexity : O(n*m)
    * Space Complexity : O(1) >> neglecting the output space
    */
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int rows = (int)mat.size();
        int cols = (int)mat[0].size();
        
        if(rows*cols != r*c)
            return mat;
        
        vector<vector<int>> result(r, vector<int>(c));
        int rowNum {}, columnNum{};
        
        for(int i = 0 ; i < rows ; i++)
        {
            for(int j = 0 ; j < cols ; j++)
            {
                result[rowNum][columnNum++] = mat[i][j];
                
                if(columnNum == c)
                    columnNum = 0, rowNum++;
            }
        }
        
        return result;
    }
};