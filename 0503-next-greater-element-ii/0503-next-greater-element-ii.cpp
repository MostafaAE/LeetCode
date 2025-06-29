class Solution {
public:
    /* 
    * Approach:
    * Use a monotonic decreasing stack for numbers, when we find a greater number than any in the stack, store it as the next greater number (iterate two times).
    * 
    * Complexity:
    * Time Complexity : O(n) => iterating on elements ~twice only
    * Space Complexity : O(n)
    */
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n{(int)nums.size()};
        vector<int> answer(n, -1);
        stack<int> st;
        
        for(int i = 0 ; i < n*2 ; i++)
        {
            int idx = i % n;
            while(!st.empty() && nums[st.top()] < nums[idx])
            {
                answer[st.top()] = nums[idx];
                st.pop();
            }
            
            if(i < n)
                st.push(idx);
        }
        
        return answer;
    }
};