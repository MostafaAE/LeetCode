typedef unordered_map<int, unordered_set<int>> GRAPH;
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
        unordered_set<int> visited;
        int maxLength{};
        GRAPH graph;
        
        // build the graph
        for(int elem : nums)
            if(s.count(elem+1))
                addUndirectedEdge(graph, elem, elem+1);
        
        // get the length of each connected component
        for(int elem : nums)
        {
            if(!visited.count(elem))
            {
                int length{};
                dfs(graph, elem, visited, length);
                maxLength = max(maxLength, length);
            }
        }
        
        return maxLength;
    }
    
    void dfs(GRAPH &graph, int node, unordered_set<int>& visited, int& length)
    {
        length++;
        visited.insert(node);
        
        for(int neighbour : graph[node])
            if(!visited.count(neighbour))
                dfs(graph, neighbour, visited, length);
    }

    void addUndirectedEdge(GRAPH &graph, int from, int to)
    {
        graph[from].insert(to);
        graph[to].insert(from);
    }
};