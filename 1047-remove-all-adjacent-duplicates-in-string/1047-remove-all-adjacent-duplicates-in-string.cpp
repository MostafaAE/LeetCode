class Solution {
public:
    string removeDuplicates(string s)
    {
        stack<char> st;
        string result;
        for (char c : s)
        {
            if (!st.empty() && c == st.top())
                st.pop();
            else
                st.push(c);
        }
        while (!st.empty())
            result = st.top() + result, st.pop();

        return result;
    }
};