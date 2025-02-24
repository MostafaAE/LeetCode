class Solution {
private:
    int bobDepth{-1};     // The depth of Bob's path from node 0
    int maxProfit{INT_MIN}; // Global maximum profit for Alice's path

public:
    /**
     * Approach:
     * 1. Build an adjacency list from the given edges.
     * 2. Perform a DFS from Bob's starting node (bob) using `bobDFS` to determine Bob’s path depth (bobDepth)
     *    and update the `amount` values along Bob's path:
     *    - If a node is on the first half of Bob's path (closer to node 0), set its amount to 0 (Bob takes all the money).
     *    - If a node is exactly at the middle when bobDepth is odd, halve its amount.
     * 3. Perform a DFS from node 0 using `aliceDFS` to compute the total profit for Alice's path.
     *    - As Alice travels, she collects the modified amounts from nodes.
     *    - At each leaf (or dead-end), update the global maxProfit.
     * 4. Return the maximum profit achieved by Alice.
     *
     * Complexity:
     * - Time Complexity: O(n), where n is the number of nodes.
     *   - Building the graph takes O(n).
     *   - Each DFS (Bob’s and Alice’s) visits each node at most once.
     * - Space Complexity: O(n)
     *   - For the adjacency list, visited arrays, and recursion stack.
     */
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) 
    {
        int n = amount.size();
        vector<vector<int>> adjList(n, vector<int>());

        // Build the adjacency list
        for (auto& e : edges)
        {
            int from = e[0], to = e[1];
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        vector<bool> visited(n, false);

        // DFS from Bob's starting point to determine his path depth and adjust amounts accordingly
        bobDFS(adjList, visited, bob, 1, amount);

        // Reset visited array for Alice's DFS
        visited = vector<bool>(n, false);
        // DFS from node 0 for Alice to collect profit along the path
        aliceDFS(adjList, visited, 0, amount, amount[0]);

        return maxProfit;
    }

    /**
     * Bob's DFS:
     * - Traverse from Bob's starting node to node 0.
     * - Record bobDepth when node 0 is reached.
     * - Adjust the `amount`:
     *   - For nodes in the first half of Bob's path, set amount to 0.
     *   - For the middle node (if bobDepth is odd), halve the amount.
     */
    void bobDFS(vector<vector<int>>& graph, vector<bool>& visited, int node, int curDepth, vector<int>& amount)
    {
        if (node == 0)
        {
            bobDepth = curDepth;
            return;
        }

        visited[node] = true;

        for (int neighbour : graph[node])
        {
            if (!visited[neighbour] && bobDepth == -1)
            {
                bobDFS(graph, visited, neighbour, curDepth + 1, amount);
            }
        }

        // Adjust the amount based on Bob's path:
        // If bobDepth is odd and we're at the middle node, halve its amount.
        if ((bobDepth & 1) && curDepth == (int)ceil(bobDepth / 2.0))
            amount[node] /= 2;
        // For nodes in the first half of Bob's path, set their amount to 0.
        if (curDepth <= bobDepth / 2)
            amount[node] = 0;
    }

    /**
     * Alice's DFS:
     * - Starting from node 0, traverse the tree to accumulate profit.
     * - At each leaf (or when no further node is available), update maxProfit with the accumulated profit.
     */
    void aliceDFS(vector<vector<int>>& graph, vector<bool>& visited, int node, vector<int>& amount, int curProfit)
    {
        visited[node] = true;

        // If it's a leaf node (except for node 0) then update maxProfit
        if (node != 0 && graph[node].size() == 1)
        {
            maxProfit = max(maxProfit, curProfit);
            return;
        }

        // Continue DFS traversal for all unvisited neighbors
        for (int neighbour : graph[node])
        {
            if (!visited[neighbour])
            {
                aliceDFS(graph, visited, neighbour, amount, curProfit + amount[neighbour]);
            }
        }
    }
};
