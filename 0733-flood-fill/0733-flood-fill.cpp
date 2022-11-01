class Solution {
private:
    //direction arrays
    // Delta for: up, right, down, left
    int dr[4]{-1, 1, 0, 0};
    int dc[4]{0, 0, -1, 1};
public:
    /* 
    * Approach:
    * depth first search
    * 
    * Complexity:
    * Time Complexity : O(N) => O(N + E) , N = RxC E = 4N => O(5N)
    * Space Complexity : O(N) => auxiliary space for stack
    */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int oldColor = image[sr][sc];
        if(oldColor == color)
            return image;
        
        image[sr][sc] = color;
        
        for(int d = 0 ; d < 4 ; d++)
        {
            int nr = sr + dr[d], nc = sc + dc[d];
            if(isValid(nr, nc, image) && image[nr][nc] == oldColor)
                floodFill(image, nr ,nc, color);    
        }
        
        return image;
    }
    
    // Return true if this position INSIDE the 2D matrix
    bool isValid(int nr, int nc, vector<vector<int>>& image)
    {
        if(nr < 0 || nr >= (int)image.size() || nc < 0 || nc >= (int)image[0].size())
            return false;
        return true;
    }
};