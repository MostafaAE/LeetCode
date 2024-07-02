class Solution {
public:
    /*
     * Approach:
     * - If the size of `nums1` is greater than `nums2`, swap them to minimize space complexity.
     * - Use a hash map to count occurrences of each element in the smaller array.
     * - Iterate through the larger array and check if each element is in the hash map.
     * - If an element from the larger array is in the hash map and the count is greater than 0,
     *   add it to the result and decrease the count in the hash map.
     *
     * Complexity:
     * - Time Complexity: O(m + n), where m is the size of nums1 and n is the size of nums2.
     * - Space Complexity: O(min(m, n)), We use a hash map to store counts of elements from the smaller array.
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        // Ensure nums1 is always the smaller array for optimal space usage.
        if((int)nums1.size() > (int)nums2.size())
            return intersect(nums2, nums1);
        
        unordered_map<int, int> valToCount;
        vector<int> result;

        // Count occurrences of each element in the smaller array.
        for(int i = 0; i < (int)nums1.size(); ++i)
            ++valToCount[nums1[i]];

        // Find common elements by checking the larger array.
        for(int i = 0; i < (int)nums2.size(); ++i)
            if(valToCount.count(nums2[i]) && valToCount[nums2[i]] > 0)
                --valToCount[nums2[i]], result.push_back(nums2[i]);

        return result;
    }
};
