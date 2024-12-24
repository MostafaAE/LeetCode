class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1,
                                  vector<vector<int>>& edges2) {
        // Calculate the number of nodes for each tree (number of edges + 1)
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Build adjacency lists for both trees
        vector<vector<int>> adjList1 = buildAdjList(n, edges1);
        vector<vector<int>> adjList2 = buildAdjList(m, edges2);

        int diameter1 =
            findDiameter(adjList1, 0, -1).first;  // Start DFS for Tree 1
        int diameter2 =
            findDiameter(adjList2, 0, -1).first;  // Start DFS for Tree 2

        // Calculate the diameter of the combined tree
        // This accounts for the longest path spanning both trees
        int combinedDiameter =
            ceil(diameter1 / 2.0) + ceil(diameter2 / 2.0) + 1;

        // Return the maximum diameter among the two trees and the combined tree
        return max({diameter1, diameter2, combinedDiameter});
    }

private:
    // Helper function to build an adjacency list from an edge list
    vector<vector<int>> buildAdjList(int size, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(size);
        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        return adjList;
    };

    // Helper function to find the diameter of a tree
    // Returns the diameter and the depth of the node's subtree
    pair<int, int> findDiameter(vector<vector<int>>& adjList, int node,
                                int parent) {
        int maxDepth1 = 0,
            maxDepth2 =
                0;  // Tracks the two largest depths from the current node
        int diameter = 0;  // Tracks the diameter of the subtree

        for (int neighbor :
             adjList[node]) {  // Iterate through neighbors of the current node
            if (neighbor == parent)
                continue;  // Skip the parent to avoid cycles

            // Recursively calculate the diameter and depth of the neighbor's
            // subtree
            auto [childDiameter, depth] = findDiameter(adjList, neighbor, node);

            // Update the maximum diameter of the subtree
            diameter = max(diameter, childDiameter);

            depth++;  // Increment the depth to include the edge to this
                      // neighbor
            // Update the two largest depths from the current node
            if (depth > maxDepth1) {
                maxDepth2 = maxDepth1;
                maxDepth1 = depth;
            } else if (depth > maxDepth2) {
                maxDepth2 = depth;
            }
        }

        // Update the diameter to include the path through the current node
        diameter = max(diameter, maxDepth1 + maxDepth2);

        return {diameter, maxDepth1};
    }
};