/**
 * Approach:
 * - Use Union-Find (Disjoint Set Union) to connect all computers.
 * - Each connection connects two computers; union them.
 * - If the number of connections is less than n-1, it's impossible to connect all computers.
 * - Otherwise, the minimum number of operations needed is (number of connected components - 1).
 * 
 * Time Complexity: O(n + m), where
 *   - n = number of computers
 *   - m = number of connections
 * Space Complexity: O(n)
 */

class UnionFind
{
private:
    vector<int> rank, parent;
    int forests;
    
    void link(int x, int y)
    {
        if (rank[x] > rank[y])
            swap(x, y); // force x to be smaller

        parent[x] = y;
        if (rank[x] == rank[y])
            rank[y]++;
    }

public:
    UnionFind(int n)
    {
        rank = vector<int>(n);
        parent = vector<int>(n);
        forests = n;

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int findSet(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = findSet(parent[x]);
    }

    bool unionSets(int x, int y)
    {
        x = findSet(x);
        y = findSet(y);
        if (x != y)
        {
            link(x, y);
            forests--;
        }
        return x != y;
    }

    int getForests()
    {
        return forests;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if ((int)connections.size() < n - 1)
            return -1;
        
        UnionFind uf(n);
        
        for (auto& edge : connections)
            uf.unionSets(edge[0], edge[1]);
        
        return uf.getForests() - 1;
    }
};