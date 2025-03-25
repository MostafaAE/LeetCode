class Solution {
public:
    /**
     * Approach:
     * - This problem is a **Directed Acyclic Graph (DAG)** scheduling problem.
     * - We use **Topological Sorting (Kahn’s Algorithm)** with a queue to process courses in order.
     * - Each node represents a course, and directed edges define prerequisites.
     * - We track **completion times** and propagate them through the graph.
     * - The **maximum completion time** across all courses is the answer.
     *
     * Complexity Analysis:
     * - **Overall Time Complexity**: **O(N + E)**
     *      - **Building the graph** takes **O(N + E)** (where `E` is the number of edges).
     *      - **Topological Sorting** takes **O(N + E)**.
     * - **Space Complexity**: **O(N + E)** (for adjacency list, indegree array, and completion time tracking).
     */
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), completionTime(n, 0);
        
        // Step 1: Build the adjacency list and indegree array
        for (auto &r : relations)
        {
            int from = r[0] - 1, to = r[1] - 1; // Convert to 0-based index
            graph[from].push_back(to);
            ++indegree[to];
        }
        
        // Step 2: Push all nodes with zero indegree into the queue (no prerequisites)
        queue<int> ready;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                ready.push(i);
                completionTime[i] = time[i]; // Initialize with self-time
            }
        }
        
        int maxTime = 0;
        
        // Step 3: Process nodes in topological order
        while (!ready.empty())
        {
            int cur = ready.front();
            ready.pop();

            maxTime = max(maxTime, completionTime[cur]); // Update max completion time

            for (int neighbour : graph[cur])
            {
                completionTime[neighbour] = max(completionTime[neighbour], completionTime[cur] + time[neighbour]);
                
                if (--indegree[neighbour] == 0)
                    ready.push(neighbour);
            }
        }

        return maxTime;
    }
};
