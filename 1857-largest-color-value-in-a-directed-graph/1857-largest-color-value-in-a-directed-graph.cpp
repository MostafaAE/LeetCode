class Solution {
public:
    /* 
    * Approach:
    * Topological sort
    * 
    * Complexity:
    * Time Complexity : O(E + V)
    * Space Complexity : O(E + V)
    */
    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        int n{(int)colors.size()}, visited{};
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        vector<vector<int>> dp(n, vector<int>(26,0));
        int answer{};
        
        for(auto &p : edges)
        {
            addDirectedEdge(graph, p[0], p[1]);
            indegree[p[1]]++;
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
                int cur = ready.front(), color = colors[cur] - 'a';
                ready.pop();
                
                dp[cur][color]++;
                visited++;
                answer = max(answer, dp[cur][color]);
                
                for(int neighbour : graph[cur])
                {
                    if(--indegree[neighbour] == 0)
                        ready.push(neighbour);
                    
                    for(int i = 0 ; i < 26 ; i++)
                        dp[neighbour][i] = max(dp[neighbour][i], dp[cur][i]);
                }
            }
        }
        
        if(visited != n)
            return -1;
        
        return answer;
    }
    
    void addDirectedEdge(vector<vector<int>> &graph, int from, int to)
    {
        graph[from].push_back(to);
    }
};