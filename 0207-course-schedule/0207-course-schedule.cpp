class Solution {
public:
    /* 
    * Approach:
    * Topological sort
    * 
    * Complexity:
    * Time Complexity : O(E+V)
    * Space Complexity : O(V) where E is "prerequisites.length" and V is "numCourses"
    */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        int finishedCount{};
        
        for(auto &p : prerequisites)
        {
            addDirectedEdge(graph, p[1], p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> ready;
        
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                ready.push(i), finishedCount++;
    
        while (!ready.empty())
        {
            int cur = ready.front();
            ready.pop();

            for (int neighbour : graph[cur])
                if (--indegree[neighbour] == 0)
                    ready.push(neighbour), finishedCount++;
        }
        
        return finishedCount == numCourses;
    }
    

    
    void addDirectedEdge(vector<vector<int>> &graph, int from, int to)
    {
        graph[from].push_back(to);
    }
};