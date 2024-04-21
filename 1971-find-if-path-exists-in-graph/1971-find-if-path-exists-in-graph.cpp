class UnionFind{
private:
    vector<int> parent, rank;
public:
    UnionFind(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
    }
    
    int findSet(int x)
    {
        if(x == parent[x])
            return x;
        return parent[x] = findSet(parent[x]);
    }
    
    bool unionSet(int x, int y)
    {
        x = findSet(x), y = findSet(y);
        
        if(x != y)
            link(x, y);
        
        return x != y;
    }
    
    void link(int x, int y)
    {
        if(rank[x] > rank[y])
            swap(x, y);
        
        parent[x] = y;
        
        if(rank[x] == rank[y])
            rank[y]++;
    }
};

class Solution {
public:
    /* 
     * Approach:
     * Utilize a Union Find DS to represent the connectivity of vertices in the graph.
     * Iterate through the edges vector and perform union operations to connect the vertices.
     * After the unions, check if the source and destination vertices belong to the same set.
     *
     * Complexity:
     * Time Complexity : O(V + E), where V is the number of vertices and E is the number of edges.
     * Space Complexity : O(V), where V is the number of vertices.
     */
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        UnionFind uf(n);
        
        for(auto &edge : edges)
            uf.unionSet(edge[0], edge[1]);
        
        return uf.findSet(source) == uf.findSet(destination);
    }
};