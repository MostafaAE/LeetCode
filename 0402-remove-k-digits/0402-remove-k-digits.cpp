class Solution {
public:
    /*
     * Approach:
     * Monotonic Increasing Stack & Greedy approach (Start from the left and remove the largest k numbers we face)
     * - Iterate over num, if the current digit is larger than the top of the stack, then put it in the stack.
     * - If the current digit is smaller, then keep popping elements from the stack until there are no more bigger elements or we removed k elements.
     *
     * Complexity:
     * Time Complexity : O(n)
     * Space Complexity : O(n)
     */
    string removeKdigits(string num, int k) 
    {
        stack<char> st;
        string res;
        
        for(int i = 0 ; i < (int)num.size() ; i++)
        {
            while(!st.empty() && num[i] < st.top() && k > 0)
            {
                st.pop();
                --k;
            }
            if(num[i] != '0' || !st.empty())
                st.push(num[i]);
        }
        
        while(!st.empty() && k > 0)
            --k, st.pop();
        
        if(st.empty())
            return "0";
        
        res.resize(st.size());
        int itr = (int)res.size()-1;
        while(!st.empty())
        {
            res[itr--] = st.top();
            st.pop();
        }
        
        return res;
    }
};