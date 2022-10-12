class Solution {
public:
    
    // Time Complexity: O(n+m)
    // Space Complexity: O(n+m)
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> merged;

        int itr1{}, itr2{};

        while (itr1 < m && itr2 < n)
        {
            if (nums1[itr1] <= nums2[itr2])
                merged.push_back(nums1[itr1++]);
            else
                merged.push_back(nums2[itr2++]);
        }

        while (itr1 < m)
            merged.push_back(nums1[itr1++]);
        while (itr2 < n)
            merged.push_back(nums2[itr2++]);

        nums1 = merged;
    }
};