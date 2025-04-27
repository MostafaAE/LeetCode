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

    int getForests()
    {
        return forests;
    }
};


class Solution {
public:
    bool isSimilar(string &str1, string &str2)
    {
        int n{(int)str1.size()};
        int cnt{};
        for(int i = 0 ; i < n ; i++)
        {
            if(str1[i] != str2[i])
                cnt++;
            
            if(cnt > 2)
                return false;
        }
        
        return true;;
    }
    
    int numSimilarGroups(vector<string>& strs) 
    {
        int n{(int)strs.size()};
       
        UnionFind uf(n);
        
        for(int i = 1 ; i < n ; i++)
            for(int j = i - 1 ; j >= 0 ; j--)
                if(isSimilar(strs[i], strs[j]))
                    uf.union_sets(i, j);
            
        return uf.forests;
        
    }
};