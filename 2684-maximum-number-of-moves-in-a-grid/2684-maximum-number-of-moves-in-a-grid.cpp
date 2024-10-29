class Solution 
{
private:
    static const  int MAX = 1001;
    int memory[MAX][MAX];
    vector<vector<int>> grid;
public:
    int maxMoves(vector<vector<int>>& _grid) 
    {
        memset(memory, -1, sizeof(memory));
        grid = _grid;
        
        int moves{};
        for(int i = 0 ; i < grid.size() ; ++i)
            moves = max(moves, maxMoves(i, 0, 0));
        
        return moves - 1;
    }
    
    int maxMoves(int r, int c, int prevVal)
    {
        if(r >= grid.size() || r < 0 || c >= grid[0].size() || prevVal >= grid[r][c])
            return 0;
        
        int &ret = memory[r][c];
        if(ret != -1)
            return ret;
        
        int upRight = maxMoves(r-1, c+1, grid[r][c]);
        int right = maxMoves(r, c+1, grid[r][c]);
        int downRight = maxMoves(r+1, c+1, grid[r][c]);
        
        return ret = 1 + max(right, max(upRight, downRight));
    }
};