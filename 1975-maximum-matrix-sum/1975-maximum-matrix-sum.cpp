class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) 
    {
        long long result{};
        int n = matrix.size(), absMin{INT_MAX}, negCount{};
        for(int i = 0 ; i < n ; ++i)
        {
            for(int j = 0 ; j < n ; ++j)
            {
                if(matrix[i][j] < 0)
                    ++negCount;
                
                result += abs(matrix[i][j]);
                absMin = min(absMin, abs(matrix[i][j]));
            }
        }
        
        if(negCount&1)
            result -= 2 * absMin;
        
        return result;
    }
};