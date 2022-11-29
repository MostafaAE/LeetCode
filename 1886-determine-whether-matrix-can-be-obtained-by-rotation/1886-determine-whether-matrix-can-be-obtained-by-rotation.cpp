class Solution {
public:
    
    /* 
    * Approach:
    * Compare the original matrix with the 4 different possible rotations in-place
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(1)
    */
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) 
    {
        int n{(int)mat.size()};
        bool found[4]{1,1,1,1};

        for(int i = 0; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                // 1 rotation
                if(mat[i][j] != target[j][n-i-1]) found[0] = false;
                // 2 rotations
                if(mat[i][j] != target[n-i-1][n-j-1]) found[1] = false;
                // 3 rotations
                if(mat[i][j] != target[n-j-1][i]) found[2] = false;
                // 4 rotations
                if(mat[i][j] != target[i][j]) found[3] = false;
            }
        }
        
        return found[0] || found[1] || found[2] || found[3];
    }
};