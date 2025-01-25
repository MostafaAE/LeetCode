class Solution {
public:
    /**
     * Approach:
     * - Sort the array to group numbers into "buckets" such that numbers in the same bucket differ by at most `limit`.
     * - Use a map (`valToBucket`) to associate each value with its bucket index.
     * - Iterate over the sorted array to create buckets using queues. Each bucket contains values in increasing order.
     * - Finally, construct the result by replacing each value in the original array with the smallest available value
     *   from its bucket while maintaining relative ordering.
     * 
     * Complexity:
     * - Time: O(n log n), where n is the size of the array.
     *   - Sorting takes O(n log n), and creating buckets and constructing the result take O(n).
     * - Space: O(n), for storing buckets and the `valToBucket` mapping.
     */
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        int n = nums.size();

        // Step 1: Sort the array and prepare to group into buckets
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());

        // Buckets to store numbers and a mapping for value-to-bucket index
        vector<queue<int>> buckets;
        unordered_map<int, int> valToBucket;

        int curBucket = 0;
        buckets.push_back(queue<int>());
        buckets[curBucket].push(sortedNums[0]);
        valToBucket[sortedNums[0]] = curBucket;

        // Step 2: Group numbers into buckets
        for (int i = 1; i < n; ++i) 
        {
            if (sortedNums[i] - sortedNums[i - 1] > limit) 
            {
                ++curBucket;
                buckets.push_back(queue<int>());
            }

            buckets[curBucket].push(sortedNums[i]);
            valToBucket[sortedNums[i]] = curBucket;
        }

        // Step 3: Construct the result using buckets
        vector<int> result(n);
        for (int i = 0; i < n; ++i) 
        {
            int bucketIdx = valToBucket[nums[i]];

            result[i] = buckets[bucketIdx].front();
            buckets[bucketIdx].pop();
        }

        return result;
    }
};