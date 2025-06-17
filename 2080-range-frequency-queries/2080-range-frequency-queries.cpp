class RangeFreqQuery {
private:
    int n;
    vector<unordered_map<int, int>> tree;

    /*
     * Build the segment tree.
     * Time: O(n)
     */
    void build(vector<int>& nums, int node, int left, int right)
    {
        if (left == right)
        {
            tree[node][nums[left]]++;
            return;
        }

        int mid = left + (right - left) / 2;
        build(nums, node * 2, left, mid);
        build(nums, node * 2 + 1, mid + 1, right);

        for (auto& [val, freq] : tree[node * 2])
            tree[node][val] += freq;

        for (auto& [val, freq] : tree[node * 2 + 1])
            tree[node][val] += freq;
    }

    /*
     * Query frequency of `value` in range [queryLeft, queryRight].
     * Time: O(log n)
     */
    int freqRange(int queryLeft, int queryRight, int value, int node, int left, int right)
    {
        // No overlap
        if (queryRight < left || right < queryLeft)
        {
            return 0;
        }

        // Full overlap
        if (queryLeft <= left && right <= queryRight)
        {
            return tree[node][value];
        }

        // Partial overlap
        int mid = left + (right - left) / 2;
        return freqRange(queryLeft, queryRight, value, node * 2, left, mid)
             + freqRange(queryLeft, queryRight, value, node * 2 + 1, mid + 1, right);
    }

public:
    /*
     * Constructor to build segment tree.
     */
    RangeFreqQuery(vector<int>& arr) 
    {
        n = arr.size();
        tree = vector<unordered_map<int, int>>(4 * n);
        build(arr, 1, 0, n - 1);
    }

    /*
     * Query frequency of value in range [left, right].
     */
    int query(int left, int right, int value) 
    {
        return freqRange(left, right, value, 1, 0, n - 1);
    }
};

/*
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left, right, value);
 */