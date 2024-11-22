class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) 
    {
        int m = matrix.size(), n = matrix[0].size(), result{};
        unordered_map<string, int> colPositionsToCount;
        
        for(int i = 0 ; i < m ; ++i)
        {
            vector<string> positions(2, "");
            for(int j = 0 ; j < n ; ++j)
                positions[matrix[i][j]] += to_string(j) + ",";
            
            result = max(result, 
                         max(++colPositionsToCount[positions[0]], 
                             ++colPositionsToCount[positions[1]]));
        }
        
        return result;
    }
};