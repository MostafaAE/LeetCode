class UnionFind{
private:
    vector<int> parent;
public:
    UnionFind(int n)
    {
        parent = vector<int>(n);
        for(int i = 0 ; i < n ; i++)
            parent[i] = i;
    }
    
    int findSet(int x)
    {
        if(x == parent[x])
            return x;
        
        return parent[x] = findSet(parent[x]);
    }
    
    void unionSet(int x, int y)
    {
        x = findSet(x);
        y = findSet(y);
        
        if(x > y)
            swap(x, y);
        
        parent[y] = x;
    }
};

class Solution {
public:
    /* 
    * Approach:
    * Utilize a Union Find Data structure to group all equivalent characters under the smallest lexicographically representative.
    *
    * Complexity:
    * Time Complexity : O(n+m)
    * Space Complexity : O(1)
    */
    string smallestEquivalentString(string s1, string s2, string baseStr) 
    {
        string result{};
        UnionFind uf(26);
        
        for(int i = 0 ; i < (int)s1.size() ; i++)
            uf.unionSet(s1[i]-'a', s2[i]-'a');
        
        for(int i = 0 ; i < (int)baseStr.size() ; i++)
            result += char(uf.findSet(baseStr[i]-'a') + 'a');
        
        return result;
    }
};