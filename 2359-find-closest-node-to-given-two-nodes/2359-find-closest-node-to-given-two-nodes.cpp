class Solution {
public:
    /*
     * Approach:
     * - We simulate a DFS-like traversal from both node1 and node2.
     * - For each node visited from either node, we record the depth (distance).
     * - We find the node reachable from both sources such that the maximum distance 
     *   from either source is minimized.
     * - If multiple nodes have the same minimum distance, the one with the smallest index is returned.
     *
     * Time Complexity: O(N)
     * - We traverse at most once from node1 and once from node2 (each O(N)).
     * 
     * Space Complexity: O(N)
     * - For storing visited node depths for both traversals.
     */
    int closestMeetingNode(vector<int>& edges, int node1, int node2) 
    {
        unordered_map<int, int> nodeToDepth1 = dfs(edges, node1);
        unordered_map<int, int> nodeToDepth2 = dfs(edges, node2);

        int closestNode = -1;
        int closestNodeDepth = INT_MAX;

        for (auto& [node, depth1] : nodeToDepth1)
        {
            if (nodeToDepth2.count(node))
            {
                // Calculate the furthest distance from either start node
                int depth2 = nodeToDepth2[node];
                int maxDepth = max(depth1, depth2);

                if (maxDepth < closestNodeDepth)
                {
                    closestNodeDepth = maxDepth;
                    closestNode = node;
                }
                else if (maxDepth == closestNodeDepth)
                {
                    // Choose the node with the smaller index
                    closestNode = min(closestNode, node);
                }
            }
        }

        return closestNode;
    }

private:
    // Helper method to simulate traversal from a node and record depth
    unordered_map<int, int> dfs(vector<int>& edges, int start)
    {
        unordered_map<int, int> nodeToDepth;
        int cur = start;
        int depth = 0;

        // Traverse until we hit a cycle or dead end
        while (cur != -1 && nodeToDepth.count(cur) == 0)
        {
            nodeToDepth[cur] = depth;
            ++depth;
            cur = edges[cur];
        }

        return nodeToDepth;
    }
};