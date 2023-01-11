typedef vector<vector<int>> GRAPH;
class Solution {
private:
    // direction arrays
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};
public:
    /* 
    * Approach:
    * Depth-First Search
    * 
    * Complexity:
    * Time Complexity : O(N) => O(N + E) , N = RxC E = 4N => O(5N)
    * Space Complexity : O(N) => auxiliary space for stack
    */
    vector<vector<int>> floodFill(GRAPH& image, int sr, int sc, int color) 
    {
        if(image[sr][sc] != color)
            dfs(image, sr, sc, color);
        
        return image;
    }
    
    void dfs(GRAPH& image, int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];
        image[sr][sc] = color;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = sr + dr[d], nc = sc + dc[d];
            if(isValid(nr, nc, image) && image[nr][nc] == oldColor)
                dfs(image, nr, nc, color);
        }
    }
    
    // Return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, GRAPH& image)
    {
        if(nr < 0 || nr >= (int)image.size() || nc < 0 || nc >= (int)image[0].size())
            return false;
        return true;
    }
};