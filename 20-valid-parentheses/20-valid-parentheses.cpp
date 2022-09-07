class Solution {
public:
    bool isValid(string s) {
        
    map<char, char> mp = {{')', '('}, {']', '['}, {'}', '{'}};
    stack<char> st;

    for (char c : s)
    {
        // c == ) or ] or }
        if (mp.count(c))
        {
            if (st.empty() || mp[c] != st.top())
                return false;

            st.pop();
        }
        else
            st.push(c);
    }
        
    return st.empty();
        
    }
};