class Solution {
private:
    static const int MAX = 200 + 1;
    int memory[MAX][MAX];
    vector<vector<int>> triangleg;
public:
    /*
     * Approach:
     * Dynamic Programming Memoization (DP on Grid)
     *
     * Complexity:
     * Time Complexity : O(MN) 
     * Space Complexity : O(MN) where M is the rows, and N is the cols
     */
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        for(int i = 0 ; i < MAX ; ++i)
            for(int j = 0 ; j < MAX ; ++j)
                memory[i][j] = INT_MAX;

        triangleg = triangle;
        
        return minimumPath(0, 0);
    }
    
    int minimumPath(int r, int c)
    {
        // last row
        if(r == (int)triangleg.size() - 1)
            return triangleg[r][c];
        
        int &ret = memory[r][c];
        if(ret != INT_MAX)
            return ret;
        
        int choice1 = minimumPath(r + 1, c);
        int choice2 = minimumPath(r + 1, c + 1);
        
        return ret = triangleg[r][c] + min(choice1, choice2);
    }
};