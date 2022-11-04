typedef unordered_map<int, int> GRAPH;
class Solution {
public:
    /* 
    * Approach:
    * reduce the problem to a graph and perfrom depth first search to get each connected component
    * the answer is the size of the longest connected component
    * 
    * Complexity:
    * Time Complexity : O(n)
    * Space Complexity : O(n)
    */
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int maxLength{};
        GRAPH graph;
        
        // build the graph
        for(int elem : s)
            if(s.count(elem+1))
                addDirectedEdge(graph, elem, elem+1);
        
        // get the length of each connected component
        for(int elem : s)
        {
            if(!s.count(elem-1))
            {
                int length = dfs(graph, elem);
                maxLength = max(maxLength, length);
            }
        }
        
        return maxLength;
    }
    
    int dfs(GRAPH &graph, int node)
    {
        int length{1};
        while(graph.count(node))
            node = graph[node], length++;
        
        return length;
    }

    void addDirectedEdge(GRAPH &graph, int from, int to)
    {
        graph[from] = to;
    }
};