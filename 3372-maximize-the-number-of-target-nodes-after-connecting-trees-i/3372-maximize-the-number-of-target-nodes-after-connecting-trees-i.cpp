class Solution {
public:
    /*
     * Approach:
     * Graph Traversal (BFS) + Preprocessing
     * 
     * - We are given two trees (edges1 and edges2), and we want to compute for each node in tree1
     *   how many nodes can be reached within `k` moves starting from that node, plus the maximum 
     *   number of reachable nodes from any node in tree2 within `k-1` moves.
     *
     * - For each node in tree1, we perform BFS up to depth `k`.
     * - Separately, we precompute the max number of reachable nodes from any node in tree2 within `k-1` depth.
     * - We then add the results and return.
     *
     * Time Complexity: O(N * K + M * (K - 1))
     * - For each of the N nodes in tree1, we may visit up to K levels (at most all nodes in worst case).
     * - Same for each of the M nodes in tree2 (but to depth K-1).
     * 
     * Space Complexity: O(N + M)
     * - For adjacency lists and visited vectors.
     */
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) 
    {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adjList1(n), adjList2(m);

        // Build adjacency list for tree1
        for (auto& e : edges1)
        {
            adjList1[e[0]].push_back(e[1]);
            adjList1[e[1]].push_back(e[0]);
        }

        // Build adjacency list for tree2
        for (auto& e : edges2)
        {
            adjList2[e[0]].push_back(e[1]);
            adjList2[e[1]].push_back(e[0]);
        }

        // Precompute max target nodes from tree2 within depth k - 1
        int maxTargetNodes2{};
        for (int i = 0; i < m; ++i)
        {
            maxTargetNodes2 = max(maxTargetNodes2, maxTargetNodesFor(i, adjList2, k - 1));
        }

        // For each node in tree1, compute reachable nodes within depth k and add precomputed max from tree2
        vector<int> result(n);
        for (int i = 0; i < n; ++i)
        {
            result[i] = maxTargetNodesFor(i, adjList1, k) + maxTargetNodes2;
        }

        return result;
    }

    // BFS to count how many nodes can be reached from `node` within maxDepth
    int maxTargetNodesFor(int node, vector<vector<int>>& adjList, int maxDepth)
    {
        queue<int> q;
        vector<bool> visited(adjList.size(), false);
        q.push(node);
        visited[node] = true;

        int curDepth = 0, maxTargetNodes = 0;

        while (!q.empty() && curDepth <= maxDepth)
        {
            int sz = q.size();
            while (sz--)
            {
                int cur = q.front(); q.pop();
                ++maxTargetNodes;

                for (int neighbour : adjList[cur])
                {
                    if (!visited[neighbour])
                    {
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
            ++curDepth;
        }

        return maxTargetNodes;
    }
};