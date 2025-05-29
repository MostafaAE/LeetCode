class Solution {
public:
    int dfs(int node, vector<vector<int>>& adjList, vector<int>& color, int parent, int depth) 
    {
        int res = 1 - depth % 2;
        color[node] = depth % 2;
        for (int neighbour : adjList[node]) 
        {
            if (neighbour != parent) 
                res += dfs(neighbour, adjList, color, node, depth + 1);
        }
        return res;
    }

    vector<int> build(const vector<vector<int>>& edges, vector<int>& color) 
    {
        int n = edges.size() + 1;
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) 
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int res = dfs(0, adjList, color, -1, 0);
        return {res, n - res};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) 
    {
        int n = edges1.size() + 1, m = edges2.size() + 1;

        vector<int> color1(n), color2(m);
        vector<int> count1 = build(edges1, color1);
        vector<int> count2 = build(edges2, color2);

        int maxTree2 = max(count2[0], count2[1]);

        vector<int> res(edges1.size() + 1);
        for (int i = 0; i < n; i++) 
        {
            res[i] = count1[color1[i]] + maxTree2;
        }

        return res;
    }
};