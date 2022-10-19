class Solution {
public:
    /* 
    * Approach:
    * use a stack to check if every open parenthese has a matching closing parenthese
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    bool isValid(string s) 
    {
        map<char,char> mp {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> st;
        
        for(char c : s)
        {
            if(!mp.count(c))
                st.push(c);
            else if(st.empty() || st.top() != mp[c])
                return false;
            else
                st.pop();
        }
        return st.empty();
    }
};