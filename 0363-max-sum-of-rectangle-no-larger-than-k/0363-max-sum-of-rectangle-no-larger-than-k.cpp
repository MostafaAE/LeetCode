class Solution {
public:
    /* 
    * Approach:
    * Maximum Sum Rectangle variant
    * - Insead of computing the max subarray, we have to compute the max subarray no larger than k
    * - Hint: to solve this problem you have to understand the maximum sum rectangle problem, and max sum subarray no larger than k problem.
    * 
    * Complexity:
    * Time Complexity : O(m^2.nlogn) << where m is the number of rows, n is the number of cols
    * Space Complexity : O(n)
    *
    * This complexity analysis assumes that m < n, but we can flip them so that:
    * Time complexity = O(min(m^2, n^2).max(m, n).log(max(m , n)))
    * Space complexity = O(max(m, n))
    *
    */
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int rows{(int)matrix.size()}, cols{(int)matrix[0].size()}, maxSoFar{INT_MIN};
        
        // do prefix sum on columns
        for(int r = 1 ; r < rows ; r++)
            for(int c = 0 ; c < cols ; c++)
                matrix[r][c] += matrix[r-1][c];
        
        for(int r1 = 0 ; r1 < rows ; r1++)
        {
            for(int r2 = r1 ; r2 < rows ; r2++)
            {
                // Find the max subarray no more than K
                // O(nlogn)
                int cum{}, best{INT_MIN};
                set<int> cumSet;
                cumSet.insert(0); 
                for(int right = 0, left = 0 ; right < cols ; right++)
                {
                    int value = matrix[r2][right];
                    if(r1 > 0)
                        value -= matrix[r1-1][right];
                    cum += value;
                    
                    auto itr = cumSet.lower_bound(cum - k);
                    if(itr != cumSet.end())
                        best=max(best,cum-*itr);
                    cumSet.insert(cum);
                }
                maxSoFar = max(maxSoFar, best);
            }
        }
        
        return maxSoFar;
    }
};