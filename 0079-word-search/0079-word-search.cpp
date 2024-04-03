class Solution {
private:
    int dr[4]{0, 0, -1, 1};
    int dc[4]{-1, 1, 0, 0};
public:
    /* 
    * Approach:
    * Backtracking approach
    * 
    * Complexity:
    * Time Complexity : O(MN4^K) => where k is the length of the word
    * Space Complexity : O(K) => auxiliary space for recursion
    */
    bool exist(vector<vector<char>>& board, string word) 
    {
        int len{};
        int m{(int)board.size()}, n{(int)board[0].size()};
        
        
        for(int r = 0 ; r < m ; r++)
        {
            for(int c = 0 ; c < n ; c++)
            {
                if(board[r][c] == word[0])
                {
                    board[r][c] = '0';
                    if(dfs(board, word, r, c, 1))
                        return true;
                    board[r][c] = word[0];
                }
            }
        }
                    
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int matchedLen)
    {
        if(matchedLen == word.size())
            return true;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            
            if(isValid(board, nr , nc) && board[nr][nc] == word[matchedLen])
            {
                board[nr][nc] = '0';
                if(dfs(board, word, nr, nc, matchedLen + 1))
                    return true;
                board[nr][nc] = word[matchedLen];
            }
        }
        return false;
    }
    
    bool isValid(vector<vector<char>>& board, int r, int c)
    {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return false;
        return true;
    }
};