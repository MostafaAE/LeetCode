class Solution {
public:
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