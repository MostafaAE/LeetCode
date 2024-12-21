class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) 
    {
        vector<vector<int>> adjList(n, vector<int>());

        for(auto& edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        int result{n};
        
        dfs(adjList, 0, -1, values, k, result);
        
        return result;
    }
    
    int dfs(vector<vector<int>>& adjList, int node, int parent, vector<int>& values, int k, int& result)
    {
        int sum{values[node]};
        for(int neighbour : adjList[node])
            if(neighbour != parent)
                sum += dfs(adjList, neighbour, node, values, k, result), sum %= k;

        if(sum % k == 0)
            return 0;
        
        --result;
        return sum;
    }
};