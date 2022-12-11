class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids)
{
    stack<int> st;
    vector<int> result;
    for (int ast : asteroids)
    {
        bool is_exploded = false;
        while (!st.empty() && ast < 0 && st.top() > 0)
        {
            if (st.top() < -ast)
            {
                st.pop();
                continue;
            }
            else if (st.top() == -ast)
                st.pop();

            is_exploded = true;
            break;
        }
        if (!is_exploded)
            st.push(ast);
    }

    while (!st.empty())
        result.push_back(st.top()), st.pop();
    reverse(result.begin(), result.end());
    return result;
}
};