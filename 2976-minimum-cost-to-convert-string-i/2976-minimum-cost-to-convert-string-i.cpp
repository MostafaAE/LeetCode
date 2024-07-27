class Solution {
private:
    const int MAX_CHAR = 26;
    const int OO = 1e9;
public:
    /**
     * Approach:
     * - Use the Floyd-Warshall algorithm to find the minimum conversion costs between all pairs of characters.
     * - Iterate through the source string and calculate the total minimum conversion cost to transform it into the target string.
     * - If a conversion is not possible (cost is OO), return -1.
     *
     * Complexity:
     * - Time Complexity: O(n + m), where n is the length of the source/target strings, and m is the length of original/changed vectors.
     * - Space Complexity: O(1)
     */
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        vector<vector<int>> adjMat(MAX_CHAR, vector<int>(MAX_CHAR, OO));
        
        for(int i = 0 ; i < MAX_CHAR ; ++i)
            adjMat[i][i] = 0;
        
        for(int i = 0 ; i < original.size() ; ++i)
        {
            int from = original[i] - 'a', to = changed[i] - 'a', weight = cost[i];
            adjMat[from][to] = min(adjMat[from][to], weight);
        }
        
        // Apply Floyd-Warshall shortest path algorithm 
        for(int k = 0 ; k < MAX_CHAR ; ++k)
        {
            for(int i = 0 ; i < MAX_CHAR ; ++i)
            {
                for(int j = 0 ; j < MAX_CHAR ; ++j)
                {
                    int relax = adjMat[i][k] + adjMat[k][j];
                    adjMat[i][j] = min(adjMat[i][j], relax);
                }
            }
        }
        
        long long result{};
        for(int i = 0 ; i < source.size() ; ++i)
        {
            int from = source[i] - 'a', to = target[i] - 'a';
            if(adjMat[from][to] >= OO)
                return -1;
            
            result += adjMat[from][to];
        }
        
        return result;
    }
};