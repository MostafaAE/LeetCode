typedef vector<vector<int>> GRAPH;

class Solution {
public:
    /**
     * Approach:
     * - **Topological Sorting (Kahn’s Algorithm)** is used to detect cycles in the course dependency graph.
     * - Construct a **directed graph** from `prerequisites`, where each edge `u -> v` means `u` must be completed before `v`.
     * - Maintain an **in-degree array** to track the number of prerequisites for each course.
     * - Push all courses with **zero in-degree** into a queue and process them.
     * - If we can process all courses, return `true`; otherwise, return `false`.
     * 
     * Complexity Analysis:
     * - **Time Complexity**: O(V + E), where `V` is `numCourses` and `E` is the number of `prerequisites`.  
     *   - Building the adjacency list takes **O(E)**.
     *   - Traversing all nodes and edges takes **O(V + E)**.
     * - **Space Complexity**: O(V + E)  
     *   - The adjacency list takes **O(E)**.
     *   - The in-degree array takes **O(V)**.
     *   - The queue in the worst case holds **O(V)** elements.
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        GRAPH graph(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Build the adjacency list and in-degree count
        for (auto &p : prerequisites)
        {
            int from = p[1], to = p[0];
            graph[from].push_back(to);
            ++indegree[to];
        }

        queue<int> ready;
        
        // Push all courses with zero in-degree into the queue
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                ready.push(i);
        }
        
        int finishedCourses = 0;
        
        // Process courses using topological sorting
        while (!ready.empty())
        {
            int cur = ready.front();
            ready.pop();
            ++finishedCourses;

            for (int neighbor : graph[cur])
            {
                if (--indegree[neighbor] == 0)
                    ready.push(neighbor);
            }
        }
        
        return finishedCourses == numCourses;
    }
};