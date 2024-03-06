class Solution {
private:
    static const int MAX = 100 + 1;
    int memory[MAX][MAX];
    int m, n;
public:
    /* 
    * Approach:
    * Dynamic Programming Memoization (DP on Grid)
    * 
    * Complexity:
    * Time Complexity : O(m*n)
    * Space Complexity : O(m*n)
    */
    int uniquePaths(int _m, int _n) 
    {
        memset(memory, -1, sizeof(memory));
        m = _m;
        n = _n;
        return countPaths(0, 0);
    }
    
    int countPaths(int r, int c)
    {
        if(r >= m || c >= n)
            return 0;
        
        if(r == m - 1 && c == n - 1)
            return 1;
        
        int &ret = memory [r][c];
        if(ret != -1)
            return ret;
        
        int right = countPaths(r, c + 1);
        int down = countPaths(r + 1, c);
        
        return ret = right + down;
    }
};