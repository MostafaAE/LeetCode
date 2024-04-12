class Solution {
public:
    /*
     * Approach
     * Get the vertices with indegree = 0.
     *
     * Complexity:
     * Time Complexity : O(V + E)
     * Space Complexity : O(V)
     */
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        vector<int> indegrees(n, 0);
        vector<int> result;
        
        for(auto &edge : edges)
            indegrees[edge[1]]++;
        
        for(int i = 0 ; i < n ; i++)
            if(!indegrees[i])
                result.push_back(i);
        
        return result;
    }
};