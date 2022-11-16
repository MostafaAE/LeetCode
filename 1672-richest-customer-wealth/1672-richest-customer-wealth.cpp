class Solution {
public:
    /* 
    * Complexity:
    * Time Complexity : O(m*n)
    * Space Complexity : O(1)
    */
    int maximumWealth(vector<vector<int>>& accounts) 
    {
        int m{(int)accounts.size()}, n{(int)accounts[0].size()}, maxWealth{INT_MIN}; 
        for(int i = 0 ; i < m ; i++)
        {
            int curWealth{};
            for(int j = 0 ; j < n ; j++)
                curWealth += accounts[i][j];
                
            maxWealth = max(maxWealth, curWealth);
        }
        
        return maxWealth;
    }
};