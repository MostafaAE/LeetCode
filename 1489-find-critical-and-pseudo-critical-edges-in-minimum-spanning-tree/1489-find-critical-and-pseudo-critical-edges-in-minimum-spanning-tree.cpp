/*
Approach:
---------
We are asked to find the Critical and Pseudo-Critical edges in a Minimum Spanning Tree (MST).

- Use Kruskal’s algorithm to build the MST normally and get the minimum total cost (`minOptimalCost`).
- For each edge:
    1. Force **including** it first and build the MST; if the cost equals `minOptimalCost`, it's either critical or pseudo-critical.
    2. Force **excluding** it and rebuild the MST; if the cost increases, the edge is **critical**.
    3. Otherwise, if forcing inclusion keeps cost the same but exclusion doesn't hurt, it's **pseudo-critical**.

We use a custom Union-Find (Disjoint Set Union - DSU) structure to manage connected components efficiently.

Kruskal's is called multiple times with minor adjustments for inclusion/exclusion cases.

---------

Time Complexity:
-----------------
- Sorting edges: O(E * log(E)), where E = number of edges.
- Kruskal's runs:
    - For each edge, we call Kruskal twice (include and exclude cases).
    - Each Kruskal call is O(E * α(N)) ≈ O(E), where α is inverse Ackermann function (almost constant).
- So total complexity: O(E^2 + E * log(E)).

Space Complexity:
------------------
- O(E + N), for storing edges and the Union-Find data structures.
*/

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int forests;

    // Helper to link two nodes considering rank (Union by Rank optimization)
    void link(int x, int y)
    {
        if (rank[x] > rank[y])
        {
            swap(x, y); // Always attach the smaller tree to the bigger one
        }

        parent[x] = y;

        if (rank[x] == rank[y])
        {
            ++rank[y];
        }
    }

public:
    // Constructor to initialize UnionFind for n nodes
    UnionFind(int n)
    {
        parent = vector<int>(n);
        rank = vector<int>(n, 1);
        forests = n;

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    // Find the root parent of x with path compression
    int findSet(int x)
    {
        if (x == parent[x])
            return x;
        
        return parent[x] = findSet(parent[x]);
    }

    // Union two sets; returns true if merged, false if already connected
    bool unionSet(int x, int y)
    {
        x = findSet(x), y = findSet(y);

        if (x != y)
        {
            link(x, y);
            --forests;
        }

        return x != y;
    }
};

class Solution {
private:
    struct edge {
        int from, to, weight, idx;

        edge(int from, int to, int weight, int idx) : from(from), to(to), weight(weight), idx(idx) {}

        bool operator <(const edge& e) const
        {
            return weight < e.weight; // Sort edges by weight ascending
        }
    };

    // Kruskal’s algorithm with optional edges to add first and edges to ignore
    int kruskal(int n, vector<edge>& edgeList, vector<edge> addList, unordered_set<int> ignoreList)
    {
        UnionFind uf(n);
        int minCost = 0;

        // Force adding certain edges first
        for (edge& e : addList)
        {
            minCost += e.weight;
            uf.unionSet(e.from, e.to);
        }

        // Regular Kruskal on remaining edges (excluding ignored ones)
        for (edge& e : edgeList)
        {
            if (!ignoreList.count(e.idx) && uf.unionSet(e.from, e.to))
            {
                minCost += e.weight;
            }
        }

        return minCost;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) 
    {
        vector<edge> edgeList;
        
        // Build edge list with original index information
        for (int i = 0; i < edges.size(); ++i)
        {
            edgeList.emplace_back(edges[i][0], edges[i][1], edges[i][2], i);
        }

        sort(edgeList.begin(), edgeList.end());

        // Find the minimum MST cost normally
        int minOptimalCost = kruskal(n, edgeList, {}, {});

        vector<vector<int>> result(2); // result[0]: critical edges, result[1]: pseudo-critical edges

        for (edge& e : edgeList)
        {
            // Case 1: Force including this edge
            int minCostInclude = kruskal(n, edgeList, {e}, {});

            if (minCostInclude > minOptimalCost)
                continue; // This edge is not part of any MST

            // Case 2: Force excluding this edge
            int minCostExclude = kruskal(n, edgeList, {}, {e.idx});
            
            if (minCostExclude == minOptimalCost)
            {
                // Pseudo-critical
                result[1].push_back(e.idx);
            }
            else
            {
                // Excluding the edge changes cost -> Critical
                result[0].push_back(e.idx);
            }
        }

        return result;
    }
};