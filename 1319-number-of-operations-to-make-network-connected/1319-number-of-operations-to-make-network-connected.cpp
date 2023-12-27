class UnionFind
{
private:
    vector<int> rank, parent;
    
    void link(int x, int y)
    {
        if (rank[x] > rank[y])
            swap(x, y); // force x to be smaller

        parent[x] = y;
        if (rank[x] == rank[y]) // equal case
            rank[y]++;
    }

public:
    int forests;
    UnionFind(int n)
    {
        rank = vector<int>(n), parent = vector<int>(n);
        forests = n; // Number of the current forests

        for (int i = 0; i < n; ++i)
            parent[i] = i, rank[i] = 1;
    }

    int find_set(int x)
    {
        if (x == parent[x])
            return x;
        // This is the path compression
        // the top parent is returned and we re-link
        return parent[x] = find_set(parent[x]);
    }

    bool union_sets(int x, int y)
    {
        x = find_set(x), y = find_set(y);
        if (x != y)
        { // Different components
            link(x, y);
            forests--; // 2 merged into 1
        }
        return x != y;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if((int)connections.size() < n-1)
          return -1;
        
        UnionFind uf(n);
        
        for(auto& edge: connections)
            uf.union_sets(edge[0], edge[1]);
        
        return uf.forests - 1;
    }
};