class Solution {
public:
    /**
     * Approach:
     * - Use topological sorting (Kahn's algorithm) to process nodes in a way that ensures each node is processed only after all its ancestors.
     * - Use a set to store the ancestors of each node to avoid duplicates and to maintain sorted order.
     * - Build an adjacency list from the edges and compute the indegree of each node.
     * - Initialize a queue with nodes that have an indegree of 0 (i.e., nodes with no ancestors).
     * - Process each node, updating the ancestors of its neighbors and pushing neighbors with an indegree of 0 into the queue.
     * - Convert sets of ancestors to vectors for the final result.
     *
     * Complexity:
     * - Time Complexity: O(n^2logn + E), where n is the number of nodes, and E is the number of edges.
     * - Space Complexity: O(n^2 + E)
     */
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) 
    {
        vector<set<int>> ancestors(n);
        vector<vector<int>> result(n);
        vector<int> indegree(n, 0);
        vector<vector<int>> adjList(n);

        // Build adjacency list and compute indegrees
        for(auto &e : edges)
        {
            ++indegree[e[1]];
            adjList[e[0]].push_back(e[1]);
        }

        // Initialize the queue with nodes having indegree 0
        queue<int> ready;
        for(int i = 0 ; i < n ; ++i)
            if(indegree[i] == 0)
                ready.push(i);

        // Process nodes using topological sorting
        while(!ready.empty())
        {
            int sz = ready.size();

            while(sz--)
            {
                int cur = ready.front();
                ready.pop();

                for(int neighbour : adjList[cur])
                {
                    // Update the ancestors of the neighbor
                    ancestors[neighbour].insert(ancestors[cur].begin(), ancestors[cur].end());
                    ancestors[neighbour].insert(cur);

                    // Decrease indegree and if it becomes 0, add to queue
                    if(--indegree[neighbour] == 0)
                        ready.push(neighbour);
                }
            }
        }

        // Convert sets of ancestors to vectors for the result
        for(int i = 0 ; i < n ; ++i)
            result[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());

        return result;
    }
};
