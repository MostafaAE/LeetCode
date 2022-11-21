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
        vector<int> completionTime(n);
        
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
                completionTime[cur] += time[cur];
                
                for(int neighbour : graph[cur])
                {
                    if(--indegree[neighbour] == 0)
                        ready.push(neighbour);
                    
                    completionTime[neighbour] = max(completionTime[neighbour], completionTime[cur]);
                }
            }
        }

        return *max_element(completionTime.begin(), completionTime.end());
    }
    
    void addDirectedEdge(vector<vector<int>> &graph, int from, int to)
    {
        graph[from].push_back(to);
    }
};