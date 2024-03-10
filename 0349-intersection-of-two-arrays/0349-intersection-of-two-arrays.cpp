class Solution {
public:
    /*
     * Approach:
     * Utilize a hash set to store the first array, then iterate on the second array checking each value if it exists in the hast set, then add it to the output.
     *
     * Complexity:
     * Time Complexity : O(n + m)
     * Space Complexity : O(n)
     */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        // O(n)
        unordered_set<int> hashSet(nums1.begin(), nums1.end()), res;
        
        // O(m)
        for(int val : nums2)
            if(hashSet.count(val))
                res.insert(val);
        
        return vector<int>(res.begin(), res.end());
    }
};