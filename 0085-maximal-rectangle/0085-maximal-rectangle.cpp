class Solution {
public:
    /* 
    * Approach:
    * 1. Prefix Sum and Histogram: We first convert the input matrix of characters to a matrix of integers where each cell represents the height of the rectangle. Then, we apply the prefix sum technique on each column, resetting the sum whenever encountering a '0'. This effectively converts the matrix into a histogram representation for each row.
    *
    * 2. Largest Rectangle in Histogram: For each row, we utilize the monotonic stack approach to compute the largest rectangle area in the histogram.
    * 
    * Complexity:
    * Time Complexity : O(MN)
    * Space Complexity : O(MN) => where M is the number of rows, N is the number of columns
    */
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int rows{(int)matrix.size()}, cols{(int)matrix[0].size()}, maxRectangle{};
        vector<vector<int>> mat(rows, vector<int>(cols, 0));
        
        // copy all values from matrix to mat as integers
        for(int r = 0 ; r < rows ; ++r)
            for(int c = 0 ; c < cols ; ++c)
                mat[r][c] = matrix[r][c] - '0';
        
        // apply prefix sum on each column but reset on every 0
        for(int r = 1 ; r < rows ; ++r)
            for(int c = 0 ; c < cols ; ++c)
                mat[r][c] = mat[r][c] * (mat[r][c] + mat[r-1][c]);
        
        // compute the largest rectangle area for each histogram
        for(int r = 0 ; r < rows ; ++r)
            maxRectangle = max(maxRectangle, largestRectangleArea(mat[r]));
        
        return maxRectangle;
    }
    
    // Prerequisite: https://leetcode.com/problems/largest-rectangle-in-histogram/
    /* 
    * Approach:
    * 1. Monotonic Stack: Utilize a monotonic stack to keep track of heights and indices in ascending order. If the height encountered is less than the height at the top of the stack, pop elements from the stack and calculate the area of the rectangles until the current index.
    * 2. Compute Largest Area: While popping elements from the stack, calculate the area of the rectangle formed by the popped height and the current index, considering the width as the difference between the current index and the index at the top of the stack.
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int largestRectangleArea(vector<int>& heights) 
    {        
        heights.push_back(-1);
        stack<pair<int, int>> st;
        int largestArea{};
        
        for(int i = 0 ; i < (int)heights.size() ; i++)
        {
            int startIdx{i};
            while(!st.empty() && heights[i] < st.top().first)
            {
                auto [height, idx] = st.top();
                st.pop();
                largestArea = max(largestArea, height * (i - idx));
                startIdx = idx;
            }
            st.push({heights[i], startIdx});
        }
        
        return largestArea;
    }
};