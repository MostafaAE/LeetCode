/*
 * Approach:
 * Binary Search
 * - The main idea is to binary search over the product space (range: [-1e10, 1e10])
 * - For each mid (potential product), we count how many products nums1[i] * nums2[j] are <= mid
 *   using a helper binary search per element in nums1.
 * - Depending on whether the count is < k or >= k, we adjust our binary search range.
 * 
 * Time Complexity : O(n1 * log(n2) * log(1e10)) 
 *                   = O(n1 * log(n2) * 34), since 1e10 ~ 2^34
 *                   where n1 = nums1.size(), n2 = nums2.size()
 * Space Complexity: O(1)
 */

class Solution {
public:
    // Helper function to count how many products nums1[i] * nums2[j] are <= targetProduct
    int countLessEqual(const vector<int>& nums2, long long x1, long long targetProduct) 
    {
        int n = nums2.size();
        int low = 0, high = n - 1;

        while (low <= high) 
        {
            int mid = low + (high - low) / 2;
            long long product = 1LL * nums2[mid] * x1;

            // For positive x1, count values <= targetProduct
            // For negative x1, reverse logic since product decreases as nums2 increases
            if ((x1 >= 0 && product <= targetProduct) || (x1 < 0 && product > targetProduct)) 
                low = mid + 1;
            else 
                high = mid - 1;
        }

        return (x1 >= 0) ? low : (n - low);
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        const long long MIN_PRODUCT = -1e10, MAX_PRODUCT = 1e10;

        long long low = MIN_PRODUCT, high = MAX_PRODUCT;

        int n1 = nums1.size();

        while (low <= high) 
        {
            long long mid = low + (high - low) / 2;

            // Count how many products are <= mid
            long long count = 0;
            for (int i = 0; i < n1; ++i) 
                count += countLessEqual(nums2, nums1[i], mid);

            if (count < k) 
                low = mid + 1;
            else 
                high = mid - 1;
        }

        return low;
    }
};