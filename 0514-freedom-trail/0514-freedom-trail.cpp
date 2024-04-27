typedef unordered_map<int, unordered_map<char, vector<pair<int, int>>>> GRAPH;
class Solution {
private:
    static const int MAX = 100 + 1;
    int memory[MAX][MAX];
public:
    /*
     * Approach:
     * Dynamic Programming with Memoization (Top-Down)
     *
     * Construct a graph to represent transitions between ring indices based on character matches.
     * Use dynamic programming to find the minimum number of steps required to spell out the key from the ring.
     * Start from the first character of the key and search for possible ways to move the pointer on the ring to match the character.
     * For each possible move, calculate the cost of the move and recursively call the function for the next character in the key.
     * Memoize the results to avoid redundant calculations.
     *
     * Complexity:
     * Time Complexity: O(K * R^2)
     * Space Complexity: O(KR + R^2), where K is the length of the key and R is the length of the ring.
     */
    int findRotateSteps(string ring, string key) 
    {
        GRAPH graph;
        memset(memory, -1, sizeof(memory));
        for(int i = 0 ; i < (int)ring.size() ; ++i)
            for(int j = i ; j <(int)ring.size() ; ++j)
                addUndirectedEdge(graph, ring, i, j);
        
        return findSteps(0, 0, key, ring, graph);
    }
    
    int findSteps(int keyIdx, int ringIdx, string& key, string& ring, GRAPH& graph)
    {
        if(keyIdx >= key.size())
            return 0;
        
        int &ret = memory[keyIdx][ringIdx];
        if(ret != -1)
            return ret;
        
        ret = INT_MAX;
        // Explore all possible ways to move the pointer on the ring to match the current character in the key
        vector<pair<int, int>> ways = graph[ringIdx][key[keyIdx]];
        for(auto &[idx, cost] : ways)
            ret = min(ret, cost + 1 + findSteps(keyIdx + 1, idx, key, ring, graph));
        
        return ret;
    }
    
    void addUndirectedEdge(GRAPH& graph, string& ring, int from, int to)
    {
        int minDistance = min(abs(from - to), (int)ring.size() - abs(from - to));
        graph[from][ring[to]].push_back({to, minDistance});
        graph[to][ring[from]].push_back({from, minDistance});
    }
};