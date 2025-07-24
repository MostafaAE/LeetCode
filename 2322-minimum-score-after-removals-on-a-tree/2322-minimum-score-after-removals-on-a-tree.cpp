/*
 * Approach:
 * - We're given a tree and need to remove two edges to split the tree into 3 components.
 * - The "score" is the difference between the maximum and minimum XOR values among the 3 parts.
 * - Goal: Minimize this score.
 *
 * Steps:
 * 1. Run DFS from the root (node 0) to compute the XOR of all subtrees.
 * 2. Try removing each edge as the **first cut** by checking every subtree rooted at each node.
 * 3. For each first cut, run another DFS (`dfs2`) to try a **second cut** in the remaining subtree.
 * 4. Track and update the minimum score by computing the XORs of the three resulting components.
 *
 * Time Complexity:
 * - O(N²) in the worst case:
 *     - First DFS runs in O(N), for each node.
 *     - For each node, a second DFS (`dfs2`) may explore almost the entire subtree again.
 *
 * Space Complexity:
 * - O(N) for the graph and recursion stack.
 */

class Solution {
private:
    vector<int> nums;
    vector<vector<int>> graph;
    int totalXor = 0;
    int result = INT_MAX;

    // Utility to compute the score between three parts
    int calc(int a, int b, int c) 
    {
        return max({a, b, c}) - min({a, b, c});
    }

    // Second DFS - Explore second edge cuts
    int dfs2(int node, int parent, int firstCutXor, int firstCutRoot) 
    {
        int subtreeXor = nums[node];

        for (int neighbor : graph[node]) 
        {
            if (neighbor == parent) 
                continue;

            subtreeXor ^= dfs2(neighbor, node, firstCutXor, firstCutRoot);
        }

        // Avoid reusing the edge that connects directly back to the first cut root
        if (parent == firstCutRoot) 
            return subtreeXor;

        // Compute the XOR values of the 3 parts
        int part1 = firstCutXor;
        int part2 = subtreeXor;
        int part3 = totalXor ^ part1 ^ part2;

        result = min(result, calc(part1, part2, part3));
        return subtreeXor;
    }

    // First DFS - Try all possible first edge cuts
    int dfs(int node, int parent) 
    {
        int subtreeXor = nums[node];

        for (int neighbor : graph[node]) 
        {
            if (neighbor == parent) 
                continue;

            subtreeXor ^= dfs(neighbor, node);
        }

        // Try cutting each subtree (edge from this node to neighbor)
        for (int neighbor : graph[node]) 
        {
            if (neighbor == parent) 
                continue;

            // Try this edge as the first cut and explore second cuts in its subtree
            dfs2(neighbor, node, subtreeXor ^ nums[neighbor], node);
        }

        return subtreeXor;
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        this->nums = nums;
        int n = nums.size();
        graph.assign(n, vector<int>());

        // Build the adjacency list for the tree
        for (auto& edge : edges) 
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Compute the total XOR of all nodes
        totalXor = 0;
        for (int val : nums) 
        {
            totalXor ^= val;
        }

        // Start DFS from root (node 0)
        dfs(0, -1);
        return result;
    }
};