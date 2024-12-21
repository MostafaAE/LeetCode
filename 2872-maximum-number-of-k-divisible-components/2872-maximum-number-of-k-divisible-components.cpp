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
        vector<bool> visited(n, 0);
        dfs(adjList, 0, visited, values, k, result);
        
        return result;
    }
    
    long long dfs(vector<vector<int>>& adjList, int node, vector<bool>& visited, vector<int>& values, int k, int& result)
    {
        visited[node] = true;

        long long sum{values[node]};
        for(int neighbour : adjList[node])
            if(!visited[neighbour])
                sum += dfs(adjList, neighbour, visited, values, k, result);

        if(sum % k == 0)
            return 0;
        
        --result;
        return sum;
    }
};