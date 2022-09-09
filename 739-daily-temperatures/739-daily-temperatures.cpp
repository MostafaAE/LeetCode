class Solution {
public:
    // O(n)-time iterating on elements ~twice only
    vector<int> dailyTemperatures(vector<int> &elements)
    {
        stack<int> st;

        for (int i = 0; i < (int)elements.size(); i++)
        {
            while (!st.empty() && elements[i] > elements[st.top()])
            {
                elements[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
            elements[st.top()] = 0, st.pop();
        return elements;
    }
};