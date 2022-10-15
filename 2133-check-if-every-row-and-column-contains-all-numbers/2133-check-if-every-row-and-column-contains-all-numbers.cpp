class Solution {
public:
    /* 
    * Approach:
    * use a hashmap to validate that each row and column does not have any duplicates
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(n)
    */
    bool checkValid(vector<vector<int>>& matrix) 
    {
        int n = (int)matrix.size();
        
        for(int i = 0 ; i < n ; i++)
        {
            unordered_set<int> row, col;
            for(int j = 0 ; j < n ; j++)
                // duplicate number
                if(!row.insert(matrix[i][j]).second || !col.insert(matrix[j][i]).second)
                    return false;
        }
        return true;
    }
};