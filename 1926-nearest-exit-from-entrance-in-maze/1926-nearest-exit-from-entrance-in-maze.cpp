const int OO = 1e9;
class Solution {
private:
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};
public:
    /* 
    * Approach:
    * Breadth First Serach
    * 
    * Complexity:
    * Time Complexity : O(m*n)
    * Space Complexity : O(m+n)
    */
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) 
    {
        queue<pair<int,int>> q;
        
        // starting point
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        
        int level{};
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [r, c] = q.front();
                q.pop();
                
                for(int d = 0 ; d < 4 ; d++)
                {
                    int nr = r + dr[d], nc = c + dc[d];
                    // exit
                    if(!isValid(nr, nc, maze) && (r != entrance[0] || c != entrance[1]))
                        return level;
                    
                    if(isValid(nr, nc, maze) && maze[nr][nc] == '.')
                    {
                        q.push({nr, nc});
                        maze[nr][nc] = '+';
                    }
                }
            }
            level++;
        }
        
        return -1;
    }
    
    
    bool isValid(int nr, int nc, vector<vector<char>>& maze)
    {
        if(0 > nr || nr >= (int)maze.size() || 0 > nc || nc >= (int)maze[0].size())
            return false;
        return true;
    }
};