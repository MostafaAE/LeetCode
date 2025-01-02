class Solution {
private:
    int querySum(vector<int> &BIT, int x) 
    {
        int sum = 0;
        for (; x > 0; x -= (x & -x))
            sum += BIT[x];

        return sum;
    }
    
    void update(vector<int> &BIT, int x, const int val) 
    {
        for (; x < BIT.size(); x += (x & -x))
            BIT[x] += val;
    }

public:
    vector<int> processQueries(vector<int>& query, int m) 
    {
        if (m == 1)
            return {0};

        int n = query.size();
        vector<int> ans, tree(m + n + 1, 0), hash(m + 1);

        for (int i = 1; i <= m; ++i) 
        {
            hash[i] = n + i;
            update(tree, n + i, 1); // build binary indexed tree
        }

        for (auto q : query) 
        {
            ans.push_back(querySum(tree, hash[q] - 1));
            update(tree, hash[q], -1); // decrease 1 element to index=hash[q] and after
            update(tree, n, 1); //increase 1 element to index=n and after
            hash[q] = n--; //update hash[q]
        }

        return ans;
    }
};