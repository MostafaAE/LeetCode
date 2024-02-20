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
            while(!st.empty() && nums[st.top()] < nums[i%n])
                answer[st.top()] = nums[i%n], st.pop();
            
            st.push(i%n);
        }
        
        return answer;
    }
};