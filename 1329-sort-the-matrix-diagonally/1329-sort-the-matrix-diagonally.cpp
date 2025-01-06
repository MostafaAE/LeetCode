class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int rows = mat.size(), cols = mat[0].size();
        vector<vector<int>> sortedMat(rows, vector<int>(cols, 0));

        for(int c = 0 ; c < cols ; ++c)
            sortDiagonal(0, c, mat, sortedMat);

        for(int r = 1 ; r < rows ; ++r)
            sortDiagonal(r, 0, mat, sortedMat);

        return sortedMat;
    }

    void sortDiagonal(int r, int c, vector<vector<int>>& mat, vector<vector<int>>& sortedMat)
    {
        vector<int> diagonal;

        for(int i = r, j = c ; i < mat.size() && j < mat[0].size() ; ++i, ++j)
            diagonal.push_back(mat[i][j]);

        sort(diagonal.begin(), diagonal.end());

        for(int i = r, j = c, k = 0; i < mat.size() && j < mat[0].size() ; ++i, ++j, ++k)
            sortedMat[i][j] = diagonal[k];
    }
};