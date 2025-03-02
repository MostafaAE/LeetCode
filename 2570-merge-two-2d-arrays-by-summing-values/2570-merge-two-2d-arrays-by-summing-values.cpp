class Solution {
public:
    /**
     * Approach:
     * - Use two pointers (`idx1`, `idx2`) to traverse `nums1` and `nums2`, respectively.
     * - Since both arrays are sorted by the first element (IDs), merge them similarly to the merge step in Merge Sort.
     * - If the IDs are equal, sum their second values and store them.
     * - If one array is exhausted, append the remaining elements of the other.
     *
     * Complexity:
     * - **Time Complexity:** O(n + m) (linear traversal of both lists)
     * - **Space Complexity:** O(n + m) (result stores all elements)
     */
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) 
    {
        int len1 = nums1.size(), len2 = nums2.size();
        int idx1 = 0, idx2 = 0;
        vector<vector<int>> result;

        while (idx1 < len1 || idx2 < len2)
        {
            if (idx1 == len1)  // nums1 is exhausted, append remaining nums2
            {
                result.push_back(nums2[idx2++]);
            }
            else if (idx2 == len2)  // nums2 is exhausted, append remaining nums1
            {
                result.push_back(nums1[idx1++]);
            }
            else
            {
                int id1 = nums1[idx1][0], id2 = nums2[idx2][0];
                if (id1 == id2)  // Merge same IDs
                {
                    result.push_back({id1, nums1[idx1++][1] + nums2[idx2++][1]});
                }
                else if (id1 < id2)  // nums1 has the smaller ID, add it
                {
                    result.push_back(nums1[idx1++]);
                }
                else  // nums2 has the smaller ID, add it
                {
                    result.push_back(nums2[idx2++]);
                }
            }
        }
        return result;
    }
};