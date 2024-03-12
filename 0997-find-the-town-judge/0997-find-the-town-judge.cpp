class Solution {
public:
    /*
     * Approach:
     * Build a directed graph, validate rule 1,2, and 3.
     *
     * Complexity:
     * Time Complexity : O(V + E)
     * Space Complexity : O(V + E) where V is the number of nodes, E the number of edges
     */
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<unordered_set<int>> adjList(n);
        
        for(auto& v : trust)
            // add direct edge
            adjList[v[0]-1].insert(v[1]-1);
        
        // get the node that trusts nobody, with outdegree 0 (rule 1)
        int judgeCount{}, idx;
        for(int i = 0 ; i < n ; i++)
            // outdegree = 0
            if(adjList[i].empty())
                idx = i, judgeCount++;
        
        // violates rule 3
        if(judgeCount != 1)
            return -1;
        
        // check that everybody trusts this judge (rule 2)
        for(int i = 0 ; i < n ; i++)
            // everyone has a direct edge to the judge
            if(i != idx && !adjList[i].count(idx))
                return -1;
        
        return idx + 1;
    }
};