class Solution {
private:
    vector<vector<int>> adjList;
    vector<int> count, result;
public:
    /* 
    * Approach: 
    * Two DFS traversals.
    * First DFS to compute the sum of distances starting from the root, and the number of nodes in each subtree rooted at each node excluding the parent.
    * Second DFS to compute the sum of distances for each node in the tree by re-rooting the tree (shifting the root to each node).
    * Suppose we shift the root from root 0 to 1
    * We can observe that count[1] nodes got 1 unit closer to new root and n - count[1] nodes got 1 unit away from the new root.
    * So, res[1] = res[0] - count[1] + n - count[1]
    * i.e, res[new_root] = res[root] - count[new_root] + n - count[new_root]
    *
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        count = vector<int>(n, 1);
        result = vector<int>(n, 0);
        adjList = vector<vector<int>>(n);
        
        for(auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        
        // First DFS to compute subtree sizes and initial sum of distances O(n)
        dfs(0);
        
        // Second DFS to compute the final sum of distances for each node O(n)
        dfs2(0);
        
        return result;
    }
    
    void dfs(int node, int parent = -1)
    {
        for(int neighbour : adjList[node])
        {
            if(neighbour != parent)
            {
                dfs(neighbour, node);
                count[node] += count[neighbour];
                result[node] += result[neighbour] + count[neighbour];
            }
        }
    }
    
    void dfs2(int node, int parent = -1)
    {
        for(int neighbour : adjList[node])
        {
            if(neighbour != parent)
            {
                result[neighbour] = result[node] - count[neighbour] + (count.size() - count[neighbour]);
                dfs2(neighbour, node);
            }
        }
    }
};