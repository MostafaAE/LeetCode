class Solution {
public:
    /* 
    * Approach:
    * 1. Prefix Sum and Histogram: Apply the prefix sum technique on each column, resetting the sum whenever encountering a '0'. This effectively converts the matrix into a histogram representation for each row.
    *
    * 2. Largest Rectangle in Histogram: For each row (histogram), sort it in descending order, and compute the largest rectangle area in the histogram.
    * 
    * Complexity:
    * Time Complexity : O(MNlogN)
    * Space Complexity : O(N) => where M is the number of rows, N is the number of columns
    */
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int rows{(int)matrix.size()}, cols{(int)matrix[0].size()}, maxArea{};
        vector<int> prevRow(cols, 0);
        
        for(int r = 0 ; r < rows ; r++)
        {
            vector<int> curRow = matrix[r];
            
            for(int c = 0 ; c < cols ; c++)
                curRow[c] += curRow[c] * prevRow[c];
            
            vector<int> sortedRow = curRow;
            sort(sortedRow.begin(), sortedRow.end(), greater());
            
            for(int c = 0 ; c < cols ; c++)
                maxArea = max(maxArea, sortedRow[c] * (c+1));
            
            prevRow = curRow;
        }
        
        return maxArea;
    }
};