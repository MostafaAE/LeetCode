class Solution {
public:
    /* 
    * Approach: 
    * - Dynamic Programming Tabulation
    *
    * Complexity:
    * Time Complexity : O(N^2)
    * Space Complexity : O(1)
    */
    int minFallingPathSum(vector<vector<int>>& grid) 
    {
        int n{(int)grid.size()};
        vector<pair<int, int>> prevMins, curMins;

        for(int c = 0 ; c < n ; ++c)
            insertMin(prevMins, grid[n-1][c], c);
        
        for(int r = n - 2; r >= 0 ; --r)
        {
            for(int c = 0 ; c < n ; ++c)
            {
                int minVal{INT_MAX};
                for(int i = 0 ; i < 2 ; ++i)
                    if(prevMins[i].second != c)
                        minVal = min(minVal, grid[r][c] + prevMins[i].first);
                
                insertMin(curMins, minVal, c);
            }
            
            swap(curMins, prevMins);
            curMins.clear();
        }
        
        return prevMins[0].first;
    }
    
    // O(1) the vector will always have at most 2 elements
    void insertMin(vector<pair<int, int>>& v, int val, int idx)
    {
        if (v.size() < 2) 
        {
            v.push_back({val, idx});
            if (v.size() == 2 && v[0].first > v[1].first)
                swap(v[0], v[1]);
        } 
        else if (val < v[1].first) 
        {
            v[1] = {val, idx};
            if (v[0].first > v[1].first)
                swap(v[0], v[1]);
        }
    }
};