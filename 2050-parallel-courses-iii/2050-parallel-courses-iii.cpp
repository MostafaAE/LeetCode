class Solution {
public:
    /* 
    * Approach:
    * Topological sort
    * 
    * Complexity:
    * Time Complexity : O(n + m) where m is "relations.length"
    * Space Complexity : O(n)
    */
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) 
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        vector<int> startTime(n);
        
        for(auto &p : relations)
        {
            addDirectedEdge(graph, p[1]-1, p[0]-1);
            indegree[p[0]-1]++;
        }
        
        queue<int> ready;
        for(int i = 0 ; i < n ; i++)
            if(!indegree[i])
                ready.push(i);
        
        while(!ready.empty())
        {
            int sz = ready.size();
            while(sz--)
            {
                int cur = ready.front();
                ready.pop();
                
                for(int neighbour : graph[cur])
                {
                    if(startTime[neighbour] < startTime[cur] + time[cur])
                        startTime[neighbour] = startTime[cur] + time[cur];
                    
                    if(--indegree[neighbour] == 0)
                        ready.push(neighbour);
                }
            }
        }
        
        int minTime{};
        for(int i = 0 ; i < n ; i++)
            if(startTime[i]+time[i] > minTime)
                minTime = startTime[i] + time[i];
        
        return minTime;
    }
    
    void addDirectedEdge(vector<vector<int>> &graph, int from, int to)
    {
        graph[from].push_back(to);
    }
};