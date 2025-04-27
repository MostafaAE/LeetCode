/**
 * Approach:
 * - Use Union-Find (Disjoint Set Union) to group similar strings.
 * - Two strings are similar if we can make them equivalent by swapping at most two letters.
 * - Compare every pair of strings. If they are similar, union them.
 * - After all unions, the number of groups is the number of forests remaining.
 * 
 * Time Complexity: O(n^2 * m), where
 *   - n = number of strings
 *   - m = length of each string (cost to compare two strings)
 * Space Complexity: O(n + m)
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
        if (rank[x] == rank[y]) // equal case
            rank[y]++;
    }

public:
    UnionFind(int n)
    {
        rank = vector<int>(n);
        parent = vector<int>(n);
        forests = n; // Number of the current forests

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find_set(int x)
    {
        if (x == parent[x])
            return x;

        return parent[x] = find_set(parent[x]);
    }

    bool union_sets(int x, int y)
    {
        x = find_set(x);
        y = find_set(y);

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
private:
    bool isSimilar(string &str1, string &str2)
    {
        int n = str1.size();
        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (str1[i] != str2[i])
                cnt++;
            
            if (cnt > 2)
                return false;
        }

        return true;
    }

public:
    int numSimilarGroups(vector<string>& strs) 
    {
        int n = strs.size();
        UnionFind uf(n);
        
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (isSimilar(strs[i], strs[j]))
                    uf.union_sets(i, j);
            }
        }
        
        return uf.getForests();
    }
};
