class Solution {
public:
    /**
     * Approach:
     * - Use an adjacency list to represent the graph of prerequisites.
     * - For each query, determine if there is a path from the source course to the destination course.
     * - Perform DFS for each source course and keep track of visited nodes to avoid redundant computations.
     * 
     * Complexity:
     * - Time: O(V * (V + E) + Q), where V is the number of courses, E is the number of prerequisites, and Q is the number of queries.
     *   - In the worst case, we may traverse the entire graph for every query.
     * - Space: O(V + E), for storing the adjacency list and visited nodes.
     */
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        // Mapping queries to their indices for result tracking
        unordered_map<int, unordered_map<int, vector<int>>> srcToDest;
        vector<vector<int>> adjList(numCourses);

        // Map queries to their corresponding indices
        int queriesLen = queries.size();
        for (int i = 0; i < queriesLen; ++i) {
            srcToDest[queries[i][0]][queries[i][1]].push_back(i);
        }

        // Build adjacency list for prerequisites
        for (auto& p : prerequisites) {
            adjList[p[0]].push_back(p[1]);
        }

        // Initialize the result array
        vector<bool> result(queriesLen, false);

        // Process each source node in the queries
        for (auto& [src, destMap] : srcToDest) {
            vector<bool> visited(numCourses, false);
            dfs(adjList, src, destMap, visited, result);
        }

        return result;
    }

private:
    // Perform DFS to check if the destination nodes are reachable
    void dfs(vector<vector<int>>& adjList, int node, unordered_map<int, vector<int>>& destMap, vector<bool>& visited, vector<bool>& result) {

        visited[node] = true;

        // Traverse neighbors
        for (int neighbor : adjList[node]) {
            // If the neighbor is in the destination map, mark the corresponding queries as true
            if (destMap.count(neighbor)) {
                for (int idx : destMap[neighbor]) {
                    result[idx] = true;
                }
            }

            // Continue DFS if the neighbor hasn't been visited
            if (!visited[neighbor]) {
                dfs(adjList, neighbor, destMap, visited, result);
            }
        }
    }
};
