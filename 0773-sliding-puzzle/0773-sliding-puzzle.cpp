class Solution {
private:
    // Predefined valid moves for each position in the 1D representation of the board
    vector<vector<int>> dir {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

public:
    /**
     * Approach:
     * - Represent the 2x3 board as a 1D string to simplify state transitions.
     * - Use **BFS (Breadth-First Search)** to explore the shortest path to the goal state.
     * - Each state represents a board configuration, and transitions occur by swapping '0' (empty tile) with adjacent tiles.
     * - Keep track of visited states using an unordered set to avoid cycles.
     * - If the goal state `"123450"` is reached, return the number of moves taken.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(n!) where n = 6 ≈ O(720)  
     *   - There are at most **6! = 720** unique board states.
     *   - BFS ensures each state is visited only once.
     * - **Space Complexity**: O(n!) where n = 6 for the queue and visited set.
     */
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        string goal{"123450"};
        string start{};

        // Convert the 2x3 board into a 1D string representation
        for(int i = 0 ; i < 2 ; i++)
            for(int j = 0 ; j < 3 ; j++)
                start += board[i][j] + '0';

        // If already solved, return 0 moves
        if(start == goal)
            return 0;

        queue<string> q;
        unordered_set<string> visited;

        q.push(start);
        visited.insert(start);
        int level = 0; // Number of moves

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                string cur = q.front();
                q.pop();

                int emptyCellIndex = cur.find('0'); // Find empty tile position
                
                for(int newIdx : dir[emptyCellIndex])
                {
                    swap(cur[emptyCellIndex], cur[newIdx]); // Move empty tile

                    if(cur == goal)
                        return level + 1;

                    if(visited.insert(cur).second)
                        q.push(cur);

                    swap(cur[emptyCellIndex], cur[newIdx]); // Undo swap for next iteration
                }
            }
            level++; // Increment move count
        }

        return -1; // No solution found
    }
};
