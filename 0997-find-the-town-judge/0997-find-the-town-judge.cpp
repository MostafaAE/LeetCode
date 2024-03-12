class Solution {
public:
    /*
     * Approach:
     * Compute the indegree and outdegree of each node, return the node with outdegree = 0 and indegree = n-1.
     *
     * Complexity:
     * Time Complexity : O(V + E)
     * Space Complexity : O(V) where V is the number of nodes, E the number of edges
     */
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int> indegree(n, 0), outdegree(n, 0);
        
        for(auto& v : trust)
            outdegree[v[0]-1]++, indegree[v[1]-1]++;
        
        // get the node that trusts nobody, with outdegree 0 (rule 1)
        // and everybody trusts it indegree n-1 (rule 2)
        for(int i = 0 ; i < n ; i++)
            // outdegree = 0
            if(outdegree[i] == 0 && indegree[i] == n-1)
                return i + 1;
        
        return -1;
    }
};