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
};

class Solution {
public:
    /**
     * Approach:
     * - Use UnionFind to detect cycles in an undirected graph.
     * - For each edge, if the two vertices are already in the same set, that edge is redundant.
     * - Otherwise, union the sets containing the two vertices.
     *
     * Time Complexity: O(E), where E is the number of edges.
     * Space Complexity: O(n), where n is the number of nodes.
     */
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        UnionFind uf(n + 1);
        
        for(auto &edge : edges)
            if(!uf.unionSets(edge[0], edge[1]))
                return edge;
        return {-1, -1};
    }
};