class Solution {
public:
    /* 
    * Approach:
    * Topological sort (Kahn's algorithm).
    * 
    * Complexity:
    * Time Complexity : O(E+V)
    * Space Complexity : O(V) where E is "prerequisites.length" and V is "numCourses"
    */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ordering;
        
        for(auto &p : prerequisites)
        {
            addDirectedEdge(graph, p[1], p[0]);
            indegree[p[0]]++;
        }
        
        queue<int> ready;
        for(int i = 0 ; i < numCourses ; i++)
            if(!indegree[i])
                ready.push(i);
        
        while(!ready.empty())
        {
            int sz = ready.size();
            while(sz--)
            {
                int cur = ready.front();
                ready.pop();
                ordering.push_back(cur);
                
                for(int neighbour : graph[cur])
                    if(--indegree[neighbour] == 0)
                        ready.push(neighbour);
            }
        }
        
        if(ordering.size() != numCourses)
            ordering.clear();
        
        return ordering;
    }
    
    void addDirectedEdge(vector<vector<int>> &graph, int from, int to)
    {
        graph[from].push_back(to);
    }
};