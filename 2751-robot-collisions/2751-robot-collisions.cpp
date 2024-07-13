class Solution {
public:
    /**
     * Approach:
     * - Use a map to store positions and corresponding indices of robots.
     * - Use a stack to manage robots moving to the right ('R').
     * - Iterate through robots in the order of their positions.
     *   - For robots moving to the left ('L'), handle collisions with robots in the stack.
     *   - For robots moving to the right ('R'), push their indices onto the stack.
     * - After processing all robots, collect the healths of surviving robots.
     *
     * Complexity:
     * - Time Complexity: O(n logn)
     * - Space Complexity: O(n)
     */
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) 
    {
        int n = positions.size();
        
        // Map to store the index of each robot based on its position
        map<int, int> posToIdx;
        // Stack to handle robots moving to the right
        stack<int> st;
        // Result vector to store the final health of surviving robots
        vector<int> result;
        
        // Populate the map with the index of each robot based on its position
        for(int i = 0 ; i < n ; ++i)
            posToIdx[positions[i]] = i;

        // Process each robot in order of their positions
        for(auto [pos, idx] : posToIdx)
        {
            char direction = directions[idx];

            if(direction == 'L')
            {
                // Handle collisions with robots in the stack (moving right)
                while(!st.empty())
                {
                    if(healths[idx] == healths[st.top()])
                    {
                        // Both robots destroy each other
                        healths[st.top()] = 0;
                        healths[idx] = 0;
                        st.pop();
                    }
                    else if(healths[idx] > healths[st.top()])
                    {
                        // Current robot destroys the top robot in the stack
                        healths[st.top()] = 0;
                        --healths[idx];
                        st.pop();
                    }
                    else
                    {
                        // Top robot in the stack destroys the current robot
                        --healths[st.top()];
                        healths[idx] = 0;
                    }
                    
                    if(healths[idx] == 0)
                        break;
                }
            }
            else
            {
                // Add robot moving to the right to the stack
                st.push(idx);
            }
        }
        
        // Collect robots that survived (health > 0)
        for(int i = 0 ; i < n ; ++i)
            if(healths[i] > 0)
                result.push_back(healths[i]);
        
        return result;
    }
};
