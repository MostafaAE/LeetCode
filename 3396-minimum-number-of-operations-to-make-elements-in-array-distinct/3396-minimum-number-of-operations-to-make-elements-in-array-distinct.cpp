class Solution {
public:
    /**
    * Approach:
    * - Iterate the array from the end, maintaining a set of seen numbers.
    * - For each number, try to insert it into the set.
    *   - If insertion fails (i.e., the number was already seen), it means we’ve encountered a duplicate.
    *   - At that point, return the group number as `(i / 3 + 1)` where `i` is the index of the duplicate.
    * - If no duplicates are found, return 0.
    * 
    * Time Complexity: O(N)
    * - We iterate through the array once and each insertion/check in the unordered_set is O(1) on average.
    * 
    * Space Complexity: O(N)
    * - In the worst case, all elements are unique, and we store them in the set.
    */
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set<int> hashSet;

        for (int i = n - 1; i >= 0; --i)
        {
            // If element already exists, return the group number
            if (!hashSet.insert(nums[i]).second)
            {
                return (i / 3 + 1);
            }
        }

        return 0;  // No duplicates found
    }
};
