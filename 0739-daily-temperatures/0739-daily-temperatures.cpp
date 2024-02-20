class Solution {
public:
    /* 
    * Approach:
    * Use a monotonic decreasing stack for temperatures, when we find a warmer temperature than any in the stack, store the distance between them.
    * 
    * Complexity:
    * Time Complexity : O(n) => iterating on elements ~twice only
    * Space Complexity : O(n)
    */
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        int n{(int)temperatures.size()};
        vector<int> answer(n, 0);
        stack<int> st;
        
        for(int i = 0 ; i < n ; i++)
        {
            while(!st.empty() && temperatures[st.top()] < temperatures[i])
                answer[st.top()] = i - st.top(), st.pop();
            
            st.push(i);
        }
        
        return answer;
    }
};