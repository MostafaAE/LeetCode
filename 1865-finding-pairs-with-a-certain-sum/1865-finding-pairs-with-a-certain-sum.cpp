/*
 * Approach:
 * - Store nums2 directly for direct index-based updates.
 * - Maintain frequency maps for nums1 and nums2 to allow fast lookup during count queries.
 * - In `add(index, val)`, update the frequency map of nums2 as the underlying value changes.
 * - In `count(tot)`, for each unique number `num` in nums1, calculate the target `tot - num`,
 *   and check how many times it appears in nums2 using the frequency map.
 *   Multiply their counts to get the number of valid pairs and accumulate.

 * Time Complexity:
 * - Constructor        : O(n + m), where n = nums1.size(), m = nums2.size()
 * - add(index, val)    : O(1)
 * - count(tot)         : O(u), where u = number of unique elements in nums1

 * Space Complexity:
 * - O(n + m), for storing nums2 and frequency maps of nums1 and nums2
 */

class FindSumPairs {
private:
    vector<int> nums2;
    unordered_map<int, int> num1ToCount;
    unordered_map<int, int> num2ToCount;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) 
    {
        this->nums2 = nums2;

        // Build frequency map for nums1
        for (int num : nums1)
            ++num1ToCount[num];

        // Build frequency map for nums2
        for (int num : nums2)
            ++num2ToCount[num];
    }

    // O(1)
    void add(int index, int val) 
    {
        // Update frequency map before and after changing value
        --num2ToCount[nums2[index]];
        nums2[index] += val;
        ++num2ToCount[nums2[index]];
    }

    // O(u), where u = number of unique values in nums1
    int count(int tot) 
    {
        int result = 0;

        for (auto [num, freq1] : num1ToCount) 
        {
            int target = tot - num;
            result += freq1 * num2ToCount[target];
        }

        return result;
    }
};

/**
 * Example usage:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index, val);
 * int result = obj->count(tot);
 */