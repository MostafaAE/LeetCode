class NumArray {
private:
    int n;
    vector<int> tree;

    /*
     * Build the segment tree.
     */
    void build(vector<int>& nums, int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = nums[left];
            return;
        }

        int mid = left + (right - left) / 2;
        build(nums, node * 2, left, mid);
        build(nums, node * 2 + 1, mid + 1, right);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    /*
     * Query the sum in range [queryLeft, queryRight].
     */
    int sumRange(int queryLeft, int queryRight, int node, int left, int right)
    {
        // No overlap
        if (queryRight < left || right < queryLeft)
        {
            return 0;
        }

        // Full overlap
        if (queryLeft <= left && right <= queryRight)
        {
            return tree[node];
        }

        // Partial overlap
        int mid = left + (right - left) / 2;
        return sumRange(queryLeft, queryRight, node * 2, left, mid)
             + sumRange(queryLeft, queryRight, node * 2 + 1, mid + 1, right);
    }

    /*
     * Update the value at index.
     */
    void update(int index, int val, int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = val;
            return;
        }

        int mid = left + (right - left) / 2;

        if (index <= mid)
        {
            update(index, val, node * 2, left, mid);
        }
        else
        {
            update(index, val, node * 2 + 1, mid + 1, right);
        }

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

public:
    /*
     * Constructor to build segment tree from input array.
     * Time: O(n), Space: O(4n)
     */
    NumArray(vector<int>& nums) 
    {
        n = nums.size();
        tree = vector<int>(4 * n, 0);
        build(nums, 1, 0, n - 1);
    }

    /*
     * Update index to new value.
     * Time: O(log n)
     */
    void update(int index, int val) 
    {
        update(index, val, 1, 0, n - 1);
    }

    /*
     * Return sum in range [left, right].
     * Time: O(log n)
     */
    int sumRange(int left, int right) 
    {
        return sumRange(left, right, 1, 0, n - 1);
    }
};

/*
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int param_2 = obj->sumRange(left, right);
 */