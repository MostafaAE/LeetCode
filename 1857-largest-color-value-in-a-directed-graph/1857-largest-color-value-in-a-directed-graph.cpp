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
                int cur = ready.front();
                ready.pop();
                dp[cur][colors[cur]-'a']++;
                visited++;
                for(int neighbour : graph[cur])
                {
                    if(--indegree[neighbour] == 0)
                        ready.push(neighbour);
                    
                    for(int i = 0 ; i < 26 ; i++)
                        dp[neighbour][i] = max(dp[neighbour][i], dp[cur][i]);
                }
            }
        }
        
        if(visited < n)
            return -1;
        
        int largestVal{0};
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < 26 ; j++)
                largestVal = max(largestVal, dp[i][j]);
        
        return largestVal;
    }
    
    void addDirectedEdge(vector<vector<int>> &graph, int from, int to)
    {
        graph[from].push_back(to);
    }
};