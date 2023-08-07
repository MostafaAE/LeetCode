class Solution {
public:
    /* 
    * Approach:
    * Backtracking
    * 
    * Complexity:
    * Time Complexity : O(2^N) for every node we either pick or leave it
    * Space Complexity : O(N) for auxiliary space and path vector
    */
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> results;
        vector<int> path;
        path.push_back(0);
        solve(0, graph, results, path);
        return results;
    }
    
    void solve(int node, vector<vector<int>> &graph, vector<vector<int>> &results, vector<int> &path)
    {
        if(node == (int)graph.size() - 1)
        {
            results.push_back(path);
            return;
        }
        
        for(int neighbour : graph[node])
        {
            path.push_back(neighbour);
            solve(neighbour, graph, results, path);
            path.pop_back();
        }
    }
};