class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(1)
    */
    int diagonalSum(vector<vector<int>>& mat) 
    {
        int n{(int)mat.size()};
        int sum{};
        
        for(int i = 0, j = n-1; i < n ; i++, j--)
        {
            sum+= mat[i][i];
            mat[i][i] = 0;
            sum+= mat[i][j];
        }
        
        return sum;
    }
};