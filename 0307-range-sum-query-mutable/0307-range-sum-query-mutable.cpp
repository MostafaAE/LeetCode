class NumArray 
{
private:
    vector<int> _tree; // Binary Indexed Tree (BIT)
    vector<int> _nums; // Original array for reference

public:
    /**
     * Approach:
     * - Use a Binary Indexed Tree (BIT) for efficient range sum queries and updates.
     * - Construct the BIT from the input array:
     *     - Update the tree values using the BIT formula.
     * - To update a value:
     *     - Calculate the difference between the new value and the original value.
     *     - Propagate the difference through the BIT.
     * - To calculate a range sum:
     *     - Use the BIT to compute prefix sums up to `right` and `left-1`.
     *     - Subtract the two prefix sums to get the range sum.
     *
     * Complexity:
     * Time Complexity:
     * - Construction: O(n log n), where `n` is the size of the input array.
     * - Update: O(log n) per update operation.
     * - Query (sumRange): O(log n) per range sum query.
     * Space Complexity: O(n) for the BIT array.
     */

    NumArray(vector<int>& nums) 
    {
        _nums = nums;
        _tree = vector<int>(_nums.size() + 1, 0); // Initialize BIT with 0

        // Build the Binary Indexed Tree (BIT)
        for (int i = 0; i < _nums.size(); ++i)
            _tree[i + 1] = _nums[i];

        for (int i = 1; i < _tree.size(); ++i) 
        {
            int parent = i + (i & -i);
            if (parent < _tree.size())
                _tree[parent] += _tree[i];
        }
    }

    // Update a value in the array and propagate the change through the BIT
    void update(int index, int val) 
    {
        int diff = val - _nums[index];
        _nums[index] = val;

        for (++index; index < _tree.size(); index += (index & -index))
            _tree[index] += diff;
    }

    // Get the prefix sum up to a given index
    int sum(int index) 
    {
        int sum = 0;
        for (++index; index > 0; index -= (index & -index))
            sum += _tree[index];
        return sum;
    }

    // Compute the range sum between `left` and `right`
    int sumRange(int left, int right) 
    {
        return left == 0 ? sum(right) : sum(right) - sum(left - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index, val);
 * int param_2 = obj->sumRange(left, right);
 */