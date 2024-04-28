class Solution {
public:
    /*
     * Approach:
     * Simulate asteroid collisions using a stack.
     * Iterate through the asteroids, and for each asteroid:
     *   - If it's a negative asteroid and the top of the stack is positive, check for collision:
     *     - If the top of the stack is larger or equal, destroy the current asteroid.
     *     - If the current asteroid is larger, destroy the top of the stack and continue checking.
     *   - If it's a positive asteroid or there are no collisions, push it onto the stack.
     *
     * Complexity:
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st;

        for(int ast : asteroids)
        {
            while(!st.empty() && ast < 0 && st.top() > 0)
            {
                if(st.top() >= -ast)
                {
                    if(st.top() == -ast)
                        st.pop();
                    ast = 0;
                }
                else
                    st.pop();
            }
            if(ast != 0)
                st.push(ast);
        }

        vector<int> result(st.size());
        for(int i = st.size()-1 ; i >= 0 ; --i)
            result[i] = st.top(), st.pop();
            
        return result;
    }
};