class Solution {
public:
    /* 
    * Approach:
    * use a hashmap to validate each row , col and sub-box does not have any duplicates
    * 
    * Complexity:
    * Time Complexity : O(n^2)
    * Space Complexity : O(n)
    */
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // validate each row and column
        for(int i = 0 ; i < 9 ; i++)
        {
            unordered_set<char> row;
            unordered_set<char> col;
            for(int j = 0 ; j < 9 ; j++)
            {
                if(board[i][j] != '.' && !row.insert(board[i][j]).second)
                    return false;
                
                if(board[j][i] != '.' && !col.insert(board[j][i]).second)
                    return false;
            }
        }
        
        // validate each sub-box
        for(int i = 0 ; i < 3 ; i++)
        {
            for(int j = 0 ; j < 3 ; j++)
            {
                unordered_set<char> box;
                
                for(int r = 0 ; r < 3 ; r++)
                {
                    for(int c = 0 ; c < 3 ; c++)
                    {
                        char cur = board[i*3+r][j*3+c];
                        if(cur != '.' && !box.insert(cur).second)
                            return false;
                    }
                }
            }
        }
        
        return true;
    }
};