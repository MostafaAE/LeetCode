class Solution {
private:
    const int OO = 1e9;
public:
    /**
     * Approach:
     * - Use the Floyd-Warshall algorithm to find the shortest paths between all pairs of cities by repeatedly relaxing the distances using intermediate cities.
     * - For each city, count the number of cities that are reachable within the distance threshold.
     * - Return the city with the smallest number of reachable cities within the distance threshold. If there are multiple such cities, return the one with the largest index.
     *
     * Complexity:
     * - Time Complexity: O(n^3) due to the three nested loops in the Floyd-Warshall algorithm.
     * - Space Complexity: O(n^2) for storing the distance matrix.
     */
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        auto mat = vector<vector<int>>(n, vector<int>(n, OO));
        
        for(int i = 0 ; i < n ; ++i)
            mat[i][i] = 0;
        
        for(auto &e : edges)
        {
            int from = e[0], to = e[1], weight = e[2];
            if(from == to)
                continue;
            mat[from][to] = min(mat[from][to], weight);
            mat[to][from] = min(mat[to][from], weight);
        }
        
        for(int k = 0 ; k < n ; ++k)
        {
            for(int i = 0 ; i < n ; ++i)
            {
                for(int j = 0 ; j < n ; ++j)
                {
                    // relaxation
                    int relax = mat[i][k] + mat[k][j];
                    mat[i][j] = min(mat[i][j], relax);
                }
            }
        }
        
        int result{}, minCount{INT_MAX};
        for(int i = 0 ; i < n ; ++i)
        {
            int count{};
            for(int j = 0 ; j < n ; ++j)
            {
                if(i == j)
                    continue;
                
                if(mat[i][j] <= distanceThreshold)
                    ++count;
            }
            
            if(minCount >= count)
            {
                result = i;
                minCount = count;
            }
        }
        
        return result;
    }
};