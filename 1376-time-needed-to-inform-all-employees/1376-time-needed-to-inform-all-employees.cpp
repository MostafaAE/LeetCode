typedef vector<vector<int>> GRAPH;
class Solution {
public:
    /* 
    * Approach:
    * Depth-First Search
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        GRAPH graph(n);
        for(int i = 0 ; i < n ; i++)
        {
            if(i == headID)
                continue;
            addDirectedEdge(graph, manager[i], i);
        }
        
        return dfs(graph, headID, informTime);
    }
    
    int dfs(GRAPH& graph, int node, vector<int>& informTime)
    {
        int maxTime{};
        for(int neighbour : graph[node])
        {   
            int time = informTime[node] + dfs(graph, neighbour, informTime);
            maxTime = max(maxTime, time);
        }
        return maxTime;
    }
    
    void addDirectedEdge(GRAPH& graph, int from, int to)
    {
        graph[from].push_back(to);
    }
};