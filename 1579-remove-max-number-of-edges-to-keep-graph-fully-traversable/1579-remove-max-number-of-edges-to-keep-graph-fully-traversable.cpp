class UnionFind
{
private:
    int forests;
    vector<int> parent, rank;

    // Helper function to link two sets by rank
    void link(int x, int y)
    {
        if(rank[x] > rank[y])
            swap(x, y);
        
        parent[x] = y;
        if(rank[x] == rank[y])
            ++rank[y];
    }
    
public:
    // Initialize UnionFind with n elements
    UnionFind(int n)
    {
        rank = vector<int>(n, 1);
        parent = vector<int>(n);
        forests = n; // Number of current forests
        
        for(int i = 0 ; i < n ; ++i)
            parent[i] = i;
    }
    
    // Find the representative of set containing x with path compression
    int find(int x)
    {
        if(x == parent[x])
            return x;
        
        return parent[x] = find(parent[x]);
    }
    
    // Union sets containing x and y
    bool unionSets(int x, int y)
    {
        x = find(x);
        y = find(y);
        
        if(x != y)
        {
            link(x, y);
            --forests;
        }
            
        return x != y;
    }
    
    // Get the number of current forests
    int getForestsCount()
    {
        return forests;
    }
};

class Solution {
public:
    /**
     * Approach:
     * - Use a UnionFind data structure to manage the connected components (forests).
     * - Separate the edges into three categories: Alice's exclusive, Bob's exclusive, and shared edges.
     * - Process the shared edges first to maximize the usage of these edges for both Alice and Bob.
     * - Process Alice's and Bob's exclusive edges separately to maintain their connectivity.
     * - Use a helper function to determine the number of edges to remove and check if Alice and Bob can fully traverse the graph.
     *
     * Complexity:
     * - Time Complexity: O(E), where E is the number of edges.
     * - Space Complexity: O(N + E).
     */
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) 
    {
        int blueEdgesToRemove{};
        UnionFind aliceUf(n), bobUf(n);
        vector<pair<int, int>> aliceEdges, bobEdges;
        
        // Process edges and categorize them
        for(auto &edge : edges)
        {
            if(edge[0] == 1)
                aliceEdges.push_back({edge[1]-1, edge[2]-1});
            else if(edge[0] == 2)
                bobEdges.push_back({edge[1]-1, edge[2]-1});
            else
            {
                if(!aliceUf.unionSets(edge[1]-1, edge[2]-1))
                    ++blueEdgesToRemove;
                bobUf.unionSets(edge[1]-1, edge[2]-1);
            }
        }
        
        int redEdgesToRemove = edgesToRemove(aliceUf, aliceEdges);
        if(redEdgesToRemove == -1)
            return -1;
        
        int greenEdgesToRemove = edgesToRemove(bobUf, bobEdges);
        if(greenEdgesToRemove == -1)
            return -1;
        
        return blueEdgesToRemove + redEdgesToRemove + greenEdgesToRemove;
    }
    
    // Helper function to determine edges to remove for a specific UnionFind instance
    int edgesToRemove(UnionFind uf, vector<pair<int, int>>& edges)
    {
        int result{};
        for(auto &edge : edges)
            if(!uf.unionSets(edge.first, edge.second))
                ++result;
        
        if(uf.getForestsCount() > 1)
            return -1;
        
        return result;
    }
};